//
// Created by Dmitry Mozgin on 03/05/2017.
//

#pragma once

#include <Game/ShapeType.h>
#include "SimpleLevel.h"

namespace vd {

//! Makes it more simple: handles positions, colors and animations.
class SimplestLevel : public SimpleLevel {
public:

    SimplestLevel();

protected:

    typedef std::function<bool(const VoidTrackRef& t, int i)> SimplestPredicate;

    class SimplestData {
    public:
        Color backgroundColor = Color::Black;
        int numberOfObjects;
        ShapeType shapeType;
        SimplestPredicate isGate;
        SimplestPredicate isPortal;
        std::vector<std::vector<int>> tracks; // 2-dimension array
        bool isRotating;
    };

    //region SimpleLevel's overrides.

    virtual void InitObject(const IVoidTrackObjectRef& object, const VoidTrackRef& track, int index) override;

    virtual int NumberOfObjects(const VoidTrackRef& t) override;

    virtual Color CreateBackgroundColor() override;

    virtual std::vector<VoidTrackRef> CreateTracks() override;

    //endregion

    //region Abstract methods.

    virtual SimplestData CreateSimplestData() = 0;

    //endregion

private:

    SimplestData& GetSimplestData();

    ShapeType GetShapeType();

    bool IsGate(const VoidTrackRef& t, int i);

    bool IsPortal(const VoidTrackRef& t, int i);

    bool IsRotating();

    std::unique_ptr<SimplestData> _simplestData;

};

}
