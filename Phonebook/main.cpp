#include <iostream>
#include <fstream>
#include <string>
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
        switch (select) {
            case 'A' :{
                string inputFName;
                string inputLName;
                string inputNumber;
                cout << "Enter name: ";
                cin >> inputFName >> inputLName;
                cout << "Enter phone: ";
                cin >> inputNumber;
                string inputName = inputFName + " " + inputLName;
                for (int i = 0; i < inputName.length(); i++) {
                    char ch = inputName[i];
                    inputName[i] = toupper(ch); 
                }
                Contact tempContact = Contact(inputName, inputNumber);
                book.add(tempContact);
                break;
            }
            case 'S' : {
                string fName;
                string lName;
                cout << "Enter name: ";
                cin >> fName >> lName;
                string search = fName + " " + lName;
                for (int i = 0; i < search.length(); i++) {
                    char ch = search[i];
                    search[i] = toupper(ch); 
                }
                // cout << search << endl;
                cout << "Phone Number: " << book.search(search) << endl;
                break;
            }
            case 'D' : {
                cout << "D" << endl;
                // deal with D
                break;
            }
            case 'L' : {
                // cout << "L" << endl;
                book.list();
                break;
            }
            case 'Q' : {
                cout << "Q" << endl;
                quit = true;
                //writePhonebook();
                break;
            }
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
        phBook.add(tempName);
    }
    return phBook;
}

void writePhonebook(Phonebook book) {
    
}

int main() {
    cout << "*** MY PHONEBOOK APPLICATION ***" << endl;
    // Contact* phonebook = new Contact[200000];   // pass by reference using pointers
    Phonebook phonebook = readPhonebook();
    menu(phonebook);
    return 0;
}