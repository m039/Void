//
// Created by Dmitry Mozgin on 18/04/2017.
//

#pragma once

#include "cinder/app/App.h"
#include "cinder/gl/gl.h"

namespace vd {

    class DebugInfoText {

    public:
        DebugInfoText(const ci::app::App &app, const ci::gl::TextureFontRef &font) : _textFont(font) {
            std::string text;

            text.append("Void, ");
            text.append((app.getWindowContentScale() > 1)? "retina" : "non-retina");
            text.append(". ");

            _text = text;
            _textSize = font->measureString(_text);
        }

        void Draw(ci::app::WindowRef window);

    private:

        std::string _text;

        ci::vec2 _textSize;

        const ci::gl::TextureFontRef &_textFont;
    };

}