#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

string Word()//chosing the different words
{
	int category;
	string chosenword;
	bool wordGot = true;
	while(wordGot)
		{
			cout << "\nChoose a category:\n1. Food\n2. Animal\n3. Miscellaneous\n>> ";
			cin >> category;
	
			if(category == 1)
			{
			string WordBankF[]={"apple", "salmon", "tomato", "sauerkraut", "steak", "lobster", "broccoli", "mushroom", "pizza", "lemon"};
			chosenword=WordBankF[rand()%10];
			wordGot = false;
			}
			else if(category == 2)
			{
			string WordBankA[]={"lion", "monkey", "giraffe", "mouse", "orangutan", "peacock", "molerat", "roadrunner", "spider", "elephant"};
			chosenword=WordBankA[rand()%10];
			wordGot = false;
			}
			else if(category == 3)
			{
			string WordBankM[]={"rocket", "building", "umbrella", "studio", "person", "shoe", "swingset", "water", "balloon", "sunglasses"};
			chosenword=WordBankM[rand()%10];
			wordGot = false;
			}
			else
			{
				cin.clear();
				cin.ignore();
				cout << "That was not a number.\n\n";;
			}
		}
	return chosenword; //chosenword is put into place of Word()
}

int main()
{
	srand(time(NULL));
	char input;
	int wrong=6;
	string answer;
	string word;
	string guess;
	bool complete;
	bool letterWrong;
	bool bankcheck;
	vector<char> bank;

	cout << "Welcome to Hangman!\n";

	while(true)
	{
		bank.clear();
		cout << "\nWould you like to play? Yes or No?\n";
		cout << ">> ";
		cin >> answer;
		transform(answer.begin(), answer.end(), answer.begin(), ::tolower);//makes it lowercase
		if(answer == "yes")
		{
			word = Word();
			cout << "\n";
			cout << "Your word is " << word.size() << " letters long.\n\n";
			wrong = 6;

			guess.resize(word.size()); //to make guess the size of the word
			for(int i=0; i < word.size(); i++)//cycles throuhg each letter
			{
				guess[i]='*';//will make every letter of guess an asterik
			}

			while(true) //GAME
			{
				letterWrong = true;
				cout << "\n";
				cout << guess << endl;
				cout << "\n";
				cout << "Your guess: ";

				cin >> input;
				system("cls");
				
				for(int i=0; i < word.size(); i++)
				{
					if(input==word[i])//checks if input matches with a letter in word
					{
						guess[i]=word[i];
						letterWrong = false;
					}
				}
				if(letterWrong==true)
				{

					bankcheck=false;
					for(int i = 0; i < bank.size(); i++)
					{
						if(bank[i] == input)
						{
							bankcheck=true;
						}
					}
					if(!bankcheck)
					{
						bank.push_back(input);
						wrong--;
					}

					if(wrong >= 0)
					{
						cout << "\nYou have " << wrong << " remaining guesses.\n";	
					}

					else
					{
						cout << "\nYou have lost. The word was '" << word << "'.\n";
						break;
					}
				}
				cout << "\n";
				if(wrong<=5)
					cout << " O\n";
				if(wrong<=3)
					cout << "-";
				if(wrong==4)
					cout << " ";
				if(wrong<=4)
					cout << "|";
				if(wrong<=2)
					cout << "-\n";
				if(wrong<=1)
					cout << "|";
				if(wrong<=0)
					cout << " |\n";
				cout << endl;

				cout << "Wrong Letters Used: ";
				
				for(int i = 0; i < bank.size(); i++)
				{
					cout << bank[i] << " ";
				}

				cout << endl;

				for(int i=0; i < word.size(); i++)//checks if there is any astricks left
				{
					if(guess[i]=='*')
					{
						complete=false;
						break;
					}
					else
					{
						complete=true;
					}
				}
				if(complete == true)
				{
					cout << "\nYou've won! The word was: " << word;
					break;
				}
			}
			cin.ignore();
			cin.ignore();
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