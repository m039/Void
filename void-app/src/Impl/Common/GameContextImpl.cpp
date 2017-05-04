//
// Created by Dmitry Mozgin on 04/05/2017.
//

#include "GameContextImpl.h"

#include "../../VoidApp.h"

using namespace vd;

GameContextImpl::GameContextImpl(VoidApp &app)
        : VoidAppObject(app)
{
}

RuntimePlatform GameContextImpl::GetRuntimePlatform() {
    // Todo: implement.
    return RuntimePlatform::OSX;
}

float GameContextImpl::GetScreenDpi() {
    // Todo: implement.
    return 120;
}

void GameContextImpl::Quit() {
    app.quit();
}
