//
// Created by Dmitry Mozgin on 06/05/2017.
//

#include "Levels.h"

using namespace vd;

//region Level2

SimplestLevel::SimplestData Level2::CreateSimplestData() {
    auto data = SimplestLevel::SimplestData();

    data.numberOfObjects = 5;
    data.backgroundColor = Colors::White;
    data.shapeType = ShapeType::Triangle;
    data.tracks = {
            {0, 0},
    };
    data.isRotating = false;
    data.isGate = [this](const VoidTrackRef& t, int i) {
        return i == NumberOfObjects(t) - 1;
    };
    data.isPortal = [this](const VoidTrackRef& t, int i) {
        return false;
    };

    return data;
}

//endregion

//region Level3

SimplestLevel::SimplestData Level3::CreateSimplestData() {
    auto data = SimplestLevel::SimplestData();

    data.numberOfObjects = 10;
    data.backgroundColor = Colors::Black;
    data.shapeType = ShapeType::Square;
    data.tracks = {
            {0, 0},
    };
    data.isRotating = false;
    data.isGate = [this](const VoidTrackRef& t, int i) {
        return i == NumberOfObjects(t) - 1;
    };
    data.isPortal = [this](const VoidTrackRef& t, int i) {
        return false;
    };

    return data;
}

//endregion

//region Level4

SimplestLevel::SimplestData Level4::CreateSimplestData() {
    auto data = SimplestLevel::SimplestData();

    data.numberOfObjects = 5;
    data.backgroundColor = Colors::White;
    data.shapeType = ShapeType::Triangle;
    data.tracks = {
            {0, 0},
            {0, 1}
    };
    data.isRotating = false;
    data.isGate = [this](const VoidTrackRef& t, int i) {
        return i == NumberOfObjects(t) - 1 && t->GetY() == 1;
    };
    data.isPortal = [this](const VoidTrackRef& t, int i) {
        return false;
    };

    return data;
}

//endregion

//region Level5

SimplestLevel::SimplestData Level5::CreateSimplestData() {
    auto data = SimplestLevel::SimplestData();

    data.numberOfObjects = 10;
    data.backgroundColor = Colors::Black;
    data.shapeType = ShapeType::Square;
    data.tracks = {
            {0, 0},
            {1, 0}
    };
    data.isRotating = false;
    data.isGate = [this](const VoidTrackRef& t, int i) {
        return i == NumberOfObjects(t) - 1 && t->GetX() == 1;
    };
    data.isPortal = [this](const VoidTrackRef& t, int i) {
        return false;
    };

    return data;
}

//endregion

//region Level6

SimplestLevel::SimplestData Level6::CreateSimplestData() {
    auto data = SimplestLevel::SimplestData();

    data.numberOfObjects = 5;
    data.backgroundColor = Colors::White;
    data.shapeType = ShapeType::Triangle;
    data.tracks = {
            {0, 0},
            {0, 1},
            {0, -1}
    };
    data.isRotating = false;
    data.isGate = [this](const VoidTrackRef& t, int i) {
        return i == NumberOfObjects(t) - 1 && t->GetY() == 1 && t->GetX() == 0;
    };
    data.isPortal = [this](const VoidTrackRef& t, int i) {
        return false;
    };

    return data;
}

//endregion

//region Level7

SimplestLevel::SimplestData Level7::CreateSimplestData() {
    auto data = SimplestLevel::SimplestData();

    data.numberOfObjects = 10;
    data.backgroundColor = Colors::Black;
    data.shapeType = ShapeType::Square;
    data.tracks = {
            {0, 0},
            {1, 0},
            {-1, 0}
    };
    data.isRotating = true;
    data.isGate = [this](const VoidTrackRef& t, int i) {
        return i == NumberOfObjects(t) - 1 && t->GetY() == 0 && t->GetX() == 1;
    };
    data.isPortal = [this](const VoidTrackRef& t, int i) {
        return false;
    };

    return data;
}

//endregion

//region Level8

