#pragma once
#include "header.h"

using namespace std;

const int MAX_ND_SIZE = 500;
const int MAX_STUDENTS = 500;

struct studentas
{
    string vardas;
    string pavarde;
     vector <int> nd;
     int egz;
     double balas;
     double vid;
     double mediana;
};

void skaitymas (vector <studentas> & A, int n);
void skaitymasTeksto (vector <studentas> & A);
bool pagalVarda(const studentas & A, const studentas &B);
bool pagalPavarde(const studentas &A, const studentas &B);
bool pagalVidurki(const studentas &A, const studentas &B);
bool pagalMediana(const studentas &A, const studentas &B);
void spausdinti (const vector <studentas> & A);
void spausdintiTeksto(const vector <studentas> & A);
void skaiciavimas (vector <studentas> & A);
void padalintiStudentus(vector <studentas> &A);
void generavimasPazymiu (vector <studentas> & A, int n);
void generavimasPazymiuCase2 (vector <studentas> & A);
void generavimasStudentu (vector <studentas> & A, int n);
void generavimasFailo (vector <studentas> & A, int n);
bool isValidName(const string &name);