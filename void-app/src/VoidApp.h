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

namespace vd {

class VoidApp : public ci::app::App {

public:

    void setup() override;

    void update() override;

    void draw() override;

    void keyDown(ci::app::KeyEvent event) override;

    void keyUp(ci::app::KeyEvent event) override;

    UnlitShaderRef getShader() const {
        return _shader;
    }

private:

    void onResize();

    std::unique_ptr<DebugInfoText> _infoText;

    std::unique_ptr<GameHut> _game;

    std::shared_ptr<ObjectPoolGl> _objectPool;

    std::shared_ptr<Camera> _camera;

    std::shared_ptr<Input> _input;

    //region Audio

    IAudioPlayerRef setupAudio();

    //endregion

    //region Fonts

    AdaptiveTextureFontRef _headlineFont;

    AdaptiveTextureFontRef _textFont;

    AdaptiveTextureFontRef loadFont(const std::string &name, float size);

    //endregion

    //region Shader

    UnlitShaderRef _shader;

    void setupShader();

    //endregion

};

}





