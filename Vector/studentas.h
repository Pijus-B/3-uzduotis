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
#include <assert.h>
#include <cassert>
using namespace std;

const int MAX_ND_SIZE = 500;
const int MAX_STUDENTS = 500;

class Studentas {
private:
    string vardas_;
    string pavarde_;
    vector<int> nd_;
    int egz_;
    double balas_;
    double vid_;
    double mediana_;

public:
    // Default constructor
    Studentas() : egz_(0), balas_(0), vid_(0), mediana_(0) {}

    // Parameterized constructor
    Studentas(const string& vardas, const string& pavarde, const vector<int>& nd, int egz, double balas, double vid, double mediana)
        : vardas_(vardas), pavarde_(pavarde), nd_(nd), egz_(egz), balas_(balas), vid_(vid), mediana_(mediana) {}
    ~Studentas() {} // destruktorius

    Studentas(const Studentas& other)
        : vardas_(other.vardas_), pavarde_(other.pavarde_), nd_(other.nd_), egz_(other.egz_), balas_(other.balas_), vid_(other.vid_), mediana_(other.mediana_) {} // copy constructor

    Studentas& operator=(const Studentas& other) { // copy assignment operatorius
        if (this != &other) {
            vardas_ = other.vardas_;
            pavarde_ = other.pavarde_;
            nd_ = other.nd_;
            egz_ = other.egz_;
            balas_ = other.balas_;
            vid_ = other.vid_;
            mediana_ = other.mediana_;
        }
        return *this;
    }

    Studentas(Studentas&& other) noexcept
        : vardas_(move(other.vardas_)), pavarde_(move(other.pavarde_)), nd_(move(other.nd_)), egz_(other.egz_), balas_(other.balas_), vid_(other.vid_), mediana_(other.mediana_) {} // move konstriuktorius

    Studentas& operator=(Studentas&& other) noexcept { // move assignment operatorius
        if (this != &other) {
            vardas_ = move(other.vardas_);
            pavarde_ = move(other.pavarde_);
            nd_ = move(other.nd_);
            egz_ = other.egz_;
            balas_ = other.balas_;
            vid_ = other.vid_;
            mediana_ = other.mediana_;
        }
        return *this;
    }

    // Getter and setter functions
    inline string getVardas() const { return vardas_; }
    inline string getPavarde() const { return pavarde_; }
    inline vector<int>& getNd() { return nd_; }
    inline int getEgz() const { return egz_; }
    inline double getBalas() const { return balas_; }
    inline double getVid() const { return vid_; }
    inline double getMediana() const { return mediana_; }
    inline void setVardas(const string& vardas) { vardas_ = vardas; }
    inline void setPavarde(const string& pavarde) { pavarde_ = pavarde; }
    inline void setNd(const vector<int>& nd) { nd_ = nd; }
    inline void setEgz(const int& egz) { egz_ = egz; }
    inline void setBalas(const double& balas) { balas_ = balas; }
    inline void setVid(const double& vid) { vid_ = vid; }
    inline void setMediana(const double& mediana) { mediana_ = mediana; }

     friend istream& operator>>(istream& is, Studentas& student) { // input metodas
        cout << "Enter student's name and surname: ";
        is >> student.vardas_ >> student.pavarde_;
        
        cout << "Enter student's exam score: ";
        is >> student.egz_;
        
        cout << "Enter student's homework scores (enter -1 to stop): ";
        int score;
        while (is >> score && score != -1) {
            student.nd_.push_back(score);
        }

        
        return is;
    }

    friend ostream& operator<<(ostream& os, const Studentas& student) { // output metodas
        os << "Name: " << student.vardas_ << " " << student.pavarde_ << endl;
        os << "Exam score: " << student.egz_ << endl;
        os << "Homework scores: ";
        for (int score : student.nd_) {
            os << score << " ";
        }
        os << endl;
        os << "Final score: " << student.balas_ << endl;
        os << "Average: " << student.vid_ << endl;
        os << "Median: " << student.mediana_ << endl;
        return os;
    }
};

void skaitymas(vector<Studentas>&, int);
void skaitymasTeksto(vector<Studentas>&);
bool pagalVarda(const Studentas&, const Studentas&);
bool pagalPavarde(const Studentas&, const Studentas&);
bool pagalVidurki(const Studentas&, const Studentas&);
bool pagalMediana(const Studentas&, const Studentas&);
void spausdinti(const vector<Studentas>&);
void spausdintiTeksto(const vector<Studentas>&);
void skaiciavimas(vector<Studentas>&);
void padalintiStudentus(vector<Studentas>&);
void generavimasPazymiu(vector<Studentas>&, int n);
void generavimasPazymiuCase2(vector<Studentas>&);
void generavimasStudentu(vector<Studentas>&, int);
void generavimasFailo(vector<Studentas>&, int);
bool isValidName(const string&);
void test_constructor ();
void test_copy_constructor ();
void test_move_constructor ();
void test_copy_assignment ();
void test_move_assignment ();
void test_input_operator ();
void test_output_operator();
#endif  
