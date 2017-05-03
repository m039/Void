//
// Created by Dmitry Mozgin on 28/04/2017.
//

#pragma once

#include <memory>
#include <Common/Vector3.h>
#include <Common/Vector2.h>

namespace vd {

class VoidTrack;

typedef std::shared_ptr<VoidTrack> VoidTrackRef;

class VoidTrack {
public:

    VoidTrack(int x, int y);

    //! Position of VoidTrack in world space coordinates.
    Vector2 GetPosition() const;

    int GetX() const;

    void SetX(int x);

    int GetY() const;

    void SetY(int y);

    VoidTrackRef GetLeftTrack() const;

    void SetLeftTrack(const VoidTrackRef& leftTrack);

    VoidTrackRef GetTopTrack() const;

    void SetTopTrack(const VoidTrackRef& topTrack);

    VoidTrackRef GetRightTrack() const;

    void SetRightTrack(const VoidTrackRef& rightTrack);

    VoidTrackRef GetBottomTrack() const;

    void SetBottomTrack(const VoidTrackRef& bottomTrack);

    std::string ToString() const;

private:

    VoidTrackRef _leftTrack;

    VoidTrackRef _topTrack;

    VoidTrackRef _rightTrack;

    VoidTrackRef _bottomTrack;

    int _x;

    int _y;

    Vector2 _position;

};

}