SimplestLevel::SimplestData Level8::CreateSimplestData() {
    auto data = SimplestLevel::SimplestData();

    data.numberOfObjects = 4;
    data.backgroundColor = Colors::White;
    data.shapeType = ShapeType::Triangle;
    data.tracks = {
            {0, 0},
            {-1, 0},
            {1, 0}
    };
    data.isRotating = false;
    data.isGate = [this](const VoidTrackRef& t, int i) {
        return i == NumberOfObjects(t) - 1 && t->GetY() == 0 && t->GetX() == 0;
    };
    data.isPortal = [this](const VoidTrackRef& t, int i) {
        return false;
    };

    return data;
}

//endregion

//region Level9

SimplestLevel::SimplestData Level9::CreateSimplestData() {
    auto data = SimplestLevel::SimplestData();

    data.numberOfObjects = 15;
    data.backgroundColor = Colors::Black;
    data.shapeType = ShapeType::Square;
    data.tracks = {
            {0, 0},
            {1, 0},
            {-1, 0}
    };
    data.isRotating = false;
    data.isGate = [this](const VoidTrackRef& t, int i) {
        return i == NumberOfObjects(t) - 1 && t->GetY() == 0 && t->GetX() == 1;
    };
    data.isPortal = [this](const VoidTrackRef& t, int i) {
        return false;
    };

    return data;
}

//endregion

//region Level10

SimplestLevel::SimplestData Level10::CreateSimplestData() {
    auto data = SimplestLevel::SimplestData();

    data.numberOfObjects = 5;
    data.backgroundColor = Colors::White;
    data.shapeType = ShapeType::Triangle;
    data.tracks = {
            {0, 0},
            {-1, 0},
            {1, 0}
    };
    data.isRotating = false;
    data.isGate = [this](const VoidTrackRef& t, int i) {
        return i == NumberOfObjects(t) - 1 && t->GetY() == 0 && t->GetX() == -1;
    };
    data.isPortal = [this](const VoidTrackRef& t, int i) {
        return i == 0 && t->GetX() == 1 && t->GetY() == 0;
    };

    return data;
}

//endregion

//region Level11

SimplestLevel::SimplestData Level11::CreateSimplestData() {
    auto data = SimplestLevel::SimplestData();

    data.numberOfObjects = 10;
    data.backgroundColor = Colors::Black;
    data.shapeType = ShapeType::Square;
    data.tracks = {
            {0, 0},
            {-1, 0},
            {1, 0}
    };
    data.isRotating = false;
    data.isGate = [this](const VoidTrackRef& t, int i) {
        return i == NumberOfObjects(t) - 1 && t->GetY() == 0 && t->GetX() == 0;
    };
    data.isPortal = [this](const VoidTrackRef& t, int i) {
        return i == 3 && t->GetX() == 0 && t->GetY() == 0;
    };

    return data;
}

//endregion

//region Level12

SimplestLevel::SimplestData Level12::CreateSimplestData() {
    auto data = SimplestLevel::SimplestData();

    data.numberOfObjects = 10;
    data.backgroundColor = Colors::White;
    data.shapeType = ShapeType::Triangle;
    data.tracks = {
            {0, 0},
            {0, 1},
            {0, -1}
    };
    data.isRotating = false;
    data.isGate = [this](const VoidTrackRef& t, int i) {
        return i == (NumberOfObjects(t) - 1) && t->GetX() == 0 && t->GetY()  == 0;
    };
    data.isPortal = [this](const VoidTrackRef& t, int i) {
        return (i == 0 && t->GetX() == 0 && (t->GetY() == 1 || t->GetY()  == -1)) ||
                (i == 5 && t->GetX() == 0 && t->GetY()  == 0);
    };

    return data;
}

//endregion

//region Level13

SimplestLevel::SimplestData Level13::CreateSimplestData() {
    auto data = SimplestLevel::SimplestData();

    data.numberOfObjects = 15;
    data.backgroundColor = Colors::Black;
    data.shapeType = ShapeType::Square;
    data.tracks = {
            {0, 0},
            {0, 1},
            {0, -1}
    };
    data.isRotating = false;
    data.isGate = [this](const VoidTrackRef& t, int i) {
        return i == (NumberOfObjects(t) - 1) && t->GetX() == 0 && t->GetY() == 0;
    };
    data.isPortal = [this](const VoidTrackRef& t, int i) {
        return (i == 0 && t->GetX() == 0 && (t->GetY() == 0 || t->GetY() == 1)) ||
                (i == 7 && t->GetX() == 0 && t->GetY() == 0);
    };

    return data;
}

