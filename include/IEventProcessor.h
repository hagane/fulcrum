#pragma once
#include <SDL.h>

namespace FGF
{
	/** \brief An interface for event processing class.
	 *
	 * Interface for a class that processes input events. To implement input
	 * processing, inherit from it, implement all methods and pass an
	 * instance to FGF::Main.
	 */
	class IEventProcessor
	{
	public:
		/**
		 * That method is called when a key is pressed.
		 * @param ev a structure containing information about event. Please refer to SDL documentation.
		 */
		virtual void KeyState(SDL_KeyboardEvent ev) = 0;

		/**
		* That method is called when a mouse is moved.
		* @param ev a structure containing information about event. Please refer to SDL documentation.
		*/
		virtual void MouseMove(SDL_MouseMotionEvent ev) = 0;

		/**
		* That method is called when a mouse button is pressed.
		* @param ev a structure containing information about event. Please refer to SDL documentation.
		*/
		virtual void MouseButton(SDL_MouseButtonEvent ev) = 0;
	};
}
