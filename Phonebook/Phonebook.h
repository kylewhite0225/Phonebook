#include <string>
using namespace std;

class Phonebook
{
private:
    Contact arr[];
    int size;
    
public:
    Phonebook();
    Phonebook(int size);
    ~Phonebook();

    void search();
    void add();
    void list();
    void del();
    
    // void setName(string n);
    // void setPhone(string num);

    // void print();
};