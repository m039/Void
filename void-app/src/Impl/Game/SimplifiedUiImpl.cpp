//
// Created by Dmitry Mozgin on 05/05/2017.
//

#include "SimplifiedUiImpl.h"

#include "cinder/gl/gl.h"
#include "../../VoidApp.h"

using namespace vd;
using namespace ci;

//region Constants

const std::string _HeadlineFontFilename = "CaviarDreamsR.ttf";

const std::string _TextFontFilename = "CrimsonTextRo.ttf";

//endregion

//region ScreenDrawerImpl

SimplifiedUiImpl::ScreenDrawerImpl::ScreenDrawerImpl(SimplifiedUiImpl& ui) : _ui(ui) {
}

void SimplifiedUiImpl::ScreenDrawerImpl::SelectHeadlineFont() {
    _ui._currentFont = _ui._headline;
}

void SimplifiedUiImpl::ScreenDrawerImpl::SelectTextFont() {
    _ui._currentFont = _ui._text;
}

void SimplifiedUiImpl::ScreenDrawerImpl::DrawText(const std::string& text, const Vector2& position, const Color& color) {
    gl::color(color.r, color.g, color.b, color.a);
    _ui._currentFont->drawString(text, ci::vec2(position.x, position.y));
}

void SimplifiedUiImpl::ScreenDrawerImpl::DrawFullscreenPlane(const Color& color) {
    auto size = _ui.GetApp().getWindow()->getSize();

    Rectf rect = Rectf(0, 0, size.x, size.y);

    gl::color(color.r, color.g, color.b, color.a);
    gl::drawSolidRect(rect);
}

float SimplifiedUiImpl::ScreenDrawerImpl::GetScreenWidth() const {
    return _ui.app.getWindow()->getSize().x;
}

float SimplifiedUiImpl::ScreenDrawerImpl::GetScreenHeight() const {
    return _ui.app.getWindow()->getSize().y;
}

Vector2 SimplifiedUiImpl::ScreenDrawerImpl::MeasureString(const std::string& text) {
    auto v = _ui._currentFont->measureString(text);
    return Vector2(v.x, v.y);
}

//endregion

//region SimplifiedUiImpl

SimplifiedUiImpl::SimplifiedUiImpl(VoidApp& app)
        : VoidAppObject(app),
          _drawer(*this)
{
    _headline = app.LoadFont(_HeadlineFontFilename, 18 * 5);
    _text = app.LoadFont(_TextFontFilename, 24);
    _currentFont = _headline;
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
