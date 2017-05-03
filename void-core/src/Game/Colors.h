//
// Created by Dmitry Mozgin on 28/04/2017.
//

#pragma once

#include <Common/Color.h>
#include <sstream>

namespace vd {

//! Game specific colors.
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