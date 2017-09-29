#include <iostream>
#include <stdlib.h>
#include <string>
#include "Word.h"

using namespace std;

void Word::readInCategory()
{
	do {
		cout << "\nChoose a category number:\n1. Food\n2. Animal\n3. Miscellaneous\n>> ";
		cin >> categoryNum;
		if (categoryNum < 1 || categoryNum > 3)
		{
			cin.clear();
			cin.ignore();
			cout << "That is not a correct input." << endl;
		}
	} while(categoryNum < 1 && categoryNum > 3);
}

string Word::chooseWord()
{
	readInCategory();
	
	string word;
	switch(categoryNum) {
		case 1:
			word = FOODS[rand() % 10];
			break;
		case 2:
			word = ANIMALS[rand() % 10];
			break;
		case 3:
			word = MISC[rand() % 10];
			break;
	}
	
	return word;
}









