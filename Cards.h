//Node class consisting of questions, answers, hints
#ifndef CARDS_H
#define CARDS_H


#include <iostream>
using namespace std;


class Card{
    public:
    Card();
    Card(string question,string answer,string hint);
    string GetQuestion();
    string GetAnswer();
    string GetHint();
    Card* GetNext();
    void SetQuestion(string question);
    void SetAnswer(string answer);
    void SetHint(string hint);
    void SetNext(Card*);
    private:
    string m_question;
    string m_answer;
    string m_hint;
    Card* m_next;
};
#endif

