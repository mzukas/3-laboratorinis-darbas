#include <D:\MECHATRONIKA IR ROBOTIKA\C++\0.4\Headeriai.h>
#include <D:\MECHATRONIKA IR ROBOTIKA\C++\0.4\Duomenys.h>

int main ()
{
    vector<duom> stud;

    int kiek = 0;
    cout << "Iveskite mokiniu kieki: ";
    try {
        cin >> kiek;
    } catch(int e) {
        cout << "Klaida " << e << endl;
    }

    auto pradzios_laikas = chrono::steady_clock::now();

    ofstream failas_galvociai; //pazymiu vidurkis daugiau nei 5
    ofstream failas_nuskriaustukai; //maziau nei 5
    failas_galvociai.open("galvociai.txt");
    failas_nuskriaustukai.open("nuskriaustukai.txt");

    failas_nuskriaustukai << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(15) << "Galutinis vid." << endl;
    failas_nuskriaustukai << string(79, '*') << endl;
    failas_galvociai << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(15) << "Galutinis vid." << endl;
    failas_galvociai << string(79, '*') << endl;


    for(int i = 0; i < kiek; i++)
    {

        stud.push_back(studentas(i));
        galutinis_paz(stud[i]);
        if(galvociai(stud[i]))
        {
            uzpildyti_eilute(stud[i], failas_galvociai);
        }
        else
        {
            uzpildyti_eilute(stud[i], failas_nuskriaustukai);
        }
    }
    failas_nuskriaustukai.close();
    failas_galvociai.close();

    auto pabaigos_laikas = chrono::steady_clock::now();
    auto laiko_skirtumas = pabaigos_laikas - pradzios_laikas;
    cout  << "Uztruko " << chrono::duration <double, milli> (laiko_skirtumas).count() << " ms" << endl;
    return 0;
}
