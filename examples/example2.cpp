/* FGF Example 2
 * SceneManager
 */

#include <Main.h>
#include <SceneManager.h>

//Ok, let's do something intresting
#include <QuadSceneNode.h>
class ExampleScene: public FGF::SceneManager
{
public:
	//Let's set up our scene
	ExampleScene()
	{
		big = new FGF::QuadSceneNode(320,240,100,100);//Big quad!
		small1 = new FGF::QuadSceneNode(-100,-100,20,20);//Small one
		small2 = new FGF::QuadSceneNode(100,100,20,20);//And another

		addNode(big);//Now we add this quad to scene graph
		big->addChild(small1);//and small ones
		big->addChild(small2);//wil be big quad's children
		big->setOrigin(0.5,0.5);
	};

	virtual void Update(float dt)
	{
		big->rotate(60*dt);//That means 60 degrees CCW per second.
	};

private:
	FGF::QuadSceneNode* big;
	FGF::QuadSceneNode* small1;
	FGF::QuadSceneNode* small2;	
};

/*
 * Entry point.
 */
int SDL_main()
{
	//Create a FGF::Main object.
	FGF::Main* fgf = new FGF::Main(640, //horizontal resolution
								   480, //vertical resolution
								   32, //Color depth in bits
								   false); //Windowed.Use true for fullscreen.
	//Create a scene manager.
	FGF::SceneManager* sm = new ExampleScene();

	//Tell the engine about scene manager.
	fgf->setSceneManager(sm);

	//Everything's ready, let's go!
	fgf->start();

	//OK, we're out of the main loop, and we can exit.
	exit(0);
}
