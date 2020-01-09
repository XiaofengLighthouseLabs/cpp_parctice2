//============================================================================
// Name        : task2.cpp
// Author      : Xiaofeng Zhang
// Version     :
// Copyright   : Your copyright notice
// Description : assignment2 task2
//============================================================================

#include <iostream>
#include "stackList.h"
using namespace std;

void menu(){
	cout << "Enter one of the following: \n"
			<< "1. push to the stack\n"
			<< "2. pop from the stack\n"
			<< "3. print\n"
			<< "4. size of the stack\n"
			<< "5. exit the stack\n";
}

template<typename T>
void testStack(StackList<T> &obj){
	const int maxsize = 10;
	menu();
	int choice;
	T value, removeValue;
	do{
		cout << "choose from menu: ";
		cin >> choice;
		cin.get();
		switch(choice){
		case 1:
			cout << "Enter a value:  ";
			cin >> value;
			obj.push(value, maxsize);
			break;
		case 2:
			if(obj.pop(removeValue)){
				cout << removeValue << " pop from the stack\n";
			}else{
				cout << "No element to move." << endl;
			}
			break;
		case 3:
			obj.printStack();
			break;
		case 4:
			if(!obj.stackEmpty()){
				cout << "The number of elements in the stack is: ";
				cout << obj.stackSize();
				cout << endl;
			}else{
				cout << "No element in the stack." << endl;
			}
			break;

		case 5:
			cout << "End stack test\n\n";
			return;
			break;
		default:
			cout << "Invalid option." << endl;
		}
	}while(choice <= 5);

}

int main() {
	StackList<int> myStack;
	testStack(myStack);
	return 0;
}
