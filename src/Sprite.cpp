#include "Sprite.h"
namespace FGF
{
	Sprite::Sprite(SceneNode* parent, float x, float y, float w, float h, float fps, Texture* aTex)
		:TexturedQuadSceneNode(parent,x,y,w,h,aTex)
	{
		framesX = (aTex->getXRes()/w);
		framesY = (aTex->getYRes()/h);
		frames = framesX*framesY;
		tcW = w/aTex->getXRes();
		tcH = h/aTex->getYRes();
		frame = 0;
		TTL = 1.0/fps;
		FPS = fps;
		setFrame(0);
		frame = 0;

		start = 0;
		end = frames-1;
	}

	Sprite::~Sprite(void)
	{
	}

	void Sprite::Update( float dt )
	{
		if(FPS > 0)
		{
			TTL -= dt;
			if(TTL <= 0.0f)
			{
				frame++;
				if(frame > end) frame = start;
				setFrame(frame);
				TTL = 1.0/FPS;
			}
		}
	}

	void Sprite::setAnimationSequence( int aStart, int aEnd )
	{
		if ((aStart < 0) || (aEnd >= frames))
			return Logger::getInstance()->Log("Frame sequence exceeds [0..(frames-1)].");
		if (aStart > aEnd)
			return Logger::getInstance()->Log("Sequence start > sequence end. FAIL.");
		start = aStart;
		frame = start;
		setFrame(start);
		end = aEnd;
	}

	void Sprite::setFrame( int next )
	{
		if (next >= frames)
			return Logger::getInstance()->Log("Frame number too large.");
		float tc_origin_x = 0.0f;
		float tc_origin_y = 1.0f;

		while(next > (framesX-1))
		{
			next -= framesX;
			tc_origin_y -= tcH;
		}

		while (next > 0)
		{
			tc_origin_x += tcW;
			next--;
		}
		
		texCoord1[0] = tc_origin_x + tcW;
		texCoord1[1] = tc_origin_x + tcW;
		texCoord1[2] = tc_origin_x;
		texCoord1[3] = tc_origin_x;

		texCoord2[0] = tc_origin_y - tcH;
		texCoord2[1] = tc_origin_y;
		texCoord2[2] = tc_origin_y;
		texCoord2[3] = tc_origin_y - tcH;
	}
}