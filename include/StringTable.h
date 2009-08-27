#pragma once
#include <map>
#include <string>
#include <fstream>
#include "Logger.h"
#include "export.h"

namespace FGF
{
	class EXPORT StringTable
	{
	public:
		StringTable(char* file);
		~StringTable(void);
		const char* get(std::string key);

	private:
		std::map<std::string, std::string> table;
	};
}
