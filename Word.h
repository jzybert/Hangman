#ifndef WORD_H
#define WORD_H

#include <string>

using namespace std;

class Word
{
private:
	string FOODS[10] = {"apple", "salmon", "tomato", "sauerkraut", "steak", "lobster", "broccoli", "mushroom", "pizza", "lemon"};
	string ANIMALS[10] = {"lion", "monkey", "giraffe", "mouse", "orangutan", "peacock", "molerat", "roadrunner", "spider", "elephant"};
	string MISC[10] = {"rocket", "building", "umbrella", "studio", "person", "shoe", "swingset", "water", "balloon", "sunglasses"};
	int categoryNum;
	/** Prompt the user to choose a category and read their input. */
	void readInCategory();
public:
	/** Choose a random word based on the given category.
	 * @return the word
	 */
	string chooseWord();
};

#endif