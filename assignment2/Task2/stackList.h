/*
 * stackList.h
 *
 *  Created on: Oct 21, 2019
 *      Author: Xiaofeng
 */

#ifndef STACKLIST_H_
#define STACKLIST_H_

#include <iostream>
#include "node.h"
using namespace std;



template <typename ListT>
class baseList{
private:
	Node<ListT> *firstPtr;
	Node<ListT> *lastPtr;
	int length;
	Node<ListT> *getNewNode(const ListT &value){
		return new Node<ListT>(value);
	}
public:
	baseList();
	~baseList();
	int lengthIs()const;
	void insertAtFront(const ListT &value);
	bool removeFromFront(ListT &value);
	bool isEmpty()const;
	bool isFull(int maxsize) const;
	void print()const;

};

template <typename listT>
baseList<listT> :: baseList(){
	firstPtr = nullptr;
	lastPtr = nullptr;
	length = 0;
};

template <typename listT>
baseList<listT> :: ~baseList(){
	if(!isEmpty()){
		Node<listT>*currentPtr = firstPtr;
		Node<listT> *tempPtr = nullptr;
		while(currentPtr != nullptr){
			tempPtr = currentPtr;
			currentPtr = currentPtr -> nextPtr;
			delete tempPtr;
		}
		length = 0;
	}
}

template <typename listT>
void baseList<listT> :: insertAtFront(const listT &value){
	Node<listT> *newPtr = getNewNode(value);
	if(isEmpty()){
		firstPtr = lastPtr = newPtr;
		length = 1;
	} else{
		newPtr -> nextPtr = firstPtr;
		firstPtr = newPtr;
		++length;
	}
}

template <typename listT>
bool baseList<listT>:: removeFromFront(listT &value){
	if(isEmpty()){
		return false;
	}else{
		Node<listT> *tempPtr = firstPtr;
		if(firstPtr == lastPtr){
			length = 1;
			firstPtr = lastPtr = nullptr;
			--length;
		}else{
			firstPtr = firstPtr -> nextPtr;
			--length;
		}
		value = tempPtr -> data;
		delete tempPtr;
		return true;
	}
}

template <typename listT>
bool baseList<listT> :: isEmpty()const{
	return firstPtr == nullptr;
}

template <typename listT>
int baseList<listT> :: lengthIs()const{
	return length;
}

template <typename listT>
bool baseList<listT> :: isFull(int maxsize)const{
	if( length == maxsize){
		return true;
	}else{
		return false;
	}
}

template <typename listT>
void baseList<listT> :: print()const{
	if(isEmpty()){
		cout <<"The list is empty\n\n";
		return;
	}
	Node<listT> *currentPtr = firstPtr;
	cout << "The list is: ";
	while(currentPtr != nullptr){
		cout << currentPtr -> data << " ";
		currentPtr = currentPtr -> nextPtr;
	}
	cout << endl;
}


template <typename stackT>
class StackList {
private:
	baseList<stackT> *myList;
public:

	void push(const stackT &data, int maxsize){
		if(!stackFull(maxsize)){
			myList->insertAtFront(data);
		}else{
			cout << "The stack is full." << endl;
		}
	}
	bool pop(stackT &data){
		return myList->removeFromFront(data);
	}
	bool stackEmpty()const{
		return myList-> isEmpty();
	}
	bool stackFull(int maxsize) const{
		return myList->isFull(maxsize);
	}
	int stackSize()const{
		return myList-> lengthIs();
	}
	void printStack()const{
		myList->print();
	}
};



#endif /* STACKLIST_H_ */
