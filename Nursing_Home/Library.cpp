#include "Library.h"

void Library::libraryMenu()
{
	bool loop = true;
	int choise;
	while (loop)
	{
		cout << "=====Library=====\n";
		cout << "[1] Add book\n";
		cout << "[2] Remove book\n";
		cout << "[3] Borrow book\n";
		cout << "[4] Return book\n";
		cout << "[5] View books\n";
		cout << "[0] Back\n";

		cin >> choise;

		switch (choise)
		{
		case 1:
			addBook();
			break;
		case 2:
			removeBook();
			break;
		case 3:
			borrowBook();
			break;
		case 4:
			returnBook();
			break;
		case 5:
			viewBooks();
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

void Library::addBook()
{
	if (bookCounter == max_number) cout << "Cant add another book..!!\n";
	else {
		cout << "Enter the book's title : ";
		cin >> books[bookCounter].title;
		cout << "Enter author's name : ";
		cin >> books[bookCounter].author;
		cout << "Enter ID to the book : ";
		cin >> books[bookCounter].id;
		books[bookCounter].isAvileble = true;

		bookCounter++;
		cout << "The book has been added successfully !!\n";
	}
}

void Library::removeBook()
{
	if (bookCounter == 0) cout << "Empty libarary\n";
	else {
		string searchID;
		bool idFound = false;
		int pos;
		cout << "Enter the ID of the book you want to remove : ";
		cin >> searchID;

		for (int i = 0; i < bookCounter; i++) {
			if (books[i].id == searchID) {
				idFound = true;
				pos = i;
				break;
			}
		}
		if (idFound) {
			for (int i = pos; i < bookCounter - 1; i++) {
				books[i] = books[i + 1];
			}
			bookCounter--;
			cout << "The book has been removed successfully !!\n";
		}
		else cout << "ID not found\n";
	}
}

void Library::borrowBook()
{
	if (bookCounter == 0) cout << "Empty libarary\n";
	else {
		string searchID;
		bool isFound = false;
		cout << "Enter the ID of the book you want to borrow : ";
		cin >> searchID;

		for (int i = 0; i < bookCounter; i++) {
			if (books[i].id == searchID) {
				if (books[i].isAvileble) {
					books[i].isAvileble = false;
					isFound = true;
					cout << "Enter the name of borrower : ";
					cin >> books[i].borrowedBy;
					break;
				}
				else cout << "this book is borrowed by " << books[i].borrowedBy << endl;

			}
		}

		if (!isFound) cout << "ID not found\n";
	}
}

void Library::returnBook()
{
	if (bookCounter == 0) cout << "Empty library\n";
	else {
		string searchID;
		bool isFound = false;
		cout << "Enter the ID of the book you want to return : ";
		cin >> searchID;

		for (int i = 0; i < bookCounter; i++) {
			if (books[i].id == searchID) {
				if (!books[i].isAvileble) {
					books[i].isAvileble = true;
					isFound = true;
					books[i].borrowedBy = "";
					break;
				}
				else cout << "this book is avilable alredy\n";

			}
		}

		if (!isFound) cout << "ID not found\n";
	}
}

void Library::viewBooks()
{
	if (bookCounter == 0) cout << "Empty library\n";
	else {
		for (int i = 0; i < bookCounter; i++) {
			cout << "Title : " << books[i].title << ", Author : " << books[i].author << ", ID : " << books[i].id;
			if (books[i].isAvileble) cout << ", Status : AVALEBLE\n";
			else cout << ", Status : NOT AVALEBLE\n";
		}
	}
}
