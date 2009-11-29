#pragma once
#include <map>
#include <SDL.h>
#include "export.h"
#include "ICommand.h"

namespace FGF
{
	/** \brief Centralised input.
	 *
	 */
	class EXPORT InputManager
	{
	public:
		InputManager();
		~InputManager();
		
		/**
		 * @param key Key code. Refer to SDL docs for key
		 * codes enumeration.
		 * @return True if key is pressed, false otherwise.
		 */
		bool getKeyState(SDLKey key);
		/**
		 * @return Mouse X-coord.
		 */
		int getMouseX();
		/**
		 * @return Mouse Y-coord.
		 */
		int getMouseY();
		/**
		 * @return Mouse X-coord difference since the last call.
		 */
		int getMouseXRel();
		/**
		 * @return Mouse Y-coord difference since the last call.
		 */		
		int getMouseYRel();
		/**
		 * @param button Mouse button number. Refer to SDL docs
		 * for enumeration.
		 * @return True if button is pressed, false otherwise.
		 */
		bool getMouseButtonState(int button);

		/**
		 * @param key Key code. Refer to SDL docs for key
		 * codes enumeration.
		 * @param cmd Command to execute when key is pressed.
		 */
		void setCommand_OnKeyPress(SDLKey key,ICommand* cmd);

		void Update(float dt);

	protected:
		std::map<SDLKey,ICommand*> key_press;
	};
}
