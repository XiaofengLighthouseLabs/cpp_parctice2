/*
 * hash.h
 *
 *  Created on: Nov 5, 2019
 *      Author: Xiaofeng
 */

#ifndef HASH_H_
#define HASH_H_

#include <iostream>
#include <string>
using namespace std;
const int tableSize = 30;

class Student{
	friend class Hash;
private:
	int studentId;
	string name;
	float marks_oop345;
	Student *next;
public:
	Student(int id, string n, float mk){
		setData(id, n, mk);
		next = nullptr;
	}
	void setData(int id, string n, float mk);
	void setId(int id);
	void setName(string n);
	void setMark(float mk);
	int getId() const;
	string getName() const;
	float getMark() const;
};

class Hash{
private:
	Student **hashTable;


public:
	Hash();
	int hashFunction(int id);
	void insertItem(int id, string n, float mk);
	void deleteItem(int id);
	void displayItems()const;
	void searchItem(int id);
	~Hash();
};



#endif /* HASH_H_ */
