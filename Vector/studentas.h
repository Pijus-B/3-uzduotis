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
#include "vector.h"
using namespace std;

const int MAX_ND_SIZE = 500;
const int MAX_STUDENTS = 500;

class Zmogus {
    protected:
    string vardas_;
    string pavarde_;
    public:
    Zmogus() = default;
    Zmogus(const string& vardas, const string& pavarde) : vardas_(vardas), pavarde_(pavarde) {}
    virtual ~Zmogus() {}

    virtual void setVardas(const string& vardas) { vardas_ = vardas; }
    virtual void setPavarde(const string& pavarde) { pavarde_ = pavarde; }
    virtual string getVardas() const = 0; // { return vardas_; }
    virtual string getPavarde() const = 0; // { return pavarde_; } 
};

class Studentas : public Zmogus {
private:
    Vector <int> nd_;
    int egz_;
    double balas_;
    double vid_;
    double mediana_;

public:
    Studentas() : egz_(0), balas_(0), vid_(0), mediana_(0) {} // default konstruktorius

    Studentas(const string& vardas, const string& pavarde, const Vector<int>& nd, int egz, double balas, double vid, double mediana) // konstruktorius
        : Zmogus(vardas, pavarde),  nd_(nd), egz_(egz), balas_(balas), vid_(vid), mediana_(mediana) {}
    ~Studentas() {nd_.clear();} // destruktorius

    Studentas(const Studentas& other)
        : Zmogus(other.getVardas(), other.getPavarde()), nd_(other.nd_), egz_(other.egz_), balas_(other.balas_), vid_(other.vid_), mediana_(other.mediana_) {} // copy constructor

    Studentas& operator=(const Studentas& other) { // copy assignment operatorius
        if (this != &other) {
            Zmogus::setVardas(other.getVardas());
            Zmogus::setPavarde(other.getPavarde());
            nd_ = other.nd_;
            egz_ = other.egz_;
            balas_ = other.balas_;
            vid_ = other.vid_;
            mediana_ = other.mediana_;
        }
        return *this;
    }

    Studentas(Studentas&& other) noexcept
      {Zmogus::setVardas(other.getVardas());
       Zmogus::setPavarde(other.getPavarde());
       nd_ = other.nd_;
       egz_ = other.egz_;
       balas_ = other.balas_;
       vid_ = other.vid_;
       mediana_ = mediana_;

       other.setVardas("");
       other.setPavarde("");
       other.nd_.clear();
       other.egz_ = 0;
       other.balas_ = 0;
       other.vid_ = 0;
       other.mediana_ = 0;
       
       //cout << "Move konstruktorius suveike" << endl;
    };

    Studentas& operator=(Studentas&& other) noexcept { // move assignment operatorius
        if (this != &other) {
            Zmogus::setVardas(move(other.getVardas()));
            Zmogus::setPavarde(move(other.getPavarde()));
            nd_ = move(other.nd_);
            egz_ = other.egz_;
            balas_ = other.balas_;
            vid_ = other.vid_;
            mediana_ = other.mediana_;
            other.egz_ = 0;
            other.balas_ = 0;
            other.vid_ = 0;
            other.mediana_ = 0;
        }
        return *this;
    }

    // Getter and setter functions
    inline string getVardas() const override{return vardas_;}
    inline string getPavarde() const override {return pavarde_;}
    inline Vector<int>& getNd() { return nd_; }
    inline int getEgz() const { return egz_; }
    inline double getBalas() const { return balas_; }
    inline double getVid() const { return vid_; }
    inline double getMediana() const { return mediana_; }
    inline void setVardas(const string& vardas) { vardas_ = vardas; }
    inline void setPavarde(const string& pavarde) { pavarde_ = pavarde; }
    inline void setNd(const Vector<int>& nd) { nd_ = nd; }
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

void skaitymas(Vector<Studentas>&, int);
void skaitymasTeksto(Vector<Studentas>&);
bool pagalVarda(const Studentas&, const Studentas&);
bool pagalPavarde(const Studentas&, const Studentas&);
bool pagalVidurki(const Studentas&, const Studentas&);
bool pagalMediana(const Studentas&, const Studentas&);
void spausdinti(const Vector<Studentas>&);
void spausdintiTeksto(const Vector<Studentas>&);
void skaiciavimas(Vector<Studentas>&);
void padalintiStudentus(Vector<Studentas>&);
void generavimasPazymiu(Vector<Studentas>&, int n);
void generavimasPazymiuCase2(Vector<Studentas>&);
void generavimasStudentu(Vector<Studentas>&, int);
void generavimasFailo(Vector<Studentas>&, int);
bool isValidName(const string&);
void test_constructor ();
void test_copy_constructor ();
void test_move_constructor ();
void test_copy_assignment ();
void test_move_assignment ();
void test_input_operator ();
void test_output_operator();
#endif  