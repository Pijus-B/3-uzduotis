# OOP
## V1.2
Pateiktas kodas yra C++ programa studentu informacijos valdymui. Ji apima funkcijas tokias kaip ivesti studentų duomenis, skaiciuoti vidurkius ir medianas bei rodyti rezultatus. Šios testavimo funkcijos įgyvendintos tam, kad būtų užtikrintas Studentas klasės veikimo teisingumas ir patikimumas:

## Rule of Five patikrinimas
| Testavimo funkcija       | Aprasymas                                                                             |  Rezultatas     |
|--------------------------|---------------------------------------------------------------------------------------|-----------------|
|`test_constructor()`      |Patikrina konstruktorių su default parametrais                                         |Sėkmingai praėjo |
|`test_copy_constructor()` |Patikrina copy konstruktorių, ar tinkamai nukopijuoja objekta                          |Sėkmingai praėjo |   
|`test_move_constructor()` |Patikrina move konstruktorių, ar tinkamai perkelia objekta be papildomo kopijavimo     |Sėkmingai praėjo |   
|`test_copy_assignment()`  |Patikrina copy assignment, ar tinkamai nukopijuoja visus atributus                     |Sėkmingai praėjo |   
|`test_move_assignment()`  |Patikrina move assignment, ar tinkamai perkelia visus atributus be papildomo kopijavimo|Sėkmingai praėjo |   

Šie testai padeda mums patvirtinti svarbią klasės funkcionalumo dalį, įskaitant studentų įrašų konstravimą, kopijavimą ir perkėlimą.

![ruleoffive](https://github.com/Pijus-B/2-uzduotis/assets/90143621/a25a36c4-c841-4c5a-9101-db32a3e47de8)


## Ivesties ir isvesties patikrinimas
| Testavimo funkcija       | Aprasymas                                                                             |  Rezultatas     |
|--------------------------|---------------------------------------------------------------------------------------|-----------------|
|`test_input_operator()`   |Patikrina įvesties konstruktorių, ar tinkamai yra nuskaitomas objektas                 |Sėkmingai praejo |
|`test_output_operator()`  |Patikrina išvesties konstruktorių, ar tinkamai yra išvedamas objektas                  |Sėkmingai praejo |

Šie testai patikrina svarbią klasės funkcionalumo dalį, įskaitant įvesties ir išvesties operatorių veikimą.

![inputoutputtestai](https://github.com/Pijus-B/2-uzduotis/assets/90143621/b927e409-0e97-4c25-967b-f321d0b5e92a)






