//endregion

//region Level14

SimplestLevel::SimplestData Level14::CreateSimplestData() {
    auto data = SimplestLevel::SimplestData();

    data.numberOfObjects = 15;
    data.backgroundColor = Colors::White;
    data.shapeType = ShapeType::Circle;
    data.tracks = {
            {0, 0},
            {-1, 0},
            {1, 0},
            {0, -1},
            {0, 1}
    };
    data.isRotating = false;
    data.isGate = [this](const VoidTrackRef& t, int i) {
        return i == (NumberOfObjects(t) - 1) && t->GetX() == 0 && t->GetY() == 0;
    };
    data.isPortal = [this](const VoidTrackRef& t, int i) {
        return false;
    };

    return data;
}

//endregion

//region Level15

SimplestLevel::SimplestData Level15::CreateSimplestData() {
    auto data = SimplestLevel::SimplestData();

    data.numberOfObjects = 15;
    data.backgroundColor = Colors::Black;
    data.shapeType = ShapeType::Square;
    data.tracks = {
            {0, 0}
    };
    data.isRotating = false;
    data.isGate = [this](const VoidTrackRef& t, int i) {
        return i == (NumberOfObjects(t) - 1) && t->GetX() == 0 && t->GetY() == 0;
    };
    data.isPortal = [this](const VoidTrackRef& t, int i) {
        return false;
    };

    return data;
}

//endregion

//region Level16

SimplestLevel::SimplestData Level16::CreateSimplestData() {
    auto data = SimplestLevel::SimplestData();

    data.numberOfObjects = 5;
    data.backgroundColor = Colors::White;
    data.shapeType = ShapeType::Triangle;
    data.tracks = {
            {0, 0},
            {-1, 0},
            {1, 0},
            {0, -1},
            {0, 1}
    };
    data.isRotating = false;
    data.isGate = [this](const VoidTrackRef& t, int i) {
        return i == (NumberOfObjects(t) - 1) && t->GetX() == 0 && t->GetY() == 0;
    };
    data.isPortal = [this](const VoidTrackRef& t, int i) {
        return (i == 0 || i == 2) && t->GetX() == 0;
    };

    return data;
}

//endregion

//region Level17

SimplestLevel::SimplestData Level17::CreateSimplestData() {
    auto data = SimplestLevel::SimplestData();

    data.numberOfObjects = 15;
    data.backgroundColor = Colors::Black;
    data.shapeType = ShapeType::Square;
    data.tracks = {
            {0, 0},
            {-1, 0},
            {1, 0},
            {0, -1},
            {0, 1}
    };
    data.isRotating = false;
    data.isGate = [this](const VoidTrackRef& t, int i) {
        return i == (NumberOfObjects(t) - 1) && t->GetX() == 1 && t->GetY() == 0;
    };
    data.isPortal = [this](const VoidTrackRef& t, int i) {
        return (i == 0 && t->GetY() == 0) ||
                (i == 5 && (t->GetY() == -1 || t->GetY() == 1));
    };

    return data;
}

//endregion

//region Level18

SimplestLevel::SimplestData Level18::CreateSimplestData() {
    auto data = SimplestLevel::SimplestData();

    data.numberOfObjects = 10;
    data.backgroundColor = Colors::White;
    data.shapeType = ShapeType::Triangle;
    data.tracks = {
            {0, 0},
            {1, 0}
    };
    data.isRotating = false;
    data.isGate = [this](const VoidTrackRef& t, int i) {
        return i == (NumberOfObjects(t) - 1) && t->GetX() == 1 && t->GetY() == 0;
    };
    data.isPortal = [this](const VoidTrackRef& t, int i) {
        return (i == 0 && t->GetX()  == 0) ||
                (i == 5 && t->GetX()  == 1);
    };

    return data;
}

//endregion

//region Level19

SimplestLevel::SimplestData Level19::CreateSimplestData() {
    auto data = SimplestLevel::SimplestData();

    data.numberOfObjects = 5;
    data.backgroundColor = Colors::Black;
    data.shapeType = ShapeType::Square;
    data.tracks = {
            {0, 0},
            {0, 1}
    };
    data.isRotating = true;
    data.isGate = [this](const VoidTrackRef& t, int i) {
        return i == (NumberOfObjects(t) - 1) && t->GetX()  == 0 && t->GetY() == 0;
    };
    data.isPortal = [this](const VoidTrackRef& t, int i) {
        return (i == 0 && t->GetY() == 0) ||
                (i == 3 && t->GetY() == 1);
    };

    return data;
}

