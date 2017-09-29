hangman: hangman.o word.o game.o
	g++ -std=c++11 hangman.o word.o game.o -o hangman

game.o: Game.cpp Game.h
	g++ -std=c++11 -g -Wall -c Game.cpp

hangman.o: hangman.cpp Game.h
	g++ -std=c++11 -g -Wall -c hangman.cpp

word.o: Word.cpp Word.h
	g++ -std=c++11 -g -Wall -c Word.cpp

clean:
	rm hangman hangman.o word.o game.o
