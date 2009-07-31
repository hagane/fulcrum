#include <stdio.h>
#include <tchar.h>
#include <iostream>

#include <Main.h>
#include <Texture.h>
#include <Sprite.h>
#include <Timer.h>

int _tmain()
{
	FGF::Main* app = new FGF::Main(1024,768,32,false);
	
	FGF::SceneManager* smgr = new FGF::SceneManager();
	app->setSceneManager(smgr);
	
	FGF::Texture* tex = new FGF::Texture("E:/Source/FGF/Debug/test.bmp");
	//FGF::Texture* tex2 = new FGF::Texture("E:/Source/FGF/Debug/1.png");

	//FGF::QuadSceneNode* quadbig = new FGF::TexturedQuadSceneNode(NULL,0,0,2000,2000, tex2);
	FGF::QuadSceneNode* quadsml = new FGF::Sprite(NULL,512,384,32,32,3, tex);
	quadsml->scale(10,10);
	((FGF::Sprite*)quadsml)->setAnimationSequence(3,5);
	/*FGF::QuadSceneNode* quadsml2 = new FGF::TexturedQuadSceneNode(quadbig,-256,192,200,200);
	FGF::QuadSceneNode* quadsml3 = new FGF::TexturedQuadSceneNode(quadbig,256,-192,200,200);
	FGF::QuadSceneNode* quadsml4 = new FGF::TexturedQuadSceneNode(quadbig,256,192,200,200);*/
	
	

	smgr->addNode(quadsml);
	
	app->start();
	delete app;
	delete smgr;
	return 0;
}