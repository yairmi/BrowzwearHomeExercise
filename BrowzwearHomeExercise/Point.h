#pragma once
#include "Base.h"

class Point :
	public Base
{
public:
	Point();
	Point(int x, int y);
	virtual ~Point();

	virtual vector<pair<string, string>> Serialize();
	virtual void Deserialze(vector<pair<string, string>> vecNameTypes);
protected:
	int m_x;
	int m_y;
};

