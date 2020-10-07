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
    void search();
    void del();
    void list();

    // void print();
};