#pragma once
#include <memory.h>
#include <vector>

using namespace std;

class SerializeAlgorithm
{
public:
	SerializeAlgorithm();
	virtual ~SerializeAlgorithm();
	virtual bool serialize(vector<vector<pair<string, string>>> nameValuePairs, string fileName) = 0;
	virtual bool deserialize(vector<vector<pair<string, string>>> & nameValuePairs, string fileName) = 0;
};

