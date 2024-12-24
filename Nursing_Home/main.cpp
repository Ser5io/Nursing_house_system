#include <iostream>
#include <ctime>
#include "Library.h"
#include "Activities.h"
#include "Visiting.h"
#include "Health.h"
using namespace std;

void mainMenu() {
	Library L1;
	Visiting V1;
	Activities A1;
	Health H1;

	int choise;
	bool loop = true;

	while (loop)
	{
		cout << "=====Nursing House(MainPage)=====\n";
		cout << "[1] Liberary\n";
		cout << "[2] Visiting\n";
		cout << "[3] Activities\n";
		cout << "[4] Health\n";
		cout << "[0] Exit\n";

		cin >> choise;

		switch (choise)
		{
		case 1:
			L1.libraryMenu();
			break;
		case 2:
			V1.visitingMenu();
			break;
		case 3:
			A1.activitiesMenu();
			break;
		case 4:
			H1.healthMenu();
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

int main() {
	mainMenu();
	return 0;
}