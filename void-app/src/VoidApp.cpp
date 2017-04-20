//
// Created by Dmitry Mozgin on 17/04/2017.
//

#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

#include "VoidApp.h"
#include "DrawHelper.h"

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
    AppBase::setup();

    _headlineFont = loadFont(_HeadlineFontName, 34);
    _textFont = loadFont(_TextFontName, 20);
    _infoText = std::make_unique<DebugInfoText>(*this, _headlineFont);

    setupShader();
    setupCamera();

    getWindow()->getSignalResize().connect(std::bind(&VoidApp::onResize, this));

    gl::enableAlphaBlending();
}

void VoidApp::update() {
    app::AppBase::update();
}

void VoidApp::draw() {
    AppBase::draw();

    gl::clear(Color::white());
    gl::color(Color::black());

    _infoText->Draw();

    drawCube();
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

void VoidApp::setupCamera() {
    auto windowSize = getWindow()->getSize();
    auto aspectRatio = (float) windowSize.x / (float) windowSize.y;

    _camera.lookAt(vec3(3, 3, 3), vec3(0));
    _camera.setPerspective(35, aspectRatio, 0.1f, 1000);
}

void VoidApp::setupShader() {
    _shader = std::make_unique<UnlitShader>(*this);

    _shader->SetFogEnabled(true);
    _shader->SetFogColor(Color::black());
    _shader->SetFogStartPosition(0);
    _shader->SetFogDensity(0.1f);
    _shader->SetMinFogFactor(0.0f);
}

//! Draw cube by hand
void VoidApp::drawCube() {
    gl::pushMatrices();
    gl::setMatrices(_camera);

    _shader->SetMatrices(_camera);
    _shader->SetMainColor(vec4(1.0f, 0.0f, 1.0f, 1.0f));

    // draw a cube by hand

    vec3 c {0.0f};
    vec3 size {1.0f};

    GLfloat sx = size.x * 0.5f;
    GLfloat sy = size.y * 0.5f;
    GLfloat sz = size.z * 0.5f;

    static std::vector<GLfloat> vertices {
            c.x+1.0f*sx,c.y+1.0f*sy,c.z+1.0f*sz,	c.x+1.0f*sx,c.y+-1.0f*sy,c.z+1.0f*sz,	c.x+1.0f*sx,c.y+-1.0f*sy,c.z+-1.0f*sz,	c.x+1.0f*sx,c.y+1.0f*sy,c.z+-1.0f*sz,		// +X
            c.x+1.0f*sx,c.y+1.0f*sy,c.z+1.0f*sz,	c.x+1.0f*sx,c.y+1.0f*sy,c.z+-1.0f*sz,	c.x+-1.0f*sx,c.y+1.0f*sy,c.z+-1.0f*sz,	c.x+-1.0f*sx,c.y+1.0f*sy,c.z+1.0f*sz,		// +Y
            c.x+1.0f*sx,c.y+1.0f*sy,c.z+1.0f*sz,	c.x+-1.0f*sx,c.y+1.0f*sy,c.z+1.0f*sz,	c.x+-1.0f*sx,c.y+-1.0f*sy,c.z+1.0f*sz,	c.x+1.0f*sx,c.y+-1.0f*sy,c.z+1.0f*sz,		// +Z
            c.x+-1.0f*sx,c.y+1.0f*sy,c.z+1.0f*sz,	c.x+-1.0f*sx,c.y+1.0f*sy,c.z+-1.0f*sz,	c.x+-1.0f*sx,c.y+-1.0f*sy,c.z+-1.0f*sz,	c.x+-1.0f*sx,c.y+-1.0f*sy,c.z+1.0f*sz,	// -X
            c.x+-1.0f*sx,c.y+-1.0f*sy,c.z+-1.0f*sz,	c.x+1.0f*sx,c.y+-1.0f*sy,c.z+-1.0f*sz,	c.x+1.0f*sx,c.y+-1.0f*sy,c.z+1.0f*sz,	c.x+-1.0f*sx,c.y+-1.0f*sy,c.z+1.0f*sz,	// -Y
            c.x+1.0f*sx,c.y+-1.0f*sy,c.z+-1.0f*sz,	c.x+-1.0f*sx,c.y+-1.0f*sy,c.z+-1.0f*sz,	c.x+-1.0f*sx,c.y+1.0f*sy,c.z+-1.0f*sz,	c.x+1.0f*sx,c.y+1.0f*sy,c.z+-1.0f*sz	// -Z
    };

    static std::vector<GLubyte> elements {
            0, 1, 2, 0, 2, 3,
            4, 5, 6, 4, 6, 7,
            8, 9,10, 8, 10,11,
            12,13,14,12,14,15,
            16,17,18,16,18,19,
            20,21,22,20,22,23
    };

    DrawHelper::draw(*this, vertices, elements);

    gl::popMatrices();
}

//endregion
