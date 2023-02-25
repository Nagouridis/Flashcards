#include "Flashcards.h"


Flashcards::Flashcards(string name){
    //sets the name of the user
    m_name = name;
}

Flashcards::~Flashcards(){
    //deconstructor
    for (unsigned int i = 0; i < m_decks.size(); i++){
        delete m_decks.at(i);
    }
}

void Flashcards::MainMenu(){
    //Menu to navigate the flashcards application
    int menuChoice;
    cout << "Time to Study!" << endl;
    while(menuChoice != 4){
        cout << "1. Show all decks" << endl;
        cout << "2. Add new deck" << endl;
        cout << "3. Start studying" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter Choice (1-4): ";
        cin >> menuChoice;
        if(menuChoice == 1){
            DisplayDecks();
        }
        if(menuChoice == 2){
            InsertDeck();
        }
        if(menuChoice == 3){
            Study();
        }
    }
    cout << "Thank you for using Flashcards :)" << endl;

}

void Flashcards::InsertDeck(){
    //inserts a new deck into the deck vector
    string subject;
    cout << "What subject would you like to be in the new deck: ";
    cin >> subject;
    Deck* newDeck = new Deck(subject);
    m_decks.push_back(newDeck);
    cout << endl;
    cout << "New deck " << newDeck->GetSubject() << "added." << endl;
}

void Flashcards::DisplayDecks(){
    //shows all decks within the deck vector
    cout << endl;
    if(m_decks.size() == 0){
        cout << "No Decks yet" << endl;
        return;
    }
    cout << "The available decks are:" << endl;
    for(unsigned int i = 0; i < m_decks.size(); i++){
        cout << i + 1 << ". " << m_decks.at(i)->GetSubject() << endl;
    }
    cout << endl;
}

void Flashcards::Study(){
    //Starts the actual study part
    cout << endl;
    //choose which deck to work on
    int deckChoice = ChooseDeck();
    int choice;
    while(choice != 4){
        cout << "Would you like to add a new card or answer some?" << endl;
        cout << "1. add card" << endl;
        cout << "2. Answer" << endl;
        cout << "3. Display all Questions in the deck" << endl;
        cout << "4. Go back" << endl;
        cout << "Enter Choice (1-4): ";
        cin >> choice;
        cin.ignore(1,'\n');
        if(choice == 1){
            //create a new question to be inserted into the deck
            string question;
            string answer;
            string hint;
            cout << "What is the question?" << endl;
            getline(cin,question);
            cout << "What is the answer?" << endl;
            getline(cin,answer);
            cout << "What is the hint?" << endl;
            getline(cin,hint);
            for(int i = 0; i < (int)m_decks.size(); i++){
                if(deckChoice-1 == i){
                m_decks.at(i)->InsertCard(question,answer,hint);
                cout << "Card successfully Added" << endl;
                }
            }
        }
        if(choice == 2){
            //allows the user to answer questions within the deck
            Card* theCard = new Card();
            bool result = false;
            for(int i = 0; i < (int)m_decks.size(); i++){
                if(deckChoice -1 == i){
                    string keepGoing = "y";
                        while(keepGoing != "n"){
                            //get a random card from the deck to answer
                            theCard = m_decks.at(i)->GetRandomCard();
                            while(result == false){
                                //check whether the user got the answer right
                                result = m_decks.at(i)->CheckAnswer(theCard);
                                if (result == false){
                                    //if the user got it wrong they keep going, and can get a hint that they set up earlier
                                    cout << "You got it wrong :(" << endl;
                                    char choice;
                                    cout << "Would you like a hint? y/n" << endl;
                                    cin >> choice;
                                    if (choice == 'y'){  
                                        cout <<  theCard->GetHint() << endl; 
                                        result = m_decks.at(i)->CheckAnswer(theCard);    
                                    }
                                    if(choice == 'n'){
                                        result = m_decks.at(i)->CheckAnswer(theCard);
                                    }
                                }
                                if(result == true){
                                    cout << "Congrats! you got it right!" << endl;
                                }
                            }
                            //allows the user to keep going and get another card
                        cout << "Keep going (y/n)" << endl;
                        cin >> keepGoing;
                        if(keepGoing == "y"){
                            result = false;
                        }
                    }
                }
            }
        }
        if(choice == 3){
            //show all the questions in the deck
            for(int i = 0; i < (int)m_decks.size(); i++){
                if(deckChoice -1 == i){
                m_decks.at(i)->DisplayDeckContents();
                }
            }
        }
    }
}

int Flashcards::ChooseDeck(){
    //allows the user to check which deck to use for studying 
    int choice = 0;
    cout << "Which deck would you like to use" << endl;
    DisplayDecks();
    cout << "Enter Choice (1 - " << (int)m_decks.size() << "): ";
    cin >> choice;
    while(choice > (int)m_decks.size() || choice < 0){
        cout << "That is not a valid deck" << endl;
        cin >> choice;
    }
    for (int i = 0; i < (int)m_decks.size(); i++){
        if(choice-1 == i){
            return choice;
        }
    }
    return choice;
}





