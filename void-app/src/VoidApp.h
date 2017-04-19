//
// Created by Dmitry Mozgin on 17/04/2017.
//

#pragma once

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

    private:

        void onResize();

        std::unique_ptr<DebugInfoText> _infoText;

        ci::gl::BatchRef _batch;

        void setupBatch(const ci::gl::GlslProgRef &shader);

        //region Fonts

        ci::gl::TextureFontRef _headlineFont;

        ci::gl::TextureFontRef _textFont;

        ci::gl::TextureFontRef loadFont(const std::string &name, float size);

        //endregion

        //region Shader

        std::unique_ptr<UnlitShader> _shader;

        void setupShader();

        //endregion

        //region Camera

        ci::CameraPersp _camera;

        void setupCamera();

        //endregion
    };

}





