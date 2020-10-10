#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int a = 10, b = 45;
    string fname = "KYLE";
    string lname = "WHITE";
    int phone = 1234567;
    ofstream outfile("out.txt");
    outfile << a << " " << b << endl;
    outfile << fname << " " << lname << " " << phone << endl;
    outfile << a << " " << b << endl;
    return 0;
}
