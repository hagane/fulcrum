// MainTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	FGF::Main* app = new FGF::Main(1024,768,32,false);
	glViewport(0,0,1024,768);
	glClearColor(0,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT);
	glOrtho(0,1,0,1,-1,1);

	glBegin(GL_POLYGON);
		glColor3f(1,1,1);
		glVertex3f(0.25,0.25,0);
		glColor3f(1,0,0);
		glVertex3f(0.75,0.25,0);
		glColor3f(0,1,0);
		glVertex3f(0.75,0.75,0);
		glColor3f(0,0,1);
		glVertex3f(0.25,0.75,0);
	glEnd();
	app->start();
	delete app;
	return 0;
}

