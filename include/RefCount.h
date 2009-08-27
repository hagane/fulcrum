#pragma once
#include "export.h"

namespace FGF
{
	class EXPORT RefCount
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
