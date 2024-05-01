# OOP
## V2.0
Pateiktas kodas yra C++ programa studentų informacijos valdymui. Ji apima funkcijas tokias kaip ivesti studentų duomenis, skaičiuoti vidurkius ir medianas bei rodyti rezultatus. Buvo sukurti `Unit Testai` naudodami C++ Unit testų framework'ą: `Google Test`. Šie testai tikrina svarbias programos funkcijas, konstruktorius, tokiu būdu užtikrinant, kad jos veikia kaip tikimasi. Testai galėjo būti įdiegti, jog padėtų identifikuoti ir ištaisyti potencialias klaidas.

## Programos paleisties proceso instrukcijos
## 1 žingsnis: Instaliuoti Chocolatey
Atsidaryti CMD kaip Administrator: Spustelti Win + X ir pasirinkti “Command Prompt (Admin)” or “Windows PowerShell (Admin)”.
Paleisti instaliavimo komandą: nusikopijuoti ta komandą ir paspausti Enter. Ši komanda yra pasiekiama per Chocolatey svetainę.
Nusikopijuoti kodą:
Set-ExecutionPolicy Bypass -Scope Process -Force; [System.Net.ServicePointManager]::SecurityProtocol = [System.Net.ServicePointManager]::SecurityProtocol -bor 3072; iex ((New-Object System.Net.WebClient). DownloadString('https://chocolatey.org/install.ps1')).
Patvirtinti instaliacija: irasyti choco i CMD ir paspausti Enter. Jeigu matote Chocolatey versijos informacija, tai jau yra instaliuota sekmingai.
## 2 žingsnis: Instaliuoti Make
Instaliuokite Make: CMD terminale (vis dar kaip Administrator), įrašykite šią komandą bei paspauskite Enter:
Nukopijuokite koda:
choco install make
Patvirtinkite Make instaliacija: įrašykite "make -v" i CMD. Jei po įrašymo rodo Make versijos informaciją, tai reiškia, kad sėkmingai instaliuota.
## 3 žingsnis: Kompiliuokite ir pradėkite savo C++ projektą
Nurodykite savo projekto direktyvą: naudokite cd komandą į CMD, jog pakeisti savo projekto direktyvą, kur yra instaliuotas Makefile.
Kompiliuokite savo projektą: Įrašykite make ir paspauskite Enter. Tada prades kompiliuoti jūsų C++ projektą pagal nurodytas Makefile instrukcijas.
Pradėkite savo projektą: Po kompiliavimo jūs turėtumete turėti vykdomąjį failą, dažniausiai vadinamą main arba kitu specifiškai pavadintu jūsų Makefile. Įrašykite main i CMD ir paspauskite Enter, kad pradėtumete savo programos veikimą.

## UnitTest testai
| Testavimo funkcija       | Aprasymas                                                                             |  Rezultatas     |
|--------------------------|---------------------------------------------------------------------------------------|-----------------|
|`test_constructor()`      |Patikrina konstruktorių su default parametrais                                         |Sėkmingai praėjo |
|`test_copy_constructor()` |Patikrina copy konstruktorių, ar tinkamai nukopijuoja objekta                          |Sėkmingai praėjo |   

