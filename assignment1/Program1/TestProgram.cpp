//============================================================================
// Name        : Program1.cpp
// Author      : Xiaofeng
// Version     :
// Copyright   :
// Description : Assignment1_Program1
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
#include "Book.h"
using namespace std;

void AddNewBook(vector<Book> *bookdata);
void PrintBooks(vector<Book> &bookdata);
void SortBooks(vector<Book> &bookdata);
void PrintMenu();

int main()
{
	vector<Book> bookdata;
	int choose;
	do{
		PrintMenu();
		do{
			cout << "Choice: ";
			cin >> choose;
			if(!cin || (choose != 1 && choose != 2 && choose != 3)){
				cin.clear();
				cin.ignore();
				cout << "Invalid choice. Please enter right number." << endl;
			}
		}while(choose != 1 && choose != 2 && choose != 3);
		cin.clear();
		cin.ignore();
		switch(choose){
		case 1:
			AddNewBook(&bookdata);
			break;
		case 2:
			PrintBooks(bookdata);
			break;
		case 3:
			cout << "Thanks and Bye!" << endl;
		}
	}while(choose != 3);

	return 0;
}

void AddNewBook(vector<Book> *bookdata){
	string new_author, new_title, new_date;
	cout << "\nEnter title: " << endl;
	getline(cin, new_title);
	cout << "Enter author: " << endl;
	getline(cin, new_author);
	cout << "Enter date: " << endl;
	getline(cin, new_date);
	Book new_book(new_author, new_title, new_date);
	bookdata -> push_back(new_book);

}

void PrintBooks(vector<Book> &bookdata){
	SortBooks(bookdata);
	cout << "\nThe books entered so far, sorted alphatetically by artist are: " << endl;
	for(unsigned int i = 0; i < bookdata.size(); i++){
		cout << "Author: "  << bookdata[i].getAuthor() << ", Title: " << bookdata[i].getTitle() << ", Date: " << bookdata[i].getDate() << endl;
	}
}

void SortBooks(vector<Book> &bookdata){
	sort(bookdata.begin(), bookdata.end());
}

void PrintMenu(){
	cout << "\nSelect from the following choices: " << endl;
	cout << "  1.Add new book " << endl;
	cout << "  2.Print listing sorted by author " << endl;
	cout << "  3.Quit " << endl;
}
