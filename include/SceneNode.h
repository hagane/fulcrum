#pragma once
#include "OpenGL.h"
#include <list>
#include "RefCount.h"
#include "export.h"

namespace FGF
{
	/** \brief Base class for any object.
	 *
	 *	If you need really custom logic and/or render, you should inherit
	 *	from this and override Render and/or Update. When overriding, do
	 *	not forget to call updateChildren and renderChildren respectively.
	 *	
	 *	Render passes are not implemented yet.
	 */
	class EXPORT SceneNode: public RefCount
	{
	public:
		/**
		 * Constructor
		 * @param parent new node's parent node
		 * @param pass -- render pass (not implemented yet)
		 */
		SceneNode(SceneNode* parent, int pass = 0);
		virtual ~SceneNode(void);

		/**
		 * Adds a child to this node.
		 * @param child node to be added as child
		 */
		void addChild(SceneNode* child);

		/**
		 * Removes a child removed this node.
		 * @param child node to be removed
		 */
		void removeChild(SceneNode* child);

		/**
		 * Sets the parent of this node.
		 * @param parent new parent.
		 */
		void setParent(SceneNode* parent);

		/**
		 * Returns a parent of this node.
		 */
		SceneNode* getParent();

		/**
		 * Rotates a node counter-clockwise.
		 * @param a -- angle in radians.
		 */
		void rotate(float a);

		/**
		 * Translates a node.
		 * @param dx,dy distance in pixels in X and Y axis respectively
		 */
		void translate(float dx, float dy);

		/**
		 * Scales a node.
		 * @param sx,sy times to scale in X and Y axis respectively
		 */
		void scale(float sx, float sy);

		/**
		 * Calls Update on this node's children.
		 * @param dt time passed since the last frame in seconds
		 */
		void updateChildren(float dt);

		/**
		 * Calls Render on this node's children.
		 * @param curPass render pass
		 */
		void renderChildren(int curPass);

		/**
		 * If you need custom logic, you should override this method.
		 * @param dt time passed since the last frame in seconds
		 */
		virtual void Update(float dt);

		/**
		 * If you need custom logic, you should override this method.
		 * @param curPass render pass
		 */
		virtual void Render(int curPass);

		/**
		 * Prepares node for rendering.
		 * @param curPass render pass
		 */
		void prepare(int curPass);

		/**
		 * Changes pass, on which the node has to be rendered.
		 */
		void setPass(int newPass);

	protected:
		/**
		 * List of this node's children.
		 */
		std::list<SceneNode*> child;

		/**
		 * This node's parent.
		 */
		SceneNode* parent;

		/**
		 * Set this to false if node should not be rendered.
		 */
		bool render;

		/**
		 * A pass on which the node has to be rendered.
		 */
		int pass;

		/**
		 * Rotation of the node.
		 */
		float rot;

		/**
		 * Coords of the node.
		 */
		float dx, dy;

		/**
		 * Scale of the node.
		 */
		float sx, sy;
	};
}
