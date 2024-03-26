#pragma once
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
#include <list>
using namespace std;

const int MAX_ND_SIZE = 500;
const int MAX_STUDENTS = 500;

struct studentas
{
    string vardas;
    string pavarde;
     list <int> nd;
     int egz;
     double balas;
     double vid;
     double mediana;
};

void skaitymas (list <studentas> & A, int n);
void skaitymasTeksto (list <studentas> & A);
bool pagalVarda(const studentas & A, const studentas &B);
bool pagalPavarde(const studentas &A, const studentas &B);
bool pagalVidurki(const studentas &A, const studentas &B);
bool pagalMediana(const studentas &A, const studentas &B);
void spausdinti (const list <studentas> & A);
void spausdintiTeksto(const list <studentas> & A);
void skaiciavimas (list <studentas> & A);
void padalintiStudentus(list <studentas> &A);
void generavimasPazymiu (list <studentas> & A, int n);
void generavimasPazymiuCase2 (list <studentas> & A);
void generavimasStudentu (list <studentas> & A, int n);
void generavimasFailo (list <studentas> & A, int n);
bool isValidName(const string &name);