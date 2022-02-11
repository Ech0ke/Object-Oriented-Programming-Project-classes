#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::vector;
struct Studentas
{
    string vardas="";
    string pavarde="";
    vector <int>nd;
    int egz=0;
    double rez = 0;
};

void ivestis(Studentas& temp, int &nd_sk);
void isvestis(Studentas& temp, int s, int nd_sk);
int main()
{
    int s;
    int nd_sk = 0;
    cout << "Kiek yra studentu: "; cin >> s;
    Studentas* mas = new Studentas[s];
    for (int i = 0; i < s; i++)
    {
        ivestis(mas[i], nd_sk);
    }
    for (int i = 0; i < s; i++)
    {
        isvestis(mas[i], s, nd_sk);
    }
    delete[] mas;
    system("pause");
    return 0;
}

void ivestis(Studentas& temp, int &nd_sk)
{
    int nd;
    cout << "Iveskite varda: "; cin >> temp.vardas;
    cout << "Iveskite pavarde: "; cin >> temp.pavarde;
    //cout <<"Kiek pazymiu turi studentas: "; cin>>n;
    string stop="T";
    while (stop != "N")
    {
        cout << "Iveskite " << nd_sk + 1 << "-a(-i) pazymi:"; cin >> nd;
        if (nd > 0 && nd <= 10)
        {
            temp.nd.push_back(nd);
            nd_sk++;
        }
        else
            cout << "Neteisingai ivesti duomenys" << endl;
        cout << "Ar dar yra pazymiu? T-taip, N-ne: "; cin >> stop;
    } 
    cout << "Iveskite egzamino iverti:"; cin >> temp.egz;
}
void isvestis(Studentas& temp, int s, int nd_sk)
{
    cout << "|" << std::left << std::setw(20) << temp.vardas << "|" << std::left << std::setw(20) << temp.pavarde << std::right;
    for (int i = 0; i < nd_sk; i++)
    {
        cout << "|" << std::setw(10) << temp.nd[i];
    }
    cout << "|" << std::setw(10) << temp.egz << "|"<<std::endl;
}