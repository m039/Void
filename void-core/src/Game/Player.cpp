//
// Created by Dmitry Mozgin on 28/04/2017.
//

#include <Common/Time.h>

#include "Player.h"
#include "Config.h"

using namespace vd;

//region IPlayer

IPlayer::~IPlayer() {
}

//endregion

//region Player

Player::Player(const ICameraRef& camera)
        : _transform(camera->GetTransform()),
          _camera(camera),
          _velocity(4.0f),
          _running(false),
          _alive(false) {
    _camera->SetNearClipPlane(0.01f);
}

Vector3 Player::GetPosition() const {
    return _transform->GetPosition();
}

void Player::SetPosition(const Vector3& vec) {
    _transform->SetPosition(vec);
}

float Player::GetVelocity() const {
    return _velocity;
}

void Player::SetVelocity(float velocity) {
    _velocity = velocity;
}

bool Player::IsAlive() const {
    return _alive;
}

void Player::SetAlive(bool alive) {
    _alive = alive;
}

void Player::StartRunning() {
    _running = true;
}

void Player::StopRunning() {
    _running = false;
}

void Player::MoveToPosition(const Vector3& position) {
    if (_moveToTrackCoroutine != nullptr) {
        GetCoroutineManager().Stop(_moveToTrackCoroutine);
        _moveToTrackCoroutine = nullptr;
    }

    _transform->SetPosition(position);
}

void Player::MoveToTrack(const VoidTrackRef& track) {
    if (_moveToTrackCoroutine != nullptr) {
        GetCoroutineManager().Stop(_moveToTrackCoroutine);
        _moveToTrackCoroutine = nullptr;
    }

    auto p = track->GetPosition();

    _moveToTrackCoroutine = GetCoroutineManager().Start(SmoothTranslationXYCoroutine(
            _transform,
            Vector3(p.x, p.y, 0.0f),
            Config::MoveTime,
            [this]() { _moveToTrackCoroutine = nullptr; }
    ));
}

bool Player::IsBehind(const IVoidObjectRef& object) {
    return _transform->GetPosition().z > object->GetTransform()->GetPosition().z;
}

bool Player::IsMovingToTrack() {
    return _moveToTrackCoroutine != nullptr;
}

bool Player::CanCollide(const IVoidObjectRef& object) {
    auto o = object->GetTransform()->GetPosition();
    auto p = GetPosition();

    const float scale = Config::DefaultScale / 2;

    // Player's collision box is a cube.
    return (o.x - scale < p.x) &&
           (o.x + scale > p.x) &&
           (o.y - scale < p.y) &&
           (o.y + scale > p.y) &&
           (o.z - scale < p.z) &&
           (o.z + scale > p.z);
}

bool Player::IsCoverWholeScreen(const IVoidTrackObjectRef& vTrackObject) {
    auto playerZ = _transform->GetPosition().z;
    auto objectZ = vTrackObject->GetTransform()->GetPosition().z;

    return objectZ - playerZ <= _camera->GetNearClipPlane();
}

Player::~Player() {

}

void Player::OnUpdate() {
    GameComponent::OnUpdate();

    if (_running) {
        auto p = _transform->GetPosition();
        p.z = p.z + _velocity * static_cast<float>(Time::GetDeltaTime());
        _transform->SetPosition(p);
    }
}

const Coroutine::EnumerationFunction Player::SmoothTranslationXYCoroutine(
        const ITransformRef& transform,
        const Vector3& destination,
        float time,
        const Callback& endCallback
) {
    return [transform, destination, time, endCallback](Coroutine::YieldHandler &yield) {
        auto start = Vector3(transform->GetPosition().x, transform->GetPosition().y);
        auto end = Vector3(destination.x, destination.y);
        auto rate = 1 / (time * Vector3::Distance(end, start));
        auto t = 0.0f;
        auto tr = transform;

        std::function<void(const Vector3&)> update = [&tr] (const Vector3& vector) {
            auto p = tr->GetPosition();
            p.x = vector.x;
            p.y = vector.y;
            tr->SetPosition(p);
        };

        while (t < 1.0f) {
            t += static_cast<float>(Time::GetDeltaTime()) * rate;
            update(Vector3::Lerp(start, end, MathF::SmoothStep(0.0f, 1.0f, t)));
            yield(nullptr);
        }

        update(end);
        yield(nullptr);

        if (endCallback != nullptr) {
            endCallback();
        }
    };
}

//endregion
