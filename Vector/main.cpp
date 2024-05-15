#include "studentas.h"
#include "vector.h"
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
    
    vector <Studentas> A;
    int n; int pasirinkimas;
    while (true){
        cout << "Pasirinkite norima veiksma: " << endl;
        cout << "1. Ivesti duomenis ranka" << endl;
        cout << "2. Nuskaityti duomenis is failo" << endl;
        cout << "3. Generuoti pazymius" << endl;
        cout << "4. Generuoti studentu vardus ir pavardes" << endl;
        cout << "5. Rusiuoti pagal pasirinktus parametrus" << endl;
        cout << "6. Generuoti failus, surusiuoti bei padalinti juos i atskirus failus" << endl;
        cout << "7. Patikrinti Rule of Five" << endl;
        cout << "8. Patikrinti << ir >> " << endl;
        cout << "9. Patikrinti testavima naujos klases" << endl;
        cout << "10. Patikrinti spartos analize" << endl;
        cout << "11. Baigti programa" << endl;
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
                A.clear();
                try {
                int n2;
                cout << "Iveskite zmoniu skaiciu" << endl;
                cin >> n2;
                if (cin.fail() || n2 <= 0){
                    cin.clear();
                    cin.ignore (numeric_limits<streamsize>::max(), '\n');
                    throw runtime_error("Neteisingas ivedimas. Iveskite is naujo");
                }
                A.reserve(n2);
                
                for (int i = 0; i < n2; i++)
            {
                Studentas student;
                bool valid_names;
                do
                {
                    try {
                        cout << "Iveskite savo varda" << endl;
                        string vardas, pavarde;
                        cin >> vardas;
                        student.setVardas(vardas);
                        cout << "Iveskite savo pavarde" << endl;
                        cin >> pavarde;
                        student.setPavarde(pavarde);
                         valid_names = isValidName(student.getVardas()) && isValidName(student.getPavarde()) && student.getVardas().length() >= 2 && student.getPavarde().length() >= 2;
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
                test_constructor ();
                test_copy_constructor();
                test_move_constructor ();
                test_copy_assignment ();
                test_move_assignment ();
                break;
            }
            case 8:
            {
                test_input_operator ();
                test_output_operator();
                cout << "Visi testai praejo" << endl;
                break;
            }
            case 9:
            {
               cout << "1. Tikriname operatorius" << endl;
                {
                    Vector<int> pirmas (100);
                    Vector<int> antras (200);

                    if (pirmas==antras) cout << "pirmas ir antras yra lygus" << endl;
                    if (pirmas!=antras) cout << "pirmas ir antras nera lygus" << endl;
                    if (pirmas<antras) cout << "pirmas yra mazesnis uz antra" << endl;
                    if (pirmas>antras) cout << "pirmas yra didesnis uz antra" << endl;
                    if (pirmas<=antras) cout << "pirmas yra mazesnis arba lygus antram" << endl;
                    if (pirmas>=antras) cout << "pirmas yra didesnis arba lygus antram" << endl;

                }

                cout << "2. Tikriname resize()" << endl;
                {
                    Vector<int> vectorr;

                    // set some initial content:
                    for (int i=1; i < 10; i++) vectorr.push_back(i);

                    vectorr.resize(5);
                    vectorr.resize(8, 100);
                    vectorr.resize(12);

                    cout << "vectorr susideda is: ";
                    for (int i = 0; i < vectorr.size();i++)
                        cout << ' ' << vectorr[i];
                    cout << endl;

                }

                cout << "3. Tikriname erase()" << endl;
                {
                    Vector<int> vectorr;

                    for (int i = 1; i <= 10; i++) vectorr.push_back(i);

                    vectorr.erase (vectorr.begin() + 5);

                    vectorr.erase (vectorr.begin(), vectorr.begin() + 3);

                    cout << "vectorr susideda is:";
                    for (unsigned i=0; i<vectorr.size(); ++i)
                        cout << ' ' << vectorr[i];
                    cout << endl;

                    }

                cout << "4. Tikriname begin()" << endl;
                {
                    Vector<int> vectorr;
                    for (int i = 1; i <= 5; i++) vectorr.push_back(i);

                    cout << "vectorr susideda is:";
                    for (Vector<int>::iterator it = vectorr.begin() ; it != vectorr.end(); ++it)
                        cout << ' ' << *it;
                    cout << endl;

                }

                cout << "5. Tikriname shrink_to_fit()" << endl;
                {
                    Vector<int> vectorr (100);
                    cout << "1. vectorr talpa: " << vectorr.capacity() << endl;

                    vectorr.resize(10);
                    cout << "2. vectorr talpa: " << vectorr.capacity() << endl;

                    vectorr.shrink_to_fit();
                    cout << "3. vectorr talpa: " << vectorr.capacity() << endl;

                }

                cout << "6. Tikriname pop_back()" << endl;
                {
                    Vector<int> vectorr;
                    int sum (0);
                    vectorr.push_back (100);
                    vectorr.push_back (200);
                    vectorr.push_back (300);

                    while (!vectorr.empty())
                    {
                        sum += vectorr.back();
                        vectorr.pop_back();
                    }

                    cout << "vectorr elementu suma: " << sum << endl;

                }
                break;

            }
            case 10:
            {
               auto start_pildyti = chrono::steady_clock::now();
               unsigned int sz = 10000; //100000, 1000000, 10000000, 100000000
               std::vector <int> v1;
               int std_vector_perskirstymas = 0;
               for (int i = 1; i <= sz; ++i){
                v1.push_back(i);
                if (v1.capacity() == v1.size()){
                    ++std_vector_perskirstymas;
                }
               }
               auto end_pildyti = chrono::steady_clock::now();
               auto skirtumas_pildyti = chrono::duration<double>(end_pildyti - start_pildyti).count();
               //cout << "Tusciu vektoriu su std::vector uzpildymas su: " << sz << " eilutemis uzeme: " << fixed << setprecision(8)
              // << skirtumas_pildyti << "s" << endl;
               cout << "Atmintis buvo perskirstyta " << std_vector_perskirstymas << " kartu su std::vector" << endl;

               auto start_pildyti_vector = chrono::steady_clock::now();
               Vector <int> v2;
               int vector_perskirstymas = 0;
               for (int i = 1; i <= sz; ++i){
                v2.push_back(i);
                if (v2.capacity() == v2.size()){
                    ++vector_perskirstymas;
                }
               }
               auto end_pildyti_vector = chrono::steady_clock::now();
               auto skirtumas_pildyti_vector = chrono::duration<double>(end_pildyti_vector - start_pildyti_vector).count();
               //cout << "Tusciu vectoriu su Vector uzpildymas su " << sz << " eilutemis uzeme: " << fixed << setprecision(8) 
               // << skirtumas_pildyti_vector << "s" << endl;
               cout << "Atmintis buvo perskirstyta " << vector_perskirstymas << " kartu su Vector" << endl;
                break;

            }
            case 11:
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