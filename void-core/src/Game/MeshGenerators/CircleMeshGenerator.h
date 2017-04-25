//
// Created by Dmitry Mozgin on 25/04/2017.
//

#pragma once

#include "MeshGenerator.h"

namespace vd {

class CircleMeshGenerator : public MeshGenerator {

protected:

    virtual IMeshRef GenHollowMesh() override;

    virtual IMeshRef GenDefaultMesh() override;

};

}

