#include <string>
using namespace std;

/*
Name: Contact.h
Author: Kyle White
Date: 10/9/2020
Description: Header file for the Contact class, which defines
the private members and all methods.
*/

class Contact
{
private:
    string name;
    string phone;
    
public:
    Contact();
    Contact(string n, string num);
    ~Contact();

    string getName();
    string getPhone();
    
    void setName(string n);
    void setPhone(string num);

    void print();
};