#include <D:\MECHATRONIKA IR ROBOTIKA\C++\ND2(0.3)\Header_0.3.h>
#include <D:\MECHATRONIKA IR ROBOTIKA\C++\ND2(0.3)\Duomenys_0.3.h>

const int max_stud_kiekis = 100;
const int max_nd_kiekis = 100;

int main()
{
    char r;
    cout << "Vesite duomenis is failo ar ekrano? f/e " << endl;
	cin >> r;
    if (r == 'e')
    try
	{ duom temp;  char kr;
	    do {
		temp.pildymas();
		lent.push_back(temp);

		cout << "Vesti kita mokini? t/n: "<<endl;;
		cin >> kr;
	} while (kr == 't' || kr == 'T');
	isvedimas();
	}
     catch(int e)
        {
            cout << "Error number " << e << endl;
        }


else if (r == 'f')
{
    duom temp[max_stud_kiekis];
    ifstream failas("ursiokai.txt");
    string eil;
    int n=0, i=0;
    try {
    failas >> eil;
    while( failas >> eil  )
        {
           read_from_file(eil, temp[n]);
           skaiciavimai(temp[n]);
           i++;
           n++;
        }
failas.close();
    }
    catch(int e)
        {
            cout << "Klaida. Numeris: " << e << endl;
        }
    cout << "Norite skaiciuoti vidurki ar mediana? (v/m)" << endl;
    cin >> r;
    if(r == 'm')
    {
        cout << string(79, '*') << endl;
        cout << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(15) << "Galutinis (med.)" << endl;
        cout << string(79, '-') << endl;
        for(int j = 0; j < i; j++)
        {
            cout << left << setw(15) <<temp[j].vardas << setw(15) << temp[j].pavarde << right<< setw(5) << temp[j].med<< endl;
        }
    }
    else if (r == 'v')
    {
        cout << string(79, '*') << endl;
        cout << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(15) << "Galutinis (vid.)" << endl;
        cout << string(79, '-') << endl;
        for(int j = 0; j < i; j++)
        {
            cout << left << setw(15) << temp[j].vardas << setw(15) << temp[j].pavarde << right << setw(5) << temp[j].vid << endl;
        }
    } }

   system("pause");
}
