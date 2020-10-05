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

