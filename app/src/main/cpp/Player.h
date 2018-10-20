//
// Created by IvanGolovin on 20/10/2018.
//

#ifndef LOWLEVELAUDIO_PLAYER_H
#define LOWLEVELAUDIO_PLAYER_H

#include <android/asset_manager.h>
#include <oboe/Oboe.h>

#include "SoundRecording.h"

using namespace oboe;

struct Player : AudioStreamCallback {
    explicit Player(AAssetManager *assetManager);

    void initPlayer();

    void play();

    void stop();

    DataCallbackResult
    onAudioReady(AudioStream *oboeStream, void *audioData, int32_t numFrames) override;

private:
    AAssetManager *assetManager{nullptr};
    AudioStream *audioStream{nullptr};
    SoundRecording *marioTheme{nullptr};
};

#endif //LOWLEVELAUDIO_PLAYER_H