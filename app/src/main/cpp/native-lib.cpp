#include <jni.h>
#include <android/asset_manager_jni.h>
#include "Player.h"

using namespace std;

extern "C" {

unique_ptr<Player> player;

JNIEXPORT void JNICALL
Java_com_example_ivan_lowlevelaudio_MainActivity_initPlayer(JNIEnv *jniEnv, jobject instance,
                                                            jobject jAssetManager) {

    AAssetManager *aAssetManager = AAssetManager_fromJava(jniEnv, jAssetManager);
    player = unique_ptr<Player>(new Player(aAssetManager));
    player->initPlayer();
}

JNIEXPORT void JNICALL
Java_com_example_ivan_lowlevelaudio_MainActivity_play(JNIEnv *jniEnv, jobject instance) {
    player->play();
}

JNIEXPORT void JNICALL
Java_com_example_ivan_lowlevelaudio_MainActivity_stop(JNIEnv *jniEnv, jobject instance) {
    player->stop();
}

}