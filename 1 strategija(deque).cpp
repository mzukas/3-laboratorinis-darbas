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
deque <duomm> lentele;
deque <duomm> nuskriaustukai;
deque <duomm> galvociai;

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
//----------------------------------------------------------------------------------------------------
void galutinis_paz(duom& stud)
{
    stud.gal = stud.vid * 0.4 + stud.egz * 0.6;
}
//----------------------------------------------------------------------------------------------------
void uzpildyti_eilute(duom stud, ofstream& file)
{
    file << left << setw(15) << stud.vardas << setw(15) << stud.pavarde << right << setw(5) << stud.gal << endl;
}
//----------------------------------------------------------------------------------------------------


void Pildymas()
{
    vector <duom> stud;
    int kiek = 0;
    char p;
    cout << "Iveskite mokiniu kieki: 0 - pildyti visus (0,10,100,1000,10000,100000): ";
    cin >> kiek;
   while (!cin.good())
{
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    cout << "Klaida. Iveskite dar karta: ";
    cin >> kiek;
}
    while (kiek != 0 && kiek != 10 && kiek != 100 && kiek != 1000 && kiek != 10000 && kiek != 100000)
{
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    cout << "Klaida. Iveskite dar karta: ";
    cin >> kiek;
}


{

    ofstream failas_desimt;
    ofstream failas_simtas;
    ofstream failas_tukst;
    ofstream failas_desimttukst;
    ofstream failas_simtastukst;



    failas_desimt.open("10.txt");
    failas_simtas.open("100.txt");
    failas_tukst.open("1000.txt");
    failas_desimttukst.open("10000.txt");
    failas_simtastukst.open("100000.txt");


if (kiek == 0)
    {
       for(int j = 0; j < 10; j++){
                stud.push_back(studentas(j));
                galutinis_paz(stud[j]);
                uzpildyti_eilute(stud[j], failas_desimt);
                    }
        stud.clear();
        for(int o = 0; o < 100; o++){
                stud.push_back(studentas(o));
                galutinis_paz(stud[o]);
                uzpildyti_eilute(stud[o], failas_simtas);
                    }
        stud.clear();
        for(int e = 0; e < 1000; e++){
                stud.push_back(studentas(e));
                galutinis_paz(stud[e]);
                uzpildyti_eilute(stud[e], failas_tukst);
                    }
        stud.clear();
        for(int a = 0; a < 10000; a++){
                stud.push_back(studentas(a));
                galutinis_paz(stud[a]);
                uzpildyti_eilute(stud[a], failas_desimttukst);
                    }
        stud.clear();
        for(int x = 0; x < 100000; x++){
                stud.push_back(studentas(x));
                galutinis_paz(stud[x]);
                uzpildyti_eilute(stud[x], failas_simtastukst);
        }
        stud.clear();
    }



else if (kiek != 0)
{
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

        }

    }
}


    failas_desimt.close();
    failas_simtas.close();
    failas_tukst.close();
    failas_desimttukst.close();
    failas_simtastukst.close();


}

    kiekis = kiek;

}
//----------------------------------------------------------------------------------------------------


void Duomenys(string& failopavadinimas)
{
ifstream is;
ofstream fs,pl;
string lin, vard, pav;
double gal;
duomm temp1;
auto tp= chrono::steady_clock::now();
is.open(failopavadinimas);
while (is >> temp1.vardas >> temp1.pavarde >> temp1.galutinis)
    {
        lentele.push_back(temp1);

    }
auto tf= chrono::steady_clock::now();
auto ls= tf-tp;
chrono::duration<double, milli> (ls).count();
cout<<"Laikas kol nuskaite duomenu faila: "<<chrono::duration<double, milli> (ls).count()<<" ms"<<endl;
auto rr= chrono::steady_clock::now();
rusiavimas();
auto re= chrono::steady_clock::now();
auto r = re - rr;
cout << "Laikas kol surusiavo pagal galutinius pazymius: " << chrono::duration<double, milli> (r).count()<<" ms"<<endl;
is.close();

}
//----------------------------------------------------------------------------------------------------


void Bendras()
{
ifstream is;
ofstream fs,pl;
string vard, pav;
double gal;
duomm temp1;
auto tp= chrono::steady_clock::now();
for (int i = 0; i < 5; i++)
{
    is.open(failopav[i]);
    while (is >> temp1.vardas >> temp1.pavarde >> temp1.galutinis)
    {
        lentele.push_back(temp1);

    }
    is.close();
}
auto tf= chrono::steady_clock::now();
auto ls= tf-tp;
chrono::duration<double, milli> (ls).count();
cout<<"Laikas kol nuskaite duomenu failus: "<<chrono::duration<double, milli> (ls).count()<<" ms"<<endl;
auto rr= chrono::steady_clock::now();
rusiavimas();
auto re= chrono::steady_clock::now();
auto r = re - rr;
cout << "Laikas kol surusiavo pagal galutinius pazymius: " << chrono::duration<double, milli> (r).count()<<" ms"<<endl;


}
//----------------------------------------------------------------------------------------------------
void Skaitymas(int s)
{

        if (s == 10)
        {
        Duomenys(failopav[0]);
            }
        else if (s == 100)
        {
        Duomenys(failopav[1]);
        }
        else if (s == 1000)
        {
        Duomenys(failopav[2]);
        }
        else if (s == 10000)
        {
        Duomenys(failopav[3]);
        }
        else if (s == 100000)
        {
        Duomenys(failopav[4]);
        }
    else if (s == 0)
    {
        Bendras();
    }

}
//----------------------------------------------------------------------------------------------------
bool rusiuot(const duomm &p, const duomm &pa)
{
    return p.galutinis<pa.galutinis;
}
//----------------------------------------------------------------------------------------------------
void rusiavimas()
{
    sort (lentele.begin(), lentele.end(), rusiuot);
}
//----------------------------------------------------------------------------------------------------
void Rasymas()
{
    ofstream ps,pp;
    auto ng= chrono::steady_clock::now();
    for (duomm i : lentele)
    {

        if (i.galutinis<5)
        {
            nuskriaustukai.push_back(i);
        }
         if (i.galutinis>5)
        {
            galvociai.push_back(i);
        }

	}
    auto nt= chrono::steady_clock::now();
    auto gn = nt - ng;
   cout << "Laikas kol surusiavo i galvocius ir nuskriaustukus: " << chrono::duration<double, milli> (gn).count()<<" ms"<<endl;

auto sp= chrono::steady_clock::now();
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
auto tn= chrono::steady_clock::now();
auto pk = tn - sp;
cout<<"Laikas isvedinejant i nuskriaustuku ir galvociu failus: "<< chrono::duration<double, milli> (pk).count() <<" ms"<<endl;

}
//----------------------------------------------------------------------------------------------------

int main()
{
    Pildymas();
    Skaitymas(kiekis);
    Rasymas();

system ("pause");
}
