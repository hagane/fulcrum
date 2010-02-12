#pragma once
#include "OpenGL.h"
#include "QuadSceneNode.h"
#include "Texture.h"
#include <vector>
#include "export.h"

namespace FGF
{
	/** \brief Animated sprite
	 *
	 */
	class EXPORT Sprite :
		public QuadSceneNode
	{
	public:
		/**
		 * Constructor.
		 *
		 * @param parent Sprite's parent node.
		 * @param w,h Width and height of sprite and size of one frame in pixels.
		 * @param fps Number of frame switches in one second. Use 0 if you want to switch frames manually.
		 * @param aTex Sprite's texture.
		 */
		Sprite(float w, float h, float fps, Texture* aTex);
		virtual ~Sprite(void);

		/**
		 * If FPS > 0, this method will update Sprite's internal timer,
		 * and do a frame change if necessary.
 		 * Animation will cycle consecutively through set sequence.
		 */
		virtual void Update(float dt);
		virtual void Render();

		/**
		 * Sets start/end frames for animation.
		 * @param aStart First frame in sequence.
		 * @param aEnd Final frame in sequence.
		 */
		void setAnimationSequence(int aStart, int aEnd);

		/**
		 * Sets current frame. Frames are numbered from left to right and top to bottom.
		 * @param next Frame number to be set as current.
		 */
		void setFrame(int next);
		
	protected:
		int start;
		int end;
		int frame;
		int frames;

		float tcW;
		float tcH;

		int framesX;
		int framesY;

		float TTL;
		float FPS;

		Texture* tex;
		float* texCoord1;
		float* texCoord2;
	};
}
