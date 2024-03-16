# OOP
## V1.0
Pateiktas kodas yra C++ programa studentu informacijos valdymui. Ji apima funkcijas tokias kaip ivesti studentų duomenis, skaiciuoti vidurkius ir medianas bei rodyti rezultatus. Zemiau pateikiamas pagrindiniu komponentu ir funkciju aprasymas:

## Testavimo sistemos parametrai
- SSD 500GB
- RAM 16GB
- CPU Intel i7-9750H

## Konteineriu testavimas

## studentai1000.txt
| Konteineris |         Darbas                            | Laikas         |
|-------------|-------------------------------------------|----------------|
| Vector      |Laikas, per kuri nuskaite teksta           | 0.0380181 s.   |
|             |Studentu skirstymo i dvi grupes laikas     | 0.0047277 s.   |
|             |Studentu rusiavimo didejimo tvarka laikas  | 0.593777 s.    |
| List        |Laikas, per kuri nuskaite teksta           | 0.0694568 s.   |
|             |Studentu skirstymo i dvi grupes laikas     | 0.0216233 s.   |
|             |Studentu rusiavimo didejimo tvarka laikas  | 0.590052 s.    |
| Deque       |Laikas, per kuri nuskaite teksta           | 0.0400197 s.   |
|             |Studentu skirstymo i dvi grupes laikas     | 0.0079072 s.   |
|             |Studentu rusiavimo didejimo tvarka laikas  | 0.775484 s.    |

## studentai10000.txt
| Konteineris |         Darbas                            | Laikas         |
|-------------|-------------------------------------------|----------------|
| Vector      |Laikas, per kuri nuskaite teksta           | 0.0434191 s.   |
|             |Studentu skirstymo i dvi grupes laikas     | 0.0052806 s.   |
|             |Studentu rusiavimo didejimo tvarka laikas  | 0.550203 s.    |
| List        |Laikas, per kuri nuskaite teksta           | 0.0635072 s.   |
|             |Studentu skirstymo i dvi grupes laikas     | 0.0186788 s.   |
|             |Studentu rusiavimo didejimo tvarka laikas  | 0.5777 s.      |
| Deque       |Laikas, per kuri nuskaite teksta           | 0.0407751 s.   |
|             |Studentu skirstymo i dvi grupes laikas     | 0.0089798 s.   |
|             |Studentu rusiavimo didejimo tvarka laikas  | 0.872097 s.    |

## studentai100000.txt
| Konteineris |         Darbas                            | Laikas         |
|-------------|-------------------------------------------|----------------|
| Vector      |Laikas, per kuri nuskaite teksta           | 0.355937 s.    |
|             |Studentu skirstymo i dvi grupes laikas     | 0.0284657 s.   |
|             |Studentu rusiavimo didejimo tvarka laikas  | 0.778239 s.    |
| List        |Laikas, per kuri nuskaite teksta           | 0.59668 s.     |
|             |Studentu skirstymo i dvi grupes laikas     | 0.186695 s.    |
|             |Studentu rusiavimo didejimo tvarka laikas  | 0.923687 s.    |
| Deque       |Laikas, per kuri nuskaite teksta           | 0.348641 s.    |
|             |Studentu skirstymo i dvi grupes laikas     | 0.0731703 s.   |
|             |Studentu rusiavimo didejimo tvarka laikas  | 1.17451 s.     |

## studentai1000000.txt
| Konteineris |         Darbas                            | Laikas         |
|-------------|-------------------------------------------|----------------|
| Vector      |Laikas, per kuri nuskaite teksta           | 3.53866 s.     |
|             |Studentu skirstymo i dvi grupes laikas     | 0.385234 s.    |
|             |Studentu rusiavimo didejimo tvarka laikas  | 2.55797 s.     |
| List        |Laikas, per kuri nuskaite teksta           | 5.86028 s.     |
|             |Studentu skirstymo i dvi grupes laikas     | 1.90549 s.     |
|             |Studentu rusiavimo didejimo tvarka laikas  | 3.37798 s.     |
| Deque       |Laikas, per kuri nuskaite teksta           | 3.563 s.       |
|             |Studentu skirstymo i dvi grupes laikas     | 0.778904 s.    |
|             |Studentu rusiavimo didejimo tvarka laikas  | 5.4972 s.      |

