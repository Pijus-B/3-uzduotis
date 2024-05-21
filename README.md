# OOP
## V3.0
Pateiktas kodas yra C++ programa studentų informacijos valdymui. Ji apima funkcijas tokias kaip ivesti studentų duomenis, skaičiuoti vidurkius ir medianas bei rodyti rezultatus. Ši klasė buvo sukurta kaip alternatyva `std::vector` konteineriui, kuri suteikia pilnavertį funkcionalumą. Taip pat leidžia saugoti ir tvarkyti duomenis dinamiškai, neprisirišant prie fiksuoto dydžio.


# Pasirinktų funkcijų ištirimas
Šis ištirimas yra skritas tam, kad pasitikrinti, ar sukurtos funkcijos veikia taip, kaip ir su konteineriu `std::vector`. Norint tą atlikti, pirmiausia reikėjo apsilankyti skirtoje dėstytojo svetainėje apie `std::vector`: https://en.cppreference.com/w/cpp/container/vector Apsilankius šioje svetainėje, galime pastebėti, kad yra nemažai pavyzdžių su funkcijomis. Dėl šios priežasties aš sukūriau panašias funkcijas, naudodamas savo `Vector` konteinerį bei lyginau rezultatus iš anksčiau minėtos svetainės.
## Operatoriai
![paveikslas](https://github.com/Pijus-B/3-uzduotis/assets/90143621/aa64ca1d-6db6-47c8-b5f8-723df8166568)

**Norimas rezultatas:**
```
pirmas ir antras nera lygus
pirmas yra mazesnis uz antra
pirmas yra mazesnis arba lygus antram
```
**Gautas rezultatas:**
```
pirmas ir antras nera lygus
pirmas yra mazesnis uz antra
pirmas yra mazesnis arba lygus antram
```
## Resize()
![resize](https://github.com/Pijus-B/3-uzduotis/assets/90143621/70146f94-54d1-47c3-85c4-2426290e95dc)

**Norimas rezultatas:**
```
vectorr susideda is: 1 2 3 4 5 100 100 0 0 0 0
```
**Gautas rezultatas:**
```
vectorr susideda is: 1 2 3 4 5 100 100 0 0 0 0
```

## Erase()
![paveikslas](https://github.com/Pijus-B/3-uzduotis/assets/90143621/49443bf0-805e-4404-983d-59cddc15ce7f)

**Norimas rezultatas:**
```
vectorr susideda is: 4 5 7 8 9 10
```
**Gautas rezultatas:**
```
vectorr susideda is: 4 5 7 8 9 10
```
## Begin()
![paveikslas](https://github.com/Pijus-B/3-uzduotis/assets/90143621/f7a679de-b883-4289-80ed-e09ae669a08a)

**Norimas rezultatas:**
```
vectorr susideda is: 1 2 3 4 5
```
**Gautas rezultatas:**
```
vectorr susideda is: 1 2 3 4 5
```
## Shrink_to_fit()
![paveikslas](https://github.com/Pijus-B/3-uzduotis/assets/90143621/5912e20f-958a-41c3-83d4-22d157270df0)

**Norimas rezultatas:**
```
1. vectorr talpa: 100
2. vectorr talpa: 100
3. vector talpa: 10
```
**Gautas rezultatas:**
```
1. vectorr talpa: 100
2. vectorr talpa: 100
3. vectorr talpa: 10
```
## Pop_back()
![paveikslas](https://github.com/Pijus-B/3-uzduotis/assets/90143621/47ca728a-19b3-4407-9e48-787622430a7f)

**Norimas rezultatas:**
```
vectorr elementu suma: 600
```
**Gautas rezultatas:**
```
vectorr elementu suma: 600
```

# Vector ir std::vector efektyvumo/spartos analizė
| Konteineriai| Elementų kiekis | Rezultatas  |            
|-------------|-----------------|-------------|
|`Vector`     | 10000           |0.00005950s  |
|             | 100000          | 0.00035170s |
|             | 1000000         | 0.00257710s |
|             | 10000000        | 0.03596280s |
|             | 100000000       |0.34461070s  |
|`std::vector`| 10000           |0.00008360s  |
|             | 100000          |0.00053260s  |
|             | 1000000         |0.00302100s  |
|             | 10000000        |0.04083550s  |
|             | 100000000       | 0.40393940s |

Galime pastebėti, kad `Vector` prisipildo elementais greičiau nei `std::vector` konteineris. Žiūrint bendrai, vidutiniškai `Vector` užtrunka apie 0,07671236 s., o konteineriui `std::vector` užtrunka apie 0,0906411s. prisipildyti elementams.

# Konteinerių `Vector` ir `std::vector` atminties perskirstymai užpildant 100000000
![paveikslas](https://github.com/Pijus-B/3-uzduotis/assets/90143621/3b777974-45f4-4f8c-9a4b-26ab866feda9)

Galime pastebėti, kai pildėme šiuos konteinerius 100000000 elementais, abudu konteineriai lygiai persiskyrė atmintį po 27 kartus.

# Konteinerių `Vector` ir `std::vector` greičio analizė
## studentai100000.txt
| Konteineris |         Darbas                            | Laikas         |
|-------------|-------------------------------------------|----------------|
|`Vector`     |Laikas, per kuri nuskaite teksta           | 0.393119 s.    |
|             |Studentu skirstymo i dvi grupes laikas     | 0.037085 s.    |
|             |Studentu rusiavimo didejimo tvarka laikas  | 0.0665835 s.   |
|`std::vector`|Laikas, per kuri nuskaite teksta           | 0.0380181 s.   |
|             |Studentu skirstymo i dvi grupes laikas     | 0.0047277 s.   |
|             |Studentu rusiavimo didejimo tvarka laikas  | 0.593777 s.    |

## studentai1000000.txt
| Konteineris |         Darbas                            | Laikas         |
|-------------|-------------------------------------------|----------------|
| `Vector`    |Laikas, per kuri nuskaite teksta           | 3.84207 s.     |
|             |Studentu skirstymo i dvi grupes laikas     | 0.332921 s.    |
|             |Studentu rusiavimo didejimo tvarka laikas  | 0.858762 s.    |
|`std::vector`|Laikas, per kuri nuskaite teksta           | 3.53866 s.     |
|             |Studentu skirstymo i dvi grupes laikas     | 0.385234 s.    |
|             |Studentu rusiavimo didejimo tvarka laikas  | 2.55797 s.     |

## studentai10000000.txt
| Konteineris |         Darbas                            | Laikas         |
|-------------|-------------------------------------------|----------------|
|`Vector`     |Laikas, per kuri nuskaite teksta           | 42.7185 s.     |
|             |Studentu skirstymo i dvi grupes laikas     | 3.27601 s.     |
|             |Studentu rusiavimo didejimo tvarka laikas  | 10.5459 s.     |
|`std::vector`|Laikas, per kuri nuskaite teksta           | 35.7867 s.     |
|             |Studentu skirstymo i dvi grupes laikas     | 3.02888 s.     |
|             |Studentu rusiavimo didejimo tvarka laikas  | 22.6922 s.     |

# Setup File naudojimosi instrukcija
## 1. Atsisiųsti diegimo failą
- Atsisiųskite diegimo vykdomąjį failą `V3.0 Setup.exe` iš pateiktos nuorodos.
## 2. Paleisti diegimo failą
- Dukart spustelėkite atsisiųstą `V3.0 Setup.exe` failą, kad pradėtumėte diegimo procesą.
## 3. Vadovautis programos nurodytomis instrukcijomis
- Sekite ekrane pateiktas diegimo vedlio instrukcijas;
- Pasirinkite diegimo katalogą ir kitas papildomas funkcijas, jei reikia.
## 4. Užbaigti diegimą
- Kai diegimas bus baigtas, spustelėkite "Finish" (Baigti), kad užbaigtumėte diegimą.
































