#include <iostream>
#include "Phonebook.h"
using namespace std;

/*
Name: Phonebook.cpp
Author: Kyle White
Date: 10/9/2020
Description: The phonebook class has two private members, a pointer
to a dynamically created array of Contact objects and an integer that
stores how many entries have been added to the array. There are methods
for adding, deleting, searching, and listing, as well as accessor methods
for the two private members.
*/

// The default constructor initializes the pArr field to a new dynamic array of
// Contact objects of size 200,000 in order to prevent overflow. The size
// field is initially set to 152000 while the Phonebook object contains no Contact objects.
// The entries field keeps track of how many items are added to the array.
Phonebook::Phonebook() {
    this->size = 100000;
    this->entries = 0;
    this->pArr = new Contact[size];
}

Phonebook::~Phonebook() {
    delete[] pArr;
}

// The add method sets a Contact object, c, to the current last position in 
// the array, which is stored in the field entries. If the capacity of the
// array is reached (entries >= size), then a new array is created,
// every value is copied over, the new addition is added, and the old
// array is deleted.
void Phonebook::add(Contact c) {
    if (this->entries >= this->size) {
        Contact* newArr = new Contact[this->size + 500];
        for (int i = 0; i < entries; i++) {
            newArr[i] = this->pArr[i];
        }
        delete[] pArr;
        pArr = newArr;
        this->size = size + 500;
        pArr[entries] = c;
        this->entries++;
    } else {
        pArr[entries] = c;
        this->entries++;
    }
}

// The delete method searches for the string, del, in the name field of
// the Contact objects stored in pArr and if found, shifts all values after
// del to the left and decreases entries.
void Phonebook::del(string del) {
    // search for del in array
    int i;
    for (i = 0; i < entries; i++) {
        if (pArr[i].getName() == del) {
            break;
        }
    }
    // if del is in array, decrease entries and shift values to the left, removing del
    if (i < entries) {
        entries--;
        for (int j = i; j < entries; j++) {
            pArr[j] = pArr[j+1];
        }
    } else if (i == entries) {
        cout << "Not found." << endl;
    }
}

// The search method searches for the string, name, in the name field of 
// the Contact objects stored in pArr and if found, returns the phone number
// stored in the phone field of the Contact object. If not found, it returns "Not Found."
string Phonebook::search(string name) {
    // search for name in array
    for (int i = 0; i < entries; i++) {
        // if the search term is found, return the phone number stored in Contact object
        if (pArr[i].getName() == name) {
            return pArr[i].getPhone();
        }
    }
    return "Not Found.";
}

// The list method utilizes the Contact class's print method to print every contact
// stored in pArr.
void Phonebook::list() {
    bool quit = false;
    int page = 1;
    cout << endl;
    for (int i = 0; i < (10 * page); i++) {
        this->pArr[i].print();
    }
    while (quit == false) {
        char select;
        cout << endl;
        cout << "Page " << page << endl;
        cout << endl;
        cout << "N(Next Page) | P(Previous Page) | Q(Return to Menu): ";
        cin >> select;
        select = toupper(select);
        switch (select) {
            case 'N' : {
                page++;
                cout << endl;
                for (int i = (10 * page - 10); i < (10 * page); i++) {
                    this->pArr[i].print();
                }
                break;
            }
            case 'P' : {
                if (page > 1) {
                    page--;
                    cout << endl;
                    for (int i = (10 * page - 10); i < (10 * page); i++) {
                        this->pArr[i].print();
                    }
                    break;
                } else {
                    cout << endl;
                    cout << "Already at first page." << endl;
                    cout << endl;
                    for (int i = 0; i < (10 * page); i++) {
                        this->pArr[i].print();
                    }
                    break;
                }
            }
            case 'Q' : {
                quit = true;
                break;
            }
            default:
                cout << "Not an option. Please try again." << endl;
                break;
        }
    }
    // for (int i = 0; i< entries; i++) {
    //     pArr[i].print();
    // }
}

// The getEntries method returns the number of values stored in the array.
int Phonebook::getEntries() {
    return entries;
}

// The getSize method returns the size of the array.
int Phonebook::getSize() {
    return size;
}

// The getArr method returns the pointer stored in pArr.
Contact* Phonebook::getArr() {
    return pArr;
}