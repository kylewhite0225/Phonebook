#include <iostream>
#include "Contact.h"
using namespace std;

Contact::Contact() {
    name = "";
    phone = "";
}

Contact::Contact(string n, string num) {
    name = n;
    phone = num;
}

Contact::~Contact() {       // destructor

}

string Contact::getName() {
    return name;
}

string Contact::getPhone() {
    return phone;
}

void Contact::setName(string n) {
    name = n;
}

void Contact::setPhone(string num) {
    phone = num;
}

void Contact::print() {
    cout << name << " " << phone << endl;
}