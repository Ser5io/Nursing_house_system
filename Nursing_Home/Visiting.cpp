#include "Visiting.h"

void Visiting::visitingMenu()
{
	bool loop = true;
	int choise;
	while (loop)
	{
		cout << "=====Visiting=====\n";
		cout << "[1] Record activity\n";
		cout << "[2] View inmate\n";
		cout << "[3] View log\n";
		cout << "[0] Back\n";

		cin >> choise;

		switch (choise)
		{
		case 1:
			recordVisiting();
			break;
		case 2:
			view();
			break;
		case 3:
			viewAll();
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

void Visiting::recordVisiting()
{
	if (logCounter == 100) cout << "Out of space..!!\n";
	else {
		cout << "Enter the inmate name : ";
		cin >> log[logCounter].resident;
		cout << "Enter the Id of the inmate : ";
		cin >> log[logCounter].residentID;
		cout << "Enter the visitor name : ";
		cin >> log[logCounter].visitor;


		time_t now = time(NULL);
		char time[26] = {};
		ctime_s(time, 26, &now);
		log[logCounter].date = time;

		logCounter++;
		cout << "DONE\n";
	}
}

void Visiting::view()
{
	if (logCounter == 0) cout << "there is no data to view....\n";
	else {
		string idSearch;
		bool isFound = false;
		cout << "Enter the resident's ID : ";
		cin >> idSearch;
		for (int i = 0; i < logCounter; i++) {
			if (idSearch != log[i].residentID) continue;
			cout << "==============\n";
			cout << "resident : " << log[i].resident << ", ID : " << log[i].residentID << endl;
			cout << "Visitor : " << log[i].visitor << endl;
			cout << "Date : " << log[i].date;
			cout << "==============\n";

			isFound = true;
		}
		if (!isFound) cout << "ID not found\n";
	}
}

void Visiting::viewAll()
{
	if (logCounter == 0) cout << "there is no data to view....\n";
	else {
		for (int i = 0; i < logCounter; i++) {
			cout << "==============\n";
			cout << "Inmate : " << log[i].resident << ", ID : " << log[i].residentID << endl;
			cout << "Visitor : " << log[i].visitor << endl;
			cout << "Date : " << log[i].date;
			cout << "==============\n";
		}
	}
}
