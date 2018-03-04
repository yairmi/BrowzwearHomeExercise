#pragma once
class Singleton
{
public:
	
	~Singleton();
	static Singleton & GetInstance();
	//static Singleton & GetInstance()
	//{
	//	static Singleton single;
	//	return single;
	//}
private:
	Singleton();
};

