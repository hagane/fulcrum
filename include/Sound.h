#pragma once
#include <SDL_mixer.h>

namespace FGF
{
	class Sound
	{
	public:
		Sound(const char* file);
		~Sound();

		void Play();
	private:
		Mix_Chunk* sample;
	};
}
