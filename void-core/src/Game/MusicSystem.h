//
// Created by Dmitry Mozgin on 21/04/2017.
//

#pragma once

namespace vd {

class IMusicSystem {

public:

    virtual void Play(int levelIndex, bool fadeIn) = 0;

    virtual void Stop(bool fadeIn) = 0;

    //! Time in seconds for the next level.
    virtual float TimeForNextLevel(int levelIndex) = 0;

    virtual ~IMusicSystem() {}
};


class MusicSystem : public IMusicSystem {

public:

    void Play(int levelIndex, bool fadeIn) override;

    void Stop(bool fadeIn) override;

    float TimeForNextLevel(int levelIndex) override;

};

}