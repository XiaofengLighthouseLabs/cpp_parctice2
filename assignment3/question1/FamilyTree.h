/*
 * familyMember.h
 *
 *  Created on: Nov 2, 2019
 *      Author: Xiaofeng
 */

#ifndef FAMILYTREE_H_
#define FAMILYTREE_H_

#include <iostream>
#include <string>
using namespace std;

class Family_Member{
	friend class FamilyTree;
private:
	int age;
	float height;
	string name;
	Family_Member *LChild;
	Family_Member *RChild;
public:
	Family_Member(int a, float h, string n){
		setData(a, h, n);
		LChild = nullptr;
		RChild = nullptr;
	}
	void setData(int a, float h, string n);
	void setAge(int a);
	void setHeight(float h);
	void setName(string n);
	int getAge() const;
	float getHeight() const;
	string getName() const;

};

class FamilyTree{
private:
	Family_Member *rootPtr;
	void destroyFamilyTree(Family_Member *ptr){
		if(!ptr){
			return;
		}
		destroyFamilyTree(ptr -> LChild);
		destroyFamilyTree(ptr -> RChild);
		delete ptr;
	};

	void insertHelper(Family_Member *&ptr, int a, float h, string n){
		if(ptr == nullptr){
			ptr = new Family_Member(a, h, n);
		}else{
			if(n < ptr -> name){
				insertHelper(ptr -> LChild, a, h, n);
			}else{
				if(n > ptr -> name){
					insertHelper(ptr -> RChild, a, h, n);
				}else{
					cout << n << " duplication" << endl;
				}
			}
		}
	}

	void makeDeletion(Family_Member *&ptr){
		Family_Member *nodeToDelete = ptr;
		Family_Member *attachPtr;
		if(ptr -> RChild == nullptr){
			ptr = ptr -> LChild;
		}else if(ptr -> LChild == nullptr){
			ptr = ptr -> RChild;
		}else{
			attachPtr = ptr -> RChild;
			while(attachPtr -> LChild != nullptr){
				attachPtr = attachPtr -> LChild;
				attachPtr -> LChild = ptr -> LChild;
				ptr = ptr -> RChild;
			}
		}
		delete nodeToDelete;
	}

	void remove(Family_Member *&ptr, string n){
		if(ptr == nullptr){
			return;
		}
		if(n < ptr -> name){
			remove(ptr -> LChild, n);
		}else if(n > ptr-> name){
			remove(ptr -> RChild, n);
		}else{
			makeDeletion(ptr);
		}

	}

	void inOrderHelper(Family_Member *ptr) const{
		if(ptr != nullptr){
			inOrderHelper(ptr -> LChild);
			cout << "Name: " << ptr -> name <<endl;
			cout << "Age: " << ptr -> age << endl;
			cout << "Height: " << ptr -> height << endl;
			inOrderHelper(ptr -> RChild);
		}
	}

	bool search(Family_Member *ptr, string n)const{
		while(ptr != nullptr){
			if(ptr -> name == n){
				cout << "Found" << endl;
				cout << "Name: " << ptr -> name << endl;
				cout << "Age: " << ptr -> age << endl;
				cout << "Height: " <<ptr -> height << endl;
				return true;
			}else if(n < ptr -> name){
				ptr = ptr -> LChild;
			}else{
				ptr = ptr -> RChild;
			}
		}
		return false;
	}


public:
	FamilyTree();
	~FamilyTree();
	void insertFamilyTree(int a, float h, string n);
	void removeFamilyMember(string n);
	bool searchFamilyTree(string n);
	void updateFamilyTree(string n, int nA, float nH, string nN);
	void inOrderDisplay()const;


};



#endif /* FAMILYTREE_H_ */
