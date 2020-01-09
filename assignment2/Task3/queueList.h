/*
 * queuList.h
 *
 *  Created on: Oct 22, 2019
 *      Author: Xiaofeng
 */

#ifndef QUEUELIST_H_
#define QUEUELIST_H_

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
	int lengthIs();
	void insertAtBack(const ListT &value);
	bool removeFromFront(ListT &value);
	bool isEmpty()const;
	bool isFull(int maxsize) const;
	void print()const;

};

template <typename listT>
baseList<listT> :: baseList():firstPtr(nullptr), lastPtr(nullptr), length(0){}

template <typename listT>
baseList<listT> :: ~baseList(){
	if(!isEmpty()){
		Node<listT>*currentPtr = firstPtr;
		Node<listT> *tempPtr = nullptr;
		while(currentPtr != nullptr){
			tempPtr = currentPtr;
			cout << tempPtr -> data << '\n';
			currentPtr = currentPtr -> nextPtr;
			delete tempPtr;
		}
	}
	length = 0;
}

template <typename listT>
void baseList<listT> :: insertAtBack(const listT &value){
	Node<listT> *newPtr = getNewNode(value);
	if(isEmpty()){
		firstPtr = lastPtr = newPtr;
		firstPtr ->forwardPtr = lastPtr -> forwardPtr = nullptr;
		firstPtr -> backwardPtr = lastPtr -> backwardPtr = nullptr;
		length = 1;
	} else{
		lastPtr -> forwardPtr = newPtr;
		newPtr -> backwardPtr = lastPtr;
		lastPtr = newPtr;
		firstPtr -> backwardPtr = lastPtr;
		lastPtr -> forwardPtr = firstPtr;
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
			firstPtr = firstPtr -> forwardPtr;
			firstPtr -> backwardPtr = lastPtr;
			lastPtr -> forwardPtr = firstPtr;
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
int baseList<listT> :: lengthIs(){
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
	}else{
		Node<listT> *currentPtr = firstPtr;
		cout << "The list is: \n";
		if(currentPtr -> forwardPtr == nullptr){
			cout << currentPtr -> data << " ";
		}else{
			do {
				cout << currentPtr -> data << " ";
				currentPtr = currentPtr -> forwardPtr;
			}while(currentPtr != firstPtr);
		}
	}
	cout << endl;
}


template <typename queueT>
class QueueList {
private:
	baseList<queueT> *myList;
public:
	void enqueue(const queueT &data, int maxsize){
		if(!queueFull(maxsize)){
			myList->insertAtBack(data);
		}else{
			cout << "The queue is full." << endl;
		}
	}
	bool dequeue(queueT &data){
		return myList->removeFromFront(data);
	}
	bool queueEmpty()const{
		return myList-> isEmpty();
	}
	bool queueFull(int maxsize) const{
		return myList->isFull(maxsize);
	}
	int queueSize()const{
		return myList -> lengthIs();
	}
	void printQueue()const{
		myList->print();
	}
};



#endif /* QUEUELIST_H_ */
