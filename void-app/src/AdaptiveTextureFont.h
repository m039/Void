//
// Created by Dmitry Mozgin on 19/04/2017.
//

#pragma once

#include "VoidAppObject.h"
#include "AdaptiveFont.h"

#include "cinder/gl/gl.h"
#include "cinder/app/App.h"

namespace vd {

typedef std::shared_ptr<class AdaptiveTextureFont>	AdaptiveTextureFontRef;

//! Wrapper for TextureFont that handles rendering on retina displays.
class AdaptiveTextureFont : public VoidAppObject {

public:

    static AdaptiveTextureFontRef create(VoidApp &app, const AdaptiveFont &font) {
        return AdaptiveTextureFontRef(new AdaptiveTextureFont(app, font));
    }

    ci::vec2 measureString(const std::string &str,
                           const ci::gl::TextureFont::DrawOptions &options = ci::gl::TextureFont::DrawOptions()) const;

    void drawString(const std::string &str,
                    const ci::vec2 &baseline,
                    const ci::gl::TextureFont::DrawOptions &options = ci::gl::TextureFont::DrawOptions());

protected:

    AdaptiveTextureFont(VoidApp &app, const AdaptiveFont &font);

private:

    ci::gl::TextureFontRef _font;

};

}
