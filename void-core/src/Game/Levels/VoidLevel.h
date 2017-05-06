//
// Created by Dmitry Mozgin on 03/05/2017.
//

#pragma once

#include <Common/Color.h>
#include <Game/VoidTrack.h>
#include <unordered_map>
#include <vector>

namespace vd {

class IGame;

typedef IGame* IGameRef;

class IVoidTrackObject;

typedef std::shared_ptr<IVoidTrackObject> IVoidTrackObjectRef;

class VoidLevel {
protected:
    typedef std::shared_ptr<std::vector<IVoidTrackObjectRef>> IVoidTrackObjectVectorRef;

public:

    VoidLevel();

    void Initialize(const IGameRef &game);

    virtual void Update(const IGameRef& game, double deltaTime);

    virtual void Destroy(const IGameRef& game);

    VoidTrackRef StartTrack();

    std::shared_ptr<const std::vector<IVoidTrackObjectRef>> Objects();

    virtual void DisableObjects();

    virtual Color GetBackgroundColor() = 0;

protected:

    virtual void Create();

    virtual void OnCreateTracks(std::vector<VoidTrackRef> &tracks) = 0;

    virtual VoidTrackRef OnStartTrack(const std::vector<VoidTrackRef> &tracks) = 0;

    virtual void OnInitialize(
            const IGameRef &game,
            const std::vector<VoidTrackRef> &tracks,
            std::unordered_map<VoidTrackRef, IVoidTrackObjectVectorRef> &objects
    ) = 0;

private:

    static const std::shared_ptr<const std::vector<IVoidTrackObjectRef>> _EmptyObjects;

    // Note: objects are cached, it works cause all levels are static.
    std::shared_ptr<std::vector<IVoidTrackObjectRef>> _cachedObjects;

    std::vector<VoidTrackRef> _tracks;

    std::unordered_map<VoidTrackRef, IVoidTrackObjectVectorRef> _objects;

    bool _created;

    static void InitTracks(std::vector<VoidTrackRef> tracks);

};

typedef std::shared_ptr<VoidLevel> VoidLevelRef;

}

