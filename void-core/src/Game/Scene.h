//
// Created by Dmitry Mozgin on 28/04/2017.
//

#pragma once

#include <memory>

namespace vd {

class IScene {
public:

    virtual ~IScene() {}
};

typedef std::shared_ptr<IScene> ISceneRef;

class Scene {

};

}

