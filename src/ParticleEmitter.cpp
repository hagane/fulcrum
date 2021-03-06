#include "../include/ParticleEmitter.h"

namespace FGF
{
	ParticleEmitter::ParticleEmitter(PEParameters* aParms, Texture* aTex)
	{
		parms = aParms;
		tex = aTex;

		srand((unsigned)time(NULL));

		bool active = false;
		T = parms->Emit_Period;
	}

	ParticleEmitter::~ParticleEmitter()
	{
		particles.clear();
	}

	void ParticleEmitter::Update(float dt)
	{
		if(active)
		{
			if(T <= 0)
			{
				EmitParticle();
				T = parms->Emit_Period;
			}
			else
			{
				T -= dt;
			}
		}

		UpdateParticles(dt);
		ClearDeadParticles();
		updateChildren(dt);//Не знаю, нахуй, но пусть будет, лол!
	}

	void ParticleEmitter::Render()
	{
		glPushMatrix();
		prepare();
		tex->Activate();
		float tex_x = tex->getXRes();
		float tex_y = tex->getYRes();
		glBegin(GL_QUADS);
		for(std::deque<particle>::iterator it = particles.begin(); it != particles.end(); it++)
		{
			float x = it->x;
			float y = it->y;
			glTexCoord2f(0,0);
			glVertex3f(x - tex_x/2, y - tex_y/2, 0);

			glTexCoord2f(1,0);
			glVertex3f(x + tex_x/2, y - tex_y/2, 0);

			glTexCoord2f(1,1);
			glVertex3f(x + tex_x/2, y + tex_y/2, 0);

			glTexCoord2f(0,1);
			glVertex3f(x - tex_x/2, y + tex_y/2, 0);
		}
		glEnd();

		renderChildren();
		glPopMatrix();
	}

	void ParticleEmitter::Fire()
	{
		active = true;
	}

	void ParticleEmitter::Stop()
	{
		active = false;
	}

	void ParticleEmitter::UpdateParticles(float dt)
	{
		for(std::deque<particle>::iterator it = particles.begin(); it != particles.end(); it++)
		{
			it->x = it->x + (it->spd_x)*dt;
			it->y = it->y + (it->spd_y)*dt;
			it->ttl -= dt;
		}	
	}

	void ParticleEmitter::EmitParticle()
	{
			float speed_range = parms->MaxSpd - parms->MinSpd;
			float spd = (speed_range *((float)(rand()%101)) / 100) + parms->MinSpd;
			float angle = parms->Direction + (((float)(rand()%101 - 50)/100) * parms->DispAngle);
			particle new_part;
			new_part.x = 0;//Относительно
			new_part.y = 0;//эмиттера
			new_part.spd_x = spd* cos(angle);
			new_part.spd_y = spd* sin(angle);
			new_part.ttl = parms->Part_TTL;
			particles.push_back(new_part);
	}

	void ParticleEmitter::ClearDeadParticles()
	{
		/* TODO: 
		 * Контейнерная магия!
		 * Заменить на что-то более разумное.
		 */
		if(!particles.empty()) while((particles.begin()->ttl) <= 0.0f) particles.pop_front();
	}
}
