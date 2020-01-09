/*
 * Book.cpp
 *
 *  Created on: Oct 4, 2019
 *      Author: Xiaofeng
 */

#include <string>
#include <iostream>
#include <cctype>
#include "Book.h"
using namespace std;


Book :: Book(){}
Book :: Book(string new_author, string new_title, string new_date){
	setData(new_author, new_title, new_date);
}

void Book :: setData(string new_author, string new_title, string new_date){
	setAuthor(new_author);
	setTitle(new_title);
	setDate(new_date);

}

void Book :: setAuthor(string new_author){
	new_author[0] = toupper(new_author[0]);
	int length = new_author.length();
	length = (length < 50? length : 50);
	author = new_author.substr(0, length);
	author[length] = '\0';

}

void Book :: setTitle(string new_title){
	int length = new_title.length();
	length = (length < 100 ? length : 99);
	title = new_title.substr(0, length);
	title[length] = '\0';
}
void Book :: setDate(string new_date){
	int year = stoi(new_date);
	if(year > 0){
		date = new_date;
	}else{
		date = "null";
	}

}

string Book :: getAuthor() const{
	return author;
}
string Book :: getTitle() const{
	return title;
}
string Book :: getDate() const{
	return date;
}

bool operator< (const Book &book1, const Book &book2)
{
	return (book1.author < book2.author);
}


