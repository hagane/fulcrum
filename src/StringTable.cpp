#include "..\include\StringTable.h"

namespace FGF
{
	StringTable::StringTable(char* file)
	{
		std::ifstream st(file);
		char buf[256];
		while(!st.eof())
		{
			st.getline(buf,256,'\n');
			std::string key(buf);
			st.getline(buf,256,'\n');
			std::string val(buf);
			table[key] = val;
		}
		std::string log;
		log.append("String Table from file '")
			.append(file)
			.append("' created");
		Logger::getInstance()->Log(log.c_str());
	}

	StringTable::~StringTable(void)
	{
		table.clear();
	}

	const char* StringTable::get(std::string key)
	{
		return table[key].c_str();
	}
}
