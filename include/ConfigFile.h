#include <fstream>
#include <map>
#include <string>
#include <sstream>

namespace FGF
{
	class ConfigFile
	{
	public:
		ConfigFile(const char* fname);
		~ConfigFile();
		
		std::wstring getValue_String(const std::wstring& key);
		int getValue_Int(const std::wstring& key);

	private:
		std::map<std::wstring, std::wstring> val;
	};
}
