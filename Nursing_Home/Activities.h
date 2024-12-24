#pragma once
#include <iostream>
using namespace std;
class Activities
{
	struct Sport
	{
		string name;
		string date;
	};

	Sport sports[100];
	int sportCounter = 0;
public:
	void activitiesMenu();
	void recordActivity();
	void view_activities();
};

