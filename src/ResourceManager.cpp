#include "ResourceManager.h"

namespace FGF
{
	ResourceManager::ResourceManager(const char* script)
	{
		std::ifstream f;
		f.open(script);
		char* token = new char[9];
		int token_id;
		char* token_path = new char[256];
		
		while(!f.eof())		
		{
			f >> token >> token_id >> token_path;
			if(strcmp(token, "TEXTURE") == 0)
			{
				textures[token_id]= new Texture(token_path);
			}
			if (strcmp(token, "STRTABLE") == 0)
			{
				str_tables[token_id] = new StringTable(token_path);
			}
			if (strcmp(token, "SOUND") == 0)
			{
				sounds[token_id] = new Sound(token_path);
			}
		}

		f.close();
	}

	ResourceManager::~ResourceManager(void)
	{
		textures.clear();
		str_tables.clear();
	}

	Texture* ResourceManager::getTexture(int id)
	{
		if(textures.find(id) != textures.end())
		{
			Texture* tmp = textures[id];
			return tmp;
		}
		else return NULL;
	}

	StringTable* ResourceManager::getStrTable(int id)
	{
		if(str_tables.find(id) != str_tables.end())
		{
			StringTable* tmp = str_tables[id];
			return tmp;
		}
		else return NULL;
	}

	Sound* ResourceManager::getSound(int id)
	{
		if(sounds.find(id) != sounds.end())
		{
			Sound* tmp = sounds[id];
			return tmp;
		}
		else return NULL;
	}
}
