/*
 * dictionary.h
 *
 *  Created on: Oct 5, 2019
 *      Author: Xiaofeng
 */

#ifndef DICTIONARY_H_
#define DICTIONARY_H_

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;


class Notations{
private:
	string meaning, synonym, antonym, example_sentence;
public:
	Notations();
	Notations(string tempMeaning, string tempSynonym, string tempAntonym, string tempExample);

	void setMeaning(string tempMeaning);
	void setSynonym(string tempSynonym);
	void setAntonym(string tempAntonym);
	void setExample(string tempExample);
	string getMeaning() const;
	string getSynonym() const;
	string getAntonym() const;
	string getExample() const;
	void disPlayNotations() const;
};


#endif /* DICTIONARY_H_ */
