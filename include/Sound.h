#pragma once
#include <SDL_mixer.h>
#include "export.h"

namespace FGF
{
	/** \brief Music/Sound effect.
	 *
	 * Loads sound or music from file and plays it.
	 */
	class EXPORT Sound
	{
	public:
		/**
		 * Constructor.
		 * @param file Path to audio file
		 */
		Sound(const char* file);
		~Sound();
		
		/**
		 * Starts playing audio.
		 */
		void Play();
	private:
		Mix_Chunk* sample;
	};
}
