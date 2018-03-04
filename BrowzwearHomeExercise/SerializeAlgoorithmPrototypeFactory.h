#pragma once
#include "SerializeAlgorithm.h"
#include <string>
#include <map>
#include <memory>

class SerializeAlgoorithmPrototypeFactory
{
public:
	~SerializeAlgoorithmPrototypeFactory() {}
public:
	typedef shared_ptr<SerializeAlgorithm>(*CreateMethodFunc)();
	static SerializeAlgoorithmPrototypeFactory & GetInstance();
	bool registerPrototype(const string & key, CreateMethodFunc method);
	shared_ptr<SerializeAlgorithm> createPrototype(const string & key);
private:
	map<const string, CreateMethodFunc> m_prototypes;
	SerializeAlgoorithmPrototypeFactory() {}

};

