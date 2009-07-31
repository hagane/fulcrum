// ResManTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	FGF::ResourceManager* res = new FGF::ResourceManager("e:/Source/FGF/Debug/res.rs");
	FGF::StringTable* st = res->getStrTable(1);
	std::cout << st->get("1") << st->get("2") << st->get("3");
	return 0;
}