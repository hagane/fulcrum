#include "../include/ConfigFile.h"

namespace FGF
{
	ConfigFile::ConfigFile(const char* fname)
	{
		std::wifstream cf;
		cf.open(fname);
		while(!cf.eof())
		{
			std::wstring key;
			std::wstring value;
			cf >> key >> value;
			val[key] = value;
		}
	}

	ConfigFile::~ConfigFile()
	{
		val.clear();
	}

	std::wstring ConfigFile::getValue_String(const std::wstring& key)
	{
		if(val.find(key) != val.end())
			return val[key];
		return L"";
	}

	int ConfigFile::getValue_Int(const std::wstring& key)
	{
		if(val.find(key) != val.end())
		{
			std::wistringstream s(key);
			int rv;
			if(s >> rv)
				return rv;
		}
		return 0;
	}
}
