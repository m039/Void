//
// Created by Dmitry Mozgin on 17/04/2017.
//

#pragma once

#include "AdaptiveTextureFont.h"
#include "DebugInfoText.h"
#include "UnlitShader.h"

#include "cinder/app/App.h"
#include "cinder/audio/audio.h"

namespace vd {

class VoidApp : public ci::app::App {

public:

    void setup() override;

    void update() override;

    void draw() override;

    void keyDown(ci::app::KeyEvent event) override;

    std::shared_ptr<UnlitShader> getShader() const {
        return _shader;
    }

private:

    void onResize();

    std::unique_ptr<DebugInfoText> _infoText;

    void drawCube();

    //region Audio

    ci::audio::SamplePlayerNodeRef _audioPlayer;

    void setupAudio();

    //endregion

    //region Fonts

    AdaptiveTextureFontRef _headlineFont;

    AdaptiveTextureFontRef _textFont;

    AdaptiveTextureFontRef loadFont(const std::string &name, float size);

    //endregion

    //region Shader

    std::shared_ptr<UnlitShader> _shader;

    void setupShader();

    //endregion

    //region Camera

    ci::CameraPersp _camera;

    void setupCamera();

    //endregion
};

}





