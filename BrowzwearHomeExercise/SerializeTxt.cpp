#include "stdafx.h"
#include "SerializeTxt.h"
#include "SerializeAlgoorithmPrototypeFactory.h"
#include "Defines.h"
#include <fstream>
#include <string>
#include <sstream>
#include <memory>

shared_ptr<SerializeAlgorithm> ConstructTxtSerializer()
{
	return make_shared<SerializeTxt>();
}

const bool registered = SerializeAlgoorithmPrototypeFactory::GetInstance().registerPrototype(DAT, ConstructTxtSerializer);
const bool registered1 = SerializeAlgoorithmPrototypeFactory::GetInstance().registerPrototype(TXT, ConstructTxtSerializer);

namespace SerializeTxtNs
{
	void createNameValue(const string & inputString, string & name, string & value)
	{
		size_t n = inputString.find("=");
		name = inputString.substr(0, n);
		value = inputString.substr(n + 1, sizeof(inputString) - 1);
	}
}


SerializeTxt::SerializeTxt()
{
}

SerializeTxt::~SerializeTxt()
{
}

bool SerializeTxt::serialize(vector<vector<pair<string, string>>> vecOfvecNameValues, string fileName)
{
	ofstream ofstr(fileName);
	for each (auto nameValues in vecOfvecNameValues)
	{
		for each (auto nameValue in nameValues)
		{
			ofstr << nameValue.first.c_str() << "=" << nameValue.second.c_str() << " ";
		}
		ofstr << endl;
	}
	ofstr.close();
	return false;
}

bool SerializeTxt::deserialize(vector<vector<pair<string, string>>>& vecOfvecNameValues, string fileName)
{
	std::ifstream ifstr(fileName);
	string line, name, value;
	while (std::getline(ifstr, line))
	{
		vector<pair<string, string>> vecNameValues;
		std::istringstream iss(line);
		while (std::getline(iss, line, ' '))
		{
			SerializeTxtNs::createNameValue(line, name, value);
			vecNameValues.push_back(pair<string, string>(name, value));
		}
		vecOfvecNameValues.push_back(vecNameValues);
	}
	return true;
}