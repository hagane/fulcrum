#pragma once
#include <SDL_mixer.h>
#include "export.h"

namespace FGF
{
	class EXPORT Sound
	{
	public:
		Sound(const char* file);
		~Sound();

		void Play();
	private:
		Mix_Chunk* sample;
	};
}
