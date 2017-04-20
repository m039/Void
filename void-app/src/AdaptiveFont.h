//
// Created by Dmitry Mozgin on 19/04/2017.
//

#pragma once

#include "AppObject.h"

#include "cinder/gl/gl.h"

namespace vd {

//! Helper class which is needed for AdaptiveTextureFont to handle rendering on retina displays.
class AdaptiveFont : public AppObject {

public:

    AdaptiveFont(const cinder::app::App &app, const ci::DataSourceRef &dataSource, float size);

    const std::shared_ptr<ci::Font> getInternalFont() const {
        return _font;
    }

private:

    std::shared_ptr<ci::Font> _font;

};

}
