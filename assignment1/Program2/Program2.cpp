//============================================================================
// Name        : Program2.cpp
// Author      : Xiaofeng
// Version     :
// Copyright   :
// Description : Assignment1_Program2
//============================================================================

#include <iostream>
#include <map>
#include <string>
#include "dictionary.h"
using namespace std;


int main() {
	map<string, Notations> Dictionary;
	map<string, Notations> :: iterator it;
	int choice;
	string key, tempMeaning, tempSynonym, tempAntonym, tempExample;
	char ch;
	while (1){
		cout << "1.Insert" << endl;
		cout << "2.Search" << endl;
		cout << "3.Display All" << endl;
		cout << "4.Size" << endl;
		cout << "5.Update" << endl;
		cout << "6.Delete" << endl;
		cout << "7.Exit" << endl;

		cout << "Enter your Choice: ";
		cin >> choice;
		cin.clear();
		cin.ignore();
		switch(choice){
		case 1:
			cout << "Enter the word:";
			getline(cin, key);
			cout << "Enter the meaning: ";
			getline(cin, tempMeaning);
			cout << "Enter the synonym: ";
			getline(cin, tempSynonym);
			cout << "Enter the antonym: ";
			getline(cin, tempAntonym);
			cout << "Enter the example sentence: ";
			getline(cin, tempExample);
			Dictionary.insert(pair<string, Notations>(key, Notations(tempMeaning, tempSynonym, tempAntonym, tempExample)));
			break;
		case 2:
			cout << "Enter the word to be searched: ";
			getline(cin, key);
			if (Dictionary.find(key) == Dictionary.end()){
				cout << "Not found" << endl;
			}else{
				it = Dictionary.find(key);
				cout << it -> first << endl;
				it -> second.disPlayNotations();
				cout << endl;
				cout << "Press ENTER to continue." << endl;
				cin.clear();
				cin.ignore();
			}
			cout << endl;
			break;
		case 3:
			cout << "Display Dictionary: " << endl;
			for(it = Dictionary.begin(); it != Dictionary.end(); it++){
				cout << endl;
				cout << it ->first <<endl;
				it -> second.disPlayNotations();
			}
			cout << endl;
			cout << endl;

			break;
		case 4:
			cout << "Size of dictionary is: ";
			cout << Dictionary.size() << endl;
			break;
		case 5:
			cout << "Enter the word to be updated: ";
			getline(cin, key);
			if(Dictionary.find(key) == Dictionary.end()){
				cout << "Not found" << endl;
			}else{

				while(ch != 'e'){

					cout << "a.Update meaning" << endl;
					cout << "b.Update synonym" << endl;
					cout << "c.Update antonym" << endl;
					cout << "d.Update example sentence" << endl;
					cout << "e save update and display" << endl;
					cout << "Enter updated choice: ";
					cin >> ch;
					cin.clear();
					cin.ignore();
					switch(ch){
					case 'a':
						cout << "Enter the updated meaning: ";
						getline(cin, tempMeaning);
						Dictionary[key].setMeaning(tempMeaning);
						break;
					case 'b':
						cout << "Enter the updated synonym: ";
						getline(cin, tempSynonym);
						Dictionary[key].setSynonym(tempSynonym);
						break;
					case 'c':
						cout << "Enter the updated antonym: ";
						getline(cin, tempAntonym);
						Dictionary[key].setAntonym(tempAntonym);
						break;
					case 'd':
						cout << "Enter the updated example sentence: " ;
						getline(cin, tempExample);
						Dictionary[key].setExample(tempExample);
						break;
					case 'e':

						cout << "Exit updated choices." << endl;
						cout << key << ":" << endl;
						Dictionary[key].disPlayNotations();
						cout << endl;
						cout << "Press ENTER to continue." << endl;
						cin.clear();
						cin.ignore();
						break;
					default:
						cout << "Wrong Updated Choice." << endl;

					}
				}
			};

			break;

		case 6:
			cout << "Enter the word to be deleted: ";
			getline(cin, key);
			if(Dictionary.find(key) == Dictionary.end()){
				cout << "Not found" << endl;
			}else{
				Dictionary.erase(key);
			}

			break;
		case 7:
			cout << "Thanks and bye!" << endl;
			exit(1);
			break;
		default:
			cout << "Wrong Choice." << endl;
		}

	}

	return 0;
}
