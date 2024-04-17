#include "Studentas.h"
using namespace std;

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
bool pagalVarda(const Studentas & A, const Studentas & B) {
    return A.getVardas() < B.getVardas();
}
bool pagalPavarde(const Studentas & A, const Studentas & B) {
    return A.getPavarde() < B.getPavarde();
}
bool pagalVidurki(const Studentas & A, const Studentas & B) {
    return A.getBalas() < B.getBalas();
}
bool pagalMediana(const Studentas & A, const Studentas & B) {
    return A.getMediana() < B.getMediana();
}
void skaitymas (vector <Studentas> & A, int n)
{ 
    cin >> n;
      for (int i = 0; i < n; i++)
    {
         Studentas student;
        string vardas, pavarde;
        cin >> vardas;
        cout << "Iveskite savo pavarde " << endl;
        cin >> pavarde;
        if (!isValidName(vardas) || !isValidName(pavarde))
        {
            cout << "Netinkami vardai. Bandykite is naujo." << endl;
            i--;
            continue;
        }
        student.setVardas(vardas);
        student.setPavarde(pavarde);
        cout << "Iveskite egzamino rezultatus " << endl;
        int egz;
        cin >> egz;
        student.setEgz(egz);
        cout << "Iveskite namu darbu tarpinius rezultatus (baigti ivesdami -1)" << endl;
        int nd;
        vector <int> nds;
        while (cin >> nd && nd != -1)
        {
            nds.push_back(nd);
        }
        student.setNd(nds);
        A.push_back(student);
    }
}
void skaitymasTeksto (vector <Studentas> & A)
{
    cout << "Pasirinkite norima faila: " << endl;
    cout << "1. studentai1000.txt" << endl;
    cout << "2. studentai10000.txt" << endl;
    cout << "3. studentai100000.txt" << endl;
    cout << "4. studentai1000000.txt" << endl;
    cout << "5. studentai10000000.txt" << endl;
    int pasirinkimas;
    cin >> pasirinkimas;
    string failas;
    switch (pasirinkimas) {
        case 1:
            failas = "studentai1000.txt";
            break;
        case 2:
            failas = "studentai10000.txt";
            break;
        case 3:
            failas = "studentai100000.txt";
            break;
        case 4:
            failas = "studentai1000000.txt";
            break;
        case 5:
            failas = "studentai10000000.txt";
            break;
        default:
            cout << "Neteisingas pasirinkimas" << endl;
            return;
    }

    ifstream fd(failas);
    if (!fd.is_open()){
        throw runtime_error ("Nepavyko atidaryti duomenu failo");
    }

    string eil;
    getline(fd, eil);

    auto pradzia = chrono::steady_clock::now();

    while (getline(fd, eil)){
        stringstream ss(eil);
        Studentas student;
        string vardas, pavarde;
        ss >> vardas >> pavarde;
        student.setVardas(vardas);
        student.setPavarde(pavarde);
        int paz;
        vector <int> nds;
        while (ss >> paz){
            nds.push_back(paz);
        }
        student.setNd(nds);
        student.setEgz(student.getNd().back());
        student.getNd().pop_back();
        A.push_back(student);
    }
    auto pabaiga = chrono::steady_clock::now();
    double trukme = chrono::duration<double>(pabaiga - pradzia).count();
    cout << "Laikas, per kuri nuskaite teksta: " << trukme << " sekundes" << endl;
    fd.close();

}
void skaiciavimas (vector <Studentas>& A)
{ 
   for (auto& student : A)
    {
        sort(student.getNd().begin(), student.getNd().end());
        int size = student.getNd().size();
        if (size % 2 == 0)
        {
           student.setMediana((student.getNd()[size / 2 - 1] + student.getNd()[size / 2]) / 2.0);
        }
        else
        {
            student.setMediana(student.getNd()[size / 2]);
        }
        double sum = accumulate(student.getNd().begin(), student.getNd().end(), 0.0);
        if (size > 0)
        {
            student.setVid(sum / size);
            student.setBalas(0.4 * student.getVid() + 0.6 * student.getEgz());
        }
        else
        {
            student.setVid(student.getEgz());
            student.setBalas(student.getVid());
            student.setMediana(student.getVid());
        }
    }
}
void padalintiStudentus(vector <Studentas> & A){
    vector<Studentas> vargsiukai;
    vector<Studentas> kietiakiai;
    cout << "Pasirinkite norima strategija: " << endl;
    cout << "1 strategija " << endl;
    cout << "2 strategija " << endl;
    cout << "3 strategija " << endl;
    int strategija;
    cin >> strategija;
    auto pradzia_dviGrupes = chrono::steady_clock::now();
    switch (strategija){
        case 1:{
            for (auto &student : A) {
        if (student.getBalas() < 5.0) {
            vargsiukai.push_back(student);    // 1 strategija
        } else {
            kietiakiai.push_back(student);
        }
    }
            break;
        }
        case 2:
        {
           auto iter = A.begin();
            while (iter != A.end()){
        if (iter -> getBalas() < 5.0){
            vargsiukai.push_back(*iter);     // 2 strategija
            iter = A.erase(iter);
        }
        else {
            iter++;
             }
             }
            break;
    }
        case 3:{
            remove_copy_if(A.begin(), A.end(), back_inserter(vargsiukai), [] (const Studentas & s){
                return s.getBalas() >= 5.0;
            });
            A.erase(remove_if(A.begin(), A.end(), [](const Studentas& s){        // 3 strategija su std::remove_if ir std::remove_if_copy
                return s.getBalas() < 5.0;
            }), A.end());
            break;
             }
            default:
            cout <<"Pasirinkta neteisinga strategija" << endl;
            return;
    }
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
     auto pradzia_rusiavimas = chrono::steady_clock::now();
    switch (pasirinkti){
        case 1:
            sort(vargsiukai.begin(), vargsiukai.end(), pagalVarda);
            sort(kietiakiai.begin(), kietiakiai.end(), pagalVarda);
            break;
        case 2:
            sort(vargsiukai.begin(), vargsiukai.end(), pagalPavarde);
            sort(kietiakiai.begin(), kietiakiai.end(), pagalPavarde);
            break;
        case 3:
            sort(vargsiukai.begin(), vargsiukai.end(), pagalVidurki);
            sort(kietiakiai.begin(), kietiakiai.end(), pagalVidurki);
            break;
        case 4:
            sort(vargsiukai.begin(), vargsiukai.end(), pagalMediana);
            sort(kietiakiai.begin(), kietiakiai.end(), pagalMediana);
            break;
        default:
            cout << "Pasirinktias netinkamas rusiavimo kriterijus" << endl;
            return;
            }
    
    auto pabaiga_rusiavimas = chrono::steady_clock::now();

    auto pradzia_isvedimas = chrono::steady_clock::now();
    ofstream vargsiukai_out ("vargsiukai.txt");
    ofstream kietiakiai_out ("kietiakiai.txt");

      for (const auto &Studentas : vargsiukai) {
        vargsiukai_out << Studentas.getVardas() << " " << Studentas.getPavarde() << " " << fixed << setprecision(2) << Studentas.getBalas() << endl;
    }

    for (const auto &Studentas : kietiakiai) {
       kietiakiai_out << Studentas.getVardas() << " " << Studentas.getPavarde() << " " << fixed << setprecision(2) << Studentas.getBalas() << endl;
   }

    vargsiukai_out.close();
    kietiakiai_out.close();

    auto pabaiga_isvedimas = chrono::steady_clock::now();

    double trukme_rusiavimas = chrono::duration<double>(pabaiga_rusiavimas - pradzia_rusiavimas).count();
    double trukme_isvedimas = chrono::duration<double>(pabaiga_isvedimas - pradzia_isvedimas).count();
    cout << "Studentu rusiavimo laikas: " << trukme_rusiavimas << " sekundes" << endl;
    cout << "Surusiuotu studentu isvedimas: " << trukme_isvedimas << " sekundes" << endl;
}
void spausdinti (const vector <Studentas>& A)
{
    cout << left << setw(10) << "Pavarde " << setw(15) << "Vardas " << setw(15) << "Galutinis (Vid.) " << " " << " / Galutinis (Med.)" << endl;
    cout << "----------------------------------------------------" << endl;
    for (const auto& student : A){
    cout << left << setw(10) << student.getVardas() << setw(15) << student.getPavarde() << fixed << setprecision(2) << setw(15) << student.getBalas() << setw(10) << student.getMediana() << endl;
    }
}
void spausdintiTeksto(const vector <Studentas>& A)
{
    ofstream fr ("kursiokai.txt");
    fr << left << setw(20) << "Pavarde " << setw(25) << "Vardas " << setw(20) << "Galutinis (Vid.) " << "/ " << " Galutinis (Med.)" << endl;
    fr << "-------------------------------------------------------------------------------------" << endl;
    for (const auto& student : A){
     fr << left << setw(20) << student.getVardas() << setw(25) << student.getPavarde() << fixed << setprecision(2) << setw(25) << student.getBalas() << setw(20) << student.getMediana() << endl;
    }
    fr.close();
}
void generavimasPazymiu(vector<Studentas>& A, int n2) {
    srand(time(0));
    A.clear();
    for (int i = 0; i < n2; i++)
    {
        Studentas student;
        int nd_count = rand() % (MAX_ND_SIZE + 1);
        vector<int> nds;
        for (int j = 0; j < nd_count; j++)
        {
            nds.push_back(rand() % 11);
        }
        student.setNd(nds);
        student.setEgz(rand() % 11);
        A.push_back(student);
    }
}
void generavimasPazymiuCase2 (vector <Studentas> & A)
{
    srand(time(0));
    for (auto& student : A){
        vector<int> nds;
        int nd_count = rand() % (MAX_ND_SIZE + 1);
        for (int j = 0; j < nd_count; j++){
            nds.push_back(rand() % 11);
        }
        student.setNd(nds);
        student.setEgz(rand() % 11);
    }
}
void generavimasStudentu(vector<Studentas>& A, int n) {
   
    srand(time(0));

    string vardai[] = {"Rokas", "Mantas", "Pijus", "Laurynas", "Ignas", "Gabriele", "Ugne", "Kamile", "Rugile", "Roberta"};
    string pavardes[] = {"Gilys", "Globys", "Bogusis", "Dulskis", "Maliauka", "Skirmantaite", "Mockute", "Zobelaite", "Macaite", "Jurpalyte"};

    for (auto& student : A)
    {
       student.setVardas(vardai[rand()% 10]);
       student.setPavarde(pavardes[rand() % 10]);
    }
}
void generavimasFailo (int kiekis)
{
    auto pradzia_generavimasFailo = chrono::steady_clock::now();
    stringstream failasStream;
    failasStream << "Studentai" << kiekis << ".txt";
    string failas = failasStream.str();
    ofstream fd (failas);

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
void test_constructor ()
{
    vector <int> nd = {95};
    Studentas student ("Tomas", "Tedis", nd, 88.0, 90.5, 92.0, 91.5);
    assert (student.getVardas() == "Tomas");
    assert (student.getPavarde() == "Tedis");
    assert (student.getNd() == nd);
    assert (student.getEgz() == 88);
    assert (student.getBalas() == 90.5);
    assert (student.getVid() == 92.0);
    assert (student.getMediana() == 91.5);
    cout << "Constructor sekmingai praejo" << endl;
}
void test_copy_constructor ()
{
    vector <int> nd = {90};
    Studentas originalas ("Egle", "Lape", nd, 92, 91.0, 91.5, 90.5);
    Studentas copy = originalas;
    assert (copy.getVardas() == "Egle");
    assert (copy.getPavarde() == "Lape");
    assert (copy.getNd() == nd);
    assert (copy.getEgz() == 92);
    assert (copy.getBalas() == 91.5);
    assert (copy.getVid() == 91.0);
    assert (copy.getMediana() == 90.5);
    cout << "Copy constructor testas sekmingai praejo" << endl;
}
void test_move_constructor ()
{
    vector <int> nd = {89};
    Studentas originalas ("Akvile", "Aleksa", nd, 87, 88.0, 88.5, 87.5);
    Studentas moved = move (originalas);
    assert (moved.getVardas() == "Akvile");
    assert (moved.getPavarde() == "Aleksa");
    cout << "Move constructor sekmingai praejo" << endl;
}
void test_copy_assignment ()
{
    vector <int> nd = {85};
    Studentas originalas ("Bobas", "Jonaitis", nd, 84, 84.0, 85.5, 85.0);
    Studentas copy;
    copy = originalas;
    assert (copy.getVardas() == "Bobas");
    assert (copy.getPavarde() == "Jonaitis");
    assert (copy.getNd() == nd);
    assert (copy.getEgz() == 84);
    assert (copy.getBalas() == 85.5);
    assert (copy.getVid() == 84.0);
    assert (copy.getMediana() == 85.0);
    cout << "Copy assignment sekmingai praejo" << endl;
}
void test_move_assignment ()
{
    vector <int> nd = {82};
    Studentas originalas ("Marius", "Lelesius", nd, 80, 80.0, 82.5, 81.5);
    Studentas moved;
    moved = move (originalas);
    assert (moved.getVardas() == "");
    assert (moved.getPavarde() == "");
    cout << "Move assignment sekmingai praejo" << endl;
    
}
void test_input_operator ()
{
   cout << "Enter student's name, surname, exam score, and homework scores (enter -1 to stop):" << endl;
    Studentas student;
    cin >> student;
    cout << "Student details:" << endl;
    cout << student;
}
void test_output_operator() 
{
    Studentas student("John", "Doe", {90, 95, 80}, 85, 87.5, 86.5, 87);
    cout << "Student details:" << endl;
    cout << student;
}