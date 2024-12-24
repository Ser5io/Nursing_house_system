#pragma once
#include <iostream>
using namespace std;
class Book
{
public:
	string title;
	string author;
	bool isAvailable;

	Book();
	void menu();
	void add_book();
	void borrow_book();
	void return_book();
	void view_books();

};

