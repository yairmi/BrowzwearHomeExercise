#pragma once
#include <string>
#include <vector>
#include <memory>
#include "Base.h"
#include "ArchiveBase.h"

using namespace std;

class OutArchive : ArchiveBase
{
public:
	OutArchive(string fileName);
	~OutArchive();
	void write(vector<shared_ptr<Base>> objects);
};

