//
// Created by Dmitry Mozgin on 03/05/2017.
//

#include "Colors.h"

using namespace vd;

const Color Colors::White = Color::White;

const Color Colors::Black = Color::Black;

const Color Colors::Red = ParseString("#ff4850");

const Color Colors::WarningRed = ParseString("#FF452BFF");

const Color Colors::Blue = Color::Blue;

const Color Colors::Green = Color::Green;

Color Colors::ParseString(const std::string &colorString) {
    static std::function<float(const std::string&)> parse = [](const std::string& s) {
        std::stringstream ss;

        ss << std::hex << s;

        unsigned int number;

        ss >> number;

        return ((float) number) / 256.0f;
    };

    auto r = parse(colorString.substr(1, 2));
    auto g = parse(colorString.substr(3, 2));
    auto b = parse(colorString.substr(5, 2));

    return Color(r, g, b, 1.0f);
}
