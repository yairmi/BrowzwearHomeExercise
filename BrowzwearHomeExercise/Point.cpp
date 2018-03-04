#include "stdafx.h"
#include "Point.h"
#include "PrototypeFactory.h"
#include "Defines.h"
#include <memory>


shared_ptr<Base> ConstructPoint()
{
	return make_shared<Point>();
}

const bool registered = PrototypeFactory::GetInstance().registerPrototype(POINT, ConstructPoint);

Point::Point(int x, int y)
{
	m_x = x;
	m_y = y;
}

Point::Point()
{

}


Point::~Point()
{
}

vector<pair<string, string>> Point::Serialize()
{
	vector<pair<string, string>> nameValuePairs;
	nameValuePairs.push_back(make_pair("type", POINT));
	nameValuePairs.push_back(make_pair("x", to_string(m_x)));
	nameValuePairs.push_back(make_pair("y", to_string(m_y)));
	return nameValuePairs;
}

void Point::Deserialze(vector<pair<string, string>> vecNameTypes)
{
	vector<pair<string, string>> nameValuePairs;
	std::string::size_type sz;
	for each (auto nameValue in vecNameTypes)
	{
		if (nameValue.first == "x")
		{
			m_x = stoi(nameValue.second, &sz);
		}
		if (nameValue.first == "y")
		{
			m_y = stoi(nameValue.second, &sz);
		}
	}
}