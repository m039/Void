//
// Created by Dmitry Mozgin on 05/05/2017.
//

#pragma once

#include <Game/VoidObject.h>
#include "SimpleLevel.h"

namespace vd {

class Level1 : public SimpleLevel {
public:

    Level1();

protected:

    //region Implementation of SimpleLevel.

    virtual void InitObject(const IVoidTrackObjectRef& object, const VoidTrackRef& track, int index) override;

    virtual int NumberOfObjects(const VoidTrackRef& t) override;

    virtual Color CreateBackgroundColor() override;

    virtual std::vector<VoidTrackRef> CreateTracks() override;

    //endregion

    //region SimpleLevel's overrides.

    virtual void OnInitialize(
            const IGameRef& game,
            const std::vector<VoidTrackRef>& tracks,
            std::unordered_map<VoidTrackRef, IVoidTrackObjectVectorRef>& objects
    ) override;

public:

    virtual void Update(const IGameRef& game, double deltaTime) override;

    virtual void Destroy(const IGameRef& game) override;

    virtual void DisableObjects() override;

    //endregion

private:

    void InitStripes(const IGameRef& game);

    void UpdateStripes(const IGameRef& game);

    void DestroyStripes(const IGameRef& game);

    IVoidTrackObjectRef _leftStripe;

    IVoidTrackObjectRef _topStripe;

    IVoidTrackObjectRef _rightStripe;

    IVoidTrackObjectRef _bottomStripe;

    bool _stripesCreated;

    float _stripeDepth;

};

}