## studentai10000000.txt
| Konteineris |         Darbas                            | Laikas         |
|-------------|-------------------------------------------|----------------|
| Vector      |Laikas, per kuri nuskaite teksta           | 35.7867 s.     |
|             |Studentu skirstymo i dvi grupes laikas     | 3.02888 s.     |
|             |Studentu rusiavimo didejimo tvarka laikas  | 22.6922 s.     |
| List        |Laikas, per kuri nuskaite teksta           | 59.1278 s.     |
|             |Studentu skirstymo i dvi grupes laikas     | 48.1863 s.     |
|             |Studentu rusiavimo didejimo tvarka laikas  | 64.8412 s.     |
| Deque       |Laikas, per kuri nuskaite teksta           | 35.2317 s.     |
|             |Studentu skirstymo i dvi grupes laikas     | 21.4108 s.     |
|             |Studentu rusiavimo didejimo tvarka laikas  | 79.5062 s.     |

## 1 strategija
### Vector konteinerio atminties analize
### studentai1000.txt
![memory1000](https://github.com/Pijus-B/OOP/assets/90143621/1afe5987-500c-4afa-a3bd-02f7b6f82831)
### studentai10000.txt
![memory10000](https://github.com/Pijus-B/OOP/assets/90143621/0a2e49e9-a333-4dc5-ba8c-23064a5079fc)
### studentai100000.txt
![memory100000](https://github.com/Pijus-B/OOP/assets/90143621/3b2587fa-0706-465b-989d-788206946190)
### studentai1000000.txt
![memory1000000](https://github.com/Pijus-B/OOP/assets/90143621/3c97be37-7255-48c0-97bf-837b10d21643)
### studentai10000000.txt
![memory10000000](https://github.com/Pijus-B/OOP/assets/90143621/fd594773-1cf7-4031-8e9b-4285b7f94bd0)

### List konteinerio atminties analize
### studentai1000.txt
![memory1000](https://github.com/Pijus-B/OOP/assets/90143621/797663d2-ac9c-4a8f-860a-980ff9a3a36b)
### studentai10000.txt
![memory10000](https://github.com/Pijus-B/OOP/assets/90143621/917323f4-9f7d-46e8-829c-747c80e4716a)
### studentai100000.txt
![memory100000](https://github.com/Pijus-B/OOP/assets/90143621/80f7c593-a3c0-495b-aaee-fef1117f1add)
### studentai1000000.txt
![memory1000000](https://github.com/Pijus-B/OOP/assets/90143621/dd6ad231-f550-4377-a0fb-3ac3cd65e88e)
### studentai10000000.txt
![memory10000000](https://github.com/Pijus-B/OOP/assets/90143621/1d67f44a-7829-4f04-8ad0-4884890e0cbf)

### Deque konteinerio atminties analize
### studentai1000.txt
![memory1000](https://github.com/Pijus-B/OOP/assets/90143621/e61620c1-c405-4277-90a5-42893b44ebe4)
### studentai10000.txt
![memory10000](https://github.com/Pijus-B/OOP/assets/90143621/7966a9a0-2a66-4567-96cb-4461d431c202)
### studentai100000.txt
![memory100000](https://github.com/Pijus-B/OOP/assets/90143621/976c14a5-713e-4399-bd0c-ab080a4e44ca)
### studentai1000000.txt
![memory1000000](https://github.com/Pijus-B/OOP/assets/90143621/46600b22-e090-4779-b1ee-2535e4d74c15)
### studentai10000000.txt
![memory10000000](https://github.com/Pijus-B/OOP/assets/90143621/19626753-9d66-48ae-9ddd-50faec25d042)

### Isvada
_Is situ rezultatu galime pastebeti, jog studentu skirstymas i dvi grupes, lyginant visus tris konteinerius, efektyviausias buvo Vector, o likusieji pasizymejo panasiais rezultatais. Taciau, be abejo, si strategija nera efektyvti del gan savo dideles atminties uzimtumu._

## 2 strategija
### fff












