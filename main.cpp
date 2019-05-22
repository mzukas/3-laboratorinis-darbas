#include <D:\MECHATRONIKA IR ROBOTIKA\C++\0.4\Headeriai.h>
#include <D:\MECHATRONIKA IR ROBOTIKA\C++\0.4\Duomenys.h>

int main ()
{
    vector<duom> stud;
    int kiek = 0;
    char p;
    cout << "Vesite ranka ar atsitiktinai? r/a: ";
    cin >> p;
    while (p != 'a' && p != 'r')
    {
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    cout << "Klaida. Iveskite dar karta: ";
    cin >> p;
    }
    if (p == 'a') {

        srand(time(0));
        kiek = rand();
    }
    else if (p == 'r') {cout << "Iveskite mokiniu kieki: ";
    try {
        cin >> kiek;
    } catch(int e) {
        cout << "Klaida " << e << endl;
    }
    }
    cout << kiek << endl;

auto pradzios_laikas = chrono::steady_clock::now();
{
    auto failu_kurimas_pradzia = chrono::steady_clock::now();
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
        if(galvociai(stud[i]))
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

    auto pabaigos_laikas = chrono::steady_clock::now();
    auto laiko_skirtumas = pabaigos_laikas - pradzios_laikas;
    cout  << "Failu kurimas ir studentu rusiavimas uztruko " << chrono::duration <double, milli> (laiko_skirtumas).count() << " ms" << endl;
    system("pause");
}
