#pragma once

#include "Logger.h"
#include "OpenGL.h"
#include <FreeImage.h>
#include "export.h"

#define TEX_NAMES 256

namespace FGF
{
	class EXPORT Texture
	{
	public:
		Texture(const char* fname);
		Texture(const GLubyte* data, int w, int h, int bpp);
		virtual ~Texture(void);
		void Activate();
		int getXRes(){return xres;}
		int getYRes(){return yres;}

	protected:
		int size;
		int xres,yres;
		GLenum format;
		GLuint texname;

		static int GenNames();
		static GLuint GetName();

		static GLuint texnames[TEX_NAMES];
		static int next_name;
	};
}
