//
// Created by Dmitry Mozgin on 03/05/2017.
//

#pragma once

#include <memory>

namespace vd {

class Animation {
public:

    virtual ~Animation();

};

typedef std::shared_ptr<Animation> AnimationRef;

}

