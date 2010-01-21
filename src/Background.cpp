#include "../include/Background.h"

namespace FGF
{
	Background::Background(float aParCoeff, Texture* aTex)
	{
		par_coeff = aParCoeff;
		tex = aTex;

		w = aTex->getXRes();
		h = aTex->getYRes();
	}

	Background::~Background()
	{
	}

	void Background::Render()
	{
		tex->Activate();
		glPushMatrix();

		glTranslatef(dx*par_coeff,dy*par_coeff,0.5f);
		glRotatef(rot,0.0f,0.0f,1.0f);
		glScalef(sx,sy,1.0f);

		glColor3f(1.0,1.0,1.0);

		glBegin(GL_QUADS);
			glTexCoord2f(0.0f,0.0f);
			glVertex3f(0.0f,0.0f,-0.5f);

			glTexCoord2f(1.0f,0.0f);
			glVertex3f(w,0.0f,-0.5f);

			glTexCoord2f(1.0f,1.0f);
			glVertex3f(w,h,-0.5f);

			glTexCoord2f(0.0f,1.0f);
			glVertex3f(0.0f,h,-0.5f);
		glEnd();
		glPopMatrix();
	}
}
