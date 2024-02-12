#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;

const int MAX_ND_SIZE = 500;
const int MAX_STUDENTS = 500;

struct studentas
{
    string vardas;
    string pavarde;
     int nd [MAX_ND_SIZE];
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

int main (){

    studentas A [MAX_STUDENTS];
    int n; int pasirinkimas;
    while (true){

        cout << "Pasirinkite norima veiksma: " << endl;
        cout << "1. Ivesti duomenis ranka" << endl;
        cout << "2. Generuoti pazymius" << endl;
        cout << "3. Generuoti ir studentu vardus, ir pavardes" << endl;
        cout << "4. Baigti programa" << endl;
        cin >> pasirinkimas;

        switch (pasirinkimas) {
            case 1:
                skaitymas (A, n);
                skaiciavimas (A, n);
                spausdinti (A, n);
                break;
            case 2:
                 cout << "Iveskite zmoniu skaiciu" << endl;
                 cin >> n;
                generavimasPazymiu (A, n);
                skaiciavimas (A, n);
                spausdinti (A, n);
                break;
            case 3:
                generavimasStudentu (A, n);
                generavimasPazymiu (A, n);
                skaiciavimas (A, n);
                spausdinti (A, n);
                break;
            case 4:
                cout << "Programos pabaiga" << endl;
                return 0;
            default:
                cout << "Neteisingas pasirinkimas. Bandykite dar karta" << endl;
        }
    }
return 0;
}
void skaitymas (studentas A [], int & n)
{  
     cout << "Iveskite zmoniu kieki " << endl;
     cin >> n;
     for (int i = 0; i < n; i++){
        cout << "Iveskite savo varda" << endl;
        cin >> A[i].vardas;
        cout << "Iveskite savo pavarde " << endl;
        cin >> A[i].pavarde;
        cout << "Iveskite namu darbu tarpinius rezultatus (baigti ivesdami -1)" << endl;
        A[i].nd_count = 0;
        int paz;
        while (cin >> paz && paz != -1){
            A[i].nd[A[i].nd_count++] = paz;
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
        A[i].nd_count = rand() % (MAX_ND_SIZE + 1);
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
        A[i].nd_count = rand() % (MAX_ND_SIZE + 1);
        for (int j = 0; j < A[i].nd_count; j++)
        {
            A[i].nd[j] = rand() % 11;
        }
    }
}