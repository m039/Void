//
// Created by Dmitry Mozgin on 17/04/2017.
//

#pragma once

#include <Game/MusicSystem.h>
#include <Game/VoidGameHut.h>
#include "AdaptiveTextureFont.h"
#include "UnlitShader.h"

#include "cinder/app/App.h"
#include "cinder/audio/audio.h"
#include "Impl/Game/ObjectPoolImpl.h"
#include "Impl/Game/CameraImpl.h"
#include "Impl/Common/InputImpl.h"
#include "Impl/Game/SimplifiedUiImpl.h"

namespace vd {

class VoidApp : public ci::app::App {

public:

    void setup() override;

    void update() override;

    void draw() override;

    void keyDown(ci::app::KeyEvent event) override;

    void keyUp(ci::app::KeyEvent event) override;

#if defined(CINDER_COCOA_TOUCH)

    void touchesBegan(ci::app::TouchEvent event) override;

    void touchesMoved(ci::app::TouchEvent event) override;

    void touchesEnded(ci::app::TouchEvent event) override;

#endif

    UnlitShaderRef GetShader() const {
        return _shader;
    }

    AdaptiveTextureFontRef LoadFont(const std::string& name, float size);

private:

    void OnResize();

    std::unique_ptr<GameHut> _game;

    std::shared_ptr<ObjectPoolImpl> _objectPool;

    std::shared_ptr<CameraImpl> _camera;

    std::shared_ptr<InputImpl> _input;

    std::shared_ptr<SimplifiedUiImpl> _ui;

    UnlitShaderRef _shader;

    IAudioPlayerRef SetupAudio();

    void SetupShader();

};

}





