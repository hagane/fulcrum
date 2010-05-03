/* FGF Example 3
 * Textures, Sprites, Resources
 */

#include <Main.h>
#include <SceneManager.h>

//Let's do something even more intresting.
#include <Sprite.h>
#include <ResourceManager.h>
class ExampleScene: public FGF::SceneManager
{
public:
  //Let's set up our scene
  ExampleScene()
  {
    /*1. Load resources*/
    rs = new FGF::ResourceManager("./example3.rs");

    /*2. Create sprites*/
    sun = new FGF::Sprite(512,512,0,rs->getTexture(1));
    earth = new FGF::Sprite(256,256,0,rs->getTexture(2));
    moon = new FGF::Sprite(128,128,0,rs->getTexture(3));

    /* Earth orbits around sun.*/
    earth->setParent(sun);
    /* Moon orbits around Earth.*/
    moon->setParent(earth);

    sun->translate(400,300); //Putting sun in the centre.
    sun->setOrigin(0.5,0.5); 
    sun->scale(0.5,0.5);

    earth->translate(300,300);//Relative to the Sun.
    earth->setOrigin(0.5,0.5);
    earth->scale(0.5,0.5);

    moon->translate(150,150);//Relative to the Earth.
    moon->setOrigin(0.5,0.5);
    moon->scale(0.5,0.5);
    
    addNode(sun); //Adds the sun to scene. Earth and Moon will follow their parents.
    glClearColor(0,0,0,0); 
  };
  
  virtual void Update(float dt)
  {
    sun->rotate(10*dt);//Sun rotates and imposes it's rotation onto Earth.
    earth->rotate(-120*dt);//Earth rotates itself and imposes it's rotation onto Moon.
    moon->rotate(120*dt);//Moon just rotates %)
  };

private:
  FGF::Sprite* sun;
  FGF::Sprite* earth;
  FGF::Sprite* moon;
 
  FGF::ResourceManager* rs;
};

/*
 * Entry point.
 */
int SDL_main()
{
	//Create a FGF::Main object.
	FGF::Main* fgf = new FGF::Main(800, //horizontal resolution
				       600, //vertical resolution
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
