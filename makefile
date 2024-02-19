CXX = g++
CXXFLAGS = -Wall -g

main: Flashcards.o Deck.o Cards.o main.cpp 
	$(CXX) $(CXXFLAGS) Flashcards.o Cards.o Deck.o main.cpp -o main.exe

Navigator.o: Deck.o Cards.o Flashcards.h Flashcards.cpp
	$(CXX) $(CXXFLAGS) -c Flashcards.cpp

Deck.o: Cards.o Deck.h Deck.cpp
	$(CXX) $(CXXFLAGS) -c Deck.cpp

Cards.o: Cards.h Cards.cpp
	$(CXX) $(CXXFLAGS) -c Cards.cpp