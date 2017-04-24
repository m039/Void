//
// Created by Dmitry Mozgin on 24/04/2017.
//

#include "AudioPlayer.h"

using namespace vd;

AudioPlayer::AudioPlayer(
        const ci::audio::SamplePlayerNodeRef &player,
        const ci::audio::GainNodeRef &gain)
    : _audioPlayer(player), _gain(gain)
{
}

AudioPlayer::~AudioPlayer() {
}

sec_t AudioPlayer::GetTime() {
    return _audioPlayer->getReadPositionTime();
}

void AudioPlayer::SetTime(sec_t time) {
    _audioPlayer->seekToTime(time);
}

bool AudioPlayer::IsPlaying() {
    return _audioPlayer->isEnabled();
}

float AudioPlayer::GetVolume() {
    return _gain->getValue();
}

void AudioPlayer::SetVolume(float volume) {
    _gain->setValue(volume);
}

void AudioPlayer::Play() {
    _audioPlayer->start();
}

void AudioPlayer::Stop() {
    _audioPlayer->stop();
}
