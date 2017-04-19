//
// Created by Dmitry Mozgin on 19/04/2017.
//

#pragma once

#include "cinder/app/App.h"

namespace vd {

//! Class which lives as long as the application lives.
class AppObject {

protected:

    AppObject(const ci::app::App &app) : app(app) {

    }

    const ci::app::App& app;

};

}



