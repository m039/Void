//
// Created by Dmitry Mozgin on 25/04/2017.
//

#include "SquareMeshGenerator.h"

using namespace vd;

IMeshRef SquareMeshGenerator::GenHollowMesh() {
    static const float s1 = Size;
    static const float s2 = Size - BorderSize;

    std::vector<Vector3> vertices {
            Vector3(-s2, -s2, 0),
            Vector3(-s2, s2, 0),
            Vector3(s2, s2, 0),
            Vector3(s2, -s2, 0),
            Vector3(-s1, -s2, 0),
            Vector3(-s1, s1, 0),
            Vector3(-s2, s1, 0),
            Vector3(s1, s1, 0),
            Vector3(s1, s2, 0),
            Vector3(s1, -s1, 0),
            Vector3(s2, -s1, 0),
            Vector3(-s1, -s1, 0)
    };

    std::vector<int> triangles {
            0, 4, 5,
            0, 5, 6,
            1, 6, 7,
            1, 7, 8,
            2, 8, 9,
            2, 9, 10,
            3, 10, 11,
            3, 11, 4
    };

    std::vector<Vector3> normals = CreateNormals(12);

    return Mesh::Create(vertices, triangles, normals);
}

IMeshRef SquareMeshGenerator::GenDefaultMesh() {
    std::vector<Vector3> vertices {
            Vector3(-Size, -Size, 0),
            Vector3(Size, -Size, 0),
            Vector3(-Size, Size, 0),
            Vector3(Size, Size, 0)
    };

    std::vector<int> triangles {
            0, 2, 1,
            2, 3, 1
    };

    std::vector<Vector2> uv {
            Vector2(0, 0),
            Vector2(1, 0),
            Vector2(0, 1),
            Vector2(1, 1)
    };

    std::vector<Vector3> normals = CreateNormals(4);

    return Mesh::Create(vertices, triangles, normals, uv);
}
