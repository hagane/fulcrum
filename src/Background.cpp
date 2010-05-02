#include "../include/Background.h"

namespace FGF
{
	Background::Background(float aParCoeff, Texture* aTex)
	{
		par_coeff = aParCoeff;
	}

	Background::~Background()
	{
	}

	void Background::Render()
	{
		glPushMatrix();

		//Суть всей этой магии в том, чтобы
		//а). смещать бэкграунд со скоростью меньшей, чем у
		//    фореграунда
		//б). рисовать бэкграунд за фореграундом.
		glTranslatef(dx*par_coeff,dy*par_coeff,0.5f);
		glRotatef(rot,0.0f,0.0f,1.0f);
		glScalef(sx,sy,1.0f);

		renderChildren();

		glPopMatrix();
	}
}
