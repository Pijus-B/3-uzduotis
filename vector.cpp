#include <bits/stdc++.h>
using namespace std;

const int MAX_ND_SIZE = 500;

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
void varduSkaitymas(studentas& student);
void spausdinti (const vector <studentas> & A);
void skaiciavimas (vector <studentas> & A);
void generavimasPazymiu (vector <studentas> & A);
void generavimasStudentu (vector <studentas> & A, int n);

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
                skaitymas (A);
                skaiciavimas (A);
                spausdinti (A);
                break;
            case 2:
                cout << "Iveskite zmoniu skaiciu" << endl;
                cin >> n;
                generavimasPazymiu (A);
                skaiciavimas (A);
                spausdinti (A);
                break;
            case 3:
                generavimasStudentu (A, n);
                generavimasPazymiu (A);
                skaiciavimas (A);
                spausdinti (A);
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
void skaitymas (vector <studentas> & A)
{  
    int n;
     cout << "Iveskite zmoniu kieki " << endl;
     cin >> n;
     for (int i = 0; i < n; i++){
        studentas student;
        cout << "Iveskite savo varda" << endl;
        cin >> student.vardas;
        cout << "Iveskite savo pavarde " << endl;
        cin >> student.pavarde;
        cout << "Iveskite egzamino rezultatus " << endl;
        cin >> student.egz;
        cout << "Iveskite namu darbu tarpinius rezultatus (baigti ivesdami -1)" << endl;
        int nd;
        while (cin >> nd && nd != -1){
            student.nd.push_back(nd);
        }
        A.push_back(student);
    }
}
void varduSkaitymas(studentas& student) {
    cout << "Iveskite savo vardą: " << endl;
    cin >> student.vardas;
    cout << "Iveskite savo pavardę: " << endl;
    cin >> student.pavarde;
    cout << "Iveskite egzamino rezultatą: " << endl;
    cin >> student.egz;

    // Sugeneruoti atsitiktinius tarpinius rezultatus (nuo 1 iki 10)
    int nd_count = rand() % (MAX_ND_SIZE + 1);
    student.nd.resize(nd_count);
    for (int i = 0; i < nd_count; i++) {
        student.nd[i] = rand() % 11;
    }
}
void skaiciavimas (vector <studentas> & A)
{ 
    double sum = 0;
    for (auto & student : A){
        sort (student.nd.begin(), student.nd.end());
        for (int paz : student.nd){
            sum += paz;
        }
        int size = student.nd.size();
        if (size % 2 == 0){
            student.mediana = (student.nd[size / 2 - 1] + student.nd[size / 2]) / 2.0;

        }
        else{
            student.mediana = student.nd[size / 2];
        }
        student.vid = sum / size;
        student.balas = 0.4 * student.vid + 0.6 * student.egz;
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
void generavimasPazymiu(vector<studentas>& A) {
    srand(time(0));
    for (auto& student : A) {
        int nd_count = rand() % (MAX_ND_SIZE + 1);
        for (int j = 0; j < nd_count; j++) {
            student.nd.push_back(rand() % 11);
        }
        student.egz = rand() % 11;
    }
}

void generavimasStudentu(vector<studentas>& A, int n) {
    srand(time(0));

    string vardai[] = {"Rokas", "Mantas", "Pijus", "Laurynas", "Ignas", "Gabriele", "Ugne", "Kamile", "Rugile", "Roberta"};
    string pavardes[] = {"Gilys", "Globys", "Bogusis", "Dulskis", "Maliauka", "Skirmantaite", "Mockute", "Zobelaite", "Macaite", "Jurpalyte"};
    A.resize(n);
    for (auto& student : A) {
        student.vardas = vardai[rand() % 10];
        student.pavarde = pavardes[rand() % 10];
        int nd_count = rand() % (MAX_ND_SIZE + 1);
        for (int j = 0; j < nd_count; j++) {
            student.nd.push_back(rand() % 11);
        }
    }
}
