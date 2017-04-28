//
// Created by Dmitry Mozgin on 19/04/2017.
//

#include "AdaptiveFont.h"

#include "VoidApp.h"

using namespace vd;

AdaptiveFont::AdaptiveFont(const VoidApp &app, const ci::DataSourceRef &dataSource, float size)
        : VoidAppObject(app)
{
    _font = std::make_shared<ci::Font>(dataSource, size * app.getWindowContentScale());
}
