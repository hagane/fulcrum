#include "TexturedQuadSceneNode.h"
namespace FGF
{
	TexturedQuadSceneNode::TexturedQuadSceneNode(SceneNode* parent, float x, float y, float w, float h, Texture* aTex):
		QuadSceneNode(parent,x,y,w,h)
	{
		tex = aTex;

		this->setOrigin(0.5,0.5);
		texCoord1 = new float[4];
		texCoord1[0] = 1.0f;
		texCoord1[1] = 1.0f;
		texCoord1[2] = 0.0f;
		texCoord1[3] = 0.0f;

		texCoord2 = new float[4];
		texCoord2[0] = 0.0f;
		texCoord2[1] = 1.0f;
		texCoord2[2] = 1.0f;
		texCoord2[3] = 0.0f;
	}

	TexturedQuadSceneNode::~TexturedQuadSceneNode(void)
	{
		delete[] texCoord1;
		delete[] texCoord2;
	}

	void TexturedQuadSceneNode::Render(int curPass)
	{
		glPushMatrix();
		prepare(curPass);

		if(render && (tex != NULL))
		{
			glEnable(GL_TEXTURE_2D);
			tex->Activate();
			glBegin(GL_QUADS);
				for(int i = 0; i < 4; i++)
				{
					color[i].activate();
					vertex[i].render();
					glTexCoord2f(texCoord1[i],texCoord2[i]);
				}
			glEnd();
		}
		renderChildren(curPass);
		glPopMatrix();
	}
}