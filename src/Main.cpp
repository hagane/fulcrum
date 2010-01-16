#include "..\include\Main.h"

namespace FGF
{
	Main::Main(int w, int h, int bpp, bool fullscreen)
	{
		Logger* logger = Logger::getInstance();
		logger->Log("SDL Init:");
		bool success = true;
		if(SDL_Init(SDL_INIT_VIDEO) == -1)
		{
			logger->Log("Video: failure");
			success = false;
		}
		else
		{
			logger->Log("Video: success");
		}

		if(SDL_InitSubSystem(SDL_INIT_AUDIO) == -1)
		{
			logger->Log("Audio: failure");
			success = false;
		}
		else
		{
			logger->Log("Audio: success");
			Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,4096);
		}
		if(!success)
		{
			logger->Log("SDL init failure. Shutting down.");
			SDL_Quit();
			exit(1);
		}

		char tmp[5];
		
		std::string log = "Setting up video mode: ";
		sprintf_s(tmp,5,"%i",w);
		log += tmp;
		log += "x";
		sprintf_s(tmp,5,"%i",h);
		log += tmp;
		log += " ";
		sprintf_s(tmp,5,"%i",bpp);
		log += tmp;
		log += "bpp ";
		log += fullscreen?"Fullscreen":"Windowed";
		
		logger->Log(log.c_str());
		SetVideoMode(w,h,bpp,fullscreen);
	}

	Main::~Main(void)
	{
		Logger::getInstance()->Log("SDL shutdown.");
		Logger::shutdown();
		Mix_CloseAudio();
		SDL_Quit();
	}

	void Main::start()
	{
		Logger* logger = Logger::getInstance();
		SDL_Event ev;
		float dt = 1.0f/60.0f;
		while(1)
		{
			timer.start();

			if(SDL_PollEvent(&ev) != 0)
			{
				if(ev.type == SDL_QUIT)
				{
					logger->Log("SDL_QUIT received. Shutting down.");
					break;
				}
			}

			glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
			smgr->Update(dt);
			smgr->Render();

			SDL_GL_SwapBuffers();
			timer.stop();
			dt = timer.getDelta();
		}
	}

	bool Main::SetVideoMode (int w, int h, int bpp, bool fullscreen)
	{	
		Logger* logger = Logger::getInstance();
		SDL_GL_SetAttribute( SDL_GL_RED_SIZE, 8 );
		SDL_GL_SetAttribute( SDL_GL_GREEN_SIZE, 8 );
		SDL_GL_SetAttribute( SDL_GL_BLUE_SIZE, 8 );
		SDL_GL_SetAttribute( SDL_GL_ALPHA_SIZE, 8 );
		SDL_GL_SetAttribute( SDL_GL_DEPTH_SIZE, 24 );
		SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );

		this->w = w;
		this->h = h;

		Uint32 flags = SDL_ANYFORMAT|SDL_OPENGL;
		if(fullscreen)
		{
			flags = flags | SDL_FULLSCREEN;
		}

		if ( SDL_SetVideoMode( w, h, bpp, flags ) == 0 )
		{
			std::string msg;
			msg = "Failed setting video mode: ";
			msg += SDL_GetError();
			logger->Log(msg.c_str());
			return false;
		}

		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LESS);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
		glEnable(GL_ALPHA_TEST);
		glAlphaFunc(GL_GREATER,0.1f);

		glLoadIdentity();
		glViewport(0,0,w,h);
		glOrtho(0,w,0,h,-1,1);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		logger->Log("OpenGL Info:");

		//Немного чорной сишной магии
		const GLubyte* gl_version = glGetString(GL_VERSION);
		const GLubyte* gl_vendor = glGetString(GL_VENDOR);
		const GLubyte* gl_renderer = glGetString(GL_RENDERER);
		char gl_info[256];
		sprintf_s(gl_info,256,"%s %s %s",gl_version, gl_vendor, gl_renderer);
		logger->Log(gl_info);

		glClearColor(0.5,0.5,0.5,0.5);
		glClearDepth(1);

		GLenum gl_err = glGetError();
		const char* err_string;
		switch(gl_err)
		{
			case GL_NO_ERROR:
				err_string = "GL Init: Success!"; break;
			default:
				err_string = reinterpret_cast<const char*>(gluErrorString(gl_err)); break;
		}
		logger->Log(err_string);
		return true;
	}

	void Main::setSceneManager(SceneManager *new_smgr)
	{
		smgr = new_smgr;
	}
}
