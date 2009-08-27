#pragma once
#include <string>
#include <fstream>
#include <ctime>
#include "export.h"

namespace FGF
	{
	class EXPORT Logger
	{
	public:
		~Logger(void);
		static Logger* getInstance(bool shutdown = false);
		static void shutdown();
		void Log(const char* log);

	private:
		Logger(std::string file);
		Logger(Logger &other);
		Logger& operator=(Logger &other);

		std::ofstream logfile;
		void logTime();
	};
}
