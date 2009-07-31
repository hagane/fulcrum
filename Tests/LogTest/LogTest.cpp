// LogTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	Logger::getInstance()->Log("Singleton logger");
	Logger::shutdown();
	return 0;
}

