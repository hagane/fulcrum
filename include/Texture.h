#pragma once

#include "Logger.h"
#include "OpenGL.h"
#include "export.h"
#include <FreeImage.h>
#include <sstream>

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

		static GLuint GetName();
	};
}
