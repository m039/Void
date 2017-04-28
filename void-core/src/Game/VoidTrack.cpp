//
// Created by Dmitry Mozgin on 28/04/2017.
//

#include "VoidTrack.h"
#include "Config.h"

using namespace vd;

Vector2 VoidTrack::GetPosition() const {
    return _position;
}

VoidTrack::VoidTrack(int x, int y) {
    SetX(x);
    SetY(y);
}

int VoidTrack::GetX() const {
    return _x;
}

void VoidTrack::SetX(int x) {
    _position.x = x * Config::Gap;
    _x = x;
}

int VoidTrack::GetY() const {
    return _y;
}

void VoidTrack::SetY(int y) {
    _position.y = y * Config::Gap;
    _y = y;
}

VoidTrackRef VoidTrack::GetLeftTrack() const {
    return _leftTrack;
}

void VoidTrack::SetLeftTrack(const VoidTrackRef &leftTrack) {
    _leftTrack = leftTrack;
}

VoidTrackRef VoidTrack::GetTopTrack() const {
    return _topTrack;
}

void VoidTrack::SetTopTrack(const VoidTrackRef &topTrack) {
    _topTrack = topTrack;
}

VoidTrackRef VoidTrack::GetRightTrack() const {
    return _rightTrack;
}

void VoidTrack::SetRightTrack(const VoidTrackRef &rightTrack) {
    _rightTrack = rightTrack;
}

VoidTrackRef VoidTrack::GetBottomTrack() const {
    return _bottomTrack;
}

void VoidTrack::SetBottomTrack(const VoidTrackRef &bottomTrack) {
    _bottomTrack = bottomTrack;
}
