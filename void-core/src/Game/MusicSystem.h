//
// Created by Dmitry Mozgin on 21/04/2017.
//

#pragma once

#include <memory>
#include <Common/Components/IAudioPlayer.h>
#include <Common/Coroutines/Coroutine.h>
#include <Common/Components/GameComponent.h>

namespace vd {

class IMusicSystem {

public:

    virtual void Play(int levelIndex, bool fadeIn) = 0;

    virtual void Stop(bool fadeIn) = 0;

    //! Time in seconds for the next level.
    virtual sec_t TimeForNextLevel(int levelIndex) = 0;

    virtual ~IMusicSystem() {}
};


class MusicSystem :
        public GameComponent,
        public IMusicSystem
{

public:

    MusicSystem(const IAudioPlayerRef& audioPlayer);

    //region Implementation of IMusicSystem.

    void Play(int levelIndex, bool fadeIn) override;

    void Stop(bool fadeOut) override;

    sec_t TimeForNextLevel(int levelIndex) override;

    //endregion

    //region Overridden GameComponent methods.

    void OnStart() override;

    //endregion

private:

    const IAudioPlayerRef _audioPlayer;

    CoroutineRef _fadeCoroutine;

    bool _mute;

    void ChangeVolume(double volume);

    void StartFade(bool fadeInOrFadeOut, const Callback& endCallback);

    const Coroutine::EnumerationFunction DoFade(bool fadeInOrFadeOut, const Callback& endCallback);

};

}