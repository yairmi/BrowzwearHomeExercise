#pragma once
#include <string>
#include <memory>
#include "SerializeAlgorithm.h"

using namespace std;

class ArchiveBase
{
public:
	ArchiveBase(string fileName);
	~ArchiveBase();
protected:
	shared_ptr<SerializeAlgorithm> m_serializeAlgorithm;
	string m_sFileName;
};

