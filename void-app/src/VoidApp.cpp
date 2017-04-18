//
// Created by Dmitry Mozgin on 17/04/2017.
//

#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

#include "VoidApp.h"

using namespace ci;
using namespace ci::app;

using namespace vd;

//region Consts

const std::string _HeadlineFontName = "CaviarDreamsR.ttf";

const std::string _TextFontName = "CrimsonTextRo.ttf";

//endregion

void prepareSettings(VoidApp::Settings *settings) {
    settings->setHighDensityDisplayEnabled();
    settings->setMultiTouchEnabled( false );
}

CINDER_APP( VoidApp, app::RendererGl, prepareSettings)

void VoidApp::setup() {
    app::AppBase::setup();

    _headlineFont = loadFont(_HeadlineFontName, 30);
    _textFont = loadFont(_TextFontName, 20);
    _infoText = std::make_unique<DebugInfoText>(*this, _headlineFont);

    setupCamera();

    getWindow()->getSignalResize()
            .connect(std::bind(&VoidApp::onResize, this));
}

void VoidApp::update() {
    app::AppBase::update();
}

void VoidApp::draw() {
    AppBase::draw();

    gl::clear(Color::white());
    gl::color(Color::black());

    _infoText->Draw();

    // draw 3d

    gl::pushMatrices();

    gl::setMatrices(_camera);

    gl::drawCube( vec3(), vec3( 1 ) );

    gl::popMatrices();
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

ci::gl::TextureFontRef VoidApp::loadFont(const std::string &name, float size) {
    auto font = Font(loadAsset("Fonts/" + name), size);

    return gl::TextureFont::create(font, gl::TextureFont::Format().enableMipmapping());
}

void VoidApp::onResize() {
    setupCamera();
}

void VoidApp::setupCamera() {
    auto windowSize = getWindow()->getSize();
    auto aspectRatio = (float) windowSize.x / (float) windowSize.y;

    _camera.lookAt(vec3(3, 3, 3), vec3(0));
    _camera.setPerspective(35, aspectRatio, 0.1f, 1000);
}

//endregion