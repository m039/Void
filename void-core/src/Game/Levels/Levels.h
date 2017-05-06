//
// Created by Dmitry Mozgin on 06/05/2017.
//

#pragma once

#include <Game/VoidObject.h>
#include <Game/Colors.h>

#include "SimpleLevel.h"
#include "SimplestLevel.h"

namespace vd {

//region Level1

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

//endregion

//region Level2

class Level2 : public SimplestLevel {
protected:

    virtual SimplestLevel::SimplestData CreateSimplestData() override;

};

//endregion

//region Level3

class Level3 : public SimplestLevel {
protected:

    virtual SimplestLevel::SimplestData CreateSimplestData() override;

};

//endregion

//region Level4

class Level4 : public SimplestLevel {
protected:

    virtual SimplestLevel::SimplestData CreateSimplestData() override;

};

//endregion

//region Level5

class Level5 : public SimplestLevel {
protected:

    virtual SimplestLevel::SimplestData CreateSimplestData() override;

};

//endregion

//region Level6

class Level6 : public SimplestLevel {
protected:

    virtual SimplestLevel::SimplestData CreateSimplestData() override;

};

//endregion

//region Level7

class Level7 : public SimplestLevel {
protected:

    virtual SimplestLevel::SimplestData CreateSimplestData() override;

};

//endregion

//region Level8

class Level8 : public SimplestLevel {
protected:

    virtual SimplestLevel::SimplestData CreateSimplestData() override;

};

//endregion

//region Level9

class Level9 : public SimplestLevel {
protected:

    virtual SimplestLevel::SimplestData CreateSimplestData() override;

};

//endregion

//region Level10

class Level10 : public SimplestLevel {
protected:

    virtual SimplestLevel::SimplestData CreateSimplestData() override;

};

//endregion

//region Level11

class Level11 : public SimplestLevel {
protected:

    virtual SimplestLevel::SimplestData CreateSimplestData() override;

};

//endregion

//region Level12

class Level12 : public SimplestLevel {
protected:

    virtual SimplestLevel::SimplestData CreateSimplestData() override;

};

//endregion

//region Level13

class Level13 : public SimplestLevel {
protected:

    virtual SimplestLevel::SimplestData CreateSimplestData() override;

};

//endregion

//region Level14

class Level14 : public SimplestLevel {
protected:

    virtual SimplestLevel::SimplestData CreateSimplestData() override;

};

//endregion

//region Level15

class Level15 : public SimplestLevel {
protected:

    virtual SimplestLevel::SimplestData CreateSimplestData() override;

};

//endregion

//region Level16

class Level16 : public SimplestLevel {
protected:

    virtual SimplestLevel::SimplestData CreateSimplestData() override;

};

//endregion

//region Level17

class Level17 : public SimplestLevel {
protected:

    virtual SimplestLevel::SimplestData CreateSimplestData() override;

};

//endregion

//region Level18

class Level18 : public SimplestLevel {
protected:

    virtual SimplestLevel::SimplestData CreateSimplestData() override;

};

//endregion

//region Level19

class Level19 : public SimplestLevel {
protected:

    virtual SimplestLevel::SimplestData CreateSimplestData() override;

};

//endregion

//region Level20

class Level20 : public SimplestLevel {
protected:

    virtual SimplestLevel::SimplestData CreateSimplestData() override;

};

//endregion

//region Level21

class Level21 : public SimplestLevel {
protected:

    virtual SimplestLevel::SimplestData CreateSimplestData() override;

};

//endregion

//region Level22

class Level22 : public SimplestLevel {
protected:

    virtual SimplestLevel::SimplestData CreateSimplestData() override;

};

//endregion

//region Level23

class Level23 : public SimplestLevel {
protected:

    virtual SimplestLevel::SimplestData CreateSimplestData() override;

};

//endregion

//region Level24

class Level24 : public SimplestLevel {
protected:

    virtual SimplestLevel::SimplestData CreateSimplestData() override;

};

//endregion

//region Level25

class Level25 : public SimplestLevel {
protected:

    virtual SimplestLevel::SimplestData CreateSimplestData() override;

};

//endregion

//region Level26

class Level26 : public SimplestLevel {
protected:

    virtual SimplestLevel::SimplestData CreateSimplestData() override;

};

//endregion

//region Level27

class Level27 : public SimplestLevel {
protected:

    virtual SimplestLevel::SimplestData CreateSimplestData() override;

};

//endregion

//region Level28

class Level28 : public SimplestLevel {
protected:

    virtual SimplestLevel::SimplestData CreateSimplestData() override;

};

//endregion

//region Level29

class Level29 : public SimplestLevel {
protected:

    virtual SimplestLevel::SimplestData CreateSimplestData() override;

};

//endregion

//region Level30

class Level30 : public SimplestLevel {
protected:

    virtual SimplestLevel::SimplestData CreateSimplestData() override;

};

//endregion

//region Level31

class Level31 : public SimplestLevel {
protected:

    virtual SimplestLevel::SimplestData CreateSimplestData() override;

};

//endregion

//region Level32

class Level32 : public SimplestLevel {
protected:

    virtual SimplestLevel::SimplestData CreateSimplestData() override;

};

//endregion

//region Level33

class Level33 : public SimplestLevel {
protected:

    virtual SimplestLevel::SimplestData CreateSimplestData() override;

};

//endregion

//region Level34

class Level34 : public SimplestLevel {
protected:

    virtual SimplestLevel::SimplestData CreateSimplestData() override;

};

//endregion

//region Level35

class Level35 : public SimplestLevel {
protected:

    virtual SimplestLevel::SimplestData CreateSimplestData() override;

};

//endregion

//region Level36

class Level36 : public SimplestLevel {
protected:

    virtual SimplestLevel::SimplestData CreateSimplestData() override;

};

//endregion

//region Level37

class Level37 : public SimplestLevel {
protected:

    virtual SimplestLevel::SimplestData CreateSimplestData() override;

};

//endregion

//region Level38

class Level38 : public SimplestLevel {
protected:

    virtual SimplestLevel::SimplestData CreateSimplestData() override;

};

//endregion

//region Level39

class Level39 : public SimplestLevel {
protected:

    virtual SimplestLevel::SimplestData CreateSimplestData() override;

};

//endregion

//region Level40

class Level40 : public SimplestLevel {
protected:

    virtual SimplestLevel::SimplestData CreateSimplestData() override;

};

//endregion

//region Level41

class Level41 : public SimplestLevel {
protected:

    virtual SimplestLevel::SimplestData CreateSimplestData() override;

};

//endregion

//region Level42

class Level42 : public SimplestLevel {
protected:

    virtual SimplestLevel::SimplestData CreateSimplestData() override;

};

//endregion

//region Level43

class Level43 : public SimplestLevel {
protected:

    virtual SimplestLevel::SimplestData CreateSimplestData() override;

};

//endregion

//region Level44

class Level44 : public Level42 {
};

//endregion

}

