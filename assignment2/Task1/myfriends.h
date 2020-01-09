/*
 * myfriends.h
 *
 *  Created on: Oct 20, 2019
 *      Author: Xiaofeng
 */

#ifndef MYFRIENDS_H_
#define MYFRIENDS_H_

#include <iostream>
#include <string>
using namespace std;

class Node{
	friend class friendsList;
private:
	string name, birthday, address, contactNumber;
	Node *forwardPtr;
	Node *backwardPtr;
public:
	explicit Node (string n, string b, string a, string num){
		setData(n, b, a, num);
		forwardPtr = nullptr;
		backwardPtr = nullptr;
	}
	void setData(string n, string b, string a, string num);
	void setName(string n);
	void setBirthday(string b);
	void setAddress(string a);
	void setContactNumber(string num);
	bool checkNum(string num);
	string getName()const;
	string getBirthday()const;
	string getAddress()const;
	string getContactNumber()const;

};

class friendsList{
private:
	Node *firstPtr;
	Node *lastPtr;
	Node *getNewNode(string n, string b, string a, string num){
		return new Node(n, b, a, num);
	}
	int size;
public:
	friendsList();
	~friendsList();
	void insertAtFront(string n, string b, string a, string num);
	void insertAtBack(string n, string b, string a, string num);
	void insertAtPos(string n, string b, string a, string num, int pos);
	Node *search(string n);
	bool removeFromFront(string &n);
	bool removeFromBack(string &n);
	bool removeAtPos(string &n,int pos);
	bool isEmpty()const;
	void print()const;
	int sizeIs()const;
};



#endif /* MYFRIENDS_H_ */
