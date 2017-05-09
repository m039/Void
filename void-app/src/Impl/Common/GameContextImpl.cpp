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
#if defined(CINDER_COCOA_TOUCH)
    return RuntimePlatform::iPhone;
#else
    return RuntimePlatform::OSX;
#endif
}

float GameContextImpl::GetScreenDpi() {
    return 72 * 2; // Hardcoded.
}

void GameContextImpl::Quit() {
    app.quit();
}
