#pragma once

#include <deque>
#include <stdlib.h>
#include <time.h>

#include "OpenGL.h"
#include "SceneNode.h"
#include "Texture.h"


namespace FGF
{
	struct particle
	{
		float x;
		float y;
		float spd_x;
		float spd_y;
	};

	class EXPORT ParticleEmitter: public SceneNode
	{
	public:
		ParticleEmitter(SceneNode* parent, int aPartMax, float aEmitTTL, float aMinSpd, float aMaxSpd, Texture* aTex);
		virtual ~ParticleEmitter();

		virtual void Update(float dt);
		virtual void Render(int currPass);

	private:
		int part_max;
		float ttl;
		float min_spd;
		float max_spd;
		Texture* tex;

		std::deque<particle> particles;
	};
}
