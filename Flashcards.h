//operating class to answer the questions in the decks, add decks, and add questions


#ifndef FLASHCARDS_H
#define FLASHCARDS_H


#include <iostream>
#include <vector>
#include "Deck.H"
using namespace std;

class Flashcards{
    public:
    Flashcards(string name);
    ~Flashcards();
    void MainMenu();
    void DisplayDecks();
    void InsertDeck();
    void Study();
    int ChooseDeck();

    private:
    string m_name;
    vector<Deck*> m_decks;
};

#endif 