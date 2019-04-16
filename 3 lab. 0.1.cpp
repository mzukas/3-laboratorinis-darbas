#include <iomanip>
#include <math.h>
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <bits/stdc++.h>

using namespace std;
void mediana(int A[]);

int main()
{
    int n;
    int s = 0;
    double v = 0;
    double V[256];
    double Vid[256];
    int kiekis;
    int vid;
    double med[256];
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

char p;
cout << "Ar zinote namu darbu kieki? t/n" << endl;
cin >> p;
while (p != 't' && p != 'n')
        {
            {
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                cout << "Klaida. Iveskite dar karta: ";
                cin >> p;
            }
        }
if (p == 't') {

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
            while (!cin.good() || paz[k-1] <= 0 || paz[k-1] > 10)
{
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    cout << "Klaida. Iveskite dar karta: ";
    cin >> paz[k-1];
}
            v = v + paz[k-1];


        }
        Vid[j] = v / kiekis;
        sort(paz, paz+kiekis);
        if (kiekis%2 == 1)
        med[j] = paz[kiekis/2];
        else if (kiekis%2 == 0 && kiekis != 2) {
            if (((paz[kiekis/2] + paz[(kiekis/2) - 1])/2) % 2 == 1)
            med[j] = (paz[kiekis/2] + paz[(kiekis/2) - 1])/2+0.5;
            else med[j] = (paz[kiekis/2] + paz[(kiekis/2) - 1])/2;
        }
        else if (kiekis%2 == 0 && kiekis == 2) med[j] = Vid[j];
        cout << "Vidurkis: " << setprecision(2) << fixed << Vid[j] << endl;
        cout << "Mediana: " << setprecision(2) << fixed << med[j] << endl;

    }



    char p;
    cout << "Rodyti mediana ar aritmetini vidurki? m/v" << endl;
    cin >> p;

    if (p == 'm') {
    cout << string(79, '*') << endl;
    cout << left << setw(30) << "Mokinys" << "Galutinis (Med.)" << endl;
    for (int o = 0; o < s; o++)
    {
        cout << left << setw(35) << Vardas[o] << med[o] << endl;
    }
    }
    if (p == 'v')
    {
    cout << string(79, '*') << endl;
    cout << left << setw(30) << "Mokinys" << "Galutinis (Vid.)" << endl;
    for (int o = 0; o < s; o++)
    {
        cout << left << setw(35) << Vardas[o] << Vid[o] << endl;
    }
    }
}
else if (p == 'n')
{

   for (int j = 1; j <= s; j++)
    {
       int kiek[256];
       int k = 0;
       double vv[256];
    {

        int i = 1;
        vv[j-1] = 0;
        kiek[j-1] = 0;
        char p;
        cout << "Iveskite " << j << " mokinio " << i << " pazymi: ";
        cin >> paz[i-1];
         while (!cin.good())
            {
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                cout << "Klaida. Iveskite dar karta: ";
                cin >> paz[i-1];
            }
        cout << "Ar visi pazymiai? t/n" << endl;
        cin >> p;
        while (p != 't' && p != 'n')
        {
            {
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                cout << "Klaida. Iveskite dar karta: ";
                cin >> p;
}
            }
        vv[j-1] = vv[j-1] + paz[i-1];
        while (p == 'n') {

            i++;
            cout << "Iveskite " << j << " mokinio " << i << " pazymi: ";
            cin >> paz[i-1];
             while (!cin.good())
            {
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                cout << "Klaida. Iveskite dar karta: ";
                cin >> paz[i-1];
            }
            vv[j-1] = vv[j-1] + paz[i-1];
            cout << "Ar visi pazymiai? t/n" << endl;
            cin >> p;
            while (p != 't' && p != 'n')
            {
            {
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                cout << "Klaida. Iveskite dar karta: ";
                cin >> p;
            }
            }

        }
        kiek[j-1] = kiek[j-1] + i;

    }
        Vid[j-1] = vv[j-1] / kiek[j-1];
        k = k + kiek[j-1];
        sort(paz, paz+k);
        if (k%2 == 1)
        med[j-1] = paz[(k/2)];
         else if (k%2 == 0 && k != 2) {
            if (((paz[k/2] + paz[(k/2) - 1])/2) % 2 == 1)
            med[j-1] = (paz[k/2] + paz[(k/2) - 1])/2+0.5;
            else med[j-1] = (paz[k/2] + paz[(k/2) - 1])/2;
        }
        else if (k%2 == 0 && k == 2) med[j-1] = Vid[j-1];

        cout << "Vidurkis: " << setprecision(2) << fixed << Vid[j-1] << endl;
        cout << "Mediana: " << setprecision(2) << fixed << med[j-1] << endl;


    }




    cout << "Rodyti mediana ar aritmetini vidurki? m/v" << endl;
    cin >> p;

    if (p == 'm') {
    cout << string(79, '*') << endl;
    cout << left << setw(30) << "Mokinys" << "Galutinis (Med.)" << endl;
    for (int o = 0; o < s; o++)
    {
        cout << left << setw(35) << Vardas[o] << med[o] << endl;
    }
    }
    if (p == 'v')
    {
    cout << string(79, '*') << endl;
    cout << left << setw(30) << "Mokinys" << "Galutinis (Vid.)" << endl;
    for (int o = 0; o < s; o++)
    {
        cout << left << setw(35) << Vardas[o] << Vid[o] << endl;
    }
    }
}
    return 0;
}




