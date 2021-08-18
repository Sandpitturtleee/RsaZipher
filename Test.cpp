#include <iostream>

using namespace std;

int main()
{
    int a = 'A';
    cout<<"tekst"<<endl;
    cout<<a<<endl;
    cout<<char(65)<<endl;
    char tekst[5];
    cout<<"Podaj tekst: ";
    cin>>tekst;
    for(int i=0;i<5;i++)
    {
        cout<<tekst[i]<<" ";
        cout<<int(tekst[i])<<" ";
    }
    return 0;
}