#pragma once
#include "Point.h"
class Circle :
	public Point
{
public:
	Circle();
	Circle(int x, int y, float radius);
	virtual ~Circle();

	virtual vector<pair<string, string>> Serialize();
	virtual void Deserialze(vector<pair<string, string>> vecNameTypes);
private:
	float m_radius;
};

