#include "Activities.h"

void Activities::activitiesMenu()
{
	bool loop = true;
	int choise;
	while (loop)
	{
		cout << "=====Activitires=====\n";
		cout << "[1] Record activity\n";
		cout << "[2] View activities\n";
		cout << "[0] Back\n";

		cin >> choise;

		switch (choise)
		{
		case 1:
			recordActivity();
			break;
		case 2:
			view_activities();
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

	void Activities::recordActivity()
	{
		if (sportCounter == 100) cout << "Out of space..!\n";
		else {
			cout << "Enter the name of the Activity : ";
			cin >> sports[sportCounter].name;

			time_t now = time(NULL);
			char time[26] = {};
			ctime_s(time, 26, &now);
			sports[sportCounter].date = time;

			sportCounter++;
			cout << "DONE\n";
		}
	}

	void Activities::view_activities()
	{
		if (sportCounter == 0) cout << "there is no data to view....\n";
		else {
			for (int i = 0; i < sportCounter; i++) {
				cout << "==============\n";
				cout << "Activity : " << sports[i].name << endl;
				cout << "Date : " << sports[i].date;
				cout << "==============\n";
			}
		}
	}
