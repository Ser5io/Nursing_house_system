#pragma once
#include <iostream>
using namespace std;

class Visits
{
public:
	string visitorName;
	string visitDate;

	Visits();
	void menu();
	void record_visit();
	void show_visits();
};

