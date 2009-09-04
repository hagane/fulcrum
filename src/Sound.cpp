#include "../include/Sound.h"

namespace FGF
{
	Sound::Sound(const char* file)
	{
		sample = Mix_LoadWAV(file);
	}

	Sound::~Sound()
	{
		Mix_FreeChunk(sample);
	}

	void Sound::Play()
	{
		Mix_PlayChannel(-1,sample,0);
	}
}