//endregion

//region Level20

SimplestLevel::SimplestData Level20::CreateSimplestData() {
    auto data = SimplestLevel::SimplestData();

    data.numberOfObjects = 15;
    data.backgroundColor = Colors::White;
    data.shapeType = ShapeType::Circle;
    data.tracks = {
            {0, 0},
            {0, 1},
            {0, -1}
    };
    data.isRotating = false;
    data.isGate = [this](const VoidTrackRef& t, int i) {
        return i == (NumberOfObjects(t) - 1) && t->GetX() == 0 && t->GetY() == 0;
    };
    data.isPortal = [this](const VoidTrackRef& t, int i) {
        return (i == 4 && t->GetY() == 0) ||
                (i == 8 && t->GetY() == 1) ||
                (i == 12 && t->GetY() == -1);
    };

    return data;
}

//endregion

//region Level21

SimplestLevel::SimplestData Level21::CreateSimplestData() {
    auto data = SimplestLevel::SimplestData();

    data.numberOfObjects = 15;
    data.backgroundColor = Colors::Black;
    data.shapeType = ShapeType::Square;
    data.tracks = {
            {0, 0},
            {-1, 0},
            {1, 0}
    };
    data.isRotating = false;
    data.isGate = [this](const VoidTrackRef& t, int i) {
        return i == (NumberOfObjects(t) - 1) && t->GetX() == 0 && t->GetY() == 0;
    };
    data.isPortal = [this](const VoidTrackRef& t, int i) {
        return (i == 0 && t->GetX() == -1) ||
                (i == 6 && t->GetX() == -1) ||
                (i == 2 && t->GetX() == 0) ||
                (i == 8 && t->GetX() == 0) ||
                (i == 4 && t->GetX() == 1) ||
                (i == 10 && t->GetX()) == 1;
    };

    return data;
}

//endregion

//region Level22

SimplestLevel::SimplestData Level22::CreateSimplestData() {
    auto data = SimplestLevel::SimplestData();

    data.numberOfObjects = 10;
    data.backgroundColor = Colors::White;
    data.shapeType = ShapeType::Triangle;
    data.tracks = {
            {0, 0},
            {1, 0}
    };
    data.isRotating = false;
    data.isGate = [this](const VoidTrackRef& t, int i) {
        return i == NumberOfObjects(t) - 1 && t->GetX() == 1;
    };
    data.isPortal = [this](const VoidTrackRef& t, int i) {
        return (i == 0 && t->GetX() == 1) ||
                (i == 4 && t->GetX() == 0) ||
                (i == 6 && t->GetX() == 1);
    };

    return data;
}

//endregion

//region Level23

SimplestLevel::SimplestData Level23::CreateSimplestData() {
    auto data = SimplestLevel::SimplestData();

    data.numberOfObjects = 10;
    data.backgroundColor = Colors::Black;
    data.shapeType = ShapeType::Square;
    data.tracks = {
            {0, 0},
            {0, 1}
    };
    data.isRotating = true;
    data.isGate = [this](const VoidTrackRef& t, int i) {
        return i == NumberOfObjects(t) - 1 && t->GetY() == 0;
    };
    data.isPortal = [this](const VoidTrackRef& t, int i) {
        return (i == 0 && t->GetY() == 0) ||
                (i == 5 && t->GetY() == 0) ||
                (i == 8 && t->GetY() == 1);
    };

    return data;
}

//endregion

//region Level24

SimplestLevel::SimplestData Level24::CreateSimplestData() {
    auto data = SimplestLevel::SimplestData();

    data.numberOfObjects = 15;
    data.backgroundColor = Colors::White;
    data.shapeType = ShapeType::Circle;
    data.tracks = {
            {0, 0},
            {0, 1},
            {0, -1}
    };
    data.isRotating = false;
    data.isGate = [this](const VoidTrackRef& t, int i) {
        return i == NumberOfObjects(t) - 1 && t->GetY() == 0;
    };
    data.isPortal = [this](const VoidTrackRef& t, int i) {
        return (i == 0 && t->GetY() == -1) ||
                (i == 6 && t->GetY() == -1) ||
                (i == 2 && t->GetY() == 0) ||
                (i == 8 && t->GetY() == 0) ||
                (i == 6 && t->GetY() == 1) ||
                (i == 12 && t->GetY() == 1);
    };

    return data;
}

