//
// Created by Dmitry Mozgin on 03/05/2017.
//

#include "Level35.h"

using namespace vd;

SimplestLevel::SimplestData Level35::CreateSimplestData() {
    auto data = SimplestLevel::SimplestData();

    data.numberOfObjects = 15;
    data.backgroundColor = Colors::White;
    data.shapeType = ShapeType::Circle;
    data.tracks = {
            {0, 0},
            {1, 0}
    };
    data.isRotating = false;
    data.isGate = [this](const VoidTrackRef& t, int i) {
        return i == NumberOfObjects(t) - 1 && t->GetX() == 1;
    };
    data.isPortal = [this](const VoidTrackRef& t, int i) {
        return (i == 3 && t->GetX() == 0) ||
                (i == 7 && t->GetX() == 1) ||
                (i == 11 && t->GetX() == 0);
    };

    return data;
}