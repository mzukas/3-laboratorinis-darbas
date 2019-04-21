#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>

using namespace std;

struct duom {
	string vardas, pavarde;
	vector <int> paz;
	double vid, med, gal;
	void pildymas();
};
vector <duom> lent;

void duom::pildymas()
{

    int itemp, p, o;
    int j = 1;
	char k;
	cout << "Iveskite mokinio varda: ";
	cin >> vardas;
	cout << "Iveskite mokinio pavarde: ";
	cin >> pavarde;

	cout << "Generuoti pazymius atsitiktinai ar ivesite ranka? a/r "; // a - atsitiktinai, r - ranka
	cin >> k;
if (k == 'a')
   {

        cout << "Mokinio pazymiu kiekis: ";
        cin >> p;
        paz.clear();
        srand(time(NULL));
        for (int o=1; o <= p; o++)
        {
            paz.push_back(rand()%10+1);
            cout << paz.back() << endl;
        }

    }
else if (k == 'r')
    {
             do {
                cout << "Iveskite " << j << " pazymi (0 - jei norite baigti pazymiu pildyma): ";
                cin >> itemp;
                paz.push_back(itemp);
                j++;
            } while(itemp);
            paz.pop_back();
    }

        vid = 0;
        for (int i : paz)
        vid += i;
        vid = double(vid) / paz.size();
        sort(paz.begin(), paz.end());
        med = (paz.size() % 2 == 1) ? paz[paz.size() / 2] : double(paz[paz.size() / 2] + paz[paz.size() / 2 - 1]) / 2;
}

void isvedimas()
{
    char p;
    cout << "Rodyti mediana ar aritmetini vidurki? m/v" << endl;
    cin >> p;
     switch (p)
    {
        case ('V','v'):
            cout << string(79, '*') << endl;
            cout << left << setw(30) << "Mokinys" << "Galutinis (Vid.)" << endl;
            for (duom i: lent)
    {
        cout << i.vardas<< " " << setw(28) << left << i.pavarde;
        cout <<fixed<<setprecision(2)<<i.vid<<endl;
    }
            break;

        case ('M','m'):
            cout << string(79, '*') << endl;
            cout << left << setw(30) << "Mokinys" << "Galutinis (Med.)" << endl;
    for (duom i: lent)
    {
        cout << i.vardas << " "  << setw(28) << left << i.pavarde;
        cout <<fixed<<setprecision(2)<<i.med<<endl;
    }
            break;
    }

}

int main()
{

    duom Sd_temp;  char kr;
	do {
		Sd_temp.pildymas();
		lent.push_back(Sd_temp);

		cout << "Vesti kita mokini? t/n: "<<endl;;
		cin >> kr;
	} while (kr == 't' || kr == 'T');

    isvedimas();


    system("pause");
}
