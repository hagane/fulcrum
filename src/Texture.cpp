#include "..\include\Texture.h"

namespace FGF
{
  Texture::Texture(const char* fname)
  {
    FIBITMAP* dib;

    /*Готовимся*/
    Logger::getInstance()->Log((std::string("Loading texture: ") + std::string(fname)).c_str());
    FREE_IMAGE_FORMAT fi_fmt = FIF_UNKNOWN;
    dib = 0;

    /*Определяем формат*/
    fi_fmt = FreeImage_GetFileType(fname,0);
    if(fi_fmt == FIF_UNKNOWN) Logger::getInstance()->Log((std::string(fname)+std::string(": unknown image type.")).c_str());

    /*Читаем*/
    if(FreeImage_FIFSupportsReading(fi_fmt))
      dib = FreeImage_Load(fi_fmt, fname);
    else
      Logger::getInstance()->Log((std::string(fname)+std::string(": unsupported format.")).c_str());

    /*Точно прочитали?*/
    if(!dib)
      Logger::getInstance()->Log((std::string(fname)+std::string(": failed to load.")).c_str());

    /*Отлично!*/
    FreeImage_SetTransparent(dib, true);

    /*Расковыриваем битмап*/
    xres = FreeImage_GetWidth(dib);
    yres = FreeImage_GetHeight(dib);

    size = xres*yres;
    bool has_alpha = FreeImage_IsTransparent(dib);
    int bytespp = has_alpha?4:3;

    /*Выделяем память*/
    GLubyte* texdata = new GLubyte[size*bytespp];

    /*Вытаскиваем пиксели*/
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

    /*Альфа-канал есть?*/
    if(bytespp == 3) format = GL_RGB;
    if(bytespp == 4) format = GL_RGBA;

    /*Получаем имя*/
    texname = GetName();

    /*Вбрасываем данные*/
    glBindTexture(GL_TEXTURE_2D, texname);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexImage2D(GL_TEXTURE_2D,0,format,xres,yres,0,format,GL_UNSIGNED_BYTE,texdata);

    delete[] texdata;
    /*CAN I HAS A TEXTURR LOLZ*/
  }

  Texture::Texture(const GLubyte* data, int w, int h, int bpp)
  {
    size = w*h;
    xres = w;
    yres = h;
    GLubyte* texdata = new GLubyte[size*(bpp/8)];
    memcpy(texdata, data, size*(bpp/8));

    /*Получаем имя*/
    texname = GetName();

    /*Вбрасываем данные*/
    glBindTexture(GL_TEXTURE_2D, texname);
    glTexImage2D(GL_TEXTURE_2D,0,format,xres,yres,0,format,GL_UNSIGNED_BYTE,texdata);

    delete[] texdata;
    /*CAN I HAS A TEXTURR LOLZ*/
  }

  void Texture::Activate()
  {
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texname);
  }

  Texture::~Texture(void)
  {
    std::stringstream tn_log;
    tn_log << "Texture name deleted: ";
    tn_log << texname;
    Logger::getInstance()->Log(tn_log.str().c_str());
    glDeleteTextures(1, &texname);
  }

  GLuint Texture::GetName()
  {
    GLuint texname;
    std::stringstream tn_log;
    glGenTextures(1,&texname);
    tn_log << "Texture name: ";
    tn_log << texname;
    Logger::getInstance()->Log(tn_log.str().c_str());
    return texname;
  }
}
