#pragma once
#include "Texture.h"
#include <vector>
namespace FGF
{
	class MultiTexture :
		public Texture
	{
	public:
		MultiTexture(const char* fname, int w, int h, int aframes);
		virtual ~MultiTexture(void);

		void Activate();
		void setFrame(int frame);

	protected:
		int nFrames;
		int active;

		std::vector<Texture> frames;
	};
}
