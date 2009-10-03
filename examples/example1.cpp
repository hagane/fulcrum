/* FGF Example 1
 * Basic application
 */

#include <Main.h>
#include <SceneManager.h>

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
	FGF::SceneManager* sm = new FGF::SceneManager();

	//Tell the engine about scene manager.
	fgf->setSceneManager(sm);

	//Everything's ready, let's go!
	fgf->start();

	//OK, we're out of the main loop, and we can exit.
	exit(0);
}
