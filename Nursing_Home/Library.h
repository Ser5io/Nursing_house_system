#pragma once
#include <iostream>
#include <vector>
using namespace std;
class Library //done
{
	struct Books {
		string title;
		string author;
		string id;
		string borrowedBy;
		bool isAvileble;
	};
	const int max_number = 100;
	Books books[100];
	int bookCounter = 0;
public:
	void libraryMenu();
	void addBook();
	void removeBook(); 
	void borrowBook();
	void returnBook();
	void viewBooks();
};

