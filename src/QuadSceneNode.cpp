#include "..\include\QuadSceneNode.h"

namespace FGF
{
	QuadSceneNode::QuadSceneNode(float x, float y, float w, float h)
	{
		vertex[0] = Vertex3f(0,0,1);
		vertex[1] = Vertex3f(0,h,1);
		vertex[2] = Vertex3f(w,h,1);
		vertex[3] = Vertex3f(w,0,1);

		color[0] = Color3f(1,1,1);
		color[1] = Color3f(1,1,1);
		color[2] = Color3f(1,1,1);
		color[3] = Color3f(1,1,1);

		this->translate(x,y);
	}

	QuadSceneNode::~QuadSceneNode(void)
	{
	}

	void QuadSceneNode::Render()
	{
		glPushMatrix();
		prepare();
		glDisable(GL_TEXTURE_2D);
		glBegin(GL_QUADS);
		for(int i = 0; i < 4; i++)
		{
			color[i].activate();
			vertex[i].render();
		}
		glEnd();
		renderChildren();
		glPopMatrix();
	}

	void QuadSceneNode::setOrigin(float ox, float oy)
	{
		float w = vertex[2].coords()[0];
		float h = vertex[2].coords()[1];
		for(int i = 0; i < 4; i++)
		{
			vertex[i].coords()[0] -= w*ox;
			vertex[i].coords()[1] -= h*oy;
		}
	}
}
