#pragma once
#include <string>
#include <vector>
#include <memory>
#include "Base.h"
#include "ArchiveBase.h"

using namespace std;

class InArchive : ArchiveBase
{
public:
	InArchive(string fileName);
	~InArchive();

	void read(vector<shared_ptr<Base>> &objects);


};

