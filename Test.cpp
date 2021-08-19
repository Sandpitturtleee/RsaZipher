#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int lenght = 0;
    char tekst[13];    
    int tekstAscii[33];
    cout<<"Podaj tekst: ";
    cin>>tekst;
    cout<<strlen(tekst)<<endl;
    for(int i=0;i<13;i++)
    {
        
        tekstAscii[i]=int(tekst[i]);
        cout<<tekstAscii[i];
    }
    cout<<endl;
    return 0;
    //33
}