//
// Created by Dmitry Mozgin on 21/04/2017.
//

#pragma once

namespace vd {

class IGameComponent {

public:

    IGameComponent() {}

    virtual ~IGameComponent() {
    }

    virtual void Start() {}

    virtual void Update() = 0;

};

}






