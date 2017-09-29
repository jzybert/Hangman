#ifndef GAME_H
#define GAME_H

#include <string>
#include <vector>

using namespace std;

class Game
{
private:
	int wrongGuesses;
	string word;
	string hiddenWord;
	vector<char> bank;
public:
	Game();
	void startGame();
};

#endif