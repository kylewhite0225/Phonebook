#include <iostream>
#include "Contact.h"
using namespace std;

Contact::Contact() {
    name = "";
    phone = 0;
}

Contact::Contact(string n, int num) {
    name = n;
    phone = num;
}

Contact::~Contact() {
}

string Contact::getName() {
    return name;
}

int Contact::getPhone() {
    return phone;
}

void Contact::setName(string n) {
    name = n;
}

void Contact::setPhone(int num) {
    phone = num;
}

