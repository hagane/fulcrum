#include "../include/TextSceneNode.h"
namespace FGF
{
	TextSceneNode::TextSceneNode(SceneNode* parent, Font* f)
		: SceneNode(parent,0)
	{
		font = f;
		str = L"";
	}

	TextSceneNode::~TextSceneNode()
	{
	}

	void TextSceneNode::setString(std::wstring s)
	{
		str = s;
	}

	void TextSceneNode::Render(int curPass)
	{
		glPushMatrix();
		prepare(curPass);
		const wchar_t* ch = str.c_str();
		int x_off = 0;
		glBegin(GL_QUADS);
			while(*ch != 0)
			{
				font->renderChar(*ch,x_off,0);
				x_off += font->getCharWidth(*ch);
				ch++;
			}
		glEnd();
		renderChildren(curPass);
		glPopMatrix();
	}
}
