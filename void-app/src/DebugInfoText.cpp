//
// Created by Dmitry Mozgin on 18/04/2017.
//

#include "DebugInfoText.h"

using namespace vd;

void DebugInfoText::Draw(ci::app::WindowRef window) {
    auto windowSize = window->getSize();
    auto textPosition = ci::vec2(windowSize.x - _textSize.x, windowSize.y - _textSize.y);

    _textFont->drawString(_text, textPosition);
}
