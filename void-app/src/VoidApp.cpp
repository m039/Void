//
// Created by Dmitry Mozgin on 17/04/2017.
//

#include <Common/Time.h>

#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/audio/audio.h"

#include "VoidApp.h"
#include "DrawHelper.h"
#include "Impl/Common/Components/AudioPlayer.h"
#include "Impl/Common/MeshFactory.h"

using namespace ci;
using namespace ci::app;

using namespace vd;

//region Constants

const std::string _HeadlineFontFilename = "CaviarDreamsR.ttf";

const std::string _TextFontFilename = "CrimsonTextRo.ttf";

const std::string _MusicFilename = "Void.ogg";

//endregion

void prepareSettings(VoidApp::Settings *settings) {
    settings->setHighDensityDisplayEnabled();
    settings->setMultiTouchEnabled( false );
}

CINDER_APP( VoidApp, app::RendererGl, prepareSettings)

void VoidApp::setup() {
    AppBase::setup();

    _headlineFont = loadFont(_HeadlineFontFilename, 34);
    _textFont = loadFont(_TextFontFilename, 20);
    _infoText = std::make_unique<DebugInfoText>(*this, _headlineFont);

    setupShader();
    auto audio = setupAudio();

    getWindow()->getSignalResize().connect(std::bind(&VoidApp::onResize, this));

    gl::enableAlphaBlending();


    _objectPool = std::make_shared<ObjectPoolGl>(*this);
    _camera = std::make_shared<Camera>(*this);

    // Create and start the game.
    _game = std::make_unique<VoidGameHut>(
            std::make_shared<MeshFactory>(),
            audio,
            _objectPool,
            _camera,
            nullptr
    );
    _game->Start();
}

void VoidApp::update() {
    app::AppBase::update();

    // Update the game.
    _game->Update();
}

void VoidApp::draw() {
    AppBase::draw();

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

    gl::color(ci::Color::white());

    _infoText->Draw();
}

void VoidApp::keyDown(KeyEvent event) {
    AppBase::keyDown(event);

    auto code = event.getCode();

    switch (code) {
        case KeyEvent::KEY_f:
            setFullScreen(!isFullScreen());
            break;
        case KeyEvent::KEY_q:
            quit();
            break;
        default:
            break;
    }
}

//region Misc

void VoidApp::onResize() {
    _camera->Setup();
}

AdaptiveTextureFontRef VoidApp::loadFont(const std::string &name, float size) {
    auto font = AdaptiveFont(*this, loadAsset("Fonts/" + name), size);
    return AdaptiveTextureFont::create(*this, font);
}

IAudioPlayerRef VoidApp::setupAudio() {
    auto context = audio::Context::master();
    auto sourceFile = audio::load(loadAsset("Music/" + _MusicFilename), context->getSampleRate());

    auto player = context->makeNode(new audio::FilePlayerNode(sourceFile));
    auto gain = context->makeNode(new audio::GainNode(1.0f));

    player >> gain >> context->getOutput();

    context->enable();

    return std::make_shared<AudioPlayer>(player, gain);
}

void VoidApp::setupShader() {
    _shader = std::make_unique<UnlitShader>(*this);

    _shader->SetFogEnabled(true);
    _shader->SetFogColor(ci::Color::black());
    _shader->SetFogStartPosition(0);
    _shader->SetFogDensity(0.1f);
    _shader->SetMinFogFactor(0.0f);
}

//endregion
