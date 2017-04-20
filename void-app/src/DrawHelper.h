//
// Created by Dmitry Mozgin on 20/04/2017.
//

#pragma once

#include "cinder/gl/gl.h"

namespace vd {

class VoidApp;

class DrawHelper {

public:

    //! Stripped version of ci::gl::drawCube.
    static void draw(const VoidApp &app , std::vector<GLfloat> vertices, std::vector<GLubyte> elements);

};

}