![paveikslas](https://github.com/Pijus-B/2-uzduotis/assets/90143621/ac31a4e9-68f6-4843-87fa-cac34574e38c)



*/## Studentas klasės informacija
## Konstruktoriai
### Konstruktorius su Default parametrais
- Parametrai:
  -   `string vardas = ""`: Vardas (default empty)
  -   `string pavarde = ""`: Pavarde (default empty)
  -   `int nd = 0`: Namu darbu pazymiai (default 0)
  -   `int egz = 0`: Egzamino pazymys (default 0)
  -   `double balas = 0.0`: galutinio balo pazymys (default 0.0)
  -   `double vid = 0.0`: vidurkio pazymys (default 0.0)
  -   `double mediana = 0.0`: pazymiu mediana (default 0.0)
  ### Copy konstruktorius
  Inicializuoja naują objektą, kuris naudoja jau egzistuojantį `Studentas` objektą.
  - Parametras: `const Studentas& other`: objektą, kurio informacija yra nukopijuojama.
  ### Move konstruktorius
  Inicializuoja naują objektą, kuris pasiima informaciją/resursus iš kito objekto be papildomo kopijavimo.
  - Parametras: `Studentas&& other` objektą, kurio resursai/informacija yra perkeliami.
  ## Destruktorius
  Destruktoriaus pagrindinis tikslas yra atlaisvinti bet kokius resursus arba atlikti bet kokias valymo operacijas, susijusias su objektu.
  ## Assignment operatoriai
  ### Copy Assignment operatorius
  Kopijuoją informaciją iš objekto `const Studentas& other`. Jis veikia tokiu būdu, kad visas narių reikšmes iš kito objekto yra kopijuojamos į šio objekto narius, o tai leidžia turėti du identiškus objektus su atskirais adresas. Tai yra svarbu, kai reikia saugoti atskirą informaciją, kuri yra nepriklausoma nuo kito objekto.
  ### Move Assignment operatorius
  Perkelia resursus iš objekto `Studentas&& other` į kitą objektą, taikant perkėlimo semantiką. Tokiu būdu padeda išvengti papildomo kopijavimo ir taip pagerina našumą.
  ## Įvesties metodas (operator>>)
  Leidžia tiesiogiai nuskaityti iš įvesties srauto (kaip std::cin) į `Studentas` objektą.
- Parametrai:
    -  `std::istream& is`: įvesties srautas.
    -  `Studentas& student`: užildyti objektą su reikiama informacija.
  ## Išvesties metodas (operator<<)
  Leidžia tiesiogiai išvesti informaciją į išvesties srautą.
- Parametrai:
    -  `std::ostream& os`: išvesties srautas.
    -  `const Studentas& student`: užildyti objektą su reikiama informacija.

Šie įvesties/išvesties metodai yra efektyvūs, nes leidžia programuotojams lengvai ir efektyviai manipuliuoti objektų įvestimi ir išvestimi. Taip pat šie operatoriai yra lengvai suprantami, leidžia sumažinti pakartotinį kodą bei programavimo klaidos gali būti aptinkamos kompiliavimo metu.
## Zmogus abstrakčios klasės informacija
## Konstruktoriai
### Konstruktorius su Default parametrais
- Parametrai:
  -   `string vardas = ""`: Vardas (default empty)
  -   `string pavarde = ""`: Pavarde (default empty)
## Destruktorius
Destruktoriaus pagrindinis tikslas yra atlaisvinti bet kokius resursus arba atlikti bet kokias valymo operacijas, susijusias su objektu.

## Rule of Five patikrinimas
| Testavimo funkcija       | Aprasymas                                                                             |  Rezultatas     |
|--------------------------|---------------------------------------------------------------------------------------|-----------------|
|`test_constructor()`      |Patikrina konstruktorių su default parametrais                                         |Sėkmingai praėjo |
|`test_copy_constructor()` |Patikrina copy konstruktorių, ar tinkamai nukopijuoja objekta                          |Sėkmingai praėjo |   
|`test_move_constructor()` |Patikrina move konstruktorių, ar tinkamai perkelia objekta be papildomo kopijavimo     |Sėkmingai praėjo |   
|`test_copy_assignment()`  |Patikrina copy assignment, ar tinkamai nukopijuoja visus atributus                     |Sėkmingai praėjo |   
|`test_move_assignment()`  |Patikrina move assignment, ar tinkamai perkelia visus atributus be papildomo kopijavimo|Sėkmingai praėjo |   

Šie testai padeda mums patvirtinti svarbią klasės funkcionalumo dalį, įskaitant studentų įrašų konstravimą, kopijavimą ir perkėlimą.

![ruleoffive](https://github.com/Pijus-B/2-uzduotis/assets/90143621/2c89644f-52bb-4355-9688-918cc3e9dbff)


## Įvesties ir išvesties patikrinimas
| Testavimo funkcija       | Aprasymas                                                                             |  Rezultatas     |
|--------------------------|---------------------------------------------------------------------------------------|-----------------|
|`test_input_operator()`   |Patikrina įvesties konstruktorių, ar tinkamai yra nuskaitomas objektas                 |Sėkmingai praejo |
|`test_output_operator()`  |Patikrina išvesties konstruktorių, ar tinkamai yra išvedamas objektas                  |Sėkmingai praejo |

Šie testai patikrina svarbią klasės funkcionalumo dalį, įskaitant įvesties ir išvesties operatorių veikimą.

![inputoutputtestai](https://github.com/Pijus-B/2-uzduotis/assets/90143621/b927e409-0e97-4c25-967b-f321d0b5e92a)

/*





































