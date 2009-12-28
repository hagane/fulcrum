#include "../include/ParticleEmitter.h"

namespace FGF
{
	ParticleEmitter::ParticleEmitter(SceneNode* parent, int aPartMax, float aEmitTTL, float aMinSpd, float aMaxSpd, Texture* aTex)
		:SceneNode(parent)
	{
		part_max = aPartMax;
		ttl = aEmitTTL;
		min_spd = aMinSpd;
		max_spd = aMaxSpd;
		tex = aTex;
		srand((unsigned)time(NULL));

		bool running = false;
	}

	ParticleEmitter::~ParticleEmitter()
	{
		particles.clear();
		/* TODO:
		 * Запилить "перевешивание" дочерних
		 * нод на родителя. А может и нет.
		 * */
	}

	void ParticleEmitter::Update(float dt)
	{
		if(particles.size() <= part_max)
		{
			/* TODO:
			 * Здесь надо исправить рандомизацию скорости.
			 * Или переписать нахуй. Лучше переписать.
			 * */
			float speed_range = max_spd - min_spd;
			float x_spd = (speed_range *((1+(rand()%(100)))) / 100) + min_spd;
			float y_spd = (speed_range *((1+(rand()%(100)))) / 100) + min_spd;
			particle new_part;
			new_part.x = 0;//Относительно
			new_part.y = 0;//эмиттера
			new_part.spd_x = x_spd;
			new_part.spd_y = y_spd;
			particles.push_front(new_part);
		}
		else
		{
			particles.pop_back();
		}

		ttl -= dt;
		
		UpdateParticles(dt);
		updateChildren(dt);//Не знаю, нахуй, но пусть будет, лол!
	}

	void ParticleEmitter::Render(int currPass)
	{
		prepare(currPass);
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

		renderChildren(currPass);
	}

	void ParticleEmitter::UpdateParticles(float dt)
	{
		for(std::deque<particle>::iterator it = particles.begin(); it != particles.end(); it++)
		{
			it->x = it->x + (it->spd_x)*dt;
			it->y = it->y + (it->spd_y)*dt;
		}
	}
}
