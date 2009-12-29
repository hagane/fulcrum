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
		class PEParameters
		{
		public:
			float Part_TTL;
			float Emit_Period;
			float Direction;//В радианах!
			float DispAngle;//Обязательно в радианах!
			float MinSpd;
			float MaxSpd;
		};

		ParticleEmitter(SceneNode* parent, PEParameters* aParms, Texture* aTex);
		virtual ~ParticleEmitter();

		virtual void Update(float dt);
		virtual void Render(int currPass);

		void Fire();
		void Stop();

	private:
		Texture* tex;
		std::deque<particle> particles;

		bool active;
		PEParameters* parms;
		float T;

		void UpdateParticles(float dt);
		void EmitParticle();
		void ClearDeadParticles();
	};
}
