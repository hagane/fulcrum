#pragma once
#include <string>
#include <map>
#include <fstream>
#include "Texture.h"
#include "StringTable.h"

namespace FGF
{
	class ResourceManager
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