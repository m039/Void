//
// Created by Dmitry Mozgin on 18/04/2017.
//

#pragma once

#include "cinder/app/App.h"
#include "cinder/gl/gl.h"

#include "VoidAppObject.h"
#include "AdaptiveTextureFont.h"

namespace vd {

class DebugInfoText : public VoidAppObject {

public:

    DebugInfoText(const VoidApp &app, const AdaptiveTextureFontRef &font);

    void Draw();

private:

    std::string _text;

    ci::vec2 _textSize;

    const AdaptiveTextureFontRef _textFont;
};

}