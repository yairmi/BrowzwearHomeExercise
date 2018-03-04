#pragma once
#include "Base.h"
#include <string>
#include <map>
#include <memory>

using namespace std;

class PrototypeFactory
{
public:
	~PrototypeFactory() {}
public:
	typedef shared_ptr<Base>(*CreateMethodFunc)();
	static PrototypeFactory & GetInstance();
	bool registerPrototype(const string & key, CreateMethodFunc method);
	shared_ptr<Base> createPrototype(const string & key);
private:
	map<const string, CreateMethodFunc> m_prototypes;
	PrototypeFactory() {}
private:

};

