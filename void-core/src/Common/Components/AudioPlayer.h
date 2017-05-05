//
// Created by Dmitry Mozgin on 24/04/2017.
//

#pragma once

#include "Common/Common.h"

namespace vd {

class IAudioPlayer {

public:

    //! Playback position in seconds.
    virtual sec_t GetTime() = 0;

    virtual void SetTime(sec_t time) = 0;

    //! Is music playing right now?
    virtual bool IsPlaying() = 0;

    //! The volume of the audio source (0.0 to 1.0).
    virtual float GetVolume() = 0;

    virtual void SetVolume(float volume) = 0;

    //! Play music.
    virtual void Play() = 0;

    //! Stop playing music.
    virtual void Stop() = 0;

    virtual ~IAudioPlayer();

};

typedef std::shared_ptr<IAudioPlayer> IAudioPlayerRef;

}