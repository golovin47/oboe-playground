package com.example.ivan.lowlevelaudio

import android.content.res.AssetManager
import android.os.Bundle
import android.support.v7.app.AppCompatActivity
import android.widget.ImageButton

class MainActivity : AppCompatActivity() {

  companion object {
    init {
      System.loadLibrary("native-lib")
    }
  }

  private var playing: Boolean = false

  private val btnPlayStop: ImageButton by lazy(LazyThreadSafetyMode.NONE) {
    findViewById<ImageButton>(R.id.btnPlayStop)
  }

  override fun onCreate(savedInstanceState: Bundle?) {
    super.onCreate(savedInstanceState)
    setContentView(R.layout.activity_main)

    btnPlayStop.setOnClickListener {
      if (playing) {
        playing = false
        btnPlayStop.setImageDrawable(getDrawable(R.drawable.ic_play))
        stop()
      } else {
        playing = true
        btnPlayStop.setImageDrawable(getDrawable(R.drawable.ic_stop))
        play()
      }
    }

    initPlayer(assets)
  }

  private external fun initPlayer(assetManager: AssetManager)

  private external fun play()

  private external fun stop()
}
