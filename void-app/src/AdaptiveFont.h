//
// Created by Dmitry Mozgin on 19/04/2017.
//

#pragma once

#include "cinder/gl/gl.h"

#include "VoidAppObject.h"

#undef None // Shit.. but otherwise a problem with compilation on rpi.

namespace vd {

//! Helper class which is needed for AdaptiveTextureFont to handle rendering on retina displays.
class AdaptiveFont : public VoidAppObject {

    friend class AdaptiveTextureFont;

public:

    AdaptiveFont(VoidApp &app, const ci::DataSourceRef &dataSource, float size);

private:

    //region Functions used by AdaptiveTextureFont

    const std::shared_ptr<ci::Font> getInternalFont() const {
        return _font;
    }

    //endregion

    std::shared_ptr<ci::Font> _font;

};

}
