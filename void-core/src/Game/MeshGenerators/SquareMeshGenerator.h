//
// Created by Dmitry Mozgin on 25/04/2017.
//

#pragma once

#include "MeshGenerator.h"

namespace vd {

class SquareMeshGenerator : public MeshGenerator {

protected:

    static constexpr float BorderSize = Size * 0.07f; // redefine

    virtual IMeshRef GenHollowMesh() override;

    virtual IMeshRef GenDefaultMesh() override;

};

}