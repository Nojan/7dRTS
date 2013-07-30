#ifndef SOUNDENGINE_H
#define SOUNDENGINE_H

#include "pch.h"

#include <stdlib.h>
#include <vector>
#include <map>

#include <QSoundEffect>

typedef std::map<char const*, QSoundEffect*> NamedSoundEffectMap;
typedef std::pair<char const*, QSoundEffect*> NamedSoundEffect;

class SoundEngine
{
public:
  ~SoundEngine();
  static SoundEngine& Instance();

  void preloadSoundEffect(char const* filename);
  void playSoundEffect(char const* filename, float volume = 1.f);

  void setSoundVolume(float volume) { _soundVolume = volume; }
  void setMusicVolume(float volume) { _musicVolume = volume; }
  void setGlobalVolume(float volume) { _globalVolume = volume; }

private:
  SoundEngine();
  std::map<char const*, QSoundEffect*> _mappedEffects;

  float _soundVolume;
  float _musicVolume;
  float _globalVolume;
};

#endif // SOUNDENGINE_H
