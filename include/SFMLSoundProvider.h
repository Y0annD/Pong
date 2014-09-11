#pragma once
#include "stdafx.h"
#include "IAudioProvider.h"

class SFMLSoundProvider: public IAudioProvider
{
 public:
  SFMLSoundProvider();

  virtual void PlaySound(std::string filename);
  virtual void PlaySong(std::string filename, bool looping = false);
  virtual void StopAllSounds();

  virtual bool IsSoundPlaying();
  virtual bool IsSongPlaying();

 private:
  sf::SoundBuffer _soundBuffer;
  sf::Sound       _sound;
  sf::Music       _music;
};
