//
// Created by Dmitry Mozgin on 03/05/2017.
//

#include "SimpleLevel.h"
#include "../Tags.h"
#include "../Game.h"

using namespace vd;

SimpleLevel::SimpleLevel()
        : _backgroundColor(Color::Black),
          _gatePositionZ(0) {
}

Color SimpleLevel::GetBackgroundColor() {
    return _backgroundColor;
}

void SimpleLevel::CreateTracks(std::vector<VoidTrackRef> &tracks) {
    auto ts = CreateTracks();
    tracks.insert(tracks.end(), ts.begin(), ts.end());
}

VoidTrackRef SimpleLevel::StartTrack(const std::vector<VoidTrackRef> &tracks) {
    return tracks[0];
}

float SimpleLevel::GetGatePositionZ() {
    return _gatePositionZ;
}

void SimpleLevel::Create() {
    VoidLevel::Create();

    _backgroundColor = CreateBackgroundColor();
}

void SimpleLevel::Init(
        const IGameRef &game,
        const std::vector<VoidTrackRef> &tracks,
        std::unordered_map<VoidTrackRef, VoidLevel::IVoidTrackObjectVectorRef> &objects
) {
    _gatePositionZ = game->GetPlayer()->GetVelocity() * game->TimeForNextLevel();

    for (auto& t: tracks) {
        auto& os = objects[t];

        int i;

        if (os->size() == 0) {
            for (i = 0; i < NumberOfObjects(t); i++) {
                os->push_back(game->GetObjectPool()->GetObject());
            }
        }

        i = 0;

        for (auto& object: *os) {
            InitObject(object, t, i);
            i++;
        }
    }

    AssertGateExist(tracks, objects);
}

void SimpleLevel::AssertGateExist(
        const std::vector<VoidTrackRef> &tracks,
        std::unordered_map<VoidTrackRef, VoidLevel::IVoidTrackObjectVectorRef> &objects)
{
    for (auto& track : tracks) {
        for (auto& object : *objects[track]) {
            if (object->GetTag() == Tags::Gate) {
                return;
            }
        }
    }

    throw  std::runtime_error("Invalid state, gate should exists!");
}



