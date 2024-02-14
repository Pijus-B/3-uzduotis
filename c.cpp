#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;

const int MAX_STUDENTS = 500;


struct studentas
{
    string vardas;
    string pavarde;
     int * nd;
     int nd_count;
     int egz;
     double balas;
     double vid;
     double mediana;
};

void skaitymas (studentas A[], int & n);
void spausdinti (const studentas A[], int n);
void skaiciavimas (studentas A[], int n);
void generavimasPazymiu (studentas A[], int n);
void generavimasStudentu (studentas A[], int n);
bool isValidName(const string &name);
int *naujas(int size);
int *kopijavimas (int *pirmas, int *antras, int size, int reiksme);

int main (){

    int n; int pasirinkimas; studentas *A;
    while (true){

        cout << "Pasirinkite norima veiksma: " << endl;
        cout << "1. Ivesti duomenis ranka" << endl;
        cout << "2. Generuoti pazymius" << endl;
        cout << "3. Generuoti ir studentu vardus, ir pavardes" << endl;
        cout << "4. Baigti programa" << endl;
        cin >> pasirinkimas;

        switch (pasirinkimas) {
            case 1:
            {
                skaitymas (A, n);
                skaiciavimas (A, n);
                spausdinti (A, n);
                break;
            }
            case 2:
            {
                 int n;
                 cout << "Iveskite zmoniu skaiciu" << endl;
                while (!(cin >> n) || cin.peek() != '\n')
                 {
                      cout << "Netinkamas ivesties formatas. Iveskite skaiciu." << endl;
                      cin.clear();
                      cin.ignore(numeric_limits<streamsize>::max(), '\n');
                 }
                 A = new studentas[n];
                for (int i = 0; i < n; ++i)
                {
                bool valid_names;
                do
                {
                    cout << "Iveskite savo varda" << endl;
                    cin >> A[i].vardas;
                    cout << "Iveskite savo pavarde" << endl;
                    cin >> A[i].pavarde;

                    valid_names = isValidName(A[i].vardas) && isValidName(A[i].pavarde);

                    if (!valid_names)
                    {
                        cout << "Netinkami vardai. Bandykite is naujo." << endl;
                    }
                } while (!valid_names);
            }

                generavimasPazymiu (A, n);
                skaiciavimas (A, n);
                spausdinti (A, n);
                break;
            }
            case 3:
            {
                n = rand() % (MAX_STUDENTS + 1);
                A = new studentas[n];
                generavimasStudentu (A, n);
                generavimasPazymiu (A, n);
                skaiciavimas (A, n);
                spausdinti (A, n);
                break;
            }
            case 4:
            {
                cout << "Programos pabaiga" << endl;
                return 0;
            default:
                cout << "Neteisingas pasirinkimas. Bandykite dar karta" << endl;
            }
        }
    }
return 0;
}
int *naujas(int size)
{
    return new int[size];
}

int *kopijavimas(int *pirmas, int *antras, int size, int reiksme)
{
    for (int i = 0; i < size; i++)
    {
        antras[i] = pirmas[i];
    }
    antras[size] = reiksme;
    return antras;
}
void skaitymas (studentas A [], int & n)
{  
     cout << "Iveskite zmoniu kieki " << endl;
     cin >> n;
     while (!(cin >> n) || cin.peek() != '\n')
     {
        cout << "Netinkamas ivesties formatas. Iveskite skaiciu." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
     for (int i = 0; i < n; i++)
    {
        bool valid_vardas = false;
        bool valid_pavarde = false;
        while (!valid_vardas || !valid_pavarde)
        {
            cout << "Iveskite savo varda" << endl;
            cin >> A[i].vardas;
            valid_vardas = isValidName(A[i].vardas);

            cout << "Iveskite savo pavarde " << endl;
            cin >> A[i].pavarde;
            valid_pavarde = isValidName(A[i].pavarde);

            if (!valid_vardas || !valid_pavarde)
            {
                cout << "Netinkami vardai. Bandykite is naujo." << endl;
            }
        }

        cout << "Iveskite namu darbu tarpinius rezultatus (baigti ivesdami -1)" << endl;
        A[i].nd = nullptr;
        A[i].nd_count = 0;
        int paz;
        while (cin >> paz && paz != -1)
        {
            int *new_nd = naujas(A[i].nd_count + 1);
        
        if (A[i].nd != nullptr)
            {
                kopijavimas(A[i].nd, new_nd, A[i].nd_count, paz);
                delete[] A[i].nd;
            }
            else
            {
                new_nd[0] = paz;
            }
            A[i].nd = new_nd;
        }
        cout << "Iveskite egzamino rezultatus" << endl;
        cin >> A[i].egz;
      }
    }
void skaiciavimas (studentas A[], int n)
{ 
    for (int i = 0; i < n; i++)
    {
        sort(A[i].nd, A[i].nd + A[i].nd_count);
        int size = A[i].nd_count;
        if (size % 2 == 0)
        {
            A[i].mediana = (A[i].nd[size / 2 - 1] + A[i].nd[size / 2]) / 2.0;
        }
        else
        {
            A[i].mediana = A[i].nd[size / 2];
        }
        double sum = 0;
        for (int j = 0; j < size; j++)
        {
            sum += A[i].nd[j];
        }
        if (size > 0)
        {
            A[i].vid = sum / size;
            A[i].balas = 0.4 * A[i].vid + 0.6 * A[i].egz;
        }
        else
        {
            A[i].vid = A[i].egz;
            A[i].balas = A[i].vid;
            A[i].mediana = A[i].vid;
        }
    }
}
void spausdinti (const studentas A[], int n)
{
    cout << left << setw(10) << "Pavarde " << setw(15) << "Vardas " << setw(15) << "Galutinis (Vid.) " << " " << "/ Galutinis (Med.)" << endl;
    cout << "----------------------------------------------------" << endl;
    for (int i = 0; i < n; i++){
     cout << left << setw(10) << A[i].vardas << setw(15) << A[i].pavarde << fixed << setprecision(2) << setw(15) << A[i].balas << setw(10) << A[i].mediana << endl;
    }
}
void generavimasPazymiu (studentas A[], int n)
{
    srand(time(0));
    for (int i = 0; i < n; i++){
        A[i].nd_count = rand() % 11;
        A[i].nd = naujas(A[i].nd_count);
        for (int j = 0; j < A[i].nd_count; j++){
            A[i].nd[j] = rand() % 11;
        }
        A[i].egz = rand() % 11;
    }
}
void generavimasStudentu (studentas A[], int n)
{
    srand(time(0));

    string vardai[] = {"Rokas", "Mantas", "Pijus", "Laurynas", "Ignas", "Gabriele", "Ugne", "Kamile", "Rugile", "Roberta"};
    string pavardes [] = {"Gilys", "Globys", "Bogusis", "Dulskis", "Maliauka", "Skirmantaite", "Mockute", "Zobelaite", "Macaite", "Jurpalyte"};

    
    for (int i = 0; i < n; i++)
    {
        A[i].vardas = vardai[rand() % 10];
        A[i].pavarde = pavardes[rand() % 10];
        A[i].nd_count = rand() % 11;
        A[i].nd = naujas(A[i].nd_count);
        for (int j = 0; j < A[i].nd_count; j++)
        {
            A[i].nd[j] = rand() % 11;
        }
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