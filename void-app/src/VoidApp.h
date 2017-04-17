//
// Created by Dmitry Mozgin on 17/04/2017.
//

#pragma once

#include "cinder/app/App.h"

class VoidApp : public ci::app::App {

public:
    void setup() override;

    void update() override;

    void draw() override;

private:

    void displayChange();
};




