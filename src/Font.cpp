#include "../include/Font.h"
namespace FGF
{
	Font::Font(const char* font_desc, const char* font_tex)
	{
		tex = new Texture(font_tex);
		std::wifstream f;
		f.open(font_desc);
		wchar_t ch;
		int origin_x_val;
		int origin_y_val;
		int width_val;
		int height_val;
		while(!f.eof())
		{
			((((f >> ch) >> origin_x_val) >> origin_y_val) >> width_val) >> height_val;
			origin_x[ch] = origin_x_val;
			origin_y[ch] = origin_y_val;
			width[ch] = width_val;
			height[ch] = height_val;
			chars.insert(ch);
		}
		f.close();
	}

	Font::~Font()
	{
		delete tex;
		origin_x.clear();
		origin_y.clear();
		width.clear();
		height.clear();
		chars.clear();
	}

	void Font::renderChar(wchar_t ch, int x_offset, int y_offset)
	{
		tex->Activate();
		if(chars.find(ch) != chars.end())
		{
			float s = float(origin_x[ch])/float(tex->getXRes());
			float t = float(origin_y[ch])/float(tex->getXRes());
			glTexCoord2f(s, t);
			glVertex3i(x_offset, y_offset, 0);

			s = float(origin_x[ch])/float(tex->getXRes());
			t = float(origin_y[ch] + height[ch])/float(tex->getXRes());
			glTexCoord2f(s, t);
			glVertex3i(x_offset, y_offset + height[ch], 0);

			s = float(origin_x[ch] + width[ch])/float(tex->getXRes());
			t = float(origin_y[ch] + height[ch])/float(tex->getXRes());
			glTexCoord2f(s, t);
			glVertex3i(x_offset + width[ch], y_offset + height[ch], 0);

			s = float(origin_x[ch] + width[ch])/float(tex->getXRes());
			t = float(origin_y[ch])/float(tex->getXRes());
			glTexCoord2f(s, t);
			glVertex3i(x_offset + width[ch], y_offset, 0);
		}
	}

	int Font::getCharWidth(wchar_t ch)
	{
		if(chars.find(ch) != chars.end())
		{
			return width[ch];
		}
		return 0;
	}
}
