// BrowzwearHomeExercise.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "PrototypeFactory.h"
#include "Base.h"
#include "Circle.h"
#include "Defines.h"
#include "OutArchive.h"
#include "InArchive.h"
#include "Singleton.h"
#include "Circle.h"
#include <vector>
#include <memory>
#include <fstream>

using namespace std;

int main()
{
	vector<shared_ptr<Base>> objects;
	objects.push_back(make_shared<Circle>(1, 3, 10));
	objects.push_back(make_shared<Point>(1, 2));
	objects.push_back(make_shared<Point>(50, 12));

	OutArchive write_archive("c:\\out.xml");
	write_archive.write(objects);

	InArchive read_archive("c:\\out.xml");
	vector<shared_ptr<Base>> objects1;
	read_archive.read(objects1);
    return 0;
}

