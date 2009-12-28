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
	/* TODO:
	 * Следует сделать эмиттер произвольно включаемым и выключаемым.
	 */
	class EXPORT ParticleEmitter: public SceneNode
	{
	public:
		/* TODO:
		 * Вот весь этот говна вагон параметров надо заменить
		 * одной няшной структуркой, я гарантирую это.
		 * */
		ParticleEmitter(SceneNode* parent, int aPartMax, float aEmitTTL, float aMinSpd, float aMaxSpd, Texture* aTex);
		virtual ~ParticleEmitter();

		virtual void Update(float dt);
		virtual void Render(int currPass);

		void Fire();
		void Stop();

	private:
		int part_max;
		float ttl;
		float min_spd;
		float max_spd;
		Texture* tex;

		std::deque<particle> particles;

		bool running;

		void UpdateParticles(float dt);
	};
}
