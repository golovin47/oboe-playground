#include "Player.h"
#include "../../../../oboe/src/common/OboeDebug.h"

using namespace oboe;

Player::Player(AAssetManager *assetManager) : assetManager(assetManager) {
}

void Player::initPlayer() {
    marioTheme = SoundRecording::loadFromAssets(assetManager, "mario_theme.raw");
    marioTheme->setLooping(true);

    AudioStreamBuilder builder;
    builder.setFormat(AudioFormat::I16);
    builder.setChannelCount(2);
    builder.setSampleRate(48000);
    builder.setCallback(this);
    builder.setPerformanceMode(PerformanceMode::LowLatency);
    builder.setSharingMode(SharingMode::Exclusive);

    Result result = builder.openStream(&audioStream);
    if (result != Result::OK) {
        LOGE("Failed to open stream. Error $s", convertToText(result));
    }

    result = audioStream->requestStart();
    if (result != Result::OK) {
        LOGE("Failed to open stream. Error $s", convertToText(result));
    }

    audioStream->setBufferSizeInFrames(audioStream->getFramesPerBurst() * 2);
}

void Player::play() {
    marioTheme->setPlaying(true);
}

void Player::stop() {
    marioTheme->setPlaying(false);
}

DataCallbackResult Player::onAudioReady(AudioStream *oboeStream, void *audioData,
                                        int32_t numFrames) {
    marioTheme->renderAudio(static_cast<int16_t *>(audioData), numFrames);
    return DataCallbackResult::Continue;
}




