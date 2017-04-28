//
// Created by Dmitry Mozgin on 28/04/2017.
//

#pragma once

#include <Common/Vector3.h>
#include <Common/Components/ICamera.h>
#include <Common/Coroutines/Coroutine.h>
#include <Common/Components/GameComponent.h>

#include "VoidObject.h"
#include "VoidTrack.h"
#include "VoidTrackObject.h"

namespace vd {

class IPlayer {
public:

    virtual Vector3 GetPosition() const = 0;

    virtual void SetPosition(const Vector3& vec) = 0;

    virtual float GetVelocity() const = 0;

    virtual void SetVelocity(float velocity) = 0;

    virtual bool IsAlive() const = 0;

    virtual void SetAlive(bool alive) = 0;

    virtual void StartRunning() = 0;

    virtual void StopRunning() = 0;

    virtual void MoveToPosition(const Vector3& position) = 0;

    virtual void MoveToTrack(const VoidTrackRef& track) = 0;

    virtual bool IsBehind(const IVoidObjectRef& vTrackObject) = 0;

    virtual bool IsMovingToTrack() = 0;

    virtual bool CanCollide(const IVoidObjectRef& vTrackObject) = 0;

    //! Returns true if vTrackObject covers whole screen.
    virtual bool IsCoverWholeScreen(const IVoidTrackObjectRef& vTrackObject) = 0;

    virtual ~IPlayer() {}
};

typedef std::shared_ptr<IPlayer> IPlayerRef;

class Player : public GameComponent, public IPlayer {
public:

    Player(const ICameraRef& camera);

    //region Implementation of IPlayer.

    virtual Vector3 GetPosition() const override;

    virtual void SetPosition(const Vector3& vec) override;

    virtual float GetVelocity() const override;

    virtual void SetVelocity(float velocity) override;

    virtual bool IsAlive() const override;

    virtual void SetAlive(bool alive) override;

    virtual void StartRunning() override;

    virtual void StopRunning() override;

    virtual void MoveToPosition(const Vector3& position) override;

    virtual void MoveToTrack(const VoidTrackRef& track) override;

    virtual bool IsBehind(const IVoidObjectRef& vTrackObject) override;

    virtual bool IsMovingToTrack() override;

    virtual bool CanCollide(const IVoidObjectRef& vTrackObject) override;

    //! Returns true if vTrackObject covers whole screen.
    virtual bool IsCoverWholeScreen(const IVoidTrackObjectRef& vTrackObject) override;

    //endregion

    //region GameComponent's overrides.

    virtual void OnUpdate() override;

    //endregion

    virtual ~Player();

private:

    const ITransformRef _transform;

    const ICameraRef _camera;

    float _velocity;

    bool _running;

    bool _alive;

    CoroutineRef _moveToTrackCoroutine;

    static const Coroutine::EnumerationFunction SmoothTranslationXYCoroutine(
            const ITransformRef& transform,
            const Vector3& destination,
            float time,
            const Callback& endCallback
    );

};

}

