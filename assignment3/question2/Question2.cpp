//============================================================================
// Name        : Question2.cpp
// Author      : Xiaofeng
// Version     :
// Copyright   : Your copyright notice
// Description : Assignment3_q2
//============================================================================

#include <iostream>
#include <string>
#include "hash.h"
using namespace std;

void menu(){
	cout << "1. Insert element" << endl;
	cout << "2. Delete element" << endl;
	cout << "3. Search element" << endl;
	cout << "4. Display elements" << endl;
	cout << "5. Exit" << endl;
}

int main() {
	menu();
	int id, choice;
	string n;
	float mk;
	Hash MyHash;
	do{
		cout << "choose from menu: ";
		cin >> choice;
		cin.get();
		switch(choice){
		case 1:
			do{
				cout << "Enter the student Id:  ";
				cin >> id;
				if(!cin){
					cin.clear();
					cin.ignore();
					cout << "Invalid enter. Please enter numbers" << endl;
				}
			}while(!id);
			cin.get();
			cout << "Enter the student name: ";
			getline(cin, n);
			do{
				cout << "Enter the student mark: ";
				cin >> mk;
				if(!cin){
					cin.clear();
					cin.ignore();
					cout << "Invalid enter. Please enter numbers" << endl;
				}
			}while(!mk);

			cin.get();
			MyHash.insertItem(id, n, mk);
			break;
		case 2:
			do{
				cout << "Enter the student Id need to be deleted:  ";
				cin >> id;
				if(!cin){
					cin.clear();
					cin.ignore();
					cout << "Invalid enter. Please enter numbers" << endl;
				}
			}while(!id);

			cin.get();
			MyHash.deleteItem(id);
			break;
		case 3:
			do{
				cout << "Enter the student id need to be searched: ";
				cin >> id;
				if(!cin){
					cin.clear();
					cin.ignore();
					cout << "Invalid enter. Please enter numbers" << endl;
				}
			}while(!id);

			cin.get();
			MyHash.searchItem(id);
			break;
		case 4:
			MyHash.displayItems();
			break;
		case 5:
			cout << "Exit\n\n";
			return 0;
			break;
		default:
			cout << "Invalid option." << endl;
		}

	}while(choice <= 5);




	return 0;
}
