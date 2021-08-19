#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int lenght = 0;
    cout<<"Podaj dlugosc hasla: ";
    cin>>lenght;
    char *password=new char[lenght];    
    int *passwordAscii=new int[lenght];
    cout<<"Podaj haslo: ";
    cin>>password;
    //cout<<strlen(password)<<endl;
    for(int i=0;i<lenght;i++)
    {
        
        passwordAscii[i]=int(password[i]);
        cout<<passwordAscii[i];
    }
    cout<<endl;
    delete [] password;
    delete [] passwordAscii;
    return 0;
    //33
}