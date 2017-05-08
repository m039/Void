//
// Created by Dmitry Mozgin on 05/05/2017.
//

#pragma once

#include <Game/SimplifiedUi.h>
#include "../../VoidAppObject.h"
#include "../../AdaptiveTextureFont.h"

namespace vd {

class SimplifiedUiImpl
        : public VoidAppObject,
          public ISimplifiedUi
{
    class ScreenDrawerImpl : public IScreenDrawer {
    public:

        ScreenDrawerImpl(SimplifiedUiImpl& ui);

        virtual void SelectHeadlineFont() override;

        virtual void SelectTextFont() override;

        virtual void DrawText(const std::string& text, const Vector2& position, const Color& color) override;

        virtual void DrawFullscreenPlane(const Color& color) override;

        virtual float GetScreenWidth() const override;

        virtual float GetScreenHeight() const override;

        virtual Vector2 MeasureString(const std::string& text) override;

    private:

        SimplifiedUiImpl &_ui;

    };

public:

    SimplifiedUiImpl(VoidApp &app);

    //region Implementation of ISimplifiedUi.

    virtual void Register(const IScreenDrawableRef& drawable) override;

    virtual void Unregister(const IScreenDrawableRef& drawable) override;

    //endregion

    VoidApp& GetApp() {
        return app; // Make it visible for ScreenDrawerImpl.
    }

    void Draw();

private:

    AdaptiveTextureFontRef _headline;

    AdaptiveTextureFontRef _text;

    AdaptiveTextureFontRef _currentFont;

    ScreenDrawerImpl _drawer;

    std::vector<IScreenDrawableRef> _drawables;

};

}
