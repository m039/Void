//
// Created by Dmitry Mozgin on 24/04/2017.
//

#pragma once

#include <cinder/audio/audio.h>

#include "Common/Components/IAudioPlayer.h"

namespace vd {

class AudioPlayer : public IAudioPlayer {

public:

    AudioPlayer(const ci::audio::SamplePlayerNodeRef &player, const ci::audio::GainNodeRef &gain);

    ~AudioPlayer() override;

    //region Implementation of IAudioPlayer

    sec_t GetTime() override;

    void SetTime(sec_t time) override;

    bool IsPlaying() override;

    float GetVolume() override;

    void SetVolume(float volume) override;

    void Play() override;

    void Stop() override;

    //endregion

private:

    const ci::audio::SamplePlayerNodeRef _audioPlayer;

    const ci::audio::GainNodeRef _gain;

};

}
