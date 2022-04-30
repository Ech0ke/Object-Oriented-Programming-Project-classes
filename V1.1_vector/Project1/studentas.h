#pragma once
#include "libraries_and_std.h"
#include "manual.h"
#include "file.h"
class Studentas
{
private:
    string vardas_;
    string pavarde_;
    vector <double>nd_;
    int egz_; //egzamino balas
    int sum_; //namu darbu rezultatu suma
    double rez_; //vidurkio rezultatas
    double med_; //mediana
public:
    Studentas()
    {
        egz_ = 0; //egzamino balas
        sum_ = 0; //namu darbu rezultatu suma
        rez_ = 0; //vidurkio rezultatas
        med_ = 0; //mediana
    }
    inline std::string getVardas() const { return vardas_; }
    void setVardas(string vardas) { vardas_ = vardas; }    // get'eriai, inline
    inline std::string getPavarde() const { return pavarde_; }// get'eriai, inline
    void setPavarde(string pavarde) { pavarde_ = pavarde; }

    double getNd(int i) const { return nd_.at(i); }
    void setNd(double nd)
    {
        nd_.reserve(nd_.size() + 1);
        nd_.push_back(nd);
    }
    void clearND() { nd_.clear(); }
    inline int sizeNd() const { return nd_.size(); }

    inline int getEgz() const { return egz_; }
    void setEgz(int egz) { egz_ = egz; }

    inline double getRez() const { return rez_; }
    void setRez(double rez) { rez_ = rez; }

    inline double getMed() const { return med_; }
    void setMed(double med) { med_ = med; }

    inline int getSum() const { return sum_; }
    void setSum(int sum) { sum_=sum; }
    void addSum(int sum) { sum_ += sum; }
    void mediana(Studentas& temp);
    void read_file(vector <Studentas>& sar, string a);  
    void isvestis_2files(vector <Studentas>& temp, string a, string b);
    
    
};
void vidurkis(Studentas& temp);
void isvestis_vid(Studentas& temp);
void isvestis_med(Studentas& temp);
void isvestis_file(vector <Studentas>& temp);
void isvestis(Studentas& temp);
void ivestis(Studentas& temp);
bool vardas_sort(const Studentas& a, const Studentas& b);
bool pazymiai_sort(const Studentas& a, const Studentas& b);
void create_file();

class zmogus {
public:
    string vardas = "";
    string pavarde = "";
    vector <int> paz;
    void gen_map(zmogus& temp);
    void naujas_failas(zmogus zm, int nd, int sk);
};