//endregion

//region Level25

SimplestLevel::SimplestData Level25::CreateSimplestData() {
    auto data = SimplestLevel::SimplestData();

    data.numberOfObjects = 15;
    data.backgroundColor = Colors::Black;
    data.shapeType = ShapeType::Square;
    data.tracks = {
            {0, 0},
            {-1, 0},
            {1, 0},
            {0, -1},
            {0, 1}
    };
    data.isRotating = false;
    data.isGate = [this](const VoidTrackRef& t, int i) {
        return i == NumberOfObjects(t) - 1 && t->GetX() == 0 && t->GetY() == 0;
    };
    data.isPortal = [this](const VoidTrackRef& t, int i) {
        return (i == 0 && t->GetY() == 0) ||
                (i == 5 && (t->GetY() == -1 || t->GetY() == 1)) ||
                (i == 10 && t->GetY() == 0);
    };

    return data;
}

//endregion

//region Level26

SimplestLevel::SimplestData Level26::CreateSimplestData() {
    auto data = SimplestLevel::SimplestData();

    data.numberOfObjects = 1;
    data.backgroundColor = Colors::White;
    data.shapeType = ShapeType::Triangle;
    data.tracks = {
            {0, 0},
    };
    data.isRotating = false;
    data.isGate = [this](const VoidTrackRef& t, int i) {
        return true;
    };
    data.isPortal = [this](const VoidTrackRef& t, int i) {
        return false;
    };

    return data;
}

//endregion

//region Level27

SimplestLevel::SimplestData Level27::CreateSimplestData() {
    auto data = SimplestLevel::SimplestData();

    data.numberOfObjects = 15;
    data.backgroundColor = Colors::Black;
    data.shapeType = ShapeType::Square;
    data.tracks = {
            {0, 0},
            {0, 1},
            {0, -1}
    };
    data.isRotating = true;
    data.isGate = [this](const VoidTrackRef& t, int i) {
        return i == NumberOfObjects(t) - 1 && t->GetX() == 0 && t->GetY() == 0;
    };
    data.isPortal = [this](const VoidTrackRef& t, int i) {
        return (i == 4 && t->GetY() == -1) ||
                (i == 6 && t->GetY() == 1) ||
                (i == 10 && t->GetY() == 0);
    };

    return data;
}

//endregion

//region Level28

SimplestLevel::SimplestData Level28::CreateSimplestData() {
    auto data = SimplestLevel::SimplestData();

    data.numberOfObjects = 15;
    data.backgroundColor = Colors::White;
    data.shapeType = ShapeType::Circle;
    data.tracks = {
            {0, 0}
    };
    data.isRotating = true;
    data.isGate = [this](const VoidTrackRef& t, int i) {
        return i == NumberOfObjects(t) - 1 && t->GetX() == 0 && t->GetY() == 0;
    };
    data.isPortal = [this](const VoidTrackRef& t, int i) {
        return false;
    };

    return data;
}

//endregion

//region Level29

SimplestLevel::SimplestData Level29::CreateSimplestData() {
    auto data = SimplestLevel::SimplestData();

    data.numberOfObjects = 10;
    data.backgroundColor = Colors::Black;
    data.shapeType = ShapeType::Square;
    data.tracks = {
            {0, 0},
            {0, 1},
            {0, -1},
            {1, 0},
            {-1, 0}
    };
    data.isRotating = true;
    data.isGate = [this](const VoidTrackRef& t, int i) {
        return i == NumberOfObjects(t) - 1 && t->GetX() == 0 && t->GetY() == 0;
    };
    data.isPortal = [this](const VoidTrackRef& t, int i) {
        return (i == 0 && t->GetY() == -1) ||
                (i == 2 && t->GetX() == 1) ||
                (i == 4 && t->GetX() == 0 && t->GetY() == 0) ||
                (i == 6 && t->GetX() == -1) ||
                (i == 8 && t->GetY() == 1);
    };

    return data;
}

//endregion

