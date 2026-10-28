#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    ofstream myfile("text_hello.txt");
    myfile<<"hello from the other file from cpp";
    myfile.close();

    string s;
    ifstream myfile_read("text_hello.txt");
    getline(myfile_read,s);
    myfile_read.close();
    cout<<s;
}