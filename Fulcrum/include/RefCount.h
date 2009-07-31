#pragma once

namespace FGF
{
	class RefCount
	{
	public:
		RefCount(void);
		virtual ~RefCount(void);

		void grab();
		bool release();
	private:
		int refCount;
	};
}