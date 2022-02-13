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
    int sum=0;
    double rez=0;
};

void ivestis(Studentas& temp);
void isvestis(Studentas& temp, int s);
void vidurkis(Studentas& temp);
int main()
{
    int s;
    int nd_sk = 0;
    cout << "Kiek yra studentu: "; cin >> s;
    Studentas* mas = new Studentas[s];
    for (int i = 0; i < s; i++)
    {
        ivestis(mas[i]);
    }
    for (int i = 0; i < s; i++)
    {
        vidurkis(mas[i]);
    }
    
    for (int i = 0; i < s; i++)
    {
        isvestis(mas[i], s);
    }
    delete[] mas;
    system("pause");
    return 0;
}

void ivestis(Studentas& temp)
{
    int nd;
    int i = 0;
    cout << "Iveskite varda: "; cin >> temp.vardas;
    cout << "Iveskite pavarde: "; cin >> temp.pavarde;
    //cout <<"Kiek pazymiu turi studentas: "; cin>>n;
    string stop;
    do
    {
        cout << "Iveskite " << i + 1 << "-a(-i) pazymi:"; cin >> nd;
        if (nd > 0 && nd <= 10)
        {
            
            temp.nd.push_back(nd);
            temp.sum += nd;
            i++;
            
        }
        cout << "Ar dar yra pazymiu? T-taip, N-ne: "; cin >> stop;
    } while (stop != "N" && stop != "n");
    cout << "Iveskite egzamino iverti:"; cin >> temp.egz;
}
void isvestis(Studentas& temp, int s)
{
    cout << "|" << std::left << std::setw(20) << temp.vardas << "|" << std::left << std::setw(20) << temp.pavarde << std::right;
    cout << "|" << std::setw(10) << temp.sum;
    cout << "|" << std::setw(10) << temp.egz << "|" << std::endl;
}
void vidurkis(Studentas& temp)
{
    size_t nd_sk = temp.nd.size();
    double nd_vid = (double)temp.sum / nd_sk;
    cout << nd_vid<<endl;
}