hangman: hangman.o word.o
	g++ -std=c++11 hangman.o word.o -o hangman

hangman.o: hangman.cpp word.h
	g++ -std=c++11 -g -Wall -c hangman.cpp

word.o: word.cpp word.h
	g++ -std=c++11 -g -Wall -c word.cpp

clean:
	rm hangman hangman.o word.o
