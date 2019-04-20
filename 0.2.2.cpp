#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <bits/stdc++.h>
#include <ctime>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
const int max_stud_kiekis = 100;
const int max_nd_kiekis = 100;

struct duom {
	string vardas, pavarde;
	vector <int> paz;
	double vid, med, gal;
	int egz;
	int kiekis;

	void pildymas(), pildymasf();
};
void read_from_file(string eilute, duom& stud);
vector<string> split(const string& s, char delimiter);
void skaiciavimai(duom& stud);

vector <duom> lent;
vector<string> split(const string& s, char delimiter)
{
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}

void skaitymas(string eilute, duom& stud)
{
    char s = '_';
    vector<string> data = split(eilute, s);

    stud.vid = 0;
    stud.vardas = data[0];
    stud.pavarde = data[1];
    for(int i = 0; i < 6; i++)
    {
        stud.paz.push_back(stoi(data[2+i]));
        stud.vid += stoi(data[2+i]);
    }
    stud.egz = stoi(data[8]);
    stud.vid = stud.vid / 6;
    stud.kiekis = 6;
}
void skaiciavimai(duom& stud)
{
    stud.gal = stud.vid * 0.4 + stud.egz * 0.6;

    int pazymiai[stud.kiekis];
    for(int i = 0; i < stud.kiekis; i++)
    {
        pazymiai[i] = stud.paz[i];
    }
    int n = sizeof(pazymiai)/sizeof(pazymiai[0]);
    sort(pazymiai, pazymiai+n);
    if (n % 2 != 0)
    {
        stud.med = (double)pazymiai[n/2];
    }
    else
    {
        stud.med = (double)(pazymiai[(n-1)/2] + pazymiai[n/2])/2;
    }
}
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
            cout << string(79, '-') << endl;
            for (duom i: lent)
    {
        cout << i.vardas<< " " << setw(28) << left << i.pavarde;
        cout <<fixed<<setprecision(2)<<i.vid<<endl;
    }
            break;

        case ('M','m'):
            cout << string(79, '*') << endl;
            cout << left << setw(30) << "Mokinys" << "Galutinis (Med.)" << endl;
            cout << string(79, '-') << endl;
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
    char r;
    cout << "Vesite duomenis is failo ar ekrano? f/e " << endl;
	cin >> r;
    if (r == 'e')
	{ duom temp;  char kr;
	    do {
		temp.pildymas();
		lent.push_back(temp);

		cout << "Vesti kita mokini? t/n: "<<endl;;
		cin >> kr;
	} while (kr == 't' || kr == 'T');
	isvedimas();
	}





    return 0;
}




