// StringTableTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	StringTable* table = new StringTable("e:/Source/FGF/Debug/testtable.txt");
	std::cout << "AAA: " << table->get("1") << std::endl;
	std::cout << "BBB: " << table->get("1") << std::endl;
	std::cout << "CCC: " << table->get("1") << std::endl;
	getchar();
	return 0;
}

