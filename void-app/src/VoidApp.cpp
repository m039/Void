//
// Created by Dmitry Mozgin on 17/04/2017.
//

#include <Common/Time.h>

#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/audio/audio.h"

#include "VoidApp.h"
#include "DrawHelper.h"
#include "Impl/Common/Components/AudioPlayerImpl.h"
#include "Impl/Common/MeshFactoryImpl.h"
#include "Impl/Common/GameContextImpl.h"
#include "Impl/Common/ShadersManagerImpl.h"

using namespace ci;
using namespace ci::app;

using namespace vd;

//region Constants

const std::string _MusicFilename = "Void.ogg";

//endregion

void prepareSettings(VoidApp::Settings *settings) {
    settings->setHighDensityDisplayEnabled();
    settings->setMultiTouchEnabled(false);
}

CINDER_APP( VoidApp, app::RendererGl, prepareSettings)

void VoidApp::setup() {
    AppBase::setup();

    SetupShader();
    auto audio = SetupAudio();

    getWindow()->getSignalResize().connect(std::bind(&VoidApp::OnResize, this));

    gl::enableAlphaBlending();

    _objectPool = std::make_shared<ObjectPoolImpl>(*this);
    _camera = std::make_shared<CameraImpl>(*this);
    _input = std::make_shared<InputImpl>(*this);
    auto shaders = std::make_shared<ShadersManagerImpl>(*this);
    auto gameContext = std::make_shared<GameContextImpl>(*this);
    _ui = std::make_shared<SimplifiedUiImpl>(*this);

    // Create and start the game.
    _game = std::make_unique<VoidGameHut>(
            gameContext,
            std::make_shared<MeshFactoryImpl>(),
            audio,
            _objectPool,
            _camera,
            _input,
            shaders,
            _ui
    );
    _game->Start();
}

void VoidApp::update() {
    app::AppBase::update();

    if (getQuitRequested()) {
        return;
    }

    _input->Update();

    // Update the game.
    _game->Update();
}

void VoidApp::draw() {
    AppBase::draw();

    if (getQuitRequested()) {
        return;
    }

    // Set background color.

    auto c = _camera->GetBackgroundColor();

    gl::clear(ci::vec4(c.r, c.g, c.b, c.a));

    gl::enableDepthRead();
    gl::enableDepthWrite();

    // Draw an object pool.

    gl::pushMatrices();

    _camera->LoadMatrices();
    _objectPool->Draw();

    gl::popMatrices();

    // Draw an info text.

    gl::disableDepthRead();
    gl::disableDepthWrite();

    // Draw UI.

    _ui->Draw();
}

void VoidApp::keyDown(KeyEvent event) {
    AppBase::keyDown(event);

    auto code = event.getCode();

    switch (code) {
        case KeyEvent::KEY_f:
            setFullScreen(!isFullScreen());
            break;
        default:
            break;
    }

    _input->KeyDown(event);
}

void VoidApp::keyUp(ci::app::KeyEvent event) {
    AppBase::keyUp(event);

    _input->KeyUp(event);
}

//region Misc

void VoidApp::OnResize() {
    _camera->Setup();
}

AdaptiveTextureFontRef VoidApp::LoadFont(const std::string& name, float size) {
    auto font = AdaptiveFont(*this, loadAsset("Fonts/" + name), size);
    return AdaptiveTextureFont::create(*this, font);
}

IAudioPlayerRef VoidApp::SetupAudio() {
    auto context = audio::Context::master();
    auto sourceFile = audio::load(loadAsset("Music/" + _MusicFilename), context->getSampleRate());

    auto player = context->makeNode(new audio::FilePlayerNode(sourceFile));
    auto gain = context->makeNode(new audio::GainNode(1.0f));

    player >> gain >> context->getOutput();

    context->enable();

    return std::make_shared<AudioPlayerImpl>(player, gain);
}

void VoidApp::SetupShader() {
    _shader = std::make_unique<UnlitShader>(*this);
}

//endregion
