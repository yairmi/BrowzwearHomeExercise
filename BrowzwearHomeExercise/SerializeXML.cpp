#include "stdafx.h"
#include "SerializeXML.h"
#include "Defines.h"
#include "SerializeAlgoorithmPrototypeFactory.h"
#include <sstream> 
#include <memory>

using namespace tinyxml2;

shared_ptr<SerializeAlgorithm> ConstructXmlSerializer()
{
	return make_shared<SerializeXML>();
}

const bool registered = SerializeAlgoorithmPrototypeFactory::GetInstance().registerPrototype(XML, ConstructXmlSerializer);

SerializeXML::SerializeXML()
{
}

SerializeXML::~SerializeXML()
{
}

bool SerializeXML::serialize(vector<vector<pair<string, string>>> vecOfvecNameValues, string fileName)
{
	m_pRoot = m_xmlDoc.NewElement(ROOT);
	m_xmlDoc.InsertFirstChild(m_pRoot);
	for each (auto nameValues in vecOfvecNameValues)
	{
		XMLElement * element = m_xmlDoc.NewElement(OBJECT);
		for each (auto nameValue in nameValues)
		{
			element->SetAttribute(nameValue.first.c_str(), nameValue.second.c_str());
		}
		m_pRoot->InsertEndChild(element);
	}
	XMLError eResult = m_xmlDoc.SaveFile(fileName.c_str());
	return eResult == XML_SUCCESS;
}

bool SerializeXML::deserialize(vector<vector<pair<string, string>>> & vecOfvecNameValues, string fileName)
{
	XMLError eResult = m_xmlDoc.LoadFile(fileName.c_str());
	if (eResult != XML_SUCCESS)
		return false;

	XMLNode * pRoot = m_xmlDoc.FirstChild();
	if (pRoot == nullptr) 
		return false;
	XMLElement * pElement = pRoot->FirstChildElement(OBJECT);
	if (pElement == nullptr)
		return false;
	for (const XMLElement *element = pRoot->FirstChildElement(OBJECT); element; element = element->NextSiblingElement(OBJECT))
	{
		vector<pair<string, string>> vecNameValues;
		for (const XMLAttribute * att = element->FirstAttribute(); att; att = att->Next())
		{
			vecNameValues.push_back(pair<string, string>(att->Name(), att->Value()));
		}
		vecOfvecNameValues.push_back(vecNameValues);
	}

	return true;

}