//region Level30

SimplestLevel::SimplestData Level30::CreateSimplestData() {
    auto data = SimplestLevel::SimplestData();

    data.numberOfObjects = 1;
    data.backgroundColor = Colors::White;
    data.shapeType = ShapeType::Triangle;
    data.tracks = {
            {0, 0}
    };
    data.isRotating = false;
    data.isGate = [this](const VoidTrackRef& t, int i) {
        return true;
    };
    data.isPortal = [this](const VoidTrackRef& t, int i) {
        return true;
    };

    return data;
}

//endregion

//region Level31

SimplestLevel::SimplestData Level31::CreateSimplestData() {
    auto data = SimplestLevel::SimplestData();

    data.numberOfObjects = 15;
    data.backgroundColor = Colors::Black;
    data.shapeType = ShapeType::Square;
    data.tracks = {
            {0, 0},
            {1, 0}
    };
    data.isRotating = false;
    data.isGate = [this](const VoidTrackRef& t, int i) {
        return i == NumberOfObjects(t) - 1 && t->GetX() == 1;
    };
    data.isPortal = [this](const VoidTrackRef& t, int i) {
        return (i == 4 && t->GetX() == 0) ||
                (i == 8 && t->GetX() == 1);
    };

    return data;
}

//endregion

//region Level32

SimplestLevel::SimplestData Level32::CreateSimplestData() {
    auto data = SimplestLevel::SimplestData();

    data.numberOfObjects = 10;
    data.backgroundColor = Colors::White;
    data.shapeType = ShapeType::Triangle;
    data.tracks = {
            {0, 0},
            {0, 1},
            {0, -1}
    };
    data.isRotating = false;
    data.isGate = [this](const VoidTrackRef& t, int i) {
        return i == NumberOfObjects(t) - 1 && t->GetY() == 0;
    };
    data.isPortal = [this](const VoidTrackRef& t, int i) {
        return (i == 3 && t->GetY() == 1) ||
                (i == 5 && t->GetY() == 0) ||
                (i == 8 && t->GetY() == -1);
    };

    return data;
}

//endregion

//region Level33

SimplestLevel::SimplestData Level33::CreateSimplestData() {
    auto data = SimplestLevel::SimplestData();

    data.numberOfObjects = 10;
    data.backgroundColor = Colors::Black;
    data.shapeType = ShapeType::Square;
    data.tracks = {
            {0, 0},
            {-1, 0},
            {1, 0},
            {0, -1},
            {0, 1}
    };
    data.isRotating = false;
    data.isGate = [this](const VoidTrackRef& t, int i) {
        return i == NumberOfObjects(t) - 1 && t->GetX() == 0 && t->GetY() == 0;
    };
    data.isPortal = [this](const VoidTrackRef& t, int i) {
        return (i == 0 && t->GetY() == 1) ||
                (i == 2 && t->GetX() == -1) ||
                (i == 4 && t->GetX() == 0 && t->GetY() == 0) ||
                (i == 6 && t->GetX() == 1) ||
                (i == 8 && t->GetY() == -1);
    };

    return data;
}

//endregion

//region Level34

