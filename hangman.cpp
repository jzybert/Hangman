#include <iostream>
#include <string>
#include <algorithm>
#include "Game.h"
using namespace std;

int main()
{
	string answer;
	cout << "Welcome to Hangman!\n";
	while(true)
	{
		cout << "\nWould you like to play? Yes or No?:";
		cin >> answer;
		transform(answer.begin(), answer.end(), answer.begin(), ::tolower);
		if(answer == "yes")
		{
			Game game = Game();
			game.startGame();
		}
		else if(answer == "no")
		{
			break;
		}
		else
		{
			cin.clear();
			cin.ignore();
			cout << "That was not Yes or No.\n\n";
		}
	}
}