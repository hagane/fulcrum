#pragma once

#include <deque>
#include <stdlib.h>
#include <time.h>
#include <math.h>

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
		float ttl;
	};

	class EXPORT ParticleEmitter: public SceneNode
	{
	public:
		ParticleEmitter(SceneNode* parent, Parameters* aParms, Texture* aTex);
		virtual ~ParticleEmitter();

		virtual void Update(float dt);
		virtual void Render(int currPass);

		void Fire();
		void Stop();

		class Parameters
		{
		public:
			float Part_TTL;
			float Direction;//В радианах!
			float DispAngle;//Обязательно в радианах!
			float MinSpd;
			float MaxSpd;
		}

	private:
		Texture* tex;
		std::deque<particle> particles;

		bool active;
		Parameters* parms;

		void UpdateParticles(float dt);
		void EmitParticle();
		void ClearDeadParticles();
	};
}
