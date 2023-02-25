#include "Flashcards.h"

int main(){
    string name = "";
    cout << "Welcome to flashcards!" << endl;
    cout << "What is your name: ";
    cin >> name;
    cout << "Hello " << name << endl;
    Flashcards new_flashcards = Flashcards(name);
    new_flashcards.MainMenu();
    return 0;
}