//
// Created by Dmitry Mozgin on 28/04/2017.
//

#pragma once

#include <sstream>

#include <Common/Color.h>

namespace vd {

//! Game specific colors, they may differ from Color's constants.
class Colors {

public:

    static const Color White;

    static const Color Black;

    static const Color Red;

    static const Color WarningRed;

    static const Color Blue;

    static const Color Green;

private:

    static Color ParseString(const std::string& colorString);

};

}
