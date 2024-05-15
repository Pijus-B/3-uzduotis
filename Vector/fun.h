#ifndef LABAS
#define LABAS
#include <iostream>
#include <numeric>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <random>
#include <ctime>
#include <chrono>
#include "vector.h"
using namespace std;

const int MAX_ND_SIZE = 500;
const int MAX_STUDENTS = 500;

struct studentas
{
    string vardas;
    string pavarde;
     Vector <int> nd;
     int egz;
     double balas;
     double vid;
     double mediana;
};

void skaitymas (Vector <studentas> & A, int n);
void skaitymasTeksto (Vector <studentas> & A);
bool pagalVarda(const studentas & A, const studentas &B);
bool pagalPavarde(const studentas &A, const studentas &B);
bool pagalVidurki(const studentas &A, const studentas &B);
bool pagalMediana(const studentas &A, const studentas &B);
void spausdinti (const Vector <studentas> & A);
void spausdintiTeksto(const Vector <studentas> & A);
void skaiciavimas (Vector <studentas> & A);
void padalintiStudentus(Vector <studentas> &A);
void generavimasPazymiu (Vector <studentas> & A, int n);
void generavimasPazymiuCase2 (Vector <studentas> & A);
void generavimasStudentu (Vector <studentas> & A, int n);
void generavimasFailo (Vector <studentas> & A, int n);
bool isValidName(const string &name);
#endif 