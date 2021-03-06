//
// Created by Dmitry Mozgin on 03/05/2017.
//

#pragma once

#include <unordered_map>
#include <vector>
#include <memory>

#include <Common/Color.h>
#include <Game/VoidTrack.h>

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

    void Create(const IGameRef& game);

    void Prepare(const IGameRef& game);

    virtual void Update(const IGameRef& game, double deltaTime);

    virtual void Destroy(const IGameRef& game);

    VoidTrackRef StartTrack();

    std::shared_ptr<const std::vector<IVoidTrackObjectRef>> Objects();

    virtual void DisableObjects();

    virtual Color GetBackgroundColor() = 0;

protected:

    virtual void OnCreate();

    virtual void OnCreateTracks(std::vector<VoidTrackRef> &tracks) = 0;

    virtual VoidTrackRef OnStartTrack(const std::vector<VoidTrackRef> &tracks) = 0;

    virtual void OnPrepare(
            const IGameRef& game,
            const std::vector<VoidTrackRef>& tracks,
            std::unordered_map<VoidTrackRef, IVoidTrackObjectVectorRef>& objects
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

