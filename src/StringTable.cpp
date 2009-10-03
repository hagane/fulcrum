#include "StringTable.h"

namespace FGF
{
	StringTable::StringTable(char* file)
	{
		std::wifstream st(file);
		wchar_t buf[256];
		while(!st.eof())
		{
			st.getline(buf,256,'\n');
			std::wstring key(buf);
			st.getline(buf,256,'\n');
			std::wstring val(buf);
			table[key] = val;
		}
		std::string log;
		log.append("String Table from file '")
			.append(file)
			.append("' created.");
		Logger::getInstance()->Log(log.c_str());
	}

	StringTable::~StringTable(void)
	{
		table.clear();
	}

	const wchar_t* StringTable::get(std::wstring key)
	{
		return table[key].c_str();
	}
}
