#include "RefCount.h"

namespace FGF
{
	RefCount::RefCount(void)
	{
		refCount = 1;
	}

	RefCount::~RefCount(void)
	{
	}

	void RefCount::grab()
	{
		refCount++;
	}

	bool RefCount::release()
	{
		refCount--;
		if(refCount <= 0)
		{
			delete this;
			return true;
		}
		return false;
	}
}