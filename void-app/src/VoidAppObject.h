//
// Created by Dmitry Mozgin on 19/04/2017.
//

#pragma once

#include "cinder/app/App.h"

namespace vd {

class VoidApp;

//! Class that lives as long as the application lives.
class VoidAppObject {

protected:

    VoidAppObject(VoidApp &app) : app(app) {
    }

    VoidApp& app;

};

}



