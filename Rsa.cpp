#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <time.h>

using namespace std;
void keys();
void password();
void cipher();
void decipher();
long long pMod(long long x, long long y, long long m);
long long phi(long long n);
long long nwd(long long a, long long b);

int main()
{
    int menu = 0;
    cout << "--------MENU--------" << endl;
    cout << "1 - deszyfrowanie" << endl;
    cout << "2 - szyfrowanie " << endl;
    cout << "3 - generator hasel" << endl;
    cout << "4 - generator kluczy" << endl;
    cin >> menu;
    switch (menu)
    {
    case 1:
        decipher();
        break;
    case 2:
        cipher();
        break;
    case 3:
        password();
        break;
    case 4:
        keys();
        break;
    default:
        cout << "Podaj cyfrę 1-4: " << endl;
        cin >> menu;
        break;
    }
    return 0;
}
void keys() {
    double p = 0; // Liczba pierwsza 1
    double q = 0; // Liczba pierwsza 2
    cout << "Podaj 1 liczbe pierwsza: ";
    cin >> p;
    cout << endl;
    cout << "Podaj 2 liczbe pierwsza: ";
    cin >> q;
    cout << endl;
    long  n = 0; // n 
    long euler = 0; // Liczba funckji Eulera
    long e = 7; // Wykładnik publiczny e
    long d = 0; // Wykładnik tajny d
    n = p * q;
    euler = (p - 1) * (q - 1);
    cout << "Podaj liczbe e wzglednie pierwsza do " << euler << " z przedzialu 1 < e < " << n << ": ";
    cin >> e;
    cout << endl;
    do {
        if (nwd(e, euler) != 1) {
            cout << "Blad, podaj liczbe e wzglednie pierwsza do " << euler << " z przedzialu 1 < e < " << n << ": ";
            cin >> e;
            cout << endl;
        }
    } while (nwd(e, euler) != 1);
    // Odwrotność modulo
    long long u, w, z, r;
    u = 1; w = e;
    d = 0; z = euler;
    while (w)
    {
        if (w < z)
        {
            r = u; u = d; d = r;
            r = w; w = z; z = r;
        }
        r = w / z;
        u -= r * d;
        w -= r * z;
    }
    if (z == 1)
    {
        if (d < 0) d += euler;
    }
    else cout << "Blad w wyliczaniu wykladnika tajnego\n";

    cout << "Klucz publiczny: (" << e << "," << n << ")";
    cout << endl;
    cout << endl;
    cout << "Klucz tajny: (" << d << "," << n << ")";
    cout << endl;
}
void password() {
    int choice = 0;
    int amount = 0;
    int lenght = 0;
    char *password = new char[lenght];
    srand(time(NULL));
    char characters1[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    char characters2[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*(){}[]|:'<>?,./";
    cout << "0 - bez znakow specjalnych" << endl;
    cout << "1 - z znakami specjalnymi" << endl;
    cin >> choice;
    cout << "Podaj ile hasel chcesz wygenerowac: ";
    cin >> amount;
    cout << "Podaj dlugosc hasla: ";
    cin >> lenght;
    cout << endl;
    if (choice == 0) {
        for (int j = 0; j < amount; j++) {
            cout << "Password: ";
            for (int i = 0; i < lenght; i++)
            {
                char character = characters1[rand() % 62];
                password[i] = character;
                cout << password[i];
            }
            cout << endl;
        }
    }
    else {
        for (int j = 0; j < amount; j++) {
            cout << "Password: ";
            for (int i = 0; i < lenght; i++)
            {
                char character = characters2[rand() % 85];
                password[i] = character;
                cout << password[i];
            }
            cout << endl;
        }
    }
    delete [] password;
}
void cipher() {
    long long eKey = 0;
    long long nKey = 0;
    long long number = 0;
    long long c = 0;
    int lenght = 0;
    char *password=new char[lenght];    
    int *passwordAscii=new int[lenght*3];
    cout << "Podaj klucz publiczny: " << endl;
    cin >> eKey;
    cin >> nKey;
    cout << "Klucz publiczny: (" <<eKey<<","<<nKey<<")" <<endl;
    //cout << "Podaj haslo do zaczyfrowania: ";
    //cin >> number;
    cout<<"Podaj dlugosc hasla: ";
    cin>>lenght;
    cout<<"Podaj haslo: ";
    cin>>password;
    //cout<<strlen(password)<<endl;
    cout<<"Zaszyfrowana liczba: ";
    for(int i=0;i<lenght;i++)
    {
        
        passwordAscii[i]=int(password[i]);
        passwordAscii[i]=pMod(passwordAscii[i],eKey,nKey);
        password[i]=char(passwordAscii[i]);
        cout<<password[i];
    }
    cout<<endl;
    //cout << "Zaszyfrowana liczba: " << pMod(number, eKey, nKey);
    delete [] password;
    delete [] passwordAscii;
}
void decipher(){
    long long dKey = 0;
    long long nKey = 0;
    long long number = 0;
    long long c = 0;
    int lenght = 0;
    char *password=new char[lenght];    
    int *passwordAscii=new int[lenght*3];
    cout << "Podaj klucz tajny: " << endl;
    cin >> dKey;
    cin >> nKey;
    cout << "Klucz tajny: (" << dKey << "," << nKey << ")" << endl;
    //cout << "Podaj liczbe do odszyfrowania: ";
    //cin >> number;
    //cout << "Odszyfrowana liczba: " << pMod(number, dKey, nKey);
    cout<<"Podaj dlugosc hasla: ";
    cin>>lenght;
    cout<<"Podaj haslo: ";
    cin>>password;
    //cout<<strlen(password)<<endl;
    cout<<"Odszyfrowana liczba: ";
    for(int i=0;i<lenght;i++)
    {
        
        passwordAscii[i]=int(password[i]);
        passwordAscii[i]=pMod(passwordAscii[i],dKey,nKey);
        password[i]=char(passwordAscii[i]);
        cout<<password[i];
    }
    cout<<endl;
    delete [] password;
    delete [] passwordAscii;
}
long long pMod(long long x, long long y, long long m) {
    long long w = x;
    if (nwd(x, m) == 1)
        y = y % phi(m);
    for (int i = 1; i < y; i++)
        w = (w * x) % m;
    return w;
}
long long nwd(long long a, long long b) {
    long long c;
    while (b != 0) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}
long long phi(long long n) {
    long long suma = n;
    long long dzielnik = 2;
    while (n != 1) {
        while (n % dzielnik != 0)
            dzielnik++;
        suma *= (1 - 1.0 / dzielnik);
        while (n % dzielnik == 0) {
            n /= dzielnik;
        }
    }
    return long(suma);
}