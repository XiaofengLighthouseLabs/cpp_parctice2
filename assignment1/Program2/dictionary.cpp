/*
 * dictionary.cpp
 *
 *  Created on: Oct 9, 2019
 *      Author: Xiaofeng
 */


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include "dictionary.h"
using namespace std;

Notations :: Notations(){};
Notations :: Notations(string tempMeaning, string tempSynonym, string tempAntonym, string tempExample)
:meaning(tempMeaning), synonym(tempSynonym), antonym(tempAntonym), example_sentence(tempExample){};

void Notations :: setMeaning(string tempMeaning){
		meaning = tempMeaning;
	}
void Notations :: setSynonym(string tempSynonym){
		synonym = tempSynonym;
	}
void Notations :: setAntonym(string tempAntonym){
		antonym = tempAntonym;
	}
void Notations :: setExample(string tempExample){
			example_sentence = tempExample;
		}
string Notations ::  getMeaning() const{
		return meaning;
	}
string Notations :: getSynonym() const{
		return synonym;
	}
string Notations :: getAntonym() const{
		return antonym;
	}
string Notations :: getExample() const{
			return example_sentence;
		}
void Notations :: disPlayNotations() const{
		cout << "Meaning: " << getMeaning();
		cout << "\nSynonym: " << getSynonym();
		cout << "\nAntonym: " << getAntonym();
		cout << "\nExample Sentence: " << getExample();
	}

