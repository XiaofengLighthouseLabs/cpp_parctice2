/*
 * FamilyTree.cpp
 *
 *  Created on: Nov 2, 2019
 *      Author: Xiaofeng
 */


#include <iostream>
#include <string>
#include "FamilyTree.h"
using namespace std;

void Family_Member :: setData(int a, float h, string n){
	setAge(a);
	setHeight(h);
	setName(n);
}

void Family_Member :: setAge(int a){
	if(a >= 0){
		age = a;
	}else{
		age = 0;
		cout << "Invalid Age Input." << endl;
	}
}

void Family_Member :: setHeight(float h){
	if(h >= 0){
		height = h;
	}else{
		height = 0;
		cout << "Invalid Height Input." << endl;
	}
}

void Family_Member  :: setName(string n){
	if(n.length() > 0){
		name = n;
	}else{
		name = '\0';
	}
}

int Family_Member :: getAge()const{
	return age;
}

float Family_Member :: getHeight()const{
	return height;
}

string Family_Member :: getName()const{
	return name;
}

FamilyTree :: FamilyTree(){
	rootPtr = nullptr;
};

FamilyTree :: ~FamilyTree(){
	destroyFamilyTree(rootPtr);
};

void FamilyTree :: insertFamilyTree(int a, float h, string n){
	insertHelper(rootPtr, a, h, n);
};

void FamilyTree :: removeFamilyMember(string n){
	remove(rootPtr, n);
}

void FamilyTree :: inOrderDisplay()const{
	if(rootPtr != nullptr){
		inOrderHelper(rootPtr);
	}else{
		cout << "No Element To Be Display." << endl;
	}
}

bool FamilyTree :: searchFamilyTree(string n){
	if(search(rootPtr, n)){
		return true;
	}else{
		return false;
	}
}

void FamilyTree :: updateFamilyTree(string n, int nA, float nH, string nN){
	remove(rootPtr, n);
	insertHelper(rootPtr, nA, nH, nN);
}
