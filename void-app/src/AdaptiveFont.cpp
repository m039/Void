//
// Created by Dmitry Mozgin on 19/04/2017.
//

#include "AdaptiveFont.h"

using namespace vd;

AdaptiveFont::AdaptiveFont(const cinder::app::App &app, ci::DataSourceRef dataSource, float size)
        : AppObject(app)
{
    _font = std::make_unique<ci::Font>(dataSource, size * app.getWindowContentScale());
}
