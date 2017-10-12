#include <iostream>
#include <string>
#include <vector>
#include "Game.h"
#include "Word.h"

using namespace std;

Game::Game()
{
	wrongGuesses = 6;
	Word w = Word();
	word = w.chooseWord();
	for(int i = 0; i < word.length(); i++)
	{
		hiddenWord += "*";
	}
	cout << "\nYour word is " << word.length() << " letters long.\n\n";
}

void Game::startGame()
{
	bool letterWrong;
	char guess;
	bool bankCheck;
	bool gameWon;
	while(true)
	{
		letterWrong = true;
		cout << "\n" << hiddenWord << "\nGuess a letter: ";
		cin >> guess;
		
		for (int i = 0; i < word.length(); i++)
		{
			if (guess == word[i])
			{
				hiddenWord[i] = word[i];
				letterWrong = false;
			}
		}
		
		if(letterWrong)
		{
			bankCheck = false;
			for (int i = 0; i < bank.size(); i++)
			{
				if(bank[i] == guess)
				{
					bankCheck = true;
				}
			}
			
			if(!bankCheck)
			{
				bank.push_back(guess);
				wrongGuesses--;
			}
			
			if(wrongGuesses >= 0)
			{
				cout << "\nYou have " << wrongGuesses << "remaining guesses.\n";
			}
			else {
				cout << "\nYou lost. The word was '" << word << "'.\n";
				break;
			}
		}
		
		cout << "\n";
		if(wrongGuesses <= 5) {cout << " O\n";}
		if(wrongGuesses <= 3) {cout << "-";}
		if(wrongGuesses == 4) {cout << " ";}
		if(wrongGuesses <= 4) {cout << "|";}
		if(wrongGuesses <= 2) {cout << "-\n";}
		if(wrongGuesses <= 1) {cout << "|";}
		if(wrongGuesses <= 0) {cout << " |\n";}
		cout << endl;
				
		cout << "Wrong Letters Used: ";
		for(int i = 0; i < bank.size(); i++)
		{
			cout << bank[i] << " ";
		}
		cout << endl;

		for(int i = 0; i < word.size(); i++) //checks if there is any astricks left
		{
			if(hiddenWord[i] == '*')
			{
				gameWon = false;
				break;
			}
			else
			{
				gameWon=true;
			}
		}
		if(gameWon == true)
		{
			cout << "\nYou've won! The word was: " << word << endl;
			break;
		}
	}
}