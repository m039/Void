//
// Created by Dmitry Mozgin on 19/04/2017.
//

#pragma once

#include "cinder/app/App.h"

namespace vd {

class VoidApp;

//! Class which lives as long as the application lives.
class VoidAppObject {

protected:

    VoidAppObject(const VoidApp &app) : app(app) {
    }

    const VoidApp& app;

};

}



