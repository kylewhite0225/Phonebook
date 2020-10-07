#include <iostream>
#include <fstream>
#include <string>
#include "Phonebook.h"
using namespace std;

Phonebook* readPhonebook() {
    Phonebook* phBook = new Phonebook();
    ifstream file;
    file.open("Phonebook.txt");
    while (!file.eof()) {
        string fname, lname, phone;
        file >> fname >> lname >> phone;
        if (fname == "") {  // fix later maybe
            break;
        }
        string name = fname + " " + lname;
        Contact tempName = Contact(name, phone);
        phBook->add(tempName);
    }
    return phBook;
}

void writePhonebook(Phonebook book) {
    ofstream outfile("Phonebook.txt", ios::out | ios::trunc);
    Contact* arr = book.getArr();
    for (int i = 0; i < book.getSize(); i++) {
        outfile << arr[i].getName() << " " << arr[i].getPhone() << endl;
    }
    outfile.close();
    delete[] arr;
}

void menu(Phonebook book) {
    bool quit = false;
    cout << "Please choose an operation: " << endl;
    while (quit == false) {
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
                    inputName[i ] = toupper(ch); 
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
                cout << "Phone Number: " << book.search(search) << endl;
                break;
            }
            case 'D' : {
                string fName;
                string lName;
                cout << "Enter name: ";
                cin >> fName >> lName;
                string del = fName + " " + lName;
                for (int i = 0; i < del.length(); i++) {
                    char ch = del[i];
                    del[i] = toupper(ch); 
                }
                book.del(del);
                break;
            }
            case 'L' : {
                book.list();
                break;
            }
            case 'Q' : {
                quit = true;
                writePhonebook(book);
                break;
            }
            default: {
                cout << "Not an option. Please try again." << endl;
                break;
            }
        }
        cout << endl;
    }
}

int main() {
    cout << "*** MY PHONEBOOK APPLICATION ***" << endl;
    // Contact* phonebook = new Contact[200000];   // pass by reference using pointers
    Phonebook* phonebook = readPhonebook();
    menu(*phonebook);
    return 0;
}