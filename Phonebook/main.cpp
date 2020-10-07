#include <iostream>
#include <fstream>
// #include "Contact.h"
#include "Phonebook.h"
using namespace std;

void menu(Phonebook book) {
    bool quit = false;
    cout << "Please choose an operation: " << endl;
    while (quit == false) {
        // cout << "Please choose an operation:" << endl;
        char select;
        cout << "A(Add) | S (Search) | D(Delete) | L(List) | Q(Quit): ";
        cin >> select;
        select = toupper(select);
        string inputName;
        string inputNumber;
        switch (select) {
            case 'A' :
                //deal with A
                // string inputName;
                // string phoneNumber;
                cout << "Enter name: ";
                cin >> inputName;
                cout << "Enter phone: ";
                cin >> inputNumber;
                inputName = "";
                inputNumber = "";
                break;
            case 'S' :
                // cout << "s" << endl;
                // DEAL WITH S
                break;
            case 'D' :
                cout << "D" << endl;
                // deal with D
                break;
            case 'L' :
                // cout << "L" << endl;
                book.list();
                break;
            case 'Q' :
                cout << "Q" << endl;
                quit = true;
                //writeContact();
                break;
        }
        cout << "\n" << endl;
    }
}

Phonebook readPhonebook() {
    Phonebook phBook = Phonebook();
    ifstream file;
    file.open("test.txt");
    string fname, lname, phone;
    string line;

    while (!file.eof()) {
        file >> fname >> lname >> phone;
        string name = fname + " " + lname;
        Contact tempName = Contact(name, phone);
        // tempName = Contact(name, phone);
        phBook.add(tempName);
    }
    return phBook;
}

int main() {
    cout << "*** MY PHONEBOOK APPLICATION ***" << endl;
    // Contact* phonebook = new Contact[200000];   // pass by reference using pointers
    Phonebook phonebook = readPhonebook();
    menu(phonebook);
    return 0;
}