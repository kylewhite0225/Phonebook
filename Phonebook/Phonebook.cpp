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

void Phonebook::del(string del) {
    // search for del in array
    int i;
    for (i = 0; i < size; i++) {
        if (arr[i].getName() == del) {
            break;
        }
    }
    if (i < size) {
        size--;
        for (int j = i; j < size; j++) {
            arr[j] = arr[j+1];
        }
    }
}

string Phonebook::search(string name) {
    for (int i = 0; i < size; i++) {
        if (arr[i].getName() == name) {
            return arr[i].getPhone();
        }
    }
    return "Not Found.";
}

void Phonebook::list() {
    for (int i = 0; i < size; i++) {
        arr[i].print();
    }
}

int Phonebook::getSize() {
    return size;
}

Contact* Phonebook::getArr() {
    return arr;
}

// construct array
// every time you add an element - another integer in phonebook to keep track of size