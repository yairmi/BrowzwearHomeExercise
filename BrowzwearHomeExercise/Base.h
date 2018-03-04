#pragma once
#include <memory>
#include <istream>
#include <iostream>
#include "SerializeAlgorithm.h"

using namespace std;

class Base
{
public:
	Base();
	virtual ~Base();

	virtual vector<pair<string, string>> Serialize() = 0;
	virtual void Deserialze(vector<pair<string, string>> vecNameTypes) = 0;
};

