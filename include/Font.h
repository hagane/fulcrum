#pragma once

#include <fstream>
#include <map>
#include <set>
#include <string>
#include "export.h"
#include "OpenGL.h"
#include "Texture.h"

namespace FGF
{
	/**
	 * This class represents a font.
	 * Format of font description file:
	 * <symbol> <origin_x> <origin_y> <width> <height>
	 */
	class EXPORT Font
	{
	public:
		/**
		 * A constructor.
		 * @param font_desc File to read font description from
		 * @param font_tex File with font texture
		 */
		Font(const char* font_desc, const char* font_tex);
		~Font();

		/**
		 * Renders a char.
		 */
		void renderChar(wchar_t ch, int x_offset, int y_offset);
		
		/**
		 * Returns a width of given character,
		 * or 0 if there is no such character in
		 * a font description.
		 */
		int getCharWidth(wchar_t ch);
		
		/**
		 * Prepares a font for rendering.
		 */
		void Activate();

	private:
		std::map<wchar_t,int> origin_x;
		std::map<wchar_t,int> origin_y;
		std::map<wchar_t,int> width;
		std::map<wchar_t,int> height;

		std::set<wchar_t> chars;

		Texture* tex;
	};
}
