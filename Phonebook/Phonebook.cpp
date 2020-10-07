#include <iostream>
#include "Phonebook.h"
// #include "Contact.h"
using namespace std;

Phonebook::Phonebook() {
    this->arr = new Contact[200000];
    this->size = 0;
}

Phonebook::~Phonebook() {

}

void Phonebook::add(Contact c) {
    arr[size] = c;
    size++;
}

void Phonebook::del() {

}

void Phonebook::search() {

}

void Phonebook::list() {
    for (int i = 0; i < size; i++) {
        arr[i].print();
    }
}

// construct array
// every time you add an element - another integer in phonebook to keep track of size