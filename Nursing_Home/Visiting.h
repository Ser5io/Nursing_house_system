#pragma once
#include <iostream>
using namespace std;
class Visiting
{
	struct Visits
	{
		string resident;
		string visitor;
		string date;
		string residentID;
	};
	Visits log[100];
	int logCounter = 0;
public:
	void visitingMenu();
	void recordVisiting();
	void view();
	void viewAll();
};

