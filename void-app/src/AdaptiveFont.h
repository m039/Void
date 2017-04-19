//
// Created by Dmitry Mozgin on 19/04/2017.
//

#pragma once

#include "AppObject.h"

#include "cinder/gl/gl.h"

namespace vd {

class AdaptiveTextureFont;

//! Helper class which is needed for AdaptiveTextureFont to handle rendering on retina displays.
class AdaptiveFont : public AppObject {

    friend AdaptiveTextureFont;

public:

    AdaptiveFont(const cinder::app::App &app, ci::DataSourceRef dataSource, float size);

private:

    const ci::Font& getFont() const {
        return *_font;
    }

    std::unique_ptr<ci::Font> _font;

};

}
