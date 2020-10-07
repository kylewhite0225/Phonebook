#include <string>
using namespace std;

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