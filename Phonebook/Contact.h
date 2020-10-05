#include <string>
using namespace std;

class Contact
{
private:
    string name;
    int phone;
    
public:
    Contact();
    Contact(string n, int num);
    ~Contact();
    string getName();
    int getPhone();
    void setName(string n);
    void setPhone(int num);

    void print();
}