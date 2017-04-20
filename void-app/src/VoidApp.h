//
// Created by Dmitry Mozgin on 17/04/2017.
//

#pragma once

#include "AdaptiveTextureFont.h"
#include "DebugInfoText.h"
#include "UnlitShader.h"

#include "cinder/app/App.h"

namespace vd {

class VoidApp : public ci::app::App {

public:

    void setup() override;

    void update() override;

    void draw() override;

    void keyDown(ci::app::KeyEvent event) override;

    UnlitShader& getShader() const {
        return *_shader;
    }

private:

    void onResize();

    std::unique_ptr<DebugInfoText> _infoText;

    //region Fonts

    AdaptiveTextureFontRef _headlineFont;

    AdaptiveTextureFontRef _textFont;

    AdaptiveTextureFontRef loadFont(const std::string &name, float size);

    //endregion

    //region Shader

    std::unique_ptr<UnlitShader> _shader;

    void setupShader();

    //endregion

    //region Camera

    ci::CameraPersp _camera;

    void setupCamera();

    //endregion

    void drawCube();
};

}





