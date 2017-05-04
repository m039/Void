//
// Created by Dmitry Mozgin on 03/05/2017.
//

#include <Common/Time.h>
#include "VoidLevel.h"
#include "../Game.h"

using namespace vd;

const std::shared_ptr<const std::vector<IVoidTrackObjectRef>> VoidLevel::_EmptyObjects =
        std::make_shared<const std::vector<IVoidTrackObjectRef>>(0);

VoidLevel::VoidLevel() : _created(false) {
}

VoidTrackRef VoidLevel::StartTrack() {
    return OnStartTrack(_tracks);
}

void VoidLevel::Initialize(const IGameRef &game) {
    // There is no way to call pure virtual function in a constructor.
    if (!_created) {
        Create();
        _created = true;
    }

    OnInitialize(game, _tracks, _objects);

    _cachedObjects = std::make_shared<std::vector<IVoidTrackObjectRef>>();

    for (auto& t: _tracks) {
        auto& objects = _objects[t];
        _cachedObjects->insert(_cachedObjects->end(), objects->begin(), objects->end());
    }

    for (auto& object : *Objects()) {
        object->SetEnabled(true);
        object->Show();

        auto r = std::dynamic_pointer_cast<Rotation>(object->GetAnimation());
        if (r != nullptr) {
            object->SetRotation(r->startAngle);
        }
    }
}

void VoidLevel::Create() {
    OnCreateTracks(_tracks);

    for (auto& t : _tracks) {
        _objects[t] = std::make_shared<std::vector<IVoidTrackObjectRef>>();
    }

    InitTracks(_tracks);
}

void VoidLevel::Update(const IGameRef &game, double deltaTime) {
    for (auto& object : *Objects()) {
        // Update animations.

        if (object->IsEnabled()) {
            auto r = std::dynamic_pointer_cast<Rotation>(object->GetAnimation());
            if (r != nullptr && Time::GetTime() > r->startTime) {
                object->Rotate(r->speed * (float) deltaTime);
            }
        }
    }
}

void VoidLevel::Destroy(const IGameRef &game) {
    for (auto& t : _tracks) {
        auto objects = _objects[t];

        game->GetObjectPool()->PutObjects(*objects);

        objects->clear();
    }

    _cachedObjects = nullptr;
}

void VoidLevel::DisableObjects() {
    for (auto& object : *Objects()) {
        object->SetEnabled(false);
        object->Hide();
    }
}

void VoidLevel::InitTracks(std::vector<VoidTrackRef> tracks) {
    for (auto& t1 : tracks) {
        for (auto& t2 : tracks) {
            if (t2 == t1) {
                continue;
            }

            if (t2->GetY() == t1->GetY()) {
                if (t2->GetX() - t1->GetX() == 1) {
                    t1->SetRightTrack(t2);
                }

                if (t2->GetX() - t1->GetX() == -1) {
                    t1->SetLeftTrack(t2);
                }
            }

            if (t2->GetX() == t1->GetX()) {
                if (t2->GetY() - t1->GetY() == 1) {
                    t1->SetTopTrack(t2);
                }

                if (t2->GetY() - t1->GetY() == -1) {
                    t1->SetBottomTrack(t2);
                }
            }
        }
    }
}

std::shared_ptr<const std::vector<IVoidTrackObjectRef>> VoidLevel::Objects() {
    if (_cachedObjects != nullptr) {
        return _cachedObjects;
    }

    return _EmptyObjects;
}
