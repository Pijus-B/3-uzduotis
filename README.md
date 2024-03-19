# OOP
## V1.0
Pateiktas kodas yra C++ programa studentu informacijos valdymui. Ji apima funkcijas tokias kaip ivesti studentų duomenis, skaiciuoti vidurkius ir medianas bei rodyti rezultatus. Zemiau pateikiamas pagrindiniu komponentu ir funkciju aprasymas:

## Programu paleisties proceso instrukcijos
- 1 zingsnis: Instaliuoti Chocolatey
Atsidaryti CMD kaip Administrator: Spustelti Win + X ir pasirinkti “Command Prompt (Admin)” or “Windows PowerShell (Admin)”.
Paleisti instaliavimo komanda: Nusikopijuoti ta komanda ir paspausti Enter. Si komanda yra pasiekiama per Chocolatey svetaine.
powershell
Nusikopijuoti koda:
Set-ExecutionPolicy Bypass -Scope Process -Force; [System.Net.ServicePointManager]::SecurityProtocol = [System.Net.ServicePointManager]::SecurityProtocol -bor 3072; iex ((New-Object System.Net.WebClient).DownloadString('https://chocolatey.org/install.ps1'))
Patvirtinti instaliacija: irasyti choco i CMD ir paspausti Enter. Jeigu matote Chocolatey versijos informacija, tai jau yra instaliuota sekmingai.
- 2 zingsnis: Instaliuoti Make
Instaliuokite Make: CMD terminale (vis dar kaip Administrator), irasykite sia komanda bei paspauskite Enter:
shell
Nukopijuokite koda:
choco install make
Patvirtinkite Make instaliacija: irasykite "make -v" i CMD. Jei po irasymo rodo Make versijos informacija, tai reiskia, kad sekmingai instaliuota.
- 3 zingsnis: Kompiliuokite ir pradekite savo C++ projekta
Nurodykite savo projekto direktyva: Naudokite cd komanda i CMD, jog pakeisti savo projekto direktyva, kur yra instaliuotas Makefile.
Kompiliuokite savo projekta: Irasykite make ir paspauskite Enter. Tada prades kompiliuoti jusu C++ projekta pagal nurodytas Makefile instrukcijas.
Pradekite savo projekta: Po kompiliavimo, jus turetumete turetiyou should have an vykdomaji faila, dazniausiai vadinama main arba kitu specifikai pavadintu jusu Makefile. Irasykite main i CMD ir paspauskite Enter, kad pradetumete savo programos veikima.

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
### **Vector konteinerio atminties analize**
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

