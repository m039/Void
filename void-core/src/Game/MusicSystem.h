//
// Created by Dmitry Mozgin on 21/04/2017.
//

#pragma once

#include <memory>
#include <Common/Components/AudioPlayer.h>
#include <Common/Coroutines/Coroutine.h>
#include <Common/Components/GameComponent.h>

namespace vd {

class IMusicSystem {

public:

    virtual void Play(int levelIndex, bool fadeIn) = 0;

    virtual void Stop(bool fadeIn) = 0;

    //! Time in seconds for the next level.
    virtual sec_t TimeForNextLevel(int levelIndex) = 0;

    virtual ~IMusicSystem();

};

typedef std::shared_ptr<IMusicSystem> IMusicSystemRef;

class MusicSystem :
        public GameComponent,
        public IMusicSystem
{

public:

    MusicSystem(const IAudioPlayerRef& audioPlayer);

    //region Implementation of IMusicSystem.

    virtual void Play(int levelIndex, bool fadeIn) override;

    virtual void Stop(bool fadeOut) override;

    virtual sec_t TimeForNextLevel(int levelIndex) override;

    //endregion

    //region GameComponent's overrides.

    virtual void OnStart() override;

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