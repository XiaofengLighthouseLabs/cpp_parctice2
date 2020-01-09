//============================================================================
// Name        : Question1.cpp
// Author      : Xiaofeng
// Version     :
// Copyright   : Your copyright notice
// Description : Assignment3_q1
//============================================================================

#include <iostream>
#include <string>
#include "FamilyTree.h"
using namespace std;

void menu(){
	cout << "Enter one of the following: \n"
			<< "1. to insert family member\n"
			<< "2. to delete family member\n"
			<< "3. to update family member\n"
			<< "4. to search family member\n"
			<< "5. to display all family members\n"
			<< "6. exit\n";
}

void test(FamilyTree &MyFamilyTree){
	menu();
	int choice{0}, a{0}, nA{0};
	float h{0}, nH{0};
	string n, nN;
	do{
		cout << "choose from menu: ";
		cin >> choice;
		cin.get();
		switch(choice){
		case 1:
			cout << "Enter the family member name:  ";
			getline(cin, n);
			do{
				cout << "Enter the family member age: ";
				cin >> a;
				if(!cin){
					cin.clear();
					cin.ignore();
					cout << "Invalid enter. Please enter numbers" << endl;
				}
			}while(!a);
			cin.get();
			do{
				cout << "Enter the family member height (cm): ";
				cin >> h;
				if(!cin){
					cin.clear();
					cin.ignore();
					cout << "Invalid enter. Please enter numbers" << endl;
				}
			}while(!h);
			MyFamilyTree.insertFamilyTree(a, h, n);
			break;
		case 2:
			cout << "Enter the family member name need to be deleted:  ";
			getline(cin, n);
			if(MyFamilyTree.searchFamilyTree(n)){
				MyFamilyTree.removeFamilyMember(n);
				cout << n << " information removed." << endl;
			}else{
				cout << "No element to remove." << endl;
			}
			break;
		case 3:
			cout << "Enter the family member name need to be updated:  ";
			getline(cin, n);
			if(MyFamilyTree.searchFamilyTree(n)){
				cout << "Enter the updated family member name:  ";
				getline(cin, nN);
				cout << "Enter the updated family member age: ";
				cin >> nA;
				cout << "Enter the updated family member height: ";
				cin >> nH;
				MyFamilyTree.updateFamilyTree(n, nA, nH, nN);
			}else{
				cout << "No element to update." << endl;
			}

			break;

		case 4:
			cout << "Enter the family member name need to be searched: ";
			getline(cin, n);
			if(!MyFamilyTree.searchFamilyTree(n)){
				cout << "Not Found." << endl;
			}
			break;
		case 5:
			MyFamilyTree.inOrderDisplay();
			break;
		case 6:
			cout << "Exit\n\n";
			return ;
			break;
		default:
			cout << "Invalid option." << endl;
		}

	}while(choice <= 6);
}

int main() {

	FamilyTree MyFamilyTree;
	test(MyFamilyTree);
	return 0;
}
