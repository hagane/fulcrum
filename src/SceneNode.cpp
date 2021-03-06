#include "..\include\SceneNode.h"

namespace FGF
{
	SceneNode::SceneNode()
	{
		parent = NULL;
		rot = 0.0f;
		dx = dy = 0.0f;
		sx = sy = 1.0f;
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
		else if(this->parent != NULL) parent->removeChild(this);
		this->parent = parent;
	}

	void SceneNode::rotate(float a)
	{
		rot += a;
	}

	float SceneNode::getRotation()
	{
		return rot;
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

	void SceneNode::renderChildren()
	{
		std::list<SceneNode*>::iterator end = child.end();
		for(std::list<SceneNode*>::iterator i = child.begin();
			i != end; i++)
		{
			(*i)->Render();
		}
		return;
	}

	void SceneNode::Render()
	{
		glPushMatrix();
		prepare();
		renderChildren();
		glPopMatrix();
	}

	void SceneNode::prepare()
	{
		glTranslatef(dx,dy,0.0f);
		glRotatef(rot,0.0f,0.0f,1.0f);
		glScalef(sx,sy,1.0f);
	}

	float SceneNode::getGlobalCoord_X()
	{
		if(parent != NULL)
		{
			float x = dx * cos(parent->getRotation() * M_PI/180) - dy * sin(parent->getRotation() * M_PI/180);
			return (x + parent->getGlobalCoord_X());
		}
		else return dx;
	}

	float SceneNode::getGlobalCoord_Y()
	{
		if(parent != NULL)
		{
			float y = dx * sin(parent->getRotation() * M_PI/180) + dy * cos(parent->getRotation() * M_PI/180);
			return (y + parent->getGlobalCoord_Y());
		}
		else return dy;
	}

	float SceneNode::getGlobalRotation()
	{
		if(parent != NULL) return (rot + parent->getGlobalRotation());
		else return rot;
	}
}
