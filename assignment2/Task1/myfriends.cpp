/*
 * myfriends.cpp
 *
 *  Created on: Oct 20, 2019
 *      Author: Xiaofeng
 */

#include <iostream>
#include <string>
#include "myfriends.h"
using namespace std;

void Node :: setData(string n, string b, string a, string num){
	setName(n);
	setBirthday(b);
	setAddress(a);
	setContactNumber(num);
}
void Node :: setName(string n){
	if(n.length() > 0){
		name = n;
	}else{
		name = '\0';
	}

}
void Node :: setBirthday(string b){
	if(b.length() > 0){
		birthday = b;
	}else{
		birthday = '\0';
	}

}
void Node :: setAddress(string a){
	if(a.length() > 0){
		address = a;
	}else{
		address = '\0';
	}
}
bool Node :: checkNum(string num){
	bool isNum = true;
	for (unsigned int i = 0; i < num.length(); i++){
		if(!isdigit(num[i])){
			isNum = false;
			break;
		}
	}
	return isNum;
}
void Node :: setContactNumber(string num){
	if(checkNum(num)){
		if(stoi(num) > 0){
			contactNumber = num;
		}
	}else{
		cout << "Invalid contact number. Set contact number to 0.\n";
		contactNumber = "0";
	}

}
string Node :: getName()const{
	return name;
}
string Node :: getBirthday()const{
	return birthday;
}
string Node :: getAddress()const{
	return address;
}
string Node :: getContactNumber()const{
	return contactNumber;
}



friendsList :: friendsList():firstPtr(nullptr), lastPtr(nullptr), size(0){}

friendsList :: ~friendsList(){
	if(!isEmpty()){
		cout << "Distroying nodes...\n";
		Node *currentPtr = firstPtr;
		Node *tempPtr = nullptr;
		while(currentPtr != nullptr){
			tempPtr = currentPtr;
			currentPtr = currentPtr -> forwardPtr;
			delete tempPtr;
		}
		size = 0;
	}
	cout << "All nodes destroyed\n\n";
}


void friendsList :: insertAtFront(string n, string b, string a, string num){
	Node *newPtr = getNewNode(n, b, a, num);
	if(isEmpty()){
		firstPtr = lastPtr = newPtr;
		firstPtr ->forwardPtr = lastPtr -> forwardPtr = nullptr;
		firstPtr -> backwardPtr = lastPtr -> backwardPtr = nullptr;
	} else{
		newPtr -> forwardPtr = firstPtr;
		firstPtr -> backwardPtr = newPtr;
		firstPtr = newPtr;
		firstPtr -> backwardPtr = lastPtr;
		lastPtr -> forwardPtr = firstPtr;
	}
	size++;
}

void friendsList :: insertAtBack(string n, string b, string a, string num){
	Node *newPtr = getNewNode(n, b, a, num);
	if(isEmpty()){
		firstPtr = lastPtr = newPtr;
		firstPtr ->forwardPtr = lastPtr -> forwardPtr = nullptr;
		firstPtr -> backwardPtr = lastPtr -> backwardPtr = nullptr;
	} else{
		lastPtr -> forwardPtr = newPtr;
		newPtr -> backwardPtr = lastPtr;
		lastPtr = newPtr;
		firstPtr -> backwardPtr = lastPtr;
		lastPtr -> forwardPtr = firstPtr;
	}
	size++;
}

void friendsList :: insertAtPos(string n, string b, string a, string num, int pos){
	if(pos < 1 || pos > sizeIs() + 1){
		cout << "Invalid position." << endl;
	}else{
		Node *tempPtr = firstPtr;
		Node *newPtr = getNewNode(n, b, a, num);
		if(isEmpty()){
			firstPtr = lastPtr = newPtr;
			firstPtr ->forwardPtr = lastPtr -> forwardPtr = nullptr;
			firstPtr -> backwardPtr = lastPtr -> backwardPtr = nullptr;
			size++;
		}else if(pos == 1){
			insertAtFront(n, b, a, num);
		}else if(pos == sizeIs() + 1){
			insertAtBack(n, b, a, num);
		}else{
			for(int i = 1; i < pos - 1; i++){
				tempPtr = tempPtr -> forwardPtr;
			};
			newPtr -> forwardPtr = tempPtr -> forwardPtr;
			(newPtr -> forwardPtr) -> backwardPtr  = newPtr;
			tempPtr -> forwardPtr = newPtr;
			newPtr -> backwardPtr = tempPtr;
			size++;
		}

	}
}


