#pragma once
#include "libraries_and_std.h"
#include "manual.h"
#include "file.h"

class Zmogus
{
    protected:
        string vardas_;
        string pavarde_;
    public:
        inline std::string getVardas() const { return vardas_; }
        virtual void setVardas(string vardas) = 0;   
        inline std::string getPavarde() const { return pavarde_; }
        virtual void setPavarde(string pavarde) = 0;
        Zmogus()
        {
            vardas_ = "";
            pavarde_ = "";
        }
};
class Studentas : public Zmogus
{
private:
    vector <double>nd_;
    int egz_; //egzamino balas
    int sum_; //namu darbu rezultatu suma
    double rez_; //vidurkio rezultatas
    double med_; //mediana
public:
    Studentas() //konstruktorius
    {
        
        egz_ = 0; //egzamino balas
        sum_ = 0; //namu darbu rezultatu suma
        rez_ = 0; //vidurkio rezultatas
        med_ = 0; //mediana
    }

    ~Studentas(){ nd_.clear(); } //destruktorius
    Studentas(const Studentas& s) //copy konstruktorius
    {
        vardas_ = s.vardas_;
        pavarde_ = s.pavarde_;
        std::copy(s.nd_.begin(), s.nd_.end(), nd_.begin());
        egz_ = s.egz_;
        sum_ = s.sum_;
        rez_ = s.rez_;
        med_ = s.med_;
       
    }
    Studentas& operator=(const Studentas& s) //prieskyros operatorius
    {
        if (this == &s)
        {
            return *this;
        }
        vardas_ = s.vardas_;
        pavarde_ = s.pavarde_;
        std::copy(s.nd_.begin(), s.nd_.end(), nd_.begin());
        egz_ = s.egz_;
        sum_ = s.sum_;
        rez_ = s.rez_;
        med_ = s.med_;
        return *this;
    }
    void setVardas(string vardas) { vardas_ = vardas; }    // get'eriai, inline
    void setPavarde(string pavarde) { pavarde_ = pavarde; }

    double getNd(int i) const { return nd_.at(i); }
    void setNd(double nd)
    {
        nd_.reserve(nd_.size() + 1);
        nd_.push_back(nd);
    }
    void clearND() { nd_.clear(); }
    void sortNd() { sort(nd_.begin(), nd_.end()); }
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

    
};
void mediana(Studentas& temp);
void vidurkis(Studentas& temp);
void read_file(vector <Studentas>& sar, string a);
void isvestis_vid(Studentas& temp);
void isvestis_med(Studentas& temp);
void isvestis_file(vector <Studentas>& temp);
void isvestis_2files(vector <Studentas>& temp, string a, string b);
void isvestis(Studentas& temp);
void ivestis(Studentas& temp);
bool vardas_sort(const Studentas& a, const Studentas& b);
bool pazymiai_sort(const Studentas& a, const Studentas& b);
void create_file();

class zmogus {
private:
    string vardas_;
    string pavarde_;
    vector <int> paz_;
public:
    
    inline std::string getVardas() const { return vardas_; }
    void setVardas(string vardas) { vardas_ = vardas; }    // get'eriai, inline
    inline std::string getPavarde() const { return pavarde_; }// get'eriai, inline
    void setPavarde(string pavarde) { pavarde_ = pavarde; }
    double getPaz(int i) const { return paz_.at(i); }
    void setPaz(double nd)
    {
        paz_.reserve(paz_.size() + 1);
        paz_.push_back(nd);
    }
    void clearPaz() { paz_.clear(); }
    void sortPaz() { sort(paz_.begin(), paz_.end()); }
    inline int sizePaz() const { return paz_.size(); }
};
void gen_map(zmogus& temp);
void naujas_failas(zmogus zm, int nd, int sk);