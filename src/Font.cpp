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

	void Font::renderChar(wchar_t ch, int x_offset, int y_offset)
	{
		tex->Activate();
		if(chars.find(ch) != chars.end())
		{
			glTexCoord2i(origin_x[ch], origin_y[ch]);
			glVertex3i(x_offset, y_offset, 0);

			glTexCoord2i(origin_x[ch], origin_y[ch] + height[ch]);
			glVertex3i(x_offset, y_offset + height[ch], 0);

			glTexCoord2i(origin_x[ch] + width[ch], origin_y[ch] + height[ch]);
			glVertex3i(x_offset + width[ch], y_offset + height[ch], 0);

			glTexCoord2i(origin_x[ch] + width[ch], origin_y[ch]);
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