SimplestLevel::SimplestData Level34::CreateSimplestData() {
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

//endregion

//region Level35

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

//endregion

//region Level36

SimplestLevel::SimplestData Level36::CreateSimplestData() {
    auto data = SimplestLevel::SimplestData();

    data.numberOfObjects = 15;
    data.backgroundColor = Colors::White;
    data.shapeType = ShapeType::Triangle;
    data.tracks = {
            {0, 0},
            {0, 1},
            {0, -1}
    };
    data.isRotating = false;
    data.isGate = [this](const VoidTrackRef& t, int i) {
        return i == NumberOfObjects(t) - 1 && t->GetY() == 1;
    };
    data.isPortal = [this](const VoidTrackRef& t, int i) {
        return (i == 8 && t->GetY() == 1) ||
                (i == 11 && t->GetY() == 0) ||
                (i == 13 && t->GetY() == -1);
    };

    return data;
}

//endregion

//region Level37

SimplestLevel::SimplestData Level37::CreateSimplestData() {
    auto data = SimplestLevel::SimplestData();

    data.numberOfObjects = 10;
    data.backgroundColor = Colors::Black;
    data.shapeType = ShapeType::Square;
    data.tracks = {
            {0, 0},
            {1, 0},
            {-1, 0}
    };
    data.isRotating = false;
    data.isGate = [this](const VoidTrackRef& t, int i) {
        return i == NumberOfObjects(t) - 1 && t->GetX() == 0;
    };
    data.isPortal = [this](const VoidTrackRef& t, int i) {
        return (i == 3 && t->GetX() == -1) ||
                (i == 5 && t->GetX() == 0) ||
                (i == 8 && t->GetX() == 1);
    };

    return data;
}

//endregion

//region Level38

SimplestLevel::SimplestData Level38::CreateSimplestData() {
    auto data = SimplestLevel::SimplestData();

    data.numberOfObjects = 15;
    data.backgroundColor = Colors::White;
    data.shapeType = ShapeType::Triangle;
    data.tracks = {
            {0, 0}
    };
    data.isRotating = false;
    data.isGate = [this](const VoidTrackRef& t, int i) {
        return i == NumberOfObjects(t) - 1 && t->GetY() == 0;
    };
    data.isPortal = [this](const VoidTrackRef& t, int i) {
        return false;
    };

    return data;
}

//endregion

//region Level39

SimplestLevel::SimplestData Level39::CreateSimplestData() {
    auto data = SimplestLevel::SimplestData();

    data.numberOfObjects = 15;
    data.backgroundColor = Colors::Black;
    data.shapeType = ShapeType::Square;
    data.tracks = {
            {0, 0},
            {1, 0},
            {-1, 0}
    };
    data.isRotating = false;
    data.isGate = [this](const VoidTrackRef& t, int i) {
        return i == NumberOfObjects(t) - 1 && t->GetX() == 0;
    };
    data.isPortal = [this](const VoidTrackRef& t, int i) {
        return false;
    };

    return data;
}

//endregion

//region Level40

SimplestLevel::SimplestData Level40::CreateSimplestData() {
    auto data = SimplestLevel::SimplestData();

    data.numberOfObjects = 15;
    data.backgroundColor = Colors::White;
    data.shapeType = ShapeType::Circle;
    data.tracks = {
            {0, 0}
    };
    data.isRotating = false;
    data.isGate = [this](const VoidTrackRef& t, int i) {
        return i == NumberOfObjects(t) - 1 && t->GetY() == 0;
    };
    data.isPortal = [this](const VoidTrackRef& t, int i) {
        return false;
    };

    return data;
}

//endregion

//region Level41

SimplestLevel::SimplestData Level41::CreateSimplestData() {
    auto data = SimplestLevel::SimplestData();

    data.numberOfObjects = 15;
    data.backgroundColor = Colors::Black;
    data.shapeType = ShapeType::Square;
    data.tracks = {
            {0, 0},
            {1, 0},
            {-1, 0},
            {0, 1},
            {0, -1}
    };
    data.isRotating = false;
    data.isGate = [this](const VoidTrackRef& t, int i) {
        return i == NumberOfObjects(t) - 1 && t->GetX() == 0 && t->GetY() == 0;
    };
    data.isPortal = [this](const VoidTrackRef& t, int i) {
        return false;
    };

    return data;
}

//endregion

//region Level42

SimplestLevel::SimplestData Level42::CreateSimplestData() {
    auto data = SimplestLevel::SimplestData();

    data.numberOfObjects = 1;
    data.backgroundColor = Colors::White;
    data.shapeType = ShapeType::Triangle;
    data.tracks = {
            {0, 0}
    };
    data.isRotating = false;
    data.isGate = [this](const VoidTrackRef& t, int i) {
        return true;
    };
    data.isPortal = [this](const VoidTrackRef& t, int i) {
        return false;
    };

    return data;
}

//endregion

//region Level43

SimplestLevel::SimplestData Level43::CreateSimplestData() {
    auto data = SimplestLevel::SimplestData();

    data.numberOfObjects = 1;
    data.backgroundColor = Colors::Black;
    data.shapeType = ShapeType::Square;
    data.tracks = {
            {0, 0}
    };
    data.isRotating = false;
    data.isGate = [this](const VoidTrackRef& t, int i) {
        return true;
    };
    data.isPortal = [this](const VoidTrackRef& t, int i) {
        return false;
    };

    return data;
}

//endregion
