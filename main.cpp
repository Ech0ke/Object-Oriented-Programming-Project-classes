#include <iostream>
#include <string>
#include <iomanip>
using std::cout;
using std::cin;
using std::string;
struct Studentas
{
    string vardas="";
    string pavarde="";
    int ND[3] = { 0 };
    int egz=0;
    double rez = 0;
};

void ivestis(Studentas& temp);
void isvestis(Studentas& temp);
int main()
{
    Studentas* mas = new Studentas[3];
    for (int i = 0; i < 3; i++)
    {
        ivestis(mas[i]);
    }
    for (int i = 0; i < 3; i++)
    {
        isvestis(mas[i]);
    }
    delete[] mas;
    system("pause");
    return 0;
}

void ivestis(Studentas& temp)
{
    int n = 3;
    cout << "Iveskite varda: "; cin >> temp.vardas;
    cout << "Iveskite pavarde: "; cin >> temp.pavarde;
    //cout <<"Kiek pazymiu turi studentas: "; cin>>n;
    for (int i = 0; i < n; i++)
    {
        cout << "Iveskite " << i + 1 << "-a(-i) pazymi:"; cin >> temp.ND[i];
    }
    cout << "Iveskite egzamino iverti:"; cin >> temp.egz;
}
void isvestis(Studentas& temp)
{
    cout << "|" << std::left << std::setw(20) << temp.vardas << "|" << std::left << std::setw(20) << temp.pavarde << std::right;
    for (int i = 0; i < 3; i++)
    {
        cout << "|" << std::setw(10) << temp.ND[i];
    }
    cout << "|" << std::setw(10) << temp.egz << "|"<<std::endl;
}