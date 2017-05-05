//
// Created by Dmitry Mozgin on 05/05/2017.
//

#include <Game/Tags.h>
#include "Level1.h"

#include "../VoidTrackObject.h"

using namespace vd;

static const float StripeWidth = 0.05f;

static const float StripeGap = 0.5f;

Level1::Level1() : _stripesCreated(false) {
}

void Level1::InitObject(const IVoidTrackObjectRef& object, const VoidTrackRef& track, int index) {
    auto p = track->GetPosition();

    object->SetColor(Color::White);
    object->SetName("Gate");
    object->SetShapeType(ShapeType::Square);
    object->SetHollow(false);
    object->GetTransform()->SetPosition(Vector3(p.x, p.y, GetGatePositionZ()));
    object->SetTag(Tags::Gate);
}

void Level1::OnInitialize(
        const IGameRef& game,
        const std::vector<VoidTrackRef>& tracks,
        std::unordered_map<VoidTrackRef, VoidLevel::IVoidTrackObjectVectorRef>& objects
) {
    SimpleLevel::OnInitialize(game, tracks, objects);

    InitStripes(game);
}

void Level1::Update(const IGameRef& game, double deltaTime) {
    VoidLevel::Update(game, deltaTime);

    UpdateStripes(game);
}

void Level1::Destroy(const IGameRef& game) {
    VoidLevel::Destroy(game);

    DestroyStripes(game);
}

void Level1::DisableObjects() {
    VoidLevel::DisableObjects();
}

int Level1::NumberOfObjects(const VoidTrackRef &t) {
    return 1;
}

Color Level1::CreateBackgroundColor() {
    return Color::Black;
}

std::vector<VoidTrackRef> Level1::CreateTracks() {
    return {
            std::make_shared<VoidTrack>(0, 0)
    };
}

void Level1::InitStripes(const IGameRef& game) {

}

void Level1::UpdateStripes(const IGameRef& game) {

}

void Level1::DestroyStripes(const IGameRef& game) {

}
