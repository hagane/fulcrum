#pragma once
#include <sdl.h>

namespace FGF
{
	class InputManager
	{
	public:
		InputManager();
		~InputManager();

		bool getKeyState(SDLKey key);
		int getMouseX();
		int getMouseY();
		int getMouseXRel();
		int getMouseYRel();
		bool getMouseButtonState(int button);
	};
}
