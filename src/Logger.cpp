#include "..\include\Logger.h"

namespace FGF
{
	Logger::Logger(std::string file)
	{
		logfile.open(file.c_str(),std::ios::out);
		Log("Log started.");
	}

	Logger::~Logger(void)
	{
		Log("Log finished.");
		logfile.flush();
		logfile.close();
	}

	void Logger::Log(const char *log)
	{
		logTime();
		logfile << log << std::endl;
		logfile.flush();
	}

	void Logger::logTime()
	{
		time_t currTime;
		time(&currTime);
		struct tm ltime;
		ltime = localtime(&currTime);
		logfile << ltime.tm_mday << "/"
			<< ltime.tm_mon+1 << "/"
			<< ltime.tm_year+1900 << " "
			<< ltime.tm_hour << ":"
			<< ltime.tm_min << ":"
			<< ltime.tm_sec << "> ";
	}

	Logger* Logger::getInstance(bool shutdown)
	{
		static Logger* instance;
		if(shutdown && (instance != NULL))
		{
			delete instance;
			return 0;
		}
		else
		{
			if(instance == NULL)
			{
				instance = new Logger("fulcrum.log");
			}
			return instance;
		}
	}

	void Logger::shutdown()
	{
		Logger::getInstance(true);
	}
}
