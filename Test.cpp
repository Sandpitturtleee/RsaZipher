#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() 
{
char *password=new char[13];    
int *passwordAscii=new int[13*3];
int LINE = 4;
cout<< "Podaj linie: ";
cin>> LINE;
ifstream f("Passwords.txt");
string s;

for (int i = 1; i <= LINE; i++)
        getline(f, s);

for (int i = 0; i < sizeof(password); i++) {
    password[i] = s[i];
    cout << password[i];
}
delete [] password;
delete [] passwordAscii;
return 0;
}