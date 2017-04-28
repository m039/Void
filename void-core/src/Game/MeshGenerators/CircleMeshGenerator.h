//
// Created by Dmitry Mozgin on 25/04/2017.
//

#pragma once

#include "MeshGenerator.h"

namespace vd {

class CircleMeshGenerator : public MeshGenerator {

protected:

    static constexpr float Size = 0.6f;

    static constexpr float BorderSize = Size * 0.05f;

    virtual IMeshRef GenHollowMesh() override;

    virtual IMeshRef GenDefaultMesh() override;

};

}

