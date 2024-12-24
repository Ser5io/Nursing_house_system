#include "Health.h"

void Health::healthMenu()
{
	bool loop = true;
	int choise;
	while (loop)
	{
		cout << "=====Health=====\n";
		cout << "[1] Record health file\n";
		cout << "[2] show file\n";
		cout << "[0] Back\n";

		cin >> choise;

		switch (choise)
		{
		case 1:
			recordHealthFile();
			break;
		case 2:
			showfile();
			break;
		case 0:
			loop = false;
			break;
		default:
			cout << "invaled choise\n";
			break;
		}
	}
}

void Health::recordHealthFile()
{
	if (fileCounter == 100) cout << "Out of space..\n";
	else {
		cout << "Enter resident ID : ";
		cin >> file[fileCounter].residentID;
		cout << "Write the health report : ";
		cin >> file[fileCounter].medicalHistory;
		cout << "Write a medication : ";
		cin >> file[fileCounter].medication;
		cout << "Note blood pressure : ";
		cin >> file[fileCounter].bloodPressure;
		cout << "Note temprature : ";
		cin >> file[fileCounter].temperature;

		time_t now = time(NULL);
		char time[26] = {};
		ctime_s(time, 26, &now);
		file[fileCounter].date = time;

		fileCounter++;
		cout << "DONE\n";
	}
}

void Health::showfile()
{
	if (fileCounter == 0) cout << "there is no data to view....\n";
	else {
		string idSearch;
		bool isFound = false;
		cout << "Enter the resident's ID : ";
		cin >> idSearch;
		for (int i = 0; i < fileCounter; i++) {
			if (file[i].residentID == idSearch)
				cout << "ID : " << file[i].residentID << ", Date : " << file[i].date << endl;
				cout << "Medical report : " << file[i].medicalHistory << endl;
				cout << "Medication : " << file[i].medication << endl;
				cout << "Blood pressure [" << file[i].bloodPressure << "] , temprature [" << file[i].temperature << "]\n";

				isFound = true;

		}
		if (!isFound) cout << "ID not found\n";
	}
}
