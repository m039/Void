//
// Created by Dmitry Mozgin on 24/04/2017.
//

#include "AudioPlayerImpl.h"

using namespace vd;

AudioPlayerImpl::AudioPlayerImpl(
        const ci::audio::SamplePlayerNodeRef &player,
        const ci::audio::GainNodeRef &gain)
    : _audioPlayer(player), _gain(gain)
{
}

sec_t AudioPlayerImpl::GetTime() {
    return _audioPlayer->getReadPositionTime();
}

void AudioPlayerImpl::SetTime(sec_t time) {
    _audioPlayer->seekToTime(time);
}

bool AudioPlayerImpl::IsPlaying() {
    return _audioPlayer->isEnabled();
}

float AudioPlayerImpl::GetVolume() {
    return _gain->getValue();
}

void AudioPlayerImpl::SetVolume(float volume) {
    _gain->setValue(volume);
}

void AudioPlayerImpl::Play() {
    _audioPlayer->start();
}

void AudioPlayerImpl::Stop() {
    _audioPlayer->stop();
}
