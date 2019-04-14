#include <iomanip>
#include <math.h>
#include <iostream>
#include <stdio.h>
using namespace std;
void Remelis(int s, int v, char* var);

int main()
{
    //1 lab uzduotis
    cout << "Matas Zukas MRino-18" << endl;
    cout << "1 laboratorinio darbo uzduotis" << endl;
    int n = 0;
    int i = 0;
    int d;
    char Vardas[256];
    cout << "Koks jusu vardas: ";
    cin >> Vardas;
    cout << "Iveskite remelio dydi: ";
    cin >> d;

    while (Vardas[i] != '\0')

    if (( Vardas[i] >= 'a' && Vardas[i] <= 'z') || (Vardas[i] >= 'A' && Vardas[i] <= 'Z') || Vardas[i] == '-' || Vardas[i] == '`')
    {
        n++;
        i++;
    }
    Remelis(d, n, Vardas);

    return 0;
}

void Remelis(int s, int v, char* var)
{
    int i;
    //"Sveikas, ... !" uzima 10 langeliu
    cout << string(1+s+10+v+s+1, '*') << endl;
    for (i=0;i<s;i++)
    {
        cout << "*" << string(s+10+v+s, ' ') << "*" << endl;
    }
    cout << "*" << string(s, ' ') << "Sveikas, " << var << "!" << string(s, ' ') << "*" << endl;
    for (i=0;i<s;i++)
    {
        cout << "*" << string(s+10+v+s, ' ') << "*" << endl;
    }
    cout << string(1+s+10+v+s+1, '*') << endl;

}
