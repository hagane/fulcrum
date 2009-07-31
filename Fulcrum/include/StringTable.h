#pragma once
#include <map>
#include <string>
#include <fstream>
#include "Logger.h"

namespace FGF
{
	class StringTable
	{
	public:
		StringTable(char* file);
		~StringTable(void);
		const char* get(std::string key);

	private:
		std::map<std::string, std::string> table;
	};
}