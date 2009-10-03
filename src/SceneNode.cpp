#include "..\include\SceneNode.h"

namespace FGF
{
	SceneNode::SceneNode(SceneNode* parent, int pass)
	{
		this->parent = NULL;
		setParent(parent);
		rot = 0.0f;
		dx = dy = 0.0f;
		sx = sy = 1.0f;
		this->pass = pass;
	}

	SceneNode::~SceneNode(void)
	{
		for(std::list<SceneNode*>::iterator i = child.begin(); i != child.end(); i++)
		{
			(*i)->release();
		}
		child.clear();
	}

	void SceneNode::addChild(SceneNode* child)
	{
		child->grab();
		if(child->getParent() != NULL)
		{
			child->getParent()->removeChild(child);
		}
		this->child.push_back(child);
	}

	void SceneNode::removeChild(FGF::SceneNode *child)
	{
		this->child.remove(child);
		child->release();
	}

	void SceneNode::setParent(SceneNode *newParent)
	{
		if(newParent != NULL) newParent->addChild(this);
		if(this->parent != NULL) this->parent->removeChild(this);
		this->parent = parent;
		
	}

	void SceneNode::rotate(float a)
	{
		rot += a;
	}

	void SceneNode::translate(float dx, float dy)
	{
		this->dx += dx;
		this->dy += dy;
	}

	void SceneNode::scale(float sx, float sy)
	{
		this->sx *= sx;
		this->sy *= sy;
	}

	SceneNode* SceneNode::getParent()
	{
		return parent;
	}

	void SceneNode::updateChildren(float dt)
	{
		std::list<SceneNode*>::iterator end = child.end();
		for(std::list<SceneNode*>::iterator i = child.begin();
			i != end; i++)
		{
			(*i)->Update(dt);
		}
		return;
	}

	void SceneNode::Update(float dt)
	{
		this->updateChildren(dt);
	}

	void SceneNode::renderChildren(int curPass)
	{
		std::list<SceneNode*>::iterator end = child.end();
		for(std::list<SceneNode*>::iterator i = child.begin();
			i != end; i++)
		{
			(*i)->Render(curPass);
		}
		return;
	}

	void SceneNode::Render(int curPass)
	{
		glPushMatrix();
		prepare(curPass);
		renderChildren(curPass);
		glPopMatrix();
	}

	void SceneNode::prepare(int curPass)
	{
		glTranslatef(dx,dy,0.0f);
		glRotatef(rot,0.0f,0.0f,1.0f);
		glScalef(sx,sy,1.0f);
		if(pass == curPass) render = true;
		else render = false;
		return;
	}

	void SceneNode::setPass(int newPass)
	{
		pass = newPass;
	}

	float SceneNode::getGlobalCoord_X()
	{
		if(parent != NULL) return (dx + parent->getGlobalCoord_X());
		else return dx;
	}

	float SceneNode::getGlobalCoord_Y()
	{
		if(parent != NULL) return (dy + parent->getGlobalCoord_X();
		else return dy;
	}
}
