//
// Created by Dmitry Mozgin on 04/05/2017.
//

#pragma once

#include <Common/GameContext.h>
#include "../../VoidAppObject.h"

namespace vd {

class GameContextImpl
        : public VoidAppObject,
          public IGameContext {
public:

    GameContextImpl(VoidApp &app);

    virtual RuntimePlatform GetRuntimePlatform() override;

    virtual float GetScreenDpi() override;

    virtual void Quit() override;

};

}



