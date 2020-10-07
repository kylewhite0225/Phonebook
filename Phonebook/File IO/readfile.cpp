#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    string fname, lname, phone;
    ifstream file;
    file.open("test.txt");
    while (!file.eof()) {
        file >> fname >> lname >> phone;
        cout << fname << " " << lname << " " << phone << endl;
    }
    return 0;
}