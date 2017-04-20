//
// Created by Dmitry Mozgin on 18/04/2017.
//

#pragma once

#include "cinder/app/App.h"
#include "cinder/gl/gl.h"

#include "AppObject.h"
#include "AdaptiveTextureFont.h"

namespace vd {

class DebugInfoText : public AppObject {

public:

    DebugInfoText(const ci::app::App &app, const AdaptiveTextureFontRef &font);

    void Draw();

private:

    std::string _text;

    ci::vec2 _textSize;

    const AdaptiveTextureFontRef _textFont;
};

}