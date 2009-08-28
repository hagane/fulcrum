/*
Copyright (c) 2009, Dmitrii Savichev
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
Redistributions of source code must retain the above copyright notice,
this list of conditions and the following disclaimer.

Redistributions in binary form must reproduce the above copyright notice,
this list of conditions and the following disclaimer in the documentation
and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.*/

#pragma once
#include <string>
#include <stdio.h>
#include <sdl.h>
#include "OpenGL.h"
#include "Logger.h"
#include "SceneManager.h"
#include "Timer.h"
#include "IEventProcessor.h"
#include "export.h"

namespace FGF
{
	/**
	 * That is a main class of the engine.
	 * It runs main loop and captures events.
	 */
	class EXPORT Main
	{
	public:
		/**
		 * Constructor
		 * @param w,h desired resolution
		 * @param bpp desired color depth
		 * @param fullscreen set to true, if you want a fullscreen application, false otherwise
		 * */
		Main(int w, int h, int bpp, bool fullscreen);
		~Main(void);

		/**
		 * Starts main loop. Scene manager should be set before calling this.
		 */
		void start();

		/**
		 * Sets scene manager to use.
		 * @param new_smgr pointer to the scene manager that will be used
		 */
		void setSceneManager(SceneManager* new_smgr);

		/**
		 * Sets event processor to use.
		 * @param new_ep pointer to event processor
		 */
		void setEventProcessor(IEventProcessor* new_ep);

	private:
		SDL_Surface* mainSurface;
		SceneManager* smgr;
		Timer timer;
		int w,h;

		IEventProcessor* ep;

		bool SetVideoMode (int w, int h, int bpp, bool fullscreen);
	};
}
