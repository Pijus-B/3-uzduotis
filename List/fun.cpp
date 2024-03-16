#pragma once
#include "fun.h"

void skaitymas (list <studentas> & A, int n)
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
void skaitymasTeksto (list <studentas> & A)
{
    ifstream fd ("studentai10000000.txt");
    string eil;
    getline(fd, eil);

    auto pradzia = chrono::steady_clock::now();

    while (getline(fd, eil)){
        stringstream ss(eil);
        studentas student;
        ss >> student.vardas >> student.pavarde;
        int paz;
        while (ss >> paz){
            student.nd.push_back(paz);
        }
        student.egz = student.nd.back();
        student.nd.pop_back();
        A.push_back(student);
    }
    auto pabaiga = chrono::steady_clock::now();
    double trukme = chrono::duration<double>(pabaiga - pradzia).count();
    cout << "Laikas, per kuri nuskaite teksta: " << trukme << " sekundes" << endl;
    fd.close();

}
void skaiciavimas (list <studentas> & A)
{ 
   for (auto& student : A)
    {
        student.nd.sort();
        int size = student.nd.size();
        if (size % 2 == 0)
        {
            int indeksas1 = size / 2 - 1;
            int indeksas2 = size / 2;
            auto it1 = next(student.nd.begin(), indeksas1);
            auto it2 = next (student.nd.begin(), indeksas2);
            student.mediana = (*it1 + *it2) / 2.0;
        }
        else
        {
            auto it = next(student.nd.begin(), size / 2);
            student.mediana = *it;
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
void padalintiStudentus(list <studentas> & A){
    auto pradzia_rusiavimas = chrono::steady_clock::now();
    list <studentas> vargsiukai;
   // list <studentas> kietiakiai;

    auto pradzia_dviGrupes = chrono::steady_clock::now();
    auto iter = A.begin();
    while (iter != A.end()){
        if (iter -> balas < 5.0){
            vargsiukai.push_back(*iter);
            iter = A.erase(iter);
        }
        else{
            iter++;
        }
    }
    /*for (auto &studentas : A) {
        if (studentas.balas < 5.0) {
            vargsiukai.push_back(studentas);      // 1 strategija
        } else {  
            kietiakiai.push_back(studentas);
        }
    }*/
    auto pabaiga_dviGrupes = chrono::steady_clock::now();
    double trukme_dviGrupes = chrono::duration<double>(pabaiga_dviGrupes - pradzia_dviGrupes).count();
    cout << "Studentu skirstymo i dvi grupes laikas: " << trukme_dviGrupes << " sekundes" << endl;
    cout << "Pasirinkite rusiavimo kriterijus: " << endl;
    cout << "1. Pagal varda " << endl;
    cout << "2. Pagal pavarde " << endl;
    cout << "3. Pagal galutini (vidurkis) " << endl;
    cout << "4. Pagal galutini (mediana) " << endl;
    int pasirinkti;
    cin >> pasirinkti;
    switch (pasirinkti){
        case 1:
            vargsiukai.sort(pagalVarda);
            //kietiakiai.sort(pagalVarda);
            break;
        case 2:
            vargsiukai.sort(pagalPavarde);
           // kietiakiai.sort(pagalPavarde);
            break;
        case 3:
            vargsiukai.sort(pagalVidurki);
            //kietiakiai.sort(pagalVidurki);
            break;
        case 4:
            vargsiukai.sort(pagalMediana);
            //kietiakiai.sort(pagalMediana);
            break;
            }
    
    auto pabaiga_rusiavimas = chrono::steady_clock::now();

    auto pradzia_isvedimas = chrono::steady_clock::now();
    ofstream vargsiukai_out ("vargsiukai.txt");
    //ofstream kietiakiai_out ("kietiakiai.txt");

      for (const auto &studentas : vargsiukai) {
        vargsiukai_out << studentas.vardas << " " << studentas.pavarde << " " << fixed << setprecision(2) << studentas.balas << endl;
    }

   // for (const auto &studentas : kietiakiai) {
     //   kietiakiai_out << studentas.vardas << " " << studentas.pavarde << " " << fixed << setprecision(2) << studentas.balas << endl;
   // }

    vargsiukai_out.close();
    //kietiakiai_out.close();
    auto pabaiga_isvedimas = chrono::steady_clock::now();

    double trukme_rusiavimas = chrono::duration<double>(pabaiga_rusiavimas - pradzia_rusiavimas).count();
    double trukme_isvedimas = chrono::duration<double>(pabaiga_isvedimas - pradzia_isvedimas).count();
    cout << "Studentu rusiavimo laikas: " << trukme_rusiavimas << " sekundes" << endl;
    cout << "Surusiuotu studentu isvedimas: " << trukme_isvedimas << " sekundes" << endl;
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
void spausdinti (const list <studentas> & A)
{
    cout << left << setw(10) << "Pavarde " << setw(15) << "Vardas " << setw(15) << "Galutinis (Vid.) " << " " << " / Galutinis (Med.)" << endl;
    cout << "----------------------------------------------------" << endl;
    for (const auto& student : A){
    cout << left << setw(10) << student.vardas << setw(15) << student.pavarde << fixed << setprecision(2) << setw(15) << student.balas << setw(10) << student.mediana << endl;
    }
}
void spausdintiTeksto(const list <studentas> & A)
{
    ofstream fr ("kursiokai.txt");
    fr << left << setw(20) << "Pavarde " << setw(25) << "Vardas " << setw(20) << "Galutinis (Vid.) " << "/ " << " Galutinis (Med.)" << endl;
    fr << "-------------------------------------------------------------------------------------" << endl;
    for (const auto& student : A){
     fr << left << setw(20) << student.vardas << setw(25) << student.pavarde << fixed << setprecision(2) << setw(25) << student.balas << setw(20) << student.mediana << endl;
    }
    fr.close();
}
void generavimasPazymiu(list <studentas>& A, int n2) {
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
void generavimasPazymiuCase2 (list <studentas> & A)
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
void generavimasStudentu(list <studentas>& A, int n) {
   
    srand(time(0));

    string vardai[] = {"Rokas", "Mantas", "Pijus", "Laurynas", "Ignas", "Gabriele", "Ugne", "Kamile", "Rugile", "Roberta"};
    string pavardes[] = {"Gilys", "Globys", "Bogusis", "Dulskis", "Maliauka", "Skirmantaite", "Mockute", "Zobelaite", "Macaite", "Jurpalyte"};

    for (auto& student : A)
    {
       student.vardas = vardai[rand() % 10];
       student.pavarde = pavardes[rand() % 10];
    }
}
void generavimasFailo (int kiekis)
{
    auto pradzia_generavimasFailo = chrono::steady_clock::now();
    stringstream fileNameStream;
    fileNameStream << "Studentai" << kiekis << ".txt";
    string filename = fileNameStream.str();
    ofstream fd (filename);

    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution <int> pazymiai (1,10);
    uniform_int_distribution <int> egzaminas (1,10);

    stringstream ss;
    ss << left << setw(20) << "Vardas" << setw(20) << "Pavarde";
    for (int i = 1; i <= 15; ++i) {
        ss << setw(8) << "ND" + to_string(i);
    }
    ss << setw(8) << "Egz." << endl;
    for (int i = 0; i < kiekis; i++) {
        ss << left << setw(20) << ("Vardas" + to_string(i + 1)) << setw(20) << ("Pavarde" + to_string(i + 1));
        for (int j = 0; j < 15; j++) {
            ss << setw(8) << pazymiai(mt);
        }
        ss << setw(8) << egzaminas(mt) << endl;
    }
    fd << ss.str();
    fd.close();
    auto pabaiga_generavimasFailo = chrono::steady_clock::now();
    double trukme_generavimasFailo = chrono::duration<double>(pabaiga_generavimasFailo - pradzia_generavimasFailo).count();
    cout << "Failu generavimo laikas: " << trukme_generavimasFailo << " sekundes" << endl;
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