//
// Created by Dmitry Mozgin on 28/04/2017.
//

#pragma once

#include <memory>
#include <Common/Components/GameComponent.h>
#include <Game/SimplifiedUi.h>

namespace vd {

class IVoidScreen {
public:

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

    virtual ~VoidScreen();

};

}

