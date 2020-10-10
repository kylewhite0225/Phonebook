#include <string>
#include "Contact.h"
using namespace std;

/*
Name: Phonebook.h
Author: Kyle White
Date: 10/9/2020
Description: Header file for the Phonebook class, which defines
the private members and all methods.
*/

class Phonebook
{
private:
    Contact *pArr;
    int size;
    int entries;
    
public:
    Phonebook();
    ~Phonebook();

    void add(Contact c);
    string search(string name);
    void del(string del);
    void list();
    int getEntries();
    int getSize();
    Contact* getArr();
};