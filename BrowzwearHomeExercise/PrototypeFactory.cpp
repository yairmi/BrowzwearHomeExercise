#include "stdafx.h"
#include "PrototypeFactory.h"
#include <memory>

PrototypeFactory & PrototypeFactory::GetInstance()
{
	static PrototypeFactory factory;
	return factory;
}

bool PrototypeFactory::registerPrototype(const string & key, CreateMethodFunc method)
{
	m_prototypes[key] = method;
	return true;
}

shared_ptr<Base> PrototypeFactory::createPrototype(const string & key)
{
	map<const string, CreateMethodFunc>::iterator iter = m_prototypes.find(key);
	if (iter == m_prototypes.end())
	{
		return nullptr;
	}

	return (*iter->second)();
}