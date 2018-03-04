#include "stdafx.h"
#include "InArchive.h"
#include "PrototypeFactory.h"
#include "Circle.h"
#include <fstream>


InArchive::InArchive(string fileName)
	: ArchiveBase(fileName)
{
}


InArchive::~InArchive()
{
}

void InArchive::read(vector<shared_ptr<Base>> &objects)
{
	PrototypeFactory &factory = PrototypeFactory::GetInstance();
	vector<vector<pair<string, string>>> vecOfvecNameTypes;
	m_serializeAlgorithm->deserialize(vecOfvecNameTypes, m_sFileName);
	for each (auto vecNameTypes in vecOfvecNameTypes)
	{
		shared_ptr<Base> shape = factory.createPrototype(vecNameTypes[0].second);
		shape->Deserialze(vecNameTypes);
		objects.push_back(shape);
	}
}
