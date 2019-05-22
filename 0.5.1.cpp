#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <chrono>


using namespace std;

struct duom {
	string vardas, pavarde;
	vector <int> paz;
	double vid, gal;
	int egz;
};
vector <duom> galvociai;
vector <duom> nuskriaustukai;
vector <duom> lentele;
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
bool rusiavimas (duom stud)
{
    return stud.gal >= 5;
}
bool eiliavimas_pagal_galutini (const duom &p, const duom &pa) // vektoriui ir deque
{
    return p.gal<pa.gal;
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
    ofstream failas_galvociai; //pazymiu vidurkis daugiau nei 5
    ofstream failas_nuskriaustukai; //maziau nei 5
    ofstream failas_desimt;
    ofstream failas_simtas;
    ofstream failas_tukst;
    ofstream failas_desimttukst;
    ofstream failas_simtastukst;
    ofstream failas_atsitiktiniskiek;

    failas_galvociai.open("galvociai.txt");
    failas_nuskriaustukai.open("nuskriaustukai.txt");
    failas_desimt.open("10.txt");
    failas_simtas.open("100.txt");
    failas_tukst.open("1000.txt");
    failas_desimttukst.open("10000.txt");
    failas_simtastukst.open("100000.txt");
    failas_atsitiktiniskiek.open("bendras.txt");

    failas_nuskriaustukai << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(15) << "Galutinis vid." << endl;
    failas_nuskriaustukai << string(79, '*') << endl;
    failas_galvociai << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(15) << "Galutinis vid." << endl;
    failas_galvociai << string(79, '*') << endl;
    failas_desimt << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(15) << "Galutinis vid." << endl;
    failas_desimt << string(79, '*') << endl;
    failas_simtas << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(15) << "Galutinis vid." << endl;
    failas_simtas << string(79, '*') << endl;
    failas_tukst << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(15) << "Galutinis vid." << endl;
    failas_tukst << string(79, '*') << endl;
    failas_desimttukst << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(15) << "Galutinis vid." << endl;
    failas_desimttukst << string(79, '*') << endl;
    failas_simtastukst << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(15) << "Galutinis vid." << endl;
    failas_simtastukst << string(79, '*') << endl;
    failas_atsitiktiniskiek << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(15) << "Galutinis vid." << endl;
    failas_atsitiktiniskiek << string(79, '*') << endl;

    for(int i = 0; i < kiek; i++)
    {

        stud.push_back(studentas(i));
        galutinis_paz(stud[i]);
        if(rusiavimas(stud[i]))
        {
            uzpildyti_eilute(stud[i], failas_galvociai);
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
        else
        {
            uzpildyti_eilute(stud[i], failas_nuskriaustukai);
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
    failas_nuskriaustukai.close();
    failas_galvociai.close();
    failas_desimt.close();
    failas_simtas.close();
    failas_tukst.close();
    failas_desimttukst.close();
    failas_simtastukst.close();
    failas_atsitiktiniskiek.close();
}

    kiekis = kiek;

}

int main ()
{

    Pildymas();

    system("pause");
}
