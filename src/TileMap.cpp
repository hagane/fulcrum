#include "../include/TileMap.h"

namespace FGF
{
	TileMap::TileMap(int aW, int aH, int aTileW, int aTileH, Texture* aTex, const char* aFName)
		:Sprite(aTileW, aTileH, 0, aTex)
	{
		Logger* log = Logger::getInstance();
		if((aW == 0) || (aH == 0))
		{
			log->Log("Cannot create zero width or heigth tile map.");
		}
		else
		{
			w = aW;
			h = aH;
			size = w*h;

			tile_w = aTileW;
			tile_h = aTileH;

			std::ifstream fs;
			fs.open(aFName);
			
			tiles = new int[size];
			for(int i = 0; i < size; i++) tiles[i] = 0;

			int i = 0;
			while(i < size)
			{
				fs >> tiles[i];
				i++;
				if(fs.eof() && (i < size))
				{
					log->Log((std::string("Unexpected EOF in ") + aFName).c_str());
					break;
				}
			}
		}
	}

	TileMap::~TileMap()
	{
		delete[] tiles;
	}

	void TileMap::Render()
	{
		glPushMatrix();
		prepare();

		if(tex != NULL)
		{
			glEnable(GL_TEXTURE_2D);
			tex->Activate();
			glBegin(GL_TRIANGLE_STRIP);
			for(int y = 0; y < h; y++)
			{
				glPushMatrix();
				for(int x = 0; x < w; x++)
				{
					for(int i = 0; i < 4; i++)
					{
						color[i].activate();
						glTexCoord2f(texCoord1[i],texCoord2[i]);
						vertex[i].render();
					}
					glTranslatef(tile_w,0,0);
				}
				glPopMatrix();
				glTranslatef(0,tile_h,0);
			}
			glEnd();
		}
		renderChildren();
		glPopMatrix();
	}
}
