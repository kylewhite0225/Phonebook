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
// field is set to 0 while the Phonebook object contains no Contact objects.
Phonebook::Phonebook() {
    this->pArr = new Contact[200000];
    this->size = 0;
}

Phonebook::~Phonebook() {
    delete[] pArr;
}

// The add method sets a Contact object, c, to the current last position in 
// the array, which is stored in the field size.
void Phonebook::add(Contact c) {
    pArr[size] = c;
    size++;
}

// The delete method searches for the string, del, in the name field of
// the Contact objects stored in pArr and if found, shifts all values after
// del to the left and decreases size.
void Phonebook::del(string del) {
    // search for del in array
    int i;
    for (i = 0; i < size; i++) {
        if (pArr[i].getName() == del) {
            break;
        }
    }
    // if del is in array, decrease size and shift values to the left, removing del
    if (i < size) {
        size--;
        for (int j = i; j < size; j++) {
            pArr[j] = pArr[j+1];
        }
    }
}

// The search method searches for the string, name, in the name field of 
// the Contact objects stored in pArr and if found, returns the phone number
// stored in the phone field of the Contact object. If not found, it returns "Not Found."
string Phonebook::search(string name) {
    // search for name in array
    for (int i = 0; i < size; i++) {
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
    for (int i = 0; i < size; i++) {
        pArr[i].print();
    }
}

// The getSize method returns the value stored in the size field.
int Phonebook::getSize() {
    return size;
}

// The getArr method returns the pointer stored in pArr.
Contact* Phonebook::getArr() {
    return pArr;
}