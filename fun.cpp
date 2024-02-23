#pragma once
#include "fun.h"

void skaitymas (vector <studentas> & A, int n)
{ 
    cin >> n;
      for (int i = 0; i < n; i++)
    {
         studentas student;
        
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
void skaitymasTeksto (vector <studentas> & A)
{
    ifstream fd ("studentai10000.txt");
    string eil;
    getline(fd, eil);

    clock_t start = clock();

    while (getline(fd, eil)){
        stringstream ss(eil);
        studentas student;
        ss >> student.vardas >> student.pavarde;
        int paz;
        while (ss >> paz){
            student.nd.push_back(paz);
        }
        ss >> student.egz;
        A.push_back(student);
    }
    clock_t end = clock();
    double elapsed_secs = double(end - start) / CLOCKS_PER_SEC;
    cout << "Laikas, per kuri nuskaite teksta: " << elapsed_secs << " sekundes" << endl;
    fd.close();

}
void skaiciavimas (vector <studentas> & A)
{ 
   for (auto& student : A)
    {
        sort(student.nd.begin(), student.nd.end());
        int size = student.nd.size();
        if (size % 2 == 0)
        {
            int indeksas1 = size / 2 - 1;
            int indeksas2 = size / 2;
            student.mediana = (student.nd.at(indeksas1) + student.nd.at(indeksas2)) / 2.0;
        }
        else
        {
            int indeksas2 = size / 2;
            student.mediana = student.nd.at(indeksas2);
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
bool pagalVarda(const studentas & A, const studentas & B) {
    return A.vardas < B.vardas;
}
bool pagalPavarde(const studentas & A, const studentas & B) {
    return A.pavarde < B.pavarde;
}
bool pagalVidurki(const studentas & A, const studentas & B) {
    return A.balas < B.balas;
}
bool pagalMediana(const studentas & A, const studentas & B) {
    return A.mediana < B.mediana;
}
void spausdinti (const vector <studentas> & A)
{
    cout << left << setw(10) << "Pavarde " << setw(15) << "Vardas " << setw(15) << "Galutinis (Vid.) " << " " << " / Galutinis (Med.)" << endl;
    cout << "----------------------------------------------------" << endl;
    for (const auto& student : A){
    cout << left << setw(10) << student.vardas << setw(15) << student.pavarde << fixed << setprecision(2) << setw(15) << student.balas << setw(10) << student.mediana << endl;
    }
}
void spausdintiTeksto(const vector <studentas> & A)
{
    ofstream fr ("kursiokai.txt");
    fr << left << setw(20) << "Pavarde " << setw(25) << "Vardas " << setw(20) << "Galutinis (Vid.) " << "/ " << " Galutinis (Med.)" << endl;
    fr << "-------------------------------------------------------------------------------------" << endl;
    for (const auto& student : A){
     fr << left << setw(20) << student.vardas << setw(25) << student.pavarde << fixed << setprecision(2) << setw(25) << student.balas << setw(20) << student.mediana << endl;
    }
    fr.close();
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
    for (auto& student : A){
        int nd_count = rand() % (MAX_ND_SIZE + 1);
        for (int j = 0; j < nd_count; j++){
            student.nd.push_back(rand() % 11);
        }
        student.egz = rand() % 11;
    }
}
void generavimasStudentu(vector<studentas>& A, int n) {
   
    srand(time(0));

    string vardai[] = {"Rokas", "Mantas", "Pijus", "Laurynas", "Ignas", "Gabriele", "Ugne", "Kamile", "Rugile", "Roberta"};
    string pavardes[] = {"Gilys", "Globys", "Bogusis", "Dulskis", "Maliauka", "Skirmantaite", "Mockute", "Zobelaite", "Macaite", "Jurpalyte"};

    for (auto& student : A)
    {
       student.vardas = vardai[rand() % 10];
       student.pavarde = pavardes[rand() % 10];
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