#include "Cards.h"

Card::Card(){
    //default constructor for the node
    m_answer = "";
    m_answer = "";
    m_hint = "";
    m_next = nullptr;
}

Card::Card(string question, string answer, string hint){
    //constructor of a node given the parameters
    SetQuestion(question);
    SetAnswer(answer);
    SetHint(hint);
    m_next = nullptr;
}

string Card::GetAnswer(){
    //returns the nodes answer
    return m_answer;
}

string Card::GetQuestion(){
    //returns the nodes question
    return m_question;
}

string Card::GetHint(){
    //returns the nodes hint
    return m_hint;
}

void Card::SetQuestion(string question){
    //sets the nodes question
    m_question = question;
}

void Card::SetAnswer(string answer){
    //sets the nodes answer
    m_answer = answer;
}

void Card::SetHint(string hint){
    //sets the hint for the question
    m_hint = hint;
}
Card* Card::GetNext(){
    //returns the next node
    return m_next;
}

void Card::SetNext(Card* a){
    //set the nodes next node
    m_next = a;
}