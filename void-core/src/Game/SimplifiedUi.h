//
// Created by Dmitry Mozgin on 05/05/2017.
//

#pragma once

#include <Common/Vector2.h>
#include <Common/Color.h>

namespace vd {

class IScreenDrawer {
public:

	virtual void SelectHeadlineFont() = 0;

	virtual void SelectTextFont() = 0;

	virtual void DrawText(const std::string& text, const Vector2& position, const Color& color) = 0;

	virtual void DrawFullscreenPlane(const Color& color) = 0;

	virtual float GetScreenWidth() const = 0;

	virtual float GetScreenHeight() const = 0;

	virtual Vector2 MeasureString(const std::string& text) = 0;

	virtual ~IScreenDrawer();

};

class IScreenDrawable {
public:

	virtual void Draw(IScreenDrawer& drawer) = 0;

    virtual ~IScreenDrawable();

};

typedef std::shared_ptr<IScreenDrawable> IScreenDrawableRef;

// Note: assume every text is static.
class ISimplifiedUi {
public:

	//! Registers \param drawable for Draw events, like IScreenDrawable::Draw.
	virtual void Register(const IScreenDrawableRef& drawable) = 0;

	virtual void Unregister(const IScreenDrawableRef& drawable) = 0;

	virtual ~ISimplifiedUi();

};

typedef std::shared_ptr<ISimplifiedUi> ISimplifiedUiRef;

}