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
    setupCamera();
    auto audio = setupAudio();

    getWindow()->getSignalResize().connect(std::bind(&VoidApp::onResize, this));

    gl::enableAlphaBlending();

    _objectPool = std::make_shared<ObjectPoolGl>();

    // Create and start the game.
    _game = std::make_unique<VoidGameHut>(
            std::make_shared<MeshFactory>(),
            audio,
            _objectPool
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

    gl::clear(ci::Color::white());
    gl::color(ci::Color::black());

    _infoText->Draw();

    drawPool();
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
    setupCamera();
}

AdaptiveTextureFontRef VoidApp::loadFont(const std::string &name, float size) {
    auto font = AdaptiveFont(*this, loadAsset("Fonts/" + name), size);
    return AdaptiveTextureFont::create(*this, font);
}

std::shared_ptr<IAudioPlayer> VoidApp::setupAudio() {
    auto context = audio::Context::master();
    auto sourceFile = audio::load(loadAsset("Music/" + _MusicFilename), context->getSampleRate());

    auto player = context->makeNode(new audio::FilePlayerNode(sourceFile));
    auto gain = context->makeNode(new audio::GainNode(1.0f));

    player >> gain >> context->getOutput();

    context->enable();

    return std::make_shared<AudioPlayer>(player, gain);
}

void VoidApp::setupCamera() {
    auto windowSize = getWindow()->getSize();
    auto aspectRatio = (float) windowSize.x / (float) windowSize.y;

    _camera.lookAt(vec3(0, 0, 3), vec3(0));
    _camera.setPerspective(35, aspectRatio, 0.1f, 1000.0f);
}

void VoidApp::setupShader() {
    _shader = std::make_unique<UnlitShader>(*this);

    _shader->SetFogEnabled(true);
    _shader->SetFogColor(ci::Color::black());
    _shader->SetFogStartPosition(0);
    _shader->SetFogDensity(0.1f);
    _shader->SetMinFogFactor(0.0f);
}

void VoidApp::drawPool() {
    gl::pushMatrices();
    gl::setMatrices(_camera);

    _shader->SetMatrices(_camera);
    _shader->SetMainColor(vec4(1.0f, 0.0f, 1.0f, 1.0f));

    _objectPool->Draw(*this);

    gl::popMatrices();
}

//endregion
