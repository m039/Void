//
// Created by Dmitry Mozgin on 19/04/2017.
//

#include "AdaptiveTextureFont.h"

using namespace ci;
using namespace vd;

AdaptiveTextureFont::AdaptiveTextureFont(const ci::app::App &app, const AdaptiveFont &font)
    : AppObject(app)
{
    _font = gl::TextureFont::create(font.getFont(), gl::TextureFont::Format().enableMipmapping(true));
}

vec2 AdaptiveTextureFont::measureString(const std::string &str,
                                        const gl::TextureFont::DrawOptions &options) const {
    return _font->measureString(str, options) / app.getWindowContentScale();
}

void AdaptiveTextureFont::drawString(const std::string &str,
                                     const ci::vec2 &baseline,
                                     const gl::TextureFont::DrawOptions &options) {
    auto scale = options.getScale();

    _font->drawString(
            str,
            baseline,
            gl::TextureFont::DrawOptions(options).scale(scale * 1.0f / app.getWindowContentScale())
    );
}
