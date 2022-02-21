/*#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <random>
#include <algorithm>
using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::setw;
using std::left;
using std::right;
struct Studentas
{
    string vardas = "";
    string pavarde = "";
    int nd[50];
    int egz = 0;
    int sum = 0;
    double rez = 0;
    double med = 0;
};

void ivestis(Studentas& temp, int& i);
void isvestis(Studentas& temp);
void vidurkis(Studentas& temp, int i);
void mediana(Studentas& temp, int i);
int main()
{
    int s, choice, count; //count - namu darbu pazymiu skaicius
    cout << "Kiek yra studentu: "; cin >> s;
    if (!s)
    {
        cout << "Neteisingi duomenys, paleiskite programa is naujo" << endl;

    }
    else
    {
        Studentas* mas = new Studentas[s];
        for (int i = 0; i < s; i++)
        {
            ivestis(mas[i], count);
        }
        for (int i = 0; i < s; i++)
        {
            vidurkis(mas[i], count);
            mediana(mas[i], count);
        }
        cout << "Irasykite 1, jei norite spausdinti vidurki.\nIrasykite 2, jei norite spausdinti mediana.\nIrasykite 3, jei norite spausdinti abu.\n";
        do
        {
            cin >> choice;
            switch (choice)
            {
            case 1:
                cout << left << setw(20) << "Vardas" << left << setw(20) << "Pavarde" << "Galutinis vid. " << endl;
                for (int i = 0; i < s; i++)
                {
                    cout << setw(20) << mas[i].vardas << setw(20) << mas[i].pavarde << setw(17) << std::fixed << std::setprecision(2) << mas[i].rez << endl;
                }
                break;
            case 2:
                cout << left << setw(20) << "Vardas" << left << setw(20) << "Pavarde" << "Galutinis med." << endl;
                for (int i = 0; i < s; i++)
                {

                    cout << setw(20) << mas[i].vardas << setw(20) << mas[i].pavarde << setw(17) << std::fixed << std::setprecision(2) << mas[i].med << endl;
                }
                break;
            case 3:
                cout << left << setw(20) << "Vardas" << left << setw(20) << "Pavarde" << "Galutinis vid. " << "/ Galutinis med." << endl;
                for (int i = 0; i < s; i++)
                {
                    isvestis(mas[i]);
                }
                break;
            default:
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Neteisinga ivestis. Iveskite 1 arba 2 arba 3. " << endl;
                break;
            }
        } while (choice != 1 && choice != 2 && choice != 3);
        delete[] mas;
        system("pause");
        return 0;
    }
}

void ivestis(Studentas& temp, int &i)
{
    int nd, egzam;
    string choice;
    i = 0;
    string stop;
    cout << "Iveskite varda: "; cin >> temp.vardas;
    cout << "Iveskite pavarde: "; cin >> temp.pavarde;
    do
    {
        cout << "Kaip vesite mokinio pazymius? Irasykite 1 arba 2.\n1.Ivesti ranka\n2.Sugeneruoti atsitiktines reiksmes" << endl;
        cin >> choice;
        if (choice != "1" && choice != "2")
        {
            cin.clear();
            cin.ignore();
            cout << "Neteisinga ivestis" << endl;
        }
    } while (choice != "1" && choice != "2");
    if (choice == "1")
    {
        do
        {
            cout << "Iveskite " << i + 1 << "-a(-i) pazymi: "; cin >> nd;
            if (nd)
            {
                if (nd > 0 && nd <= 10)
                {
                    temp.nd[i] = nd; //irasau namu darbu rezultata i masyva
                    temp.sum += nd;
                    i++;
                    cout << "Ar dar yra pazymiu? T-taip, N-ne: "; cin >> stop;
                    if (stop == "T" || stop == "t" || stop == "N" || stop == "n")
                    {
                        continue;
                    }
                    else
                    {

                        do
                        {
                            cout << "Neteisinga ivestis" << endl;
                            cout << "Ar dar yra pazymiu? T-taip, N-ne: "; cin >> stop;
                        } while ((stop != "T" && stop != "t") && (stop != "N" && stop != "n"));
                    }

                }
                else
                {
                        cout << "Neteisinga ivestis" << endl;
                }

            }
            else
            {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Neteisinga ivestis" << endl;
            }
        } while (stop != "N" && stop != "n");
        int arrSize = *(&temp.nd + 1) - temp.nd;
        
        do
        {
            cout << "Iveskite egzamino iverti:"; cin >> egzam;
            if (egzam)
            {
                if (egzam > 0 && egzam <= 10)
                {
                    continue;
                }
                else
                {
                    cin.clear();
                    cin.ignore();
                    cout << "Neteisinga ivestis" << endl;
                }
            }
            else
            {
                cin.clear();
                cin.ignore();
                cout << "Neteisinga ivestis" << endl;
            }
        } while (!egzam || (egzam <= 0 || egzam > 10));
        temp.egz = egzam;


    }
    else
    {
        do
        {
            srand(time(NULL));
            nd = (rand() % 10) + 1;
            cout << "Sugeneruotas " << i + 1 << "-as pazymys: " << nd << endl;
            temp.nd[i] = nd; ///sugeneruota reiksme rasau i masyva
            temp.sum += nd;
            i++;
            cout << "Ar dar yra pazymiu? T-taip, N-ne: "; cin >> stop;
            if ((stop != "T" && stop != "t") && (stop != "N" && stop != "n"))
                do
                {
                    cout << "Neteisinga ivestis" << endl;
                    cout << "Ar dar yra pazymiu? T-taip, N-ne: "; cin >> stop;
                } while ((stop != "T" && stop != "t") && (stop != "N" && stop != "n"));
        } while (stop != "N" && stop != "n");
        egzam = (rand() % 10) + 1;
        cout << "Sugeneruotas atsitiktinis egzamino balas: " << egzam << endl;
        temp.egz = egzam;
    }
}
void isvestis(Studentas& temp)
{

    cout << setw(20) << temp.vardas << setw(20) << temp.pavarde << setw(17) << std::fixed << std::setprecision(2) << temp.rez
        << temp.med << endl;
}
void vidurkis(Studentas& temp, int i)
{
    int nd_sk = i;
    double nd_vid = (double)temp.sum / nd_sk;
    temp.rez = 0.4 * nd_vid + 0.6 * temp.egz;

}
void mediana(Studentas& temp, int i)
{
    double med;
    int n = i;
    std::sort(temp.nd, temp.nd + n);
    if (n % 2 == 0)
    {
        med = (temp.nd[n / 2 - 1] + temp.nd[n / 2]) / 2;
    }
    else
    {
        med = temp.nd[n / 2];
    }
    temp.med = 0.4 * med + 0.6 * temp.egz;
}
*/