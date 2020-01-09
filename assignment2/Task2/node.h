/*
 * stackList.cpp
 *
 *  Created on: Oct 21, 2019
 *      Author: Xiaofeng
 */


#include <iostream>
using namespace std;

template <typename NodeT> class baseList;

template <typename NodeT>
class Node{
	friend class baseList<NodeT>;
private:
	NodeT data;
	Node *nextPtr;
public:
	explicit Node(const NodeT &info){
		nextPtr = nullptr;
		setData(info);
	};
	void setData(const NodeT &info){
		data = info;
	}
	int getData() const{
		return data;
	}

};



