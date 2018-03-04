#include "stdafx.h"
#include "Singleton.h"


Singleton & Singleton::GetInstance()
{
	static Singleton single;
	return single;
}

Singleton::Singleton()
{
}


Singleton::~Singleton()
{
}
