#pragma once
#include <sdl.h>

namespace FGF
{
	class IEventProcessor
	{
	public:
		virtual void KeyState(SDL_KeyboardEvent ev) = 0;
		virtual void MouseMove(SDL_MouseMotionEvent ev) = 0;
		virtual void MouseButton(SDL_MouseButtonEvent ev) = 0;
	};
}
