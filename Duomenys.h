#ifndef DUOMENYS_H_INCLUDED
#define DUOMENYS_H_INCLUDED

using namespace std;

struct duom {
	string vardas, pavarde;
	vector <int> paz;
	double vid, gal;
	int egz;
};

duom studentas(int s);
void galutinis_paz(duom& stud);
bool galvociai(duom stud);
void uzpildyti_eilute(duom stud, ofstream& file);

//--------------------------------------------------------------------------------------------------------------------
void uzpildyti_eilute(duom stud, ofstream& file)
{
    file << left << setw(15) << stud.vardas << setw(15) << stud.pavarde << right << setw(5) << stud.gal << endl;
}

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

bool galvociai (duom stud)
{
    return stud.gal >= 5;
}

void galutinis_paz(duom& stud)
{
    stud.gal = stud.vid * 0.4 + stud.egz * 0.6;
}

#endif // DUOMENYS_H_INCLUDED
