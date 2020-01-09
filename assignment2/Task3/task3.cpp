//============================================================================
// Name        : task3.cpp
// Author      : Xiaofeng Zhang
// Version     :
// Copyright   : Your copyright notice
// Description : assignment2 task3
//============================================================================

#include <iostream>
#include "queueList.h"
using namespace std;

void menu(){
	cout << "Enter one of the following: \n"
			<< "1. enqueue to the queue\n"
			<< "2. dequeue from the queue\n"
			<< "3. print\n"
			<< "4. queue size\n"
			<< "5. exit the queue\n";
}

template<typename T>
void testQueue(QueueList<T> &obj){
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
			obj.enqueue(value, maxsize);
			break;
		case 2:
			if(obj.dequeue(removeValue)){
				cout << removeValue << " dequeue from the queue\n";
			}else{
				cout << "No element to remove." << endl;
			}
			break;
		case 3:
			obj.printQueue();
			break;
		case 4:
			if(!obj.queueEmpty()){
				cout << "The number of elements in the queue is: ";
				cout << obj.queueSize();
				cout << endl;
			}else{
				cout << "No element in the queue." << endl;
			}

			break;
		case 5:
			cout << "End queue test\n\n";
			return;
			break;
		default:
			cout << "Invalid option." << endl;
		}

	}while(choice <= 5);

}

int main() {
	QueueList<int> myQueue;
	testQueue(myQueue);
	return 0;
}
