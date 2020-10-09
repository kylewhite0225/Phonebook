#include <iostream>
#include <fstream>
#include <string>
#include "Phonebook.h"
using namespace std;

/* 
Name: main.cpp
Author: Kyle White
Date: 10/9/2020
Description: A phonebook application that reads names and numbers 
from a text file, lets the user add, list, delete, and search for 
names. Writes modified data out to the same file.
*/


// readPhonebook function which creates a pointer to a Phonebook object pBook,
// creates an ifstream object 'file,' and opens Phonebook.txt which provides
// the contact data for the program. Each line in the file is stored in a 
// temporary Contact object and then added to pBook, which is then returned.
Phonebook* readPhonebook() {
    Phonebook *pBook = new Phonebook();
    ifstream file;
    file.open("Phonebook.txt");
    while (!file.eof()) {
        string fname, lname, phone;
        file >> fname >> lname >> phone;
        if (fname == "") {  // fix later maybe
            break;
        }
        string name = fname + " " + lname;
        Contact tempContact = Contact(name, phone);
        pBook->add(tempContact);
    }
    file.close();
    return pBook;
}

// writePhonebook function which accepts a Phonebook object 'book' as an argument
// and creates an ofstream object 'outfile.' outfile opens Phonebook.txt and truncates
// the text file. A pointer to a Contact array object is created to reference
// the array stored in the parameter Phonebook object. Each private field of each
// contact object stored in the array is written out to the text file, before it is closed
// and the pointer is deleted.
void writePhonebook(Phonebook book) {
    ofstream outfile("Phonebook.txt", ios::out | ios::trunc);
    Contact *pArr = book.getArr();
    for (int i = 0; i < book.getSize(); i++) {
        outfile << pArr[i].getName() << " " << pArr[i].getPhone() << endl;
    }
    outfile.close();
    delete[] pArr;
}


// The Menu function handles all user input with a switch case, and also
// handles some of the string formatting in the add, search, and delete
// cases.
void menu(Phonebook book) {
    bool quit = false;
    cout << "Please choose an operation: " << endl;
    while (quit == false) {
        char select;
        cout << "A(Add) | S (Search) | D(Delete) | L(List) | Q(Quit): ";
        cin >> select;
        // Use char toupper function to ensure user input matches case
        select = toupper(select);
        switch (select) {
            // Add case which defines three strings, accepts user input, and 
            // creates a temporary Contact object tempContact and adds that to
            // the book object using the Phonebook class's add method.
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
            // Search case which defines two strings, accepts user input, formats
            // the strings into one uppercase string, then passes it to the Phonebook's
            // search method during output to the terminal.
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
            // Delete case defines two strings, formats them, and passes the
            // resultant single string to the Phonebook's delete method.
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
            // List case which calls the Phonebook's list method.
            case 'L' : {
                book.list();
                break;
            }
            // Quit case which sets the boolean value quit to false, then
            // passes the book object to the writePhonebook function defined in main.cpp.
            case 'Q' : {
                quit = true;
                writePhonebook(book);
                break;
            }
            // The default case rejects any user input that is not a valid
            // option.
            default: {
                cout << "Not an option. Please try again." << endl;
                break;
            }
        }
        cout << endl;
    }
}

// The main function prints out the title of the phonebook application, then creates
// a pointer to a Phonebook object that is returned from the readPhonebook function.
// Then it passes that pointer to the menu function, and once the user elects to 
// quit the application, deletes pPhonebook from memory before ending the program.
int main() {
    cout << "*** MY PHONEBOOK APPLICATION ***" << endl;
    Phonebook *pPhonebook = readPhonebook();
    menu(*pPhonebook);
    delete pPhonebook;
    return 0;
}