#pragma once
#include <bits/stdc++.h>
using namespace std;

const int MAX_ND_SIZE = 500;
const int MAX_STUDENTS = 500;

struct studentas
{
    string vardas;
    string pavarde;
     deque <int> nd;
     int egz;
     double balas;
     double vid;
     double mediana;
};

void skaitymas (deque <studentas> & A, int n);
void skaitymasTeksto (deque <studentas> & A);
bool pagalVarda(const studentas & A, const studentas &B);
bool pagalPavarde(const studentas &A, const studentas &B);
bool pagalVidurki(const studentas &A, const studentas &B);
bool pagalMediana(const studentas &A, const studentas &B);
void spausdinti (const deque <studentas> & A);
void spausdintiTeksto(const deque <studentas> & A);
void skaiciavimas (deque <studentas> & A);
void padalintiStudentus(deque <studentas> &A);
void generavimasPazymiu (deque <studentas> & A, int n);
void generavimasPazymiuCase2 (deque <studentas> & A);
void generavimasStudentu (deque <studentas> & A, int n);
void generavimasFailo (deque <studentas> & A, int n);
bool isValidName(const string &name);