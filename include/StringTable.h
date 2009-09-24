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
		const wchar_t* get(std::wstring key);

	private:
		std::map<std::wstring, std::wstring> table;
	};
}