### **List konteinerio atminties analize**
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
### **Vector konteineris**
### studentai1000.txt
![memory1000](https://github.com/Pijus-B/OOP/assets/90143621/3c1154a5-3586-4521-83d0-26e5c7999adc)
![vector1000](https://github.com/Pijus-B/OOP/assets/90143621/086671f7-2069-403f-ba78-24548ff1725a)
### studentai10000.txt
![memory10000](https://github.com/Pijus-B/OOP/assets/90143621/b3dd0218-5f45-461b-b9da-cb817d508ad2)
![vector10000](https://github.com/Pijus-B/OOP/assets/90143621/a4df4abb-7de7-4bae-8f59-ce5003364b50)
### studentai100000.txt
![memory100000](https://github.com/Pijus-B/OOP/assets/90143621/a57e5c96-d83f-40d2-bb1a-804d91f8fd2c)
![vector100000](https://github.com/Pijus-B/OOP/assets/90143621/bac133eb-e697-40b0-bf50-33bc82553ddd)

_Su likusiais failais studentu skirstymo i dvi grupes laikas buvo per didelis, kad galeciau pateikti rezultatus._

### **List konteineris**
### studentai1000.txt
![memory1000](https://github.com/Pijus-B/OOP/assets/90143621/f1436d62-6e93-4482-a6a0-c5a2094b2d0b)
![list1000](https://github.com/Pijus-B/OOP/assets/90143621/3e6dca8f-4774-4ce7-a1eb-e88587f0b89e)
### studentai10000.txt
![memory10000](https://github.com/Pijus-B/OOP/assets/90143621/52c95601-31cc-4c51-b86a-f64949b31f19)
![list10000](https://github.com/Pijus-B/OOP/assets/90143621/c4762926-58c1-4f04-849a-404c13a48e3d)
### studentai100000.txt
![memory100000](https://github.com/Pijus-B/OOP/assets/90143621/6cd5bdc0-84f2-495a-bc8e-70b32c958ba0)
![list100000](https://github.com/Pijus-B/OOP/assets/90143621/54eb2c95-a348-49ca-b26f-a1d7b74538e5)
### studentai1000000.txt
![memory1000000](https://github.com/Pijus-B/OOP/assets/90143621/e47947fd-7ec4-4aa2-996c-17141c78babe)
![list1000000](https://github.com/Pijus-B/OOP/assets/90143621/e812fd1f-532c-457a-93c7-721b736d59b7)
### studentai10000000.txt
![memory10000000](https://github.com/Pijus-B/OOP/assets/90143621/cf808137-4533-4d1d-ae7e-4e2ed4e69a29)
![list10000000](https://github.com/Pijus-B/OOP/assets/90143621/51b48fbb-ea14-4b77-b124-81b5487c5dc4)

### **Deque konteineris**
### studentai1000.txt
![memory1000](https://github.com/Pijus-B/OOP/assets/90143621/72389be8-395e-40b0-82bb-c837043a9399)
![deque1000](https://github.com/Pijus-B/OOP/assets/90143621/a469a2dc-67c6-4a65-9f75-a6d88a86c878)
### studentai10000.txt
![memory10000](https://github.com/Pijus-B/OOP/assets/90143621/d1395c99-f1b7-47f3-bd95-ba38f6967491)
![deque10000](https://github.com/Pijus-B/OOP/assets/90143621/295ff217-5c15-4b5e-b400-624fcfa034ae)
### studentai100000.txt
![memory100000](https://github.com/Pijus-B/OOP/assets/90143621/7d43c7c7-d00b-44ec-b833-81548d5c3337)
![deque100000](https://github.com/Pijus-B/OOP/assets/90143621/67420cae-7948-43c9-9d5e-7645692d039b)

_Su likusiais failais tas pats, kaip ir su Vector konteineriu, studentu skirstymo i dvi grupes laikas yra gan per didelis, jog galeciau isvesti rezultatus._
### Isvada
_Taigi, galima pastebeti, jog 2 strategija yra zenkliai efektyvesne ties atminties atzvilgiu, taciau skaiciuojant su didesniais failo duomenu kiekiais, tampa "skausminga" Vector ir Deque konteineriams del susijusiu su istrynimu is vidurio ir atminties pertekliaus valdymu._

## 3 strategija
### Vector konteinerio optimizacija su std::remove_if ir std::remove_if_copy
![Screenshot 2024-03-16 180107](https://github.com/Pijus-B/OOP/assets/90143621/79542be5-ca72-4375-83bf-6094252614d2)
![vector](https://github.com/Pijus-B/OOP/assets/90143621/30388577-8a53-41f5-92db-7aa621e2ef05)

_Rezultatai gauti su studentai10000000.txt_

### Vector konteinerio optimizacija su std::partition ir std::copy_if
![Screenshot 2024-03-16 180755](https://github.com/Pijus-B/OOP/assets/90143621/0f3a3b65-6df5-4c83-a87a-f984e215fc7c)
![Screenshot 2024-03-16 181235](https://github.com/Pijus-B/OOP/assets/90143621/ef210683-5f31-417f-aad6-1dbd302d298c)

_Rezultatai gauti su studentai10000000.txt_

### Isvada
Galima pastebeti, jog naudojantis siais algoritmais, programos veikimo sparta zenkliai padideja. Lyginant 2 strategija su 3 Vector konteinerio, galima lengvai pamatyti, kaip sie algoritmai sumazina atminties ir laiko sanaudas, nes nereikia kiekvieno elemento kopijuoti i nauja konteineri.

































