//
// Created by Dmitry Mozgin on 05/05/2017.
//

#include <Game/Tags.h>
#include "Levels.h"

#include "../VoidTrackObject.h"
#include "../Game.h"

using namespace vd;

static const float StripeWidth = 0.05f;

static const float StripeGap = 0.5f;

Level1::Level1()
        : _leftStripe(nullptr),
          _topStripe(nullptr),
          _rightStripe(nullptr),
          _bottomStripe(nullptr),
          _stripesCreated(false),
          _stripeDepth(false) {
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

    if (_stripesCreated) {
        _leftStripe->SetEnabled(false);
        _topStripe->SetEnabled(false);
        _rightStripe->SetEnabled(false);
        _bottomStripe->SetEnabled(false);
        _leftStripe->Hide();
        _topStripe->Hide();
        _rightStripe->Hide();
        _bottomStripe->Hide();
    }
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
    _stripeDepth = GetGatePositionZ() / 2;

    if (!_stripesCreated) {
        auto pool = game->GetObjectPool();

        // left
        _leftStripe = std::make_shared<VoidTrackObject>(*pool, "Left Stripe", ShapeType::Square, false);
        _leftStripe->SetColor(Colors::Red);
        _leftStripe->Rotate(0, -90, 0);

        // top
        _topStripe = std::make_shared<VoidTrackObject>(*pool, "Top Stripe", ShapeType::Square, false);
        _topStripe->SetColor(Colors::Red);
        _topStripe->Rotate(-90, 0, 0);

        // right
        _rightStripe = std::make_shared<VoidTrackObject>(*pool, "Right Stripe", ShapeType::Square, false);
        _rightStripe->SetColor(Colors::Red);
        _rightStripe->Rotate(0, 90, 0);

        // bottom
        _bottomStripe = std::make_shared<VoidTrackObject>(*pool, "Bottom Stripe", ShapeType::Square, false);
        _bottomStripe->SetColor(Colors::Red);
        _bottomStripe->Rotate(90, 0, 0);

        _stripesCreated = true;
    }

    _leftStripe->SetEnabled(true);
    _topStripe->SetEnabled(true);
    _rightStripe->SetEnabled(true);
    _bottomStripe->SetEnabled(true);
    _leftStripe->Show();
    _topStripe->Show();
    _rightStripe->Show();
    _bottomStripe->Show();

    _leftStripe->GetTransform()->SetLocaleScale(Vector3(_stripeDepth, StripeWidth, 1));
    _topStripe->GetTransform()->SetLocaleScale(Vector3(StripeWidth, _stripeDepth, 1));
    _rightStripe->GetTransform()->SetLocaleScale(Vector3(_stripeDepth, StripeWidth, 1));
    _bottomStripe->GetTransform()->SetLocaleScale(Vector3(StripeWidth, _stripeDepth, 1));
}

void Level1::UpdateStripes(const IGameRef& game) {
    if (_stripesCreated) {
        auto gatePositionZ = GetGatePositionZ();

        auto z = 1 - (gatePositionZ - game->GetPlayer()->GetPosition().z) / gatePositionZ;

        _bottomStripe->GetTransform()->SetPosition(
                Vector3(0, -StripeGap, (gatePositionZ + _stripeDepth / 2) * (1 - z / 0.25f))
        );

        _rightStripe->GetTransform()->SetPosition(
                Vector3(StripeGap, 0, (gatePositionZ + _stripeDepth / 2) * (1 - (z - 0.25f) / 0.25f))
        );

        _leftStripe->GetTransform()->SetPosition(
                Vector3(-StripeGap, 0, (gatePositionZ + _stripeDepth / 2) * (1 - (z - 0.5f) / 0.25f))
        );

        _topStripe->GetTransform()->SetPosition(
                Vector3(0, StripeGap, (gatePositionZ + _stripeDepth / 2) * (1 - (z - 0.75f) / 0.25f))
        );
    }
}

void Level1::DestroyStripes(const IGameRef& game) {
    if (_stripesCreated) {
        _leftStripe->Hide();
        _topStripe->Hide();
        _rightStripe->Hide();
        _bottomStripe->Hide();

        // Get rid of references.
        _topStripe->Destroy();
        _topStripe = nullptr;
        _leftStripe->Destroy();
        _leftStripe = nullptr;
        _bottomStripe->Destroy();
        _bottomStripe = nullptr;
        _rightStripe->Destroy();
        _rightStripe = nullptr;

        _stripesCreated = false;
    }
}
