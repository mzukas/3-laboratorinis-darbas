#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct duom {
	string vardas, pavarde;
	vector <int> paz;
	double vid, med, gal;
	void pildymas;
};
vector <duom> lent;

void duom::pildymas();
{
    int itemp, j=1, p, o, lol;
	char k;
	cout << "Iveskite mokinio varda: ";
	cin >> vardas;
	cout << "Iveskite mokinio pavarde: ";
	paz.clear();
	cout << "Ar generuoti pazymius atsitiktinai? t/n";
	cin >> k;
	if (k == 't')
    {
        cout << "Kiek pazymiu bus?";
        cin >> p;
        for (int i=0; i < k; i++)
        {
            paz.push_back(rand()%10);
        }
    }
}

int main()
{

    return 0;
}




