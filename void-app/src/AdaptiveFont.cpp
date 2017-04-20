//
// Created by Dmitry Mozgin on 19/04/2017.
//

#include "AdaptiveFont.h"

using namespace vd;

AdaptiveFont::AdaptiveFont(const cinder::app::App &app, const ci::DataSourceRef &dataSource, float size)
        : AppObject(app)
{
    _font = std::make_shared<ci::Font>(dataSource, size * app.getWindowContentScale());
}
