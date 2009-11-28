#pragma once

namespace FGF
{
	/** \brief Interface for event-based input command.
	 *
	 */
	class ICommand
	{
	public:
		virtual void Execute(float dt) = 0;
	};
}
