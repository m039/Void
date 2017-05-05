//
// Created by Dmitry Mozgin on 03/05/2017.
//

#include <Game/Tags.h>
#include <Game/Colors.h>
#include "SimplestLevel.h"
#include "../VoidTrackObject.h"

using namespace vd;

SimplestLevel::SimplestLevel() : _simplestData(nullptr) {
}

void SimplestLevel::InitObject(const IVoidTrackObjectRef& object, const VoidTrackRef& t, int i) {
    auto shapeType = GetShapeType();

    if (IsGate(t, i)) {
        object->SetColor((GetBackgroundColor() == Colors::White) ? Colors::Black : Colors::White);
        object->SetName("Gate");
        object->SetShapeType(shapeType);
        object->SetHollow(false);
        object->GetTransform()->SetPosition(
                Vector3(
                        t->GetPosition().x,
                        t->GetPosition().y,
                        GetGatePositionZ()
                )
        );
        object->SetTag(Tags::Gate);
        object->SetAnimation(IsRotating()? std::make_shared<Rotation>(0, 0, 90 / 1.23f) : nullptr);
    } else if (IsPortal(t, i)) {
        object->SetColor(Colors::Red);
        object->SetName("Portal");
        object->SetShapeType(shapeType);
        object->SetHollow(false);
        object->GetTransform()->SetPosition(
                Vector3(
                        t->GetPosition().x,
                        t->GetPosition().y,
                        GetGatePositionZ() / 2 + i * (GetGatePositionZ() / 2) / (NumberOfObjects(t) - 1)
                )
        );
        object->SetTag(Tags::Portal);
        object->SetAnimation(IsRotating()? std::make_shared<Rotation>(0, 0, 90 / 1.23f) : nullptr);
    } else {
        object->SetColor(Colors::Red);
        object->SetName("VTrackObject[" + std::to_string(i) + "] at " + t->ToString());
        object->SetShapeType(shapeType);
        object->SetHollow(true);
        object->GetTransform()->SetPosition(
                Vector3(
                        t->GetPosition().x,
                        t->GetPosition().y,
                        GetGatePositionZ() / 2 + i * (GetGatePositionZ() / 2) / (NumberOfObjects(t) - 1)
                )
        );
        object->SetTag("");
        object->SetAnimation(IsRotating()? std::make_shared<Rotation>(0, 0, 90 / 1.23f) : nullptr);
    }
}

int SimplestLevel::NumberOfObjects(const VoidTrackRef& t) {
    return GetSimplestData().numberOfObjects;
}

Color SimplestLevel::CreateBackgroundColor() {
    return GetSimplestData().backgroundColor;
}

std::vector<VoidTrackRef> SimplestLevel::CreateTracks() {
    auto ints = GetSimplestData().tracks;
    auto tracks = std::vector<VoidTrackRef>(ints.size());

    for (auto i = 0; i < tracks.size(); i++) {
        tracks[i] = std::make_shared<VoidTrack>(ints[i][0], ints[i][1]);
    }

    return tracks;
}

SimplestLevel::SimplestData &SimplestLevel::GetSimplestData() {
    if (_simplestData == nullptr) {
        _simplestData = std::make_unique<SimplestLevel::SimplestData>(CreateSimplestData());
    }

    return *_simplestData;
}

ShapeType SimplestLevel::GetShapeType() {
    return GetSimplestData().shapeType;
}

bool SimplestLevel::IsGate(const VoidTrackRef& t, int i) {
    return GetSimplestData().isGate(t, i);
}

bool SimplestLevel::IsPortal(const VoidTrackRef& t, int i) {
    return GetSimplestData().isPortal(t, i);
}

bool SimplestLevel::IsRotating() {
    return GetSimplestData().isRotating;
}