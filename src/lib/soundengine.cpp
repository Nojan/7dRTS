#include "soundengine.h"

#include <assert.h>

SoundEngine& SoundEngine::Instance()
{
  static SoundEngine instance;
  return instance;
}

SoundEngine::SoundEngine()
  : _soundVolume(1.f)
  , _musicVolume(1.f)
  , _globalVolume(1.f)
{
}

SoundEngine::~SoundEngine()
{
  for(NamedSoundEffectMap::iterator it = _mappedEffects.begin(); it!=_mappedEffects.end(); ++it)
    delete it->second;

  _mappedEffects.clear();
}

void SoundEngine::preloadSoundEffect(char const* filename)
{
  QSoundEffect* newEffect = new QSoundEffect();
  newEffect->setSource(QUrl::fromLocalFile(filename));
  newEffect->setLoopCount(1);
  newEffect->setVolume(1.f);
  assert(newEffect->status() != QSoundEffect::Null && newEffect->status() != QSoundEffect::Error);
  _mappedEffects.insert(NamedSoundEffect(filename, newEffect));
}

void SoundEngine::playSoundEffect(char const* filename, float volume)
{
  assert(!_mappedEffects.empty());
  NamedSoundEffectMap::iterator it = _mappedEffects.find(filename);
  QSoundEffect* effectToPlay = it->second;
  assert(effectToPlay != NULL);
  effectToPlay->setVolume(volume * (_globalVolume * _soundVolume));
  effectToPlay->play();
}
