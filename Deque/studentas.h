#ifndef KA
#define KA
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
using namespace std;
class Studentas {
private:
    string vardas_;
    string pavarde_;
    vector <int> nd_;
    int egz_;
    double balas_;
    double vid_;
    double mediana_;
public:
    Studentas () : egz_(0), balas_(0), vid_(0), mediana_(0) {} // default konstruktorius
    Studentas (const string& vardas, const string& pavarde, const vector<int>& nd, int egz, double balas, double vid, double mediana) : vardas_(vardas), pavarde_(pavarde), nd_(nd), egz_(egz), balas_(balas), vid_(vid), mediana_(mediana) {} // konstruktoriai
    ~Studentas () {} // destruktorius

    inline string getVardas() const { return vardas_;} // getteris
    inline string getPavarde() const {return pavarde_;} // geteris
    inline vector<int> geNnd() const {return nd_;} // getteris
    inline int getEgz() const {return egz_;} // getteris
    inline double getBalas() const {return balas_;} // getteris
    inline double getVid () const {return vid_;} // getteris
    inline double getMediana () const {return mediana_;} // getteris

    inline void setVardas (const string& vardas) {vardas_ = vardas;} // setteris
    inline void setPavarde (const string &pavarde) {pavarde_ = pavarde;} // setteris
    inline void setNd (const vector<int>& nd) {nd_ = nd;} // setteris
    inline void setEgz (const int& egz) {egz_ = egz;} // setteris
    inline void setBalas (const double& balas) {balas_ = balas;} // setteris
    inline void setVid (const double& vid) {vid_ = vid;} // setteris
    inline void setMediana (const double& mediana) {mediana_ = mediana;} // setteris

    inline void skaiciavimas (vector <Studentas>);

};
/*void skaitymas (vector <Studentas> &, int); //get
void skaitymasTeksto (vector <Studentas> &); //get
bool pagalVarda(const Studentas &, const Studentas &);
bool pagalPavarde(const Studentas &, const Studentas &);
bool pagalVidurki(const Studentas &, const Studentas &);
bool pagalMediana(const Studentas &, const Studentas &);
void spausdinti (const vector <Studentas> &);//get
void spausdintiTeksto(const vector <Studentas> &); //get
void skaiciavimas (vector <Studentas> &); //funkc
void padalintiStudentus(vector <Studentas> &); //
void generavimasPazymiu (vector <Studentas> &, int n);
void generavimasPazymiuCase2 (vector <Studentas> &);
void generavimasStudentu (vector <Studentas> &, int);
void generavimasFailo (vector <Studentas> &, int);
bool isValidName(const string &);*/
#endif 