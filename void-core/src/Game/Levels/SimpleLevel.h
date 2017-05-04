//
// Created by Dmitry Mozgin on 03/05/2017.
//

#pragma once

#include "VoidLevel.h"

namespace vd {

//! Makes level creation a little bit easier.
class SimpleLevel : public VoidLevel {
public:

    SimpleLevel();

protected:

    //region Abstract methods.

    virtual void InitObject(const IVoidTrackObjectRef& object, const VoidTrackRef& track, int index) = 0;

    virtual int NumberOfObjects(const VoidTrackRef& t) = 0;

    virtual Color CreateBackgroundColor() = 0;

    virtual std::vector<VoidTrackRef> CreateTracks() = 0;

    //endregion

    //region VoidLevel's overrides.

public:
    virtual Color GetBackgroundColor() override;

protected:
    virtual void OnCreateTracks(std::vector<VoidTrackRef> &tracks) override;

    virtual VoidTrackRef OnStartTrack(const std::vector<VoidTrackRef> &tracks) override;

    virtual void Create() override;

    virtual void OnInitialize(
            const IGameRef &game,
            const std::vector<VoidTrackRef> &tracks,
            std::unordered_map<VoidTrackRef, IVoidTrackObjectVectorRef> &objects
    ) override;

    //endregion

    float GetGatePositionZ();

private:

    static void AssertGateExist(
            const std::vector<VoidTrackRef>& tracks,
            std::unordered_map<VoidTrackRef, IVoidTrackObjectVectorRef>& objects
    );

    Color _backgroundColor;

    float _gatePositionZ;

};

}
