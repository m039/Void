//
// Created by Dmitry Mozgin on 21/04/2017.
//

#include "MusicSystem.h"
#include "Config.h"

#include <array>
#include <Common/Time.h>
#include <Common/Math.h>

using namespace vd;

// Synchronization by time laps.
static std::array<sec_t, 44> _Syncs {{
        4.792f,
        9.661f,
        14.428f,
        19.206f,
        23.992f,
        28.763f,
        33.591f,
        38.374f,
        43.179f,
        47.999f,
        52.796f,
        57.593f,
        62.39f,
        67.2f,
        72.003f,
        76.732f,
        81.608f,
        86.425f,
        91.249f,
        95.991f,
        100.791f,
        105.598f,
        110.428f,
        115.206f,
        120.032f,
        124.845f,
        129.62f,
        134.406f,
        139.203f,
        144.062f,
        148.824f,
        153.631f,
        158.423f,
        163.263f,
        168.011f,
        172.825f,
        177.595f,
        182.385f,
        187.258f,
        192.018f,
        196.774f,
        196.774f + 4.8f,
        196.774f + 2 * 4.8f,
        196.774f + 3 * 4.8f
}};

MusicSystem::MusicSystem(const IAudioPlayerRef& audioPlayer)
        : _audioPlayer(audioPlayer),
          _mute(false)
{
}

void MusicSystem::OnStart() {
    GameComponent::OnStart();

    _audioPlayer->SetVolume(_mute ? 0.0f : 1.0f);
}

void MusicSystem::Play(int levelIndex, bool fadeIn) {
    _audioPlayer->Play();

    if (fadeIn) {
        ChangeVolume(0.0f);
        StartFade(true, nullptr);
    } else {
        ChangeVolume(1.0f);
    }

    if (levelIndex <= 0) {
        _audioPlayer->SetTime(0.0f);
    } else {
        _audioPlayer->SetTime(_Syncs[levelIndex - 1]);
    }
}

void MusicSystem::Stop(bool fadeOut) {
    Action h = [this]() {
        _audioPlayer->Stop();
    };

    if (fadeOut) {
        StartFade(false, h);
    } else {
        h();
    }
}

void MusicSystem::StartFade(bool fadeInOrFadeOut, const Action& endCallback)
{
    if (_fadeCoroutine != nullptr) {
        GetCoroutineManager().Stop(_fadeCoroutine);
    }

    _fadeCoroutine = GetCoroutineManager()
            .Start(DoFade(fadeInOrFadeOut, endCallback));
}

sec_t MusicSystem::TimeForNextLevel(int levelIndex) {
    if (_audioPlayer->IsPlaying()) {
        sec_t sync = _Syncs.at(static_cast<uint>(levelIndex));
        sec_t playingTime = _audioPlayer->GetTime();
        return sync - playingTime;
    } else {
        return -1;
    }
}

void MusicSystem::ChangeVolume(double volume) {
    if (!_mute) {
        _audioPlayer->SetVolume(volume);
    } else {
        _audioPlayer->SetVolume(0.0f);
    }
}

const Coroutine::EnumerationFunction MusicSystem::DoFade(bool fadeInOrFadeOut, const Action& endCallback) {
    return [this, fadeInOrFadeOut, endCallback](Coroutine::YieldHandler &yield) {
        sec_t t = 0.0f;

        if (fadeInOrFadeOut) {
            while (t < 1) {
                t += Time::GetDeltaTime() / Config::FadeTime;
                yield(nullptr);
                ChangeVolume(MathD::SmoothStep(0, 1, t));
            }
        } else {
            while (t < 1) {
                t += Time::GetDeltaTime() / Config::FadeTime;
                yield(nullptr);
                ChangeVolume(1 - MathD::SmoothStep(0, 1, t));
            }
        }

        if (endCallback != nullptr) {
            endCallback();
        }
    };
}