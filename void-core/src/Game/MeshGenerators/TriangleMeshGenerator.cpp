//
// Created by Dmitry Mozgin on 25/04/2017.
//

#include "TriangleMeshGenerator.h"

using namespace vd;

const float TriangleMeshGenerator::A1 = 2 * Size / (1 + MathF::Sin(MathF::Pi / 6.0f));

const float TriangleMeshGenerator::B1 = A1 * MathF::Sin(MathF::Pi / 6);

const float TriangleMeshGenerator::C1 = A1 * MathF::Cos(MathF::Pi / 6);

const float TriangleMeshGenerator::A2 = 2 * (Size - BorderSize) / (1 + MathF::Sin(MathF::Pi / 6));

const float TriangleMeshGenerator::B2 = A2 * MathF::Sin(MathF::Pi / 6);

const float TriangleMeshGenerator::C2 = A2 * MathF::Cos(MathF::Pi / 6);

IMeshRef TriangleMeshGenerator::GenHollowMesh() {
    return nullptr;
}

IMeshRef TriangleMeshGenerator::GenDefaultMesh() {
    std::vector<Vector3> vertices {
             Vector3(-C1, -B1, 0),
             Vector3(C1, -B1, 0),
             Vector3(0, A1, 0)
    };

    std::vector<int> triangles {
            0, 2, 1
    };

    std::vector<Vector3> normals = CreateNormals(3);

    return Mesh::Create(vertices, triangles, normals);
}
