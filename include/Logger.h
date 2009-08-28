#pragma once
#include <string>
#include <fstream>
#include <ctime>
#include "export.h"

namespace FGF
	{
		/** \brief A class for logging events.
		 *
		 * This is a singleton class that prints log to a file.
		 */
		class EXPORT Logger
		{
		public:
			/**
			 * Since Logger is a singleton, that method is the only way to obtain
			 * an instance of this class. It creates an instance of this class if
			 * it not exists.
			 * @param shutdown set this to true if you want instance to be destroyed.
			 */
			static Logger* getInstance(bool shutdown = false);

			/**
			 * Call this if you want instance to be destroyed.
			 */
			static void shutdown();

			/**
			 * Writes a time and a given string to the output file.
			 * @param log string that sould be written
			 */
			void Log(const char* log);

		private:
			Logger(std::string file);
			Logger(Logger &other);
			Logger& operator=(Logger &other);
			~Logger(void);

			std::ofstream logfile;
			void logTime();
	};
}
