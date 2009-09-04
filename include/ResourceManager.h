#pragma once
#include <string>
#include <map>
#include <fstream>
#include "Texture.h"
#include "StringTable.h"
#include "Sound.h"
#include "export.h"

namespace FGF
{
	/** \brief A class that manages resources.
	 *
	 * Resource Manager delivers automatic loading and freeing resources, described in a resource script.
	 *
	 * Format of a resource script:
	 *
	 * <type> <handle> <path>
	 *
	 * where:
	 * - <type>:
	 *  - TEXTURE -- resource is a texture
	 *  - STRTABLE -- resource is a string table
	 *  - SOUND -- resource is a sound
	 * - <handle> can be any unsigned decimal integer. It should be unique among all resources of the same type.
	 * - <path> is a relative or absolute path to resource
	 */
	class EXPORT ResourceManager
	{
	public:
		/**
		 * Constructor.
		 * @param script path (absolute or relative) to resource script.
		 */
		ResourceManager(const char* script);
		~ResourceManager(void);

		/**
		 * Returns a texture with given ID.
		 */
		Texture* getTexture(int id);

		/**
		 * Returns a string table with given ID.
		 */
		StringTable* getStrTable(int id);

		/**
		 * Returns a sound with given ID.
		 */
		Sound* getSound(int id);

	private:
		std::map<int, Texture*> textures;
		std::map<int, StringTable*> str_tables;
		std::map<int, Sound*> sounds;
	};
}
