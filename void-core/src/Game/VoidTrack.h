//
// Created by Dmitry Mozgin on 28/04/2017.
//

#pragma once

#include <memory>
#include <Common/Vector3.h>

namespace vd {

class VoidTrack {

public:

    Vector3 GetPosition() const;

};

typedef std::shared_ptr<VoidTrack> VoidTrackRef;

}

