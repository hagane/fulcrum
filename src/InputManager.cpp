#include "../include/InputManager.h"

namespace FGF
{
	InputManager::InputManager()
	{
	}

	InputManager::~InputManager()
	{
		key_press.clear();
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

	void InputManager::setCommand_OnKeyPress(SDLKey key,ICommand* cmd)
	{
		key_press[key] = cmd;
	}

	void InputManager::Update(float dt)
	{
		for(std::map<SDLKey,ICommand*>::iterator it = key_press.begin();
				it != key_press.end(); it++)
		{
			if(getKeyState(it->first)) it->second->Execute(dt);
		}
	}
}
