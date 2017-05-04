//
// Created by Dmitry Mozgin on 18/04/2017.
//

#include "DebugInfoText.h"

#include "VoidApp.h"

using namespace vd;

DebugInfoText::DebugInfoText(VoidApp &app, const AdaptiveTextureFontRef &font)
        : VoidAppObject(app), _textFont(font) {
    std::string text;

    text.append("Void, ");
    text.append((app.getWindowContentScale() > 1)? "retina" : "non-retina");
    text.append(". ");

    _text = text;
    _textSize = font->measureString(_text);
}

void DebugInfoText::Draw() {
    auto windowSize = app.getWindow()->getSize();
    auto textPosition = ci::vec2(windowSize.x - _textSize.x, windowSize.y - _textSize.y);

    _textFont->drawString(_text, textPosition);
}
