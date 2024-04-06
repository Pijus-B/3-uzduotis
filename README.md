# OOP
## V1.1
Pateiktas kodas yra C++ programa studentu informacijos valdymui. Ji apima funkcijas tokias kaip ivesti studentų duomenis, skaiciuoti vidurkius ir medianas bei rodyti rezultatus. Zemiau pateikiamas pagrindiniu komponentu ir funkciju aprasymas:

## Greiciausios dalijimo strategijos analize
## structure
| Konteineris | Strategija| Kiekis |Skaitymo laikas| Skirstymo i dvi grupes laikas  | Visos programos veikimo laikas|
|-------------|-----------|--------|---------------|--------------------------------|-------------------------------|
| Vector      | 3         |  100000| 0.347613 s.   |  0.0255194 s.                  | 4.14924 s.                   |
| Vector      | 3         | 1000000| 3.43581 s.    | 0.212184 s.                    | 9.65609 s.                    |

## class
| Konteineris | Strategija| Kiekis |Skaitymo laikas| Skirstymo i dvi grupes laikas  | Visos programos veikimo laikas|
|-------------|-----------|--------|---------------|--------------------------------|-------------------------------|
| Vector      | 3         |  100000| 0.0377109 s   |   0.0326658 s.                 | 3.34398 s.                    |
| Vector      | 3         | 1000000| 3.76804 s.    | 0.261562 s.                    | 9.79389 s.                    |

## Eksperimentine flags analize
## studentai100000.txt
| Flag        |         Darbas                            | Laikas         | EXE failo dydis|
|-------------|-------------------------------------------|----------------|----------------|
| O3          |Laikas, per kuri nuskaite teksta           | 0.0377109 s.   |0.6 MB          |
|             |Studentu skirstymo i dvi grupes laikas     | 0.0326658 s.   |                |
|             |Studentu rusiavimo didejimo tvarka laikas  | 0.0299215 s.   |                |
|             |Visos programos veikimo laikas             | 3.34398 s.     |                |
| O2          |Laikas, per kuri nuskaite teksta           | 0.39066 s.     |0.6 MB          |
|             |Studentu skirstymo i dvi grupes laikas     | 0.0335157 s.   |                |
|             |Studentu rusiavimo didejimo tvarka laikas  | 0.031161s.     |                |
|             |Visos programos veikimo laikas             | 4.07467 s.     |                |
| O1          |Laikas, per kuri nuskaite teksta           | 0.384744 s.    |0.6 MB          |
|             |Studentu skirstymo i dvi grupes laikas     | 0.0271367 s.   |                |
|             |Studentu rusiavimo didejimo tvarka laikas  | 0.0319533 s.   |                |
|             |Visos programos veikimo laikas             | 3.08285 s.     |                |

## studentai1000000.txt
| Flag        |         Darbas                            | Laikas         | EXE failo dydis|
|-------------|-------------------------------------------|----------------|----------------|
| O3          |Laikas, per kuri nuskaite teksta           | 3.76804 s.     |0.6 MB          |
|             |Studentu skirstymo i dvi grupes laikas     | 0.261562 s.    |                |
|             |Studentu rusiavimo didejimo tvarka laikas  | 0.375548 s.    |                |
|             |Visos programos veikimo laikas             | 9.79389 s.     |                |
| O2          |Laikas, per kuri nuskaite teksta           | 3.86501 s.     |0.6 MB          |
|             |Studentu skirstymo i dvi grupes laikas     | 0.284823 s.    |                |
|             |Studentu rusiavimo didejimo tvarka laikas  | 0.383344 s.    |                |
|             |Visos programos veikimo laikas             | 10.417 s.      |                |
| O1          |Laikas, per kuri nuskaite teksta           | 3.69437 s.     |0.6 MB          |
|             |Studentu skirstymo i dvi grupes laikas     | 0.253949 s.    |                |
|             |Studentu rusiavimo didejimo tvarka laikas  | 0.391814 s.    |                |
|             |Visos programos veikimo laikas             | 8.84713 s.     |                |

































