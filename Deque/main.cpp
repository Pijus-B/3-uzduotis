#include "fun.cpp"

int main (){
    try {
        ifstream fd ("studentai10000.txt");
        if (!fd.is_open()){
            throw runtime_error ("Nepavyko atidaryti duomenu failo");
        }
        ofstream fr ("kursiokai.txt");
        if (!fr.is_open()){
            throw runtime_error ("Nepavyko atidaryti rezultatu failo");
        }
    
    deque <studentas> A;
    int n; int pasirinkimas;
    while (true){
        cout << "Pasirinkite norima veiksma: " << endl;
        cout << "1. Ivesti duomenis ranka" << endl;
        cout << "2. Nuskaityti duomenis is failo" << endl;
        cout << "3. Generuoti pazymius" << endl;
        cout << "4. Generuoti studentu vardus ir pavardes" << endl;
        cout << "5. Rusiuoti pagal pasirinktus parametrus" << endl;
        cout << "6. Generuoti failus, surusiuoti bei padalinti juos i atskirus failus" << endl;
        cout << "7. Baigti programa" << endl;
        cin >> pasirinkimas;

        switch (pasirinkimas){
            case 1:
            {
                skaitymas (A, n);
                skaiciavimas (A);
                spausdinti (A);
                break;
            }
            case 2:
            {
                A.clear();
                skaitymasTeksto (A);
                skaiciavimas (A);
                spausdintiTeksto (A);
                break;
            }
            case 3:
            {
                try {
                int n2;
                cout << "Iveskite zmoniu skaiciu" << endl;
                cin >> n2;
                if (cin.fail() || n2 <= 0){
                    cin.clear();
                    cin.ignore (numeric_limits<streamsize>::max(), '\n');
                    throw runtime_error("Neteisingas ivedimas. Iveskite is naujo");
                }
                A.clear();
                for (int i = 0; i < n2; i++)
            {
                studentas student;
                bool valid_names;
                do
                {
                    try {
                        cout << "Iveskite savo varda" << endl;
                        cin >> student.vardas;
                        cout << "Iveskite savo pavarde" << endl;
                        cin >> student.pavarde;
                         valid_names = isValidName(student.vardas) && isValidName(student.pavarde) && student.vardas.length() >= 2 && student.pavarde.length() >= 2;
                        if (!valid_names){
                            throw runtime_error ("Netinkami vardai su pavardemis. Bandykite is naujo");
                        }
                    }
                        catch (const exception& e){
                            cout << "Klaida: " << e.what() << endl;
                            cin.clear();
                            cin.ignore (numeric_limits <streamsize> :: max(), '\n');
                            valid_names = false;
                        }
                }
                while (!valid_names);
                 A.push_back(student);
            }
                generavimasPazymiuCase2(A);
                skaiciavimas (A);
                spausdinti (A);
                }
                catch (const exception& e){
                    cout << "Klaida: " << e.what() << endl;
                }
                break;
            }
            case 4:
            {
                int n3 = rand() % (MAX_STUDENTS + 1);
                A.clear();
                generavimasPazymiu (A, n3);
                generavimasStudentu (A, n3);
                skaiciavimas (A);
                spausdinti (A);
                break;
            }
            case 5:
            {
                cout << "Pasirinkite rusiavimo kriterijus: " << endl;
                cout << "1. Pagal varda" << endl;
                cout << "2. Pagal pavarde" << endl;
                cout << "3. Pagal galutini (vidurkis)" << endl;
                cout << "4. Pagal galutini (mediana)" << endl;
                int rusiavimas;
                cin >> rusiavimas;

                switch (rusiavimas) {
                    case 1:
                        sort(A.begin(), A.end(), pagalVarda);
                        break;
                    case 2:
                        sort(A.begin(), A.end(), pagalPavarde);
                        break;
                    case 3:
                        sort(A.begin(), A.end(), pagalVidurki);
                        break;
                    case 4:
                        sort(A.begin(), A.end(), pagalMediana);
                        break;
            }
            spausdintiTeksto(A);
            break;
                
            }
            case 6:
            {
                auto pradzia = chrono::steady_clock::now();
                //generavimasFailo(100);
                skaitymasTeksto(A);
                skaiciavimas(A);
                padalintiStudentus(A);
                auto pabaiga = chrono::steady_clock::now();
                double trukme = chrono::duration<double>(pabaiga - pradzia).count();
                cout << "Visos programos veikimo laikas: " << trukme << " sekundes" << endl;
                break;
            }
            case 7:
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
 }
    catch (const exception & e) {
        cout << e.what () << endl;
    }
    return 0;
}