//============================================================================
// Name        : task1.cpp
// Author      : Xiaofeng Zhang
// Version     :
// Copyright   : Your copyright notice
// Description : assignment2 task1
//============================================================================

#include <iostream>
#include <string>
#include "myfriends.h"
using namespace std;

void menu(){
	cout << "Enter one of the following: \n"
			<< "1. to insert the friend information at beginning of list\n"
			<< "2. to insert the friend information at end of list\n"
			<< "3. to insert the friend information at particular position\n"
			<< "4. to delete the friend information from beginning of list\n"
			<< "5. to delete the friend information from end of list\n"
			<< "6. to delete the friend information at particular position\n"
			<< "7. to find the friend information in the list\n"
			<< "8. to display all friends' information\n"
			<< "9. to end list processing\n";
}

void testList(friendsList &listObj){
	menu();
	int choice, pos;
	string n, b, a, num, removeName, target;
	do{
		cout << "choose from menu: ";
		cin >> choice;
		cin.get();
		switch(choice){
		case 1:
			cout << "Enter the name:  ";
			getline(cin, n);
			cout << "Enter the date of birth: ";
			getline(cin, b);
			cout << "Enter the address: ";
			getline(cin, a);
			cout << "Enter the contact number: ";
			getline(cin, num);
			listObj.insertAtFront(n, b, a, num);
			break;
		case 2:
			cout << "Enter the name:  ";
			getline(cin, n);
			cout << "Enter the date of birth: ";
			getline(cin, b);
			cout << "Enter the address: ";
			getline(cin, a);
			cout << "Enter the contact number: ";
			getline(cin, num);
			listObj.insertAtBack(n, b, a, num);
			break;
		case 3:
			cout << "Enter the inserted position: ";
			cin >> pos;
			cin.get();
			cout << "Enter the name:  ";
			getline(cin, n);
			cout << "Enter the date of birth: ";
			getline(cin, b);
			cout << "Enter the address: ";
			getline(cin, a);
			cout << "Enter the contact number: ";
			getline(cin, num);
			listObj.insertAtPos(n, b, a, num, pos);
			break;

		case 4:
			if(listObj.removeFromFront(removeName)){
				cout << removeName << " information removed from list\n";
			}else{
				cout << "No element to remove." << endl;
			}
			break;
		case 5:
			if(listObj.removeFromBack(removeName)){
				cout << removeName << " information removed from list\n";
			}else{
				cout << "No element to remove. " << endl;
			}
			break;
		case 6:
			cout << "Enter the deleted position: ";
			cin >> pos;
			if(listObj.removeAtPos(removeName, pos)){
				cout << removeName << " information removed from list\n";
			}else{
				cout << "No element to remove. " << endl;
			}
			break;
		case 7:
			cout << "Enter the name need to be searched: ";
			getline(cin, target);
			if(listObj.search(target)!= NULL){
				cout << "found" << endl;
				cout << "Name: " << listObj.search(target) -> getName() << endl;
				cout << "Date of Birth: " << listObj.search(target) -> getBirthday() << endl;
				cout << "Address: " << listObj.search(target) -> getAddress() << endl;
				cout << "Contact Number: " << listObj.search(target) -> getContactNumber() << endl;
			}else{
				cout << "Not found." << endl;
			}
			break;
		case 8:
			listObj.print();
			break;
		case 9:
			cout << "End list test\n\n";
			return ;
			break;
		default:
			cout << "Invalid option." << endl;
		}

	}while(choice <= 9);
}

int main() {
	friendsList myFriendsList;
	testList(myFriendsList);

	return 0;
}
