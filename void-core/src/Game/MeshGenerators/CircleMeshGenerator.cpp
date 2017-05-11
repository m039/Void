//
// Created by Dmitry Mozgin on 25/04/2017.
//

#include "CircleMeshGenerator.h"

#include "../Config.h"

using namespace vd;

static const unsigned int NumberOfSides = Config::NumberOfSidesInCircle;

IMeshRef CircleMeshGenerator::GenHollowMesh() {
    // vertices

    std::vector<Vector3> vertices(NumberOfSides * 2);

    static const float s1 = Size;
    static const float s2 = Size - BorderSize;

    auto angle = 0.0f;
    static const float dAngle = 2 * MathF::Pi / NumberOfSides;

    for (unsigned i = 0; i < NumberOfSides; i++) {
        vertices[i] = Vector3(
                s2 * MathF::Sin(angle),
                s2 * MathF::Cos(angle),
                0
        );

        vertices[i + NumberOfSides] = Vector3(
                s1 * MathF::Sin(angle),
                s1 * MathF::Cos(angle),
                0
        );

        angle += dAngle;
    }

    // triangles

    std::vector<int> triangles(NumberOfSides * 2 * 3);

    auto k = 0;

    for (unsigned i = 0; i < NumberOfSides - 1; i++, k += 6) {
        triangles[k] = i;
        triangles[k + 1] = i + NumberOfSides;
        triangles[k + 2] = i + NumberOfSides + 1;
        triangles[k + 3] = i;
        triangles[k + 4] = i + NumberOfSides + 1;
        triangles[k + 5] = i + 1;
    }

    triangles[k] = NumberOfSides - 1;
    triangles[k + 1] = NumberOfSides * 2 - 1;
    triangles[k + 2] = NumberOfSides;
    triangles[k + 3] = NumberOfSides - 1;
    triangles[k + 4] = NumberOfSides;
    triangles[k + 5] = 0;

    return Mesh::Create(vertices, triangles, CreateNormals(static_cast<unsigned int>(vertices.size())));
}

IMeshRef CircleMeshGenerator::GenDefaultMesh() {
    // vertices

    static const unsigned int length = NumberOfSides + 1;

    std::vector<Vector3> vertices(length);

    vertices[0] = Vector3(0, 0, 0);

    auto angle = 0.0f;
    const float dAngle = 2 * MathF::Pi / NumberOfSides;

    for (unsigned i = 1; i < length; i++) {
        vertices[i] = Vector3(
                Size * MathF::Sin(angle),
                Size * MathF::Cos(angle),
                0
        );

        angle += dAngle;
    }

    // triangles

    std::vector<int> triangles(NumberOfSides * 3);

    auto k = 0;

    for (unsigned i = 0; i < NumberOfSides - 1; i++, k += 3) {
        triangles[k] = 0;
        triangles[k + 1] = i + 1;
        triangles[k + 2] = i + 2;
    }

    triangles[k] = 0;
    triangles[k + 1] = NumberOfSides;
    triangles[k + 2] = 1;

    return Mesh::Create(vertices, triangles, CreateNormals(length));
}
