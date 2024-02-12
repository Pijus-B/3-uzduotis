#include <bits/stdc++.h>
using namespace std;

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


void skaitymas (vector <studentas> & A, int & n);
void spausdinti (const vector <studentas> & A);
void skaiciavimas (vector <studentas> & A);

int main (){
    
    vector <studentas> A;
    int n;
    skaitymas(A, n);
    skaiciavimas (A);
    spausdinti (A);

return 0;
}
void skaitymas (vector <studentas> & A, int & n)
{  
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
