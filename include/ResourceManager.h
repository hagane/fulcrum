#pragma once
#include <string>
#include <map>
#include <fstream>
#include "Texture.h"
#include "StringTable.h"
#include "export.h"

namespace FGF
{
	/**
	 * Resource Manager delivers automatic loading and freeing resources, described in a resource script.
	 * Format of a resource script:
	 * <type> <handle> <path>
	 * where:
	 * -<type>:
	 * -# TEXTURE -- resource is a texture
	 * -# STRTABLE -- resource a string table
	 * -<handle> can be any unsigned decimal integer
	 * -<path> is a relative or absolute path to resource
	 */
	class EXPORT ResourceManager
	{
	public:
		ResourceManager(const char* script);
		~ResourceManager(void);
		Texture* getTexture(int id);
		StringTable* getStrTable(int id);

	private:
		std::map<int, Texture*> textures;
		std::map<int, StringTable*> str_tables;
	};
}
