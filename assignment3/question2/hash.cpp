/*
 * hash.cpp
 *
 *  Created on: Nov 5, 2019
 *      Author: Xiaofeng
 */


#include <iostream>
#include <string>
#include "hash.h"
using namespace std;

void Student :: setData(int id, string n, float mk){
	setId(id);
	setName(n);
	setMark(mk);
}

void Student :: setId(int id){
	if(id > 0){
		studentId = id;
	}else{
		id = 0;
		cout <<"Invalid student id input."<< endl;
	}
}

void Student :: setName(string n){
	if(n.length() > 0){
		name = n;
	}else{
		name = "\0";
		cout <<"Invalid student name input."<< endl;
	}
}

void Student :: setMark(float mk){
	if(mk > 0){
		marks_oop345 = mk;
	}else{
		marks_oop345 = 0;
		cout <<"Invalid student mark input."<< endl;
	}
}

int Student :: getId() const{
	return studentId;
}

string Student :: getName() const{
	return name;
}

float Student :: getMark() const{
	return marks_oop345;
}



Hash :: Hash(){
	hashTable = new Student*[tableSize];
	for(int i = 0; i < tableSize; i++ ){
		hashTable[i] = nullptr;
	}
}



int Hash :: hashFunction(int id){
	return id % tableSize;
}

void Hash :: insertItem(int id, string n, float mk){

	int hashIndex = hashFunction(id);
	Student *prev = nullptr;
	Student *temp = hashTable[hashIndex];

	while(temp != NULL){
		prev = temp;
		temp = temp -> next;
	}
	if(temp == nullptr){
		temp = new Student(id, n, mk);
		if(prev == nullptr){
			hashTable[hashIndex] = temp;
		}else{
			prev -> next = temp;
		}
	}else{
		temp -> name = n;
		temp -> marks_oop345 = mk;
	}

}

void Hash :: deleteItem(int id){
	int hashIndex = hashFunction(id);
	Student *p1;
	Student *p2;
	Student *temp;

	if(hashTable[hashIndex] == nullptr){
		cout << "No student found at id " << id << endl;
		return;
	}else if(hashTable[hashIndex] -> studentId == id && hashTable[hashIndex] -> next == nullptr){
		hashTable[hashIndex] = nullptr;
		cout << id << " was removed from the hash table." << endl;

	}else if(hashTable[hashIndex] -> studentId == id){
		temp = hashTable[hashIndex];
		hashTable[hashIndex] = hashTable[hashIndex] -> next;
		delete temp;
		cout << id << " was removed from the hash table." << endl;
	}else{
		p1 = hashTable[hashIndex] -> next;
		p2 = hashTable[hashIndex];
		while(p1 != nullptr && p1 -> studentId != id){
			p2 = p1;
			p1 = p1 -> next;
		}
		if(p1 == nullptr){
			cout << id << " was not found in the hash table." << endl;
		}else{
			temp = p1;
			p1 = p1 -> next;
			p2 -> next = p1;
			delete temp;
			cout << id << " was removed from the hash table." << endl;
		}
	}
}

void Hash :: searchItem(int id){
	int hashIndex = hashFunction(id);
	bool foundId = false;
	Student *ptr = hashTable[hashIndex];
	if(ptr != nullptr){
		while(ptr != nullptr){
			if(ptr -> studentId == id){
				foundId = true;
			}
			if(foundId == true){
				cout << "Student Id: " << ptr -> studentId << endl;
				cout << "Student Name: " << ptr  -> name << endl;
				cout << "Student Mark: " << ptr  -> marks_oop345 << endl;
			}
			ptr = ptr -> next;
		}

	}
	if(!foundId){
		cout << "No info was found in the hash table" << endl;
	}
}

void Hash :: displayItems()const{
	int count = 0;
	for(int i = 0; i < tableSize; i++){
		if(hashTable[i] != nullptr && hashTable[i] -> studentId){
			cout << "Student Id: " << hashTable[i] -> studentId << endl;
			cout << "Student Name: " << hashTable[i] -> name << endl;
			cout << "Student Mark: " << hashTable[i] -> marks_oop345 << endl;
			count++;
		}
	}
	if(count == 0){
		cout << "No Element to Display." << endl;
	}

}


Hash :: ~Hash(){
	for(int i = 0; i < tableSize; i++){
		Student *temp = hashTable[i];
		while(temp != nullptr){
			Student *p = temp;
			temp = temp -> next;
			delete p;
		}
	}
	delete[] hashTable;
}
