#include "Deck.H"




Deck::Deck(string subject){
    //default constructor for a deck given a subject
    m_head = nullptr;
    m_tail = nullptr;
    m_subject = subject;
    
}

string Deck::GetSubject(){
    //returns the subject of the deck
    return m_subject;
}

Deck::~Deck(){
    //deconstructor of the linked list going from head to tail
    Card* temp = m_head;
    while(m_head != nullptr){
        temp = m_head->GetNext();
        delete m_head;
        m_head = temp;
    }
    m_head = nullptr;
    m_tail = nullptr;
    m_subject = "";
}

void Deck::InsertCard(string question,string answer,string hint){
    //inserting nodes into the linked list from the tail
    Card* new_card = new Card(question,answer,hint);
    new_card->SetNext(nullptr);
    if(m_head == nullptr){
         m_head = new_card;
         m_size++;
         return;
     }else{
         m_tail = m_head;
         while(m_tail->GetNext() != nullptr){
         m_tail = m_tail->GetNext();
         }
         m_tail->SetNext(new_card);
         m_tail = new_card;
     }
     m_size++;
}

Card* Deck::GetRandomCard(){
    //picks a random node from the linked list and returns it
    if(m_head == nullptr){
        return nullptr;
    }
    srand(time(nullptr));
    Card* result = m_head;
    Card* current = m_head;
    int n;
    for(n = 2; current != nullptr; n++){
        if(rand() % n == 0){
            result = current;
        }
        current = current->GetNext();
    }
    return result;
}

void Deck::DisplayQuestion(Card* aCard){
    //shows whatever the question is given a node
    cout << "The Question is: " << aCard->GetQuestion() << endl;
}

bool Deck::CheckAnswer(Card* aCard){
    //given a user answer, compares it to the node answer to determine if it is correct
    DisplayQuestion(aCard);
    string answer = "";
    cout << "What is the answer?" << endl;
    cin >> answer;
    if(answer == aCard->GetAnswer()){
        return true;
    }
    else{
        return false;
    }
}

void Deck::DisplayDeckContents(){
    //displays all of the nodes in the linked lists
    if(m_head == nullptr){
        cout << "No cards in deck yet" << endl;
    }
    Card* temp = m_head;
    int counter = 0;
    while(temp != nullptr){
        cout << counter+1 << ". " << temp->GetQuestion() << endl;
        temp = temp->GetNext();
        counter++;
    }
}