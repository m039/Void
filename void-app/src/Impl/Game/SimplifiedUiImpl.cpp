//
// Created by Dmitry Mozgin on 05/05/2017.
//

#include "SimplifiedUiImpl.h"

using namespace vd;

//region ScreenDrawerImpl

SimplifiedUiImpl::ScreenDrawerImpl::ScreenDrawerImpl(SimplifiedUiImpl& ui) : _ui(ui) {

}

void SimplifiedUiImpl::ScreenDrawerImpl::SelectHeadlineFont() {

}

void SimplifiedUiImpl::ScreenDrawerImpl::SelectTextFont() {

}

void SimplifiedUiImpl::ScreenDrawerImpl::DrawText(const std::string& text, const Vector2& position, const Color& color) {

}

void SimplifiedUiImpl::ScreenDrawerImpl::DrawFullscreenPlane(const Color& color) {

}

float SimplifiedUiImpl::ScreenDrawerImpl::GetScreenWidth() const {
    return 100;
}

float SimplifiedUiImpl::ScreenDrawerImpl::GetScreenHeight() const {
    return 100;
}

Vector2 SimplifiedUiImpl::ScreenDrawerImpl::MeasureString(const std::string& text) {
    return vd::Vector2(10, 10);
}

//endregion

//region SimplifiedUiImpl

SimplifiedUiImpl::SimplifiedUiImpl(VoidApp& app)
        : VoidAppObject(app),
          _drawer(*this)
{
}

void SimplifiedUiImpl::Register(const IScreenDrawableRef& drawable) {
    _drawables.push_back(drawable);
}

void SimplifiedUiImpl::Unregister(const IScreenDrawableRef& drawable) {
    auto begin = _drawables.begin();
    auto end = _drawables.end();
    auto it = std::find(begin, end, drawable);

    if (it != end) {
        _drawables.erase(it);
    }
}

void SimplifiedUiImpl::Draw() {
    for (auto& d: _drawables) {
        d->Draw(_drawer);
    }
}

//endregion
