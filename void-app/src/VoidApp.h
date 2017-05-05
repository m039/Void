//
// Created by Dmitry Mozgin on 17/04/2017.
//

#pragma once

#include <Game/MusicSystem.h>
#include <Game/VoidGameHut.h>
#include "AdaptiveTextureFont.h"
#include "DebugInfoText.h"
#include "UnlitShader.h"

#include "cinder/app/App.h"
#include "cinder/audio/audio.h"
#include "Impl/Game/ObjectPoolGl.h"
#include "Impl/Game/Camera.h"
#include "Impl/Common/Input.h"
#include "Impl/Game/SimplifiedUiImpl.h"

namespace vd {

class VoidApp : public ci::app::App {

public:

    void setup() override;

    void update() override;

    void draw() override;

    void keyDown(ci::app::KeyEvent event) override;

    void keyUp(ci::app::KeyEvent event) override;

    UnlitShaderRef GetShader() const {
        return _shader;
    }

    AdaptiveTextureFontRef LoadFont(const std::string& name, float size);

private:

    void OnResize();

    std::unique_ptr<GameHut> _game;

    std::shared_ptr<ObjectPoolGl> _objectPool;

    std::shared_ptr<Camera> _camera;

    std::shared_ptr<Input> _input;

    std::shared_ptr<SimplifiedUiImpl> _ui;

    //region Audio

    IAudioPlayerRef SetupAudio();

    //endregion

    //region Shader

    UnlitShaderRef _shader;

    void SetupShader();

    //endregion

};

}





