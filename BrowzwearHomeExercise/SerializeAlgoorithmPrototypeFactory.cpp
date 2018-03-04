#include "stdafx.h"
#include "SerializeAlgoorithmPrototypeFactory.h"


SerializeAlgoorithmPrototypeFactory & SerializeAlgoorithmPrototypeFactory::GetInstance()
{
	static SerializeAlgoorithmPrototypeFactory factory;
	return factory;
}

bool SerializeAlgoorithmPrototypeFactory::registerPrototype(const string & key, CreateMethodFunc method)
{
	m_prototypes[key] = method;
	return true;
}

shared_ptr<SerializeAlgorithm> SerializeAlgoorithmPrototypeFactory::createPrototype(const string & key)
{
	map<const string, CreateMethodFunc>::iterator iter = m_prototypes.find(key);
	if (iter == m_prototypes.end())
	{
		return nullptr;
	}

	return (*iter->second)();
}
