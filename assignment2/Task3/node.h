/*
 * node.h
 *
 *  Created on: Oct 22, 2019
 *      Author: Xiaofeng
 */

#ifndef NODE_H_
#define NODE_H_

#include <iostream>
using namespace std;

template <typename NodeT> class baseList;

template <typename NodeT>
class Node{
	friend class baseList<NodeT>;
private:
	NodeT data;
	Node *forwardPtr;
	Node *backwardPtr;
public:
	explicit Node(const NodeT &info){
		forwardPtr = nullptr;
		backwardPtr = nullptr;
		setData(info);
	};
	void setData(const NodeT &info){
		data = info;
	}
	int getData() const{
		return data;
	}

};



#endif /* NODE_H_ */
