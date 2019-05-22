#include <chrono>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <list>
#include <deque>







using namespace std;
struct duom {
	string vardas, pavarde;
	vector <int> paz;
	double vid, gal;
	int egz;

};
struct duomm {
	string vardas, pavarde;
	double galutinis;

};
void rusiavimas();
vector <duomm> lentele;
vector <duomm> nuskriaustukai;
vector <duomm> galvociai;

int kiekis;
duom studentas(int s);
void galutinis_paz(duom& stud);
bool rusiavimas(duom stud);
void uzpildyti_eilute(duom stud, ofstream& file);
string failopav[7]= {"10.txt","100.txt","1000.txt","10000.txt","100000.txt","galvociai.txt","nuskriaustukai.txt"};
//--------------------------------------------------------------------------------------------------------------------
duom studentas(int s)
{
    duom stud;
    stud.vid = 0;
    stud.vardas = "Vardas" + to_string(s);
    stud.pavarde = "Pavarde" + to_string(s);
    for(int i = 0; i < 5; i++)
    {
        int ran = rand() % 10 + 1;
        stud.vid += ran;
    }
    stud.egz = rand() % 10 + 1;
    stud.vid = stud.vid / 5;
    return stud;
}
void galutinis_paz(duom& stud)
{
    stud.gal = stud.vid * 0.4 + stud.egz * 0.6;
}
void uzpildyti_eilute(duom stud, ofstream& file)
{
    file << left << setw(15) << stud.vardas << setw(15) << stud.pavarde << right << setw(5) << stud.gal << endl;
}
void Pildymas()
{
    vector <duom> stud;
    int kiek = 0;
    char p;
    cout << "Iveskite mokiniu kieki(10,100,1000,10000,100000): ";
    try {
        cin >> kiek;
    } catch(int e) {
        cout << "Klaida " << e << endl;
    }


{

    ofstream failas_desimt;
    ofstream failas_simtas;
    ofstream failas_tukst;
    ofstream failas_desimttukst;
    ofstream failas_simtastukst;
    ofstream failas_atsitiktiniskiek;


    failas_desimt.open("10.txt");
    failas_simtas.open("100.txt");
    failas_tukst.open("1000.txt");
    failas_desimttukst.open("10000.txt");
    failas_simtastukst.open("100000.txt");
    failas_atsitiktiniskiek.open("bendras.txt");

    for(int i = 0; i < kiek; i++)
    {

        stud.push_back(studentas(i));
        galutinis_paz(stud[i]);
        {
            if (kiek == 10) {
            uzpildyti_eilute(stud[i], failas_desimt);
            }
            else if (kiek == 100) {
            uzpildyti_eilute(stud[i], failas_simtas);
            }
            else if (kiek == 1000) {
                 uzpildyti_eilute(stud[i], failas_tukst);
            }
            else if (kiek == 10000) {
                 uzpildyti_eilute(stud[i], failas_desimttukst);
            }
            else if (kiek == 100000) {
                 uzpildyti_eilute(stud[i], failas_simtastukst);
            }
            else {
                uzpildyti_eilute(stud[i], failas_atsitiktiniskiek);
            }
        }

    }



    failas_desimt.close();
    failas_simtas.close();
    failas_tukst.close();
    failas_desimttukst.close();
    failas_simtastukst.close();
    failas_atsitiktiniskiek.close();

}

    kiekis = kiek;

}



void Skaitymas(int s)
{
    ifstream is;
    ofstream fs;
    string lin, vard, pav;
    double gal;
    duomm temp1;
        if (s == 10)
        {is.open(failopav[0]);
            }
        else if (s == 100)
        {is.open(failopav[1]);
        }
        else if (s == 1000)
        {is.open(failopav[2]);
        }
        else if (s == 10000)
        {is.open(failopav[3]);
        }
        else if (s == 100000)
        {is.open(failopav[4]);
        }
while (is >> temp1.vardas >> temp1.pavarde >> temp1.galutinis)
    {
        lentele.push_back(temp1);
    }
rusiavimas();

for (duomm i : lentele)
{
     fs <<i.vardas<<setw(15)<<i.pavarde<<setw(10)<<i.galutinis<<endl;
}
is.close();

}

bool rusiuot(const duomm &p, const duomm &pa)
{
    return p.galutinis<pa.galutinis;
}

void rusiavimas()
{
    sort (lentele.begin(), lentele.end(), rusiuot);
}

void Rasymas()
{
    ofstream ps,pp;
    for (duomm i : lentele)
    {
        if (i.galutinis<5)
        {
            nuskriaustukai.push_back(i);
        }
        else if(i.galutinis>5)
        {
            galvociai.push_back(i);

        }
	}

//isvedimas i tinginiu ir grauziku failus

ps.open("nuskriaustukai.txt", std::ofstream::out | std::ofstream::trunc);
pp.open("galvociai.txt", std::ofstream::out | std::ofstream::trunc);

for (duomm i : nuskriaustukai)
{
     ps <<i.vardas<<setw(15)<<i.pavarde<<setw(10)<<i.galutinis<<endl;
}
for (duomm i : galvociai)
{
     pp <<i.vardas<<setw(15)<<i.pavarde<<setw(10)<<i.galutinis<<endl;
}

ps.close();
pp.close();



}


int main()
{
    Pildymas();
    Skaitymas(kiekis);
    Rasymas();
return 0;
}
