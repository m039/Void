//
// Created by Dmitry Mozgin on 25/04/2017.
//

#pragma once

#include "MeshGenerator.h"

namespace vd {

class TriangleMeshGenerator : public MeshGenerator {

protected:

    virtual IMeshRef GenHollowMesh() override;

    virtual IMeshRef GenDefaultMesh() override;

private:

    static constexpr float BorderSize = Size * 0.07f;

    static const float A1;

    static const float B1;

    static const float C1;

    static const float A2;

    static const float B2;

    static const float C2;
};

}