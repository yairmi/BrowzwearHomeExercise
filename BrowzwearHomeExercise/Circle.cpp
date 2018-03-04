#include "stdafx.h"
#include "Circle.h"
#include "Defines.h"
#include "PrototypeFactory.h"
#include <sstream>
#include <vector>


shared_ptr<Base> ConstructCircle()
{
	return make_shared<Circle>();
}

const bool registered = PrototypeFactory::GetInstance().registerPrototype(CIRCLE, ConstructCircle);

Circle::Circle()
{

}

Circle::Circle(int x, int y, float radius)
	:Point(x, y)
{
	m_radius = radius;	
}


Circle::~Circle()
{
}

vector<pair<string, string>> Circle::Serialize()
{
	vector<pair<string, string>> vecNameValues;
	vecNameValues.push_back(make_pair("type", CIRCLE));
	vecNameValues.push_back(make_pair("radius", to_string(m_radius)));
	vecNameValues.push_back(make_pair("x", to_string(m_x)));
	vecNameValues.push_back(make_pair("y", to_string(m_y)));

	return vecNameValues;
	
}
void  Circle::Deserialze(vector<pair<string, string>> vecNameTypes)
{
	vector<pair<string, string>> nameValuePairs;
	std::string::size_type sz;
	for each (auto nameValue in vecNameTypes)
	{
		if (nameValue.first == "radius")
		{
			m_radius = stof(nameValue.second, &sz);
		}
		if (nameValue.first == "x")
		{
			m_x = stoi(nameValue.second, &sz);
		}
		if (nameValue.first == "y")
		{
			m_y = stoi(nameValue.second, &sz);
		}
	}
	//istr >> m_radius >> m_x >> m_y;
}