bool friendsList :: removeFromFront(string &n){
	if(isEmpty()){
		return false;
	}else{
		Node *tempPtr = firstPtr;
		if(firstPtr == lastPtr){
			firstPtr = lastPtr = nullptr;
		}else{
			firstPtr = firstPtr -> forwardPtr;
			firstPtr -> backwardPtr = lastPtr;
			lastPtr -> forwardPtr = firstPtr;
		}
		n = tempPtr -> name;
		delete tempPtr;
		size--;
		return true;
	}
}



bool friendsList :: removeFromBack(string &n){
	if(isEmpty()){
		return false;
	}else{
		Node *tempPtr = lastPtr;
		if(firstPtr == lastPtr){
			firstPtr = lastPtr = nullptr;
		}else{
			lastPtr = lastPtr -> backwardPtr;
			lastPtr -> forwardPtr = firstPtr;
			firstPtr -> backwardPtr = lastPtr;
		}

		n = tempPtr -> name;
		delete tempPtr;
		size--;
		return true;
	}
}

bool friendsList :: removeAtPos(string &n, int pos){
	if(isEmpty()){
		return false;
	}else if(pos < 1 || pos > sizeIs() + 1){
		cout << "Invalid position." << endl;
		return false;
	}else{
		Node *tempPtr = firstPtr;
		for(int i = 1; i < pos; i++){
			tempPtr = tempPtr -> forwardPtr;
		};
		if(pos == 1){
			removeFromFront(n);
		}else if(tempPtr == lastPtr){
			removeFromBack(n);
		}else {
			(tempPtr -> backwardPtr) -> forwardPtr = tempPtr -> forwardPtr;
			(tempPtr -> forwardPtr) -> backwardPtr = tempPtr -> backwardPtr;
			n = tempPtr -> name;
			delete tempPtr;
			size--;
		}
		return true;
	}
}

Node *friendsList :: search(string target){
	if(isEmpty()){
		cout <<"The list is empty\n\n";
		return NULL;
	}else{
		Node *currentPtr = firstPtr;
		int flag = 0;
		while(currentPtr -> forwardPtr != firstPtr){
			if(currentPtr -> name == target){
				flag = 1;
				break;
			}
			currentPtr = currentPtr -> forwardPtr;
		}
		if(currentPtr -> name == target){
			flag = 1;
		}
		if(flag == 1){
			return currentPtr;
		}else{
			return NULL;
		}
	}


}

bool friendsList :: isEmpty()const{
	return firstPtr == nullptr;
}

int friendsList :: sizeIs()const{
	return size;
}

void friendsList :: print()const{
	if(isEmpty()){
		cout <<"The list is empty\n\n";
		return;
	}else{
		Node *currentPtr = firstPtr;
		cout << "The list is: \n";
		if(currentPtr -> forwardPtr == nullptr){
			cout << "Name: " << currentPtr -> name << '\n'
					<< "Date of Birth: " << currentPtr -> birthday << '\n'
					<< "Address: " << currentPtr -> address << '\n'
					<< "Contact Number: " << currentPtr -> contactNumber << endl;
		}else{
			do{
				cout << "Name: " << currentPtr -> name << '\n'
						<< "Date of Birth: " << currentPtr -> birthday << '\n'
						<< "Address: " << currentPtr -> address << '\n'
						<< "Contact Number: " << currentPtr -> contactNumber << endl;
				currentPtr = currentPtr -> forwardPtr;
			}while(currentPtr != firstPtr);
		}
	}
}
