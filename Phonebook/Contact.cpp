#include <iostream>
#include "Contact.h"
using namespace std;

/*
Name: Contact.cpp
Author: Kyle White
Date: 10/9/2020
Description: The Contact class has two private members which are both strings, name and phone.
There are two constructors, accessor and mutator methods for both private members 
as well as a print method.
*/

// Default constructor which initializes each private member but does not
// assign any values.
Contact::Contact() {
    name;
    phone;
}

// Constructor with two parameters, which assigns the name field to the parameter n,
// and the phone field to the parameter num.
Contact::Contact(string n, string num) {
    name = n;
    phone = num;
}

Contact::~Contact() {       // destructor
}

// The getName method returns the string stored in the name field.
string Contact::getName() {
    return name;
}

// The getPhone method returns the string stored in the phone field.
string Contact::getPhone() {
    return phone;
}

// The setName method sets the name field to the parameter n.
void Contact::setName(string n) {
    name = n;
}

// THe setPhone method sets the phone feild to the parameter num.
void Contact::setPhone(string num) {
    phone = num;
}

// The Print function prints out the strings stored in name and phone.
void Contact::print() {
    cout << name << " " << phone << endl;
}