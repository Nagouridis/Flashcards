//linked list class which will consist of card nodes, allowing for multiple cards to be stored and accessed quickly

#ifndef DECK_H
#define DECK_H



#include "Cards.h"

class Deck{
    public:
    Deck(string subject);
    ~Deck();
    void SetSubject(string subject);
    void InsertCard(string question, string answer, string hint);
    Card* GetRandomCard();
    void DisplayDeckContents();
    void DisplayQuestion(Card* aCard);
    bool CheckAnswer(Card* aCard);
    string GetSubject();

    private:
    string m_subject;
    Card* m_head;
    Card* m_tail;
    int m_size;

};








#endif