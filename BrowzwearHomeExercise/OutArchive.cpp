#include "stdafx.h"
#include "OutArchive.h"
#include <fstream>

OutArchive::OutArchive(string fileName)
	:ArchiveBase(fileName)
{
}


OutArchive::~OutArchive()
{
}

void OutArchive::write(vector<shared_ptr<Base>> objects)
{
	vector<vector<pair<string, string>>> outObjects;

	for each (shared_ptr<Base> shape in objects)
	{
		vector<pair<string, string>> object = shape->Serialize();
		outObjects.push_back(object);
	}
	m_serializeAlgorithm->serialize(outObjects, m_sFileName);
}
