# OOP
## V2.0
Pateiktas kodas yra C++ programa studentų informacijos valdymui. Ji apima funkcijas tokias kaip ivesti studentų duomenis, skaičiuoti vidurkius ir medianas bei rodyti rezultatus. Buvo sukurti `Unit Testai` naudodami C++ Unit testų framework'ą: `Google Test`. Šie testai tikrina svarbias programos funkcijas, konstruktorius, tokiu būdu užtikrinant, kad jos veikia kaip tikimasi. Testai galėjo būti įdiegti, jog padėtų identifikuoti ir ištaisyti potencialias klaidas.

# Dokumentacija su HTML formatu
Šis formatas leidžia varototui draugišką sąsają naršant per projekto kodą, jo svarbiausias funkcijas, klases ir kitus svarbius likusius kodo elementus.
## Dokumentacijos su HTML formatu pasiekimas
1. Nueikite į `docs/html` aplanką projekto repozitorijoje.
2. Atidarykite `index.html` failą pasirinktame interneto naršyklės lange.
3. Naršykite dokumentaciją naudodami navigacijos nuorodas ir paieškos funkciją.
# Dokumentacija su TeX formatu
Šis formatas leidžia vartotojui statinę, draugišką sąsają, kurie nori atsispausdinti bei išsaugoti dokumentaciją. Taip pat kontroliuoja teksto ir grafinių elementų išsidėstymą, tačiau nėra tokia interaktyvi kaip HTML formatu parengta dokumentacija.
## Dokumentacijos su TeX formatu pasiekimas
1. Naviguokite į `docs/latex` aplanką projekto repozitorijoje.
2. Atidarykite atitinkamus TeX failus naudodami LaTeX redaktorių, pvz., TeXShop, TeXworks arba Overleaf.
3. Sukompiliuokite TeX failus, kad būtų sugeneruota PDF dokumentacija.
# Programos paleisties proceso instrukcijos
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

# UnitTest testai
## UnitTest paleidimas
1. `Nusiklonuokite testų repozitoriją`: nusiklonuokite unit testų repozitoriją, jei ji yra atskiroje vietoje, arba įsitikinkite, kad testai yra jūsų projekto repozitorijoje.
2. `Įsitikinkite, kad turite visus reikalavimus`: įsitikinkite, kad visi reikalavimai, pavyzdžiui, naudojantis Visual Studio, reikalingos unit testams paleisti, yra įdiegtos jūsų sistemoje.
3. `Paleiskite unit testus`: naudojant norimą C++ unit testų framework'ą, pavyzdžiui kaip `Google Test`, paleiskite unit testus. Tai gali būti cmake, make arba tiesiog paleidžiant vykdomąjį failą.
4. `Analizuokite rezultatus`: atidžiai peržiūrėkite unit testų rezultatus, kad įsitikintumėte, jog jūsų kodas veikia teisingai ir atitinka numatytus reikalavimus.
5. `Taisymas ir kartotinis paleidimas`: jei vienas ar keli testai yra spausdinami su klaidomis, taisykite savo kodą ir paleiskite unit testus dar kartą, kad įsitikintumėte, jog viskas veikia teisingai.
6. `Testų kūrimas`: taip pat galite kurti savo testus ir atlikti iš naujo viršuj paminėtus žingsnius.
###
| Testavimo funkcija       | Aprasymas                                                                             |  Rezultatas     |
|--------------------------|---------------------------------------------------------------------------------------|-----------------|
|`test_constructor()`      |Patikrina konstruktorių su default parametrais                                         |Sėkmingai praėjo |
|`test_copy_constructor()` |Patikrina copy konstruktorių, ar tinkamai nukopijuoja objekta                          |Sėkmingai praėjo |
|`test_move_constructor()` |Patikrina move konstruktorių, ar tinkamai perkelia objekta be papildomo kopijavimo     |Sėkmingai praėjo |   
|`test_copy_assignment()`  |Patikrina copy assignment, ar tinkamai nukopijuoja visus atributus                     |Sėkmingai praėjo |   
|`test_move_assignment()`  |Patikrina move assignment, ar tinkamai perkelia visus atributus be papildomo kopijavimo|Sėkmingai praėjo |  

![paveikslas](https://github.com/Pijus-B/2-uzduotis/assets/90143621/7c323150-49a2-4535-b8a3-1f7c63d4a467)




































