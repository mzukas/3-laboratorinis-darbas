#include <iomanip>
#include <math.h>
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
using namespace std;


int main()
{
    int n;
    int s = 0;
    double V[256];
    double Vid[256];
    double kiekis;
    int paz[256];
    string Vardas[256];
    string Sarasas[256];
    cout << "Iveskite studentu kieki: ";
    cin >> n;
    while (!cin.good())
{
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    cout << "Klaida. Iveskite dar karta: ";
    cin >> n;
}
    cin.ignore();
    for (int i = 1; i <= n; i++)
    {
        cout << "Iveskite " << i << " studento(-es) varda ir pavarde: ";
        getline(cin, Vardas[i-1]);
        s++;
    }
    for (int j = 0; j < s; j++)
    {

        cout << "Iveskite studento(-es) " << Vardas[j] << " pazymiu kieki: ";
        cin >> kiekis;
        while (!cin.good())
{
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    cout << "Klaida. Iveskite dar karta: ";
    cin >> kiekis;
}

        cin.ignore();
        double v = 0;
        for (int k = 1; k <= kiekis; k++)
        {

            cout << "Iveskite " << k << " pazymi: ";
            cin >> paz[k-1];
            while (!cin.good())
{
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    cout << "Klaida. Iveskite dar karta: ";
    cin >> paz[k-1];
}
            v = v + paz[k-1];


        }
        Vid[j] = v / kiekis;
        cout << "Vidurkis: " << setprecision(2) << fixed << Vid[j];
        cout << endl;

    }
    cout << string(79, '*') << endl;
    cout << left << setw(30) << "Mokinys" << "Galutinis (Vid.)" << endl;
    for (int o = 0; o < s; o++)
    {
        cout << left << setw(35) << Vardas[o] << Vid[o] << endl;
    }



    return 0;
}

