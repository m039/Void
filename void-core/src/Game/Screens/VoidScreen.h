//
// Created by Dmitry Mozgin on 28/04/2017.
//

#pragma once

#include <memory>
#include <Common/Components/GameComponent.h>
#include <Game/SimplifiedUi.h>
#include <Game/Localization/TextId.h>
#include <Game/Config.h>

namespace vd {

enum class TextPlaceId
{
    Title = 0,
    Body = 1,
    Footer = 2,
    Message = 3,
    Info = 4,
    Void = 5
};

class IVoidScreen {
public:

    virtual bool IsVisible() = 0;

    virtual void Show() = 0;
    
    virtual void Hide() = 0;
    
    virtual void ShowWithAnimation(Callback endAnimationCallback) = 0;
    
    virtual void HideWithAnimation(Callback endAnimationCallback) = 0;
    
    virtual void SetText(TextPlaceId textId, TextId id) = 0;
    
    virtual void SetTextColor(TextPlaceId textId, Color color) = 0;

    virtual ~IVoidScreen();

};

typedef std::shared_ptr<IVoidScreen> IVoidScreenRef;

class IHelpScreen : public virtual IVoidScreen {
public:

    virtual void ShowAndHide() = 0;

    ~IHelpScreen() {}
};

typedef std::shared_ptr<IHelpScreen> IHelpScreenRef;

class VoidScreen
        : public GameComponent,
          public virtual IVoidScreen,
          public IScreenDrawable
{
public:

    VoidScreen();

    //region Implementation of IVoidScreen.

    virtual bool IsVisible() override;

    virtual void Show() override;

    virtual void Hide() override;

    virtual void ShowWithAnimation(Callback endAnimationCallback) override;

    virtual void HideWithAnimation(Callback endAnimationCallback) override;

    virtual void SetText(TextPlaceId placeId, TextId textId) override;

    virtual void SetTextColor(TextPlaceId placeId, Color color) override;

    //endregion

protected:

    inline float GetAlpha();

private:

    static constexpr float ShowTime = Config::FadeTime / 2;

    void SetAlpha(float alpha);

    void PerformShow(bool showOrHide);

    void StartAnimation(bool showOrHide, Callback endAnimationCallback);

    Coroutine::EnumerationFunction AnimationCoroutine(bool showOrHide, Callback endAnimationCallback);

    float _alpha;

    bool _visible;

    CoroutineRef _coroutine;

};

}

