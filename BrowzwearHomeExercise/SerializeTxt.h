#pragma once

#include "SerializeAlgorithm.h"

class SerializeTxt : public SerializeAlgorithm
{
public:
	SerializeTxt();
	virtual ~SerializeTxt();
	virtual bool serialize(vector<vector<pair<string, string>>> nameValuePairs, string fileName);
	virtual bool deserialize(vector<vector<pair<string, string>>> & nameValuePairs, string fileName);
};

