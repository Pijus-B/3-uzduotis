#include <bits/stdc++.h>
using namespace std;

const int MAX_ND_SIZE = 500;
const int MAX_STUDENTS = 500;
//a
struct studentas
{
    string vardas;
    string pavarde;
     vector <int> nd;
     int egz;
     double balas;
     double vid;
     double mediana;
};


void skaitymas (vector <studentas> & A);
void spausdinti (const vector <studentas> & A);
void skaiciavimas (vector <studentas> & A);
void generavimasPazymiu (vector <studentas> & A, int n);
void generavimasPazymiuCase2 (vector <studentas> & A);
void generavimasStudentu (vector <studentas> & A, int n);
bool isValidName(const string &name);

int main (){
    
    vector <studentas> A;
    int n; int pasirinkimas;
    while (true){
        cout << "Pasirinkite norima veiksma: " << endl;
        cout << "1. Ivesti duomenis ranka" << endl;
        cout << "2. Generuoti pazymius" << endl;
        cout << "3. Generuoti studentu vardus ir pavardes" << endl;
        cout << "4. Baigti programa" << endl;
        cin >> pasirinkimas;

        switch (pasirinkimas){
            case 1:
            {
                A.clear();
                skaitymas (A);
                skaiciavimas (A);
                spausdinti (A);
                break;
            }
            case 2:
            {
                int n2;
                cout << "Iveskite zmoniu skaiciu" << endl;
                cin >> n2;
                A.clear();
                for (int i = 0; i < n2; i++)
            {
                studentas student;
                bool valid_names;
                do
                {
                    cout << "Iveskite savo varda" << endl;
                    cin >> student.vardas;
                    cout << "Iveskite savo pavarde" << endl;
                    cin >> student.pavarde;
                    valid_names = isValidName(student.vardas) && isValidName(student.pavarde);
                    if (!valid_names)
                    {
                        cout << "Netinkami vardai. Bandykite is naujo." << endl;
                    }
                } while (!valid_names);
                 A.push_back(student);
            }
                generavimasPazymiuCase2(A);
                skaiciavimas (A);
                spausdinti (A);
                break;
            }
            case 3:
            {
                int n3 = rand() % (MAX_STUDENTS + 1);
                A.clear();
                generavimasPazymiu (A, n3);
                generavimasStudentu (A, n3);
                skaiciavimas (A);
                spausdinti (A);
                break;
            }
            case 4:
            {
                cout << "Programos pabaiga" << endl;
                return 0;
            }
            default:
            {
                cout << "Neteisingas pasirinkimas. Bandykite dar karta" << endl;
                break;
            }
        }
    }

return 0;
}
void skaitymas (vector <studentas> & A)
{  
    int n;
     cout << "Iveskite zmoniu kieki " << endl;
     cin >> n;
      for (int i = 0; i < n; i++)
    {
        studentas student;
        cout << "Iveskite savo varda" << endl;
        cin >> student.vardas;
        cout << "Iveskite savo pavarde " << endl;
        cin >> student.pavarde;
        bool valid_vardas = isValidName(student.vardas);
        bool valid_pavarde = isValidName(student.pavarde);
        if (!valid_vardas || !valid_pavarde)
        {
            cout << "Netinkami vardai. Bandykite is naujo." << endl;
            i--;
            continue;
        }
        cout << "Iveskite egzamino rezultatus " << endl;
        cin >> student.egz;
        cout << "Iveskite namu darbu tarpinius rezultatus (baigti ivesdami -1)" << endl;
        int nd;
        while (cin >> nd && nd != -1)
        {
            student.nd.push_back(nd);
        }
        A.push_back(student);
    }
}
void skaiciavimas (vector <studentas> & A)
{ 
   for (auto &student : A)
    {
        sort(student.nd.begin(), student.nd.end());
        int size = student.nd.size();
        if (size % 2 == 0)
        {
            student.mediana = (student.nd[size / 2 - 1] + student.nd[size / 2]) / 2.0;
        }
        else
        {
            student.mediana = student.nd[size / 2];
        }
        double sum = accumulate(student.nd.begin(), student.nd.end(), 0);
        if (size > 0)
        {
            student.vid = sum / size;
            student.balas = 0.4 * student.vid + 0.6 * student.egz;
        }
        else
        {
            student.vid = student.egz;
            student.balas = student.vid;
            student.mediana = student.vid;
        }
    }
}
void spausdinti (const vector <studentas> & A)
{
    cout << left << setw(10) << "Pavarde " << setw(15) << "Vardas " << setw(15) << "Galutinis (Vid.) " << " " << "/ Galutinis (Med.)" << endl;
    cout << "----------------------------------------------------" << endl;
    for (const auto & student : A){
     cout << left << setw(10) << student.vardas << setw(15) << student.pavarde << fixed << setprecision(2) << setw(15) << student.balas << setw(10) << student.mediana << endl;
    }
}
void generavimasPazymiu(vector<studentas>& A, int n2) {
    srand(time(0));
    A.clear();
    for (int i = 0; i < n2; i++)
    {
        studentas student;
        int nd_count = rand() % (MAX_ND_SIZE + 1);
        for (int j = 0; j < nd_count; j++)
        {
            student.nd.push_back(rand() % 11);
        }
        student.egz = rand() % 11;
        A.push_back(student);
    }
}
void generavimasPazymiuCase2 (vector <studentas> & A)
{
    srand(time(0));
    for (int i = 0; i < A.size(); i++){
        int nd_count = rand() % (MAX_ND_SIZE + 1);
        for (int j = 0; j < nd_count; j++){
            A[i].nd.push_back(rand() % 11);
        }
        A[i].egz = rand() % 11;
    }
}
void generavimasStudentu(vector<studentas>& A, int n) {
   
    srand(time(0));

    string vardai[] = {"Rokas", "Mantas", "Pijus", "Laurynas", "Ignas", "Gabriele", "Ugne", "Kamile", "Rugile", "Roberta"};
    string pavardes[] = {"Gilys", "Globys", "Bogusis", "Dulskis", "Maliauka", "Skirmantaite", "Mockute", "Zobelaite", "Macaite", "Jurpalyte"};

    for (int i = 0; i < A.size(); i++)
    {
        studentas student;
       A[i].vardas = vardai[rand() % 10];
       A[i].pavarde = pavardes[rand() % 10];
    }
}
bool isValidName(const string &name)
{
    for (char c : name)
    {
        if (!isalpha(c) && c != ' ')
        {
            return false;
        }
    }
    return true;
}