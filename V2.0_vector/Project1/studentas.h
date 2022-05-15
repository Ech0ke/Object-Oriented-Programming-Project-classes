#pragma once
#include "libraries_and_std.h"
#include "manual.h"
#include "file.h"
//!  Abstrakčioji žmogaus klasė.
class Zmogus 
{
    protected:
        string vardas_; //!< Žmogaus vardas.
        string pavarde_; //!< Žmogaus pavardė.
    public:
        inline std::string getVardas() const { return vardas_; }  //!< Gaunamas žmogaus vardas.
        virtual void setVardas(string vardas) = 0;   //!< Įrašomas žmogaus vardas.
        inline std::string getPavarde() const { return pavarde_; } //!< Gaunama žmogaus pavardė.
        virtual void setPavarde(string pavarde) = 0;  //!< Įrašoma žmogaus pavardė.
        //!  Abstrakčiosios klasės konstruktorius
        Zmogus()
        {
            vardas_ = "";
            pavarde_ = "";
        }
};
//!  Studento klasė.
class Studentas : public Zmogus
{
private:
    vector <double>nd_;  
    int egz_; //!< Egzamino balas.
    int sum_; //!< Namų darbų rezultatų suma.
    double rez_; //!< Vidurkio rezultatas.
    double med_; //!< Mediana.
public:
    //! Konstruktorius
    Studentas() 
    {
        
        egz_ = 0; //egzamino balas
        sum_ = 0; //namu darbu rezultatu suma
        rez_ = 0; //vidurkio rezultatas
        med_ = 0; //mediana
    }
    //! Destruktorius
    ~Studentas(){ nd_.clear(); }
    //! Copy konstruktorius.
    Studentas(const Studentas& s) 
    {
        vardas_ = s.vardas_;
        pavarde_ = s.pavarde_;
        std::copy(s.nd_.begin(), s.nd_.end(), nd_.begin());
        egz_ = s.egz_;
        sum_ = s.sum_;
        rez_ = s.rez_;
        med_ = s.med_;
       
    }
    //! Prieskyros operatorius
    Studentas& operator=(const Studentas& s) 
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
    void setVardas(string vardas) { vardas_ = vardas; }   //!< Įrašomas studento vardas.
    void setPavarde(string pavarde) { pavarde_ = pavarde; } //!< Įrašoma studento pavardė.

    double getNd(int i) const { return nd_.at(i); } //!< Gaunamas namų darbo rezultatas.
    void setNd(double nd) //!< Įrašomi namų darbai.
    {
        nd_.reserve(nd_.size() + 1);
        nd_.push_back(nd);
    }
    void clearND() { nd_.clear(); } //!< Ištrinami visi studento namų darbai.
    void sortNd() { sort(nd_.begin(), nd_.end()); } //!< Išrūšiuojami namų darbų rezultatai nuo mažiausio, iki didžiausio.
    inline int sizeNd() const { return nd_.size(); } //!< Gaunamas namų darbų skaičius.

    inline int getEgz() const { return egz_; } //!< Gaunamas egzamino balas.
    void setEgz(int egz) { egz_ = egz; } //!< Įrašomas egzamino balas.

    inline double getRez() const { return rez_; }  //!< Gaunamas galutinis balas.
    void setRez(double rez) { rez_ = rez; }  //!< Įrašomas galutinis balas.

    inline double getMed() const { return med_; }  //!< Gaunama mediana.
    void setMed(double med) { med_ = med; }  //!< Įrašoma mediana.

    inline int getSum() const { return sum_; } //!< Gaunama suma.
    void setSum(int sum) { sum_=sum; } //!< Įrašoma visa suma.
    void addSum(int sum) { sum_ += sum; } //!< Sumuojami duomenys į sum_ kintamąjį.

    
};
void mediana(Studentas& temp);  //!< Apskaičiuojama mediana.
void vidurkis(Studentas& temp); //!< Apskaičiuojamas vidurkis.
void read_file(vector <Studentas>& sar, string a);  //!< Nuskaitomas .txt studento duomenų failas
void isvestis_vid(Studentas& temp); //!< Rezultatų išvedimas, spausdinant vidurkį.
void isvestis_med(Studentas& temp); //!< Rezultatų išvedimas, spausdinant medianą.
void isvestis_file(vector <Studentas>& temp); //!< Rezultatų išvedimas iš sugeneruoto failo.
void isvestis_2files(vector <Studentas>& temp, string a, string b); //!< Rezultatų išvedimas į 2 failus, suskirstant studentus pagal pažangumą.
void isvestis(Studentas& temp);  //!< Rezultatų išvedimas, spausdinant vidurkį ir medianą.
void ivestis(Studentas& temp); //!< Rankinis studento duomenų įvedimas.
bool vardas_sort(const Studentas& a, const Studentas& b); //!< Vardų išrūšiavimas pagal abecėlės tvarką.
bool pazymiai_sort(const Studentas& a, const Studentas& b); //!< Išrūšiuojami studentai pagal galutinį balą nuo mažiausio, iki didžiausio.
void create_file(); //!< Studentų duomenų spartos tyrimas.
//! Klasė, naudojama studentų atsitiktinių duomenų generavimui.
class zmogus {
private:
    string vardas_;  //!< Studento vardas.
    string pavarde_; //!< Studento pavardė.
    vector <int> paz_; //!< Pažymiai.
public:
    
    inline std::string getVardas() const { return vardas_; } //!< Gaunamas studento vardas.
    void setVardas(string vardas) { vardas_ = vardas; }     //!< Įrašomas studento vardas.
    inline std::string getPavarde() const { return pavarde_; }//!< Gaunama studento pavardė.
    void setPavarde(string pavarde) { pavarde_ = pavarde; } //!< Įrašoma studento pavardė.
    double getPaz(int i) const { return paz_.at(i); }  //!< Gaunamas namų darbo rezultatas.
    void setPaz(double nd) //!< Įrašomi pažymiai.
    {
        paz_.reserve(paz_.size() + 1);
        paz_.push_back(nd);
    }
    void clearPaz() { paz_.clear(); } //!< Ištrinami visi studento pažymiai.
    void sortPaz() { sort(paz_.begin(), paz_.end()); } //!< Išrūšiuojami pažymiai nuo mažiausio, iki didžiausio.
    inline int sizePaz() const { return paz_.size(); } //!< Gaunamas pažymių skaičius.
};
void gen_map(zmogus& temp); //!< Generuojami atsitiktiniai vardai ir pavardės.
void naujas_failas(zmogus zm, int nd, int sk); //!< Generuojamas failas su atsitiktiniai vardais, pavardėm ir pažymiais.