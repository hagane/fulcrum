#include <sdl.h>

namespace FGF
{
	class IEventProcessor
	{
	public:
		virtual bool ProcessEvent(SDL_Event e) = 0;
	};
}