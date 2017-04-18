//
// Created by Dmitry Mozgin on 17/04/2017.
//

#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

#include "VoidApp.h"

using namespace ci;

void prepareSettings(VoidApp::Settings *settings) {
    settings->setHighDensityDisplayEnabled();
    settings->setMultiTouchEnabled( false );
}

CINDER_APP( VoidApp, app::RendererGl, prepareSettings)

void VoidApp::setup() {
    app::AppBase::setup();

    console() << "Setup " << std::endl;

    getWindow()->getSignalDisplayChange().connect( std::bind( &VoidApp::displayChange, this ) );
}

void VoidApp::update() {
    app::AppBase::update();
}

void VoidApp::draw() {
    app::AppBase::draw();

    gl::clear( Color::black() );
    
    std::string s = ( getWindowContentScale() > 1 ) ? "Retina" : "Non-Retina";

    gl::drawString("Hello, world. " + s + ".", vec2(40, 40));
}

void VoidApp::displayChange() {

}
