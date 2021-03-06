/*
 * Book.h
 *
 *  Created on: Oct 4, 2019
 *      Author: Xiaofeng
 */

#ifndef BOOK_H_
#define BOOK_H_

#include <string>
#include <iostream>
using namespace std;

class Book
{
public:
	Book();
	Book(string new_author, string new_title, string new_date);
	void setData(string new_author, string new_title, string new_date);
	void setAuthor(string new_author);
	void setTitle(string new_title);
	void setDate(string new_date);
	string getAuthor() const;
	string getTitle() const;
	string getDate() const;
	friend bool operator< (const Book &book1, const Book &book2);
private:
	string author, title, date;
};


#endif /* BOOK_H_ */
