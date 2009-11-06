#include "../include/InputManager.h"

namespace FGF
{
	InputManager::InputManager()
	{
	}

	InputManager::~InputManager()
	{
	}

	bool InputManager::getKeyState(SDLKey key)
	{
		return SDL_GetKeyState(NULL)[key];
	}

	int InputManager::getMouseX()
	{
		int x;
		SDL_GetMouseState(&x,NULL);
		return x;
	}
	int InputManager::getMouseY()
	{
		int y;
		SDL_GetMouseState(NULL,&y);
		return y;
	}

	int InputManager::getMouseXRel()
	{
		int x;
		SDL_GetRelativeMouseState(&x,NULL);
		return x;
	}
	int InputManager::getMouseYRel()
	{
		int y;
		SDL_GetRelativeMouseState(NULL,&y);
		return y;
	}

	bool InputManager::getMouseButtonState(int button)
	{
		return (SDL_GetMouseState(NULL,NULL)&SDL_BUTTON(button));
	}
}
