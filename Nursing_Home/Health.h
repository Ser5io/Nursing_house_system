#pragma once
#include <iostream>
using namespace std;
class Health
{
	struct HealthFile {
		string medicalHistory;
		string medication;
		string bloodPressure;
		string temperature;
		string residentID;
		string date;
	};
	HealthFile file[100];
	int fileCounter = 0;

public:
	void healthMenu();
	void recordHealthFile();
	void showfile();
};

