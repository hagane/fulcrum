#include "Texture.h"
#include <memory.h>

namespace FGF
{
	Texture::Texture(const char* fname)
	{
		Logger::getInstance()->Log((std::string("Loading texture: ") + std::string(fname)).c_str());
		FREE_IMAGE_FORMAT fi_fmt = FIF_UNKNOWN;
		dib = 0;

		fi_fmt = FreeImage_GetFileType(fname,0);
		if(fi_fmt == FIF_UNKNOWN) Logger::getInstance()->Log((std::string(fname)+std::string(": unknown image type.")).c_str());

		if(FreeImage_FIFSupportsReading(fi_fmt))
			dib = FreeImage_Load(fi_fmt, fname);
		else
			Logger::getInstance()->Log((std::string(fname)+std::string(": unsupported format.")).c_str());

		if(!dib)
			Logger::getInstance()->Log((std::string(fname)+std::string(": failed to load.")).c_str());

		FreeImage_SetTransparent(dib, true);

		xres = FreeImage_GetWidth(dib);
		yres = FreeImage_GetHeight(dib);

		size = xres*yres;
		bool has_alpha = FreeImage_IsTransparent(dib);
		int bytespp = has_alpha?4:3;
		texdata = new GLubyte[size*bytespp];
		int ix = 0;
		for(int y = 0; y < yres; y++)
			for (int x = 0; x < xres; x++)
			{
				RGBQUAD rgba;
				FreeImage_GetPixelColor(dib, x, y, &rgba);
				texdata[ix] = rgba.rgbRed;
				texdata[ix+1] = rgba.rgbGreen;
				texdata[ix+2] = rgba.rgbBlue;
				if(bytespp == 4) texdata[ix+3] = rgba.rgbReserved;
				ix += bytespp;
			}
		FreeImage_Unload(dib);
		if(bytespp == 3) format = GL_RGB;
		if(bytespp == 4) format = GL_RGBA;
	}

	Texture::Texture(const GLubyte* data, int w, int h, int bpp)
	{
		size = w*h;
		xres = w;
		yres = h;
		texdata = new GLubyte[size*(bpp/8)];
		memcpy(texdata, data, size*(bpp/8));
	}

	void Texture::Activate()
	{
		glEnable(GL_TEXTURE_2D);
		glTexImage2D(GL_TEXTURE_2D,0,format,xres,yres,0,format,GL_UNSIGNED_BYTE,texdata);
	}

	Texture::~Texture(void)
	{
		delete[] texdata;
	}
}
