#include <string>
#include "Contact.h"
using namespace std;

class Phonebook
{
private:
    Contact* arr;
    int size;
    
public:
    Phonebook();
    // Phonebook(int size);
    ~Phonebook();

    void add(Contact c);
    string search(string name);
    void del(string del);
    void list();
    int getSize();
    Contact* getArr();

    // void print();
};