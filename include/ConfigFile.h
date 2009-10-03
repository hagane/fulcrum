#include <fstream>
#include <map>
#include <string>
#include <sstream>

namespace FGF
{
	/** \brief Works with configuration files.
	 *
	 * Format for config files is simply
	 *
	 * <key> <val>
	 * 
	 * - <key> is an UTF-8 string;
	 * - <val> is an UTF-8 string or an integer number;
	 */
	class ConfigFile
	{
	public:
		/**
		 * Constructor
		 * @param fname Path to configuration file.
		 */
		ConfigFile(const char* fname);
		~ConfigFile();
		
		/**
		 * Returns an UTF-8 string, or empty string
		 * if key is unknown.
		 */
		std::wstring getValue_String(const std::wstring& key);

		/**
		 * Returns an integer number, or 0 if key is unknown
		 * or value is not a number.
		 */
		int getValue_Int(const std::wstring& key);

	private:
		std::map<std::wstring, std::wstring> val;
	};
}
