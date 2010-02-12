#pragma once
#include <fstream>

#include "OpenGL.h"
#include "Logger.h"
#include "Texture.h"
#include "Sprite.h"

namespace FGF
{
	class TileMap: public Sprite
	{
	public:
		TileMap(int aW, int aH, int aTileW, int aTileH, Texture* aTex, const char* aFName);
		virtual ~TileMap();

		virtual void Render();
	protected:
		int w;
		int h;

		float tile_w;
		float tile_h;

		int size;
		int* tiles;
	};
}
