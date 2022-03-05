#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::vector;
using std::setw;
using std::left;
using std::right;
using std::mt19937;
using std::stringstream;
using hrClock = std::chrono::high_resolution_clock;
typedef std::uniform_int_distribution<int>  int_distribution;

struct Studentas
{
    string vardas = "";
    string pavarde = "";
    vector <double>nd;
    int egz = 0; //egzamino balas
    int sum = 0; //namu darbu rezultatu suma
    double rez = 0; //vidurkio rezultatas
    double med = 0; //mediana
};
void Manual();
void File();
void ivestis(Studentas& temp);
void isvestis(Studentas& temp);
void isvestis_file(vector <Studentas>& temp);
void isvestis_med(Studentas& temp);
void isvestis_vid(Studentas& temp);
void vidurkis(Studentas& temp);
void mediana(Studentas& temp);
bool vardas_sort(const Studentas& a, const Studentas& b);
int main()
{
    int choice;
    cout << "Irasykite 1, jei duomenis nuskaityti is failo.\nIrasykite 2, jei norite duomenis rasyti ranka.\n";
    do
    {
        cin >> choice;
        switch (choice)
        {
        case 1:
            File();
            break;
        case 2:
            Manual();
            break;
        default:

            cout << "Neteisinga ivestis. Iveskite 1 arba 2. " << endl;
            cin.clear(); //isvaloma neteisinga ivestis
            cin.ignore(10000, '\n'); //ignoruojama ivestis ir taip apsaugoma nuo string ivesties
            break;
        }
    } while (choice != 1 && choice != 2);

}
void Manual()
{
    int s, choice; //s-studentu kiekis, choice - rezultatu isvesties pasirinkimo budas
    cout << "Kiek yra studentu: "; cin >> s;
    if (!s)
    {
        cout << "Neteisingi duomenys, paleiskite programa is naujo" << endl;
    }
    else
    {
        vector <Studentas> sar;
        Studentas st;
        sar.reserve(s);
        for (int i = 0; i < s; i++)
        {
            ivestis(st); //perduodami studento duomenys i ivesties funkcija
            sar.push_back(st);
        }
        for (int i = 0; i < sar.size(); i++)
        {
            vidurkis(sar.at(i)); //skaiciuojamas studento vidurkis
            mediana(sar.at(i)); //skaiciuojamas studento vidurkis, naudojant mediana
        }
        cout << "Irasykite 1, jei norite spausdinti vidurki.\nIrasykite 2, jei norite spausdinti mediana.\nIrasykite 3, jei norite spausdinti abu.\n";
        do
        {
            cin >> choice; //pagal naudotojo ivesti, bus pateikiamas rezultatu atspausdinimo metodas
            switch (choice)
            {
            case 1: //Spausdinamas tik vidurkis
                cout << left << setw(20) << "Vardas" << left << setw(20) << "Pavarde" << "Galutinis vid. " << endl;
                for (int i = 0; i < sar.size(); i++)
                {
                    isvestis_vid(sar.at(i));
                }
                break;
            case 2: //Spausdinama tik mediana
                cout << left << setw(20) << "Vardas" << left << setw(20) << "Pavarde" << "Galutinis med." << endl;
                for (int i = 0; i < sar.size(); i++)
                {
                    isvestis_med(sar.at(i));
                }
                break;
            case 3: //Spausdinamas vidurkis ir mediana
                cout << left << setw(20) << "Vardas" << left << setw(20) << "Pavarde" << "Galutinis vid. " << "/ Galutinis med." << endl;
                for (int i = 0; i < sar.size(); i++)
                {
                    isvestis(sar.at(i));
                }
                break;
            default:

                cout << "Neteisinga ivestis. Iveskite 1 arba 2 arba 3. " << endl;
                cin.clear(); //isvaloma neteisinga ivestis
                cin.ignore(10000, '\n'); //ignoruojama ivestis ir taip apsaugoma nuo string ivesties
                break;
            }
        } while (choice != 1 && choice != 2 && choice != 3); //kartojama, kol bus pasirinktas teisingas variantas
        system("pause");
    }
}
void File()
{
    vector <Studentas> sar;
    Studentas st;
    string line;
    int nd, egz, lines;
    std::ifstream fd("kursiokai.txt");
    std::getline(fd, line); //perskaitoma pirma failo eilute
    stringstream x;
    x << line;
    int how_many_columns = 0;
    string value;

    while (x >> value) how_many_columns++;  //Kol kazkas randama eiluteje tarp tarpu, skaiciuojama
    // suskaiciuoti eiluciu skaiciu
    for (lines = 0; std::getline(fd, line); lines++)
    {
    }
    sar.reserve(lines);
    fd.clear();
    fd.seekg(0);
    stringstream my_buffer;
    std::getline(fd, line);
    my_buffer << fd.rdbuf();
    fd.close();
    for (int i = 0; i < lines; i++)
    {
        my_buffer >> st.vardas;
        my_buffer >> st.pavarde;
        for (int i = 0; i < how_many_columns - 3; i++)
        {

            my_buffer >> nd;
            st.nd.push_back(nd);
            st.sum += nd;

        }
        my_buffer >> egz;
        st.egz = egz;
        vidurkis(st);
        mediana(st);
        st.sum = 0;
        st.nd.clear();
        sar.push_back(st);

    }
    sort(sar.begin(), sar.end(), vardas_sort);
    isvestis_file(sar);
    sar.clear();


}
void ivestis(Studentas& temp)
{
    int nd, egzam;
    string choice; //namu darbu rezultatu ivesties pasirinkimas
    int i = 0;
    string stop; //Triggeris, kuris parodys, kada vartotojas jau nebenori toliau ivedineti namu darbu rezultatu
    cout << "Iveskite varda: "; cin >> temp.vardas;
    cout << "Iveskite pavarde: "; cin >> temp.pavarde;
    do
    {
        cout << "Kaip vesite mokinio pazymius? Irasykite 1 arba 2.\n1.Ivesti ranka\n2.Sugeneruoti atsitiktines reiksmes" << endl;
        cin >> choice;
        if (choice != "1" && choice != "2")
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Neteisinga ivestis" << endl; //Jei ivestis neteisinga, apie tai pranesama
        }
    } while (choice != "1" && choice != "2"); //ciklas veikia tol, kol bus gauta teisinga ivestis
    if (choice == "1") //Pasirinktas ivedimas ranka
    {
        do
        {
            cout << "Iveskite " << i + 1 << "-a(-i) pazymi: "; cin >> nd;
            if (nd || nd == 0) //tikrinama, ar ivestas skaicius
            {
                if (nd >= 0 && nd <= 10) //tikrinama, ar pazymys yra nuo 0 iki 10
                {

                    temp.nd.push_back(nd); //pazymys pridedamas i vector konteineri
                    temp.sum += nd; //sumuojami pazymiai
                    i++;
                    cout << "Ar dar yra pazymiu? T-taip, N-ne: "; cin >> stop;
                    if (stop == "T" || stop == "t" || stop == "N" || stop == "n") //jei gaunama teisinga ivestis, programa tesia darba
                    {
                        continue;
                    }
                    else //kitaip pranesama apie neteisinga ivesti ir bandoma is naujo gauti teisinga ivesti
                    {

                        do
                        {
                            cout << "Neteisinga ivestis" << endl;
                            cout << "Ar dar yra pazymiu? T-taip, N-ne: "; cin >> stop;
                        } while ((stop != "T" && stop != "t") && (stop != "N" && stop != "n"));
                    }

                }
                else //jei ivestas neteisingas skaicius, pranesama apie tai ir klausiama ar dar bus pazymiu, jei taip, prasys is naujo ivesti pazymi
                {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "Neteisinga ivestis" << endl;
                }

            } //jei ivestas ne skaicius, pranesama apie tai ir klausiama ar dar bus pazymiu
            else
            {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Neteisinga ivestis" << endl;

            }

        } while (stop != "N" && stop != "n"); //viskas vykdoma, kol vartotojas ives norima namu darbu skaiciu
        do
        {
            cout << "Iveskite egzamino iverti:"; cin >> egzam;
            if (egzam) //tikrinama, ar ivestas skaicius
            {
                if (egzam >= 0 && egzam <= 10) //Jei ivestas egzamino balas yra tarp 0 ir 10, tesiama
                {
                    continue;
                }
                else //Jei ivestas neteisingas egzamino balas, pranesama
                {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "Neteisinga ivestis" << endl;
                }
            }
            else //jei ivestas string, pvz - zodis
            {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Neteisinga ivestis" << endl;
            }
        } while (!egzam || (egzam < 0 || egzam > 10)); //tol, kol neivestas skaicius arba kol skaicius nepatenka i intervala nuo 1 iki 10
        temp.egz = egzam; //ivestas egzamino balas issaugomas strukturoje


    }
    else //jei vartotojas pasirenka generuoti skaicius (choice==2)
    {
        mt19937 mt(static_cast<long unsigned int>(hrClock::now().time_since_epoch().count()));
        int_distribution dist(0, 10);
        int skaitl;
        cout << "Kiek pazymiu sugeneruoti? " << endl;
        do
        {
            cin >> skaitl;
            if (skaitl > 0)
            {
                for (int i = 0; i < skaitl; i++)
                {
                    nd = dist(mt);
                    temp.nd.push_back(nd); //balas pridedamas i studento vector konteineri
                    temp.sum += nd;
                }
                cout << "Sugeneruoti pazymiai: ";
                for (int i = 0; i < temp.nd.size(); i++)
                {
                    cout << temp.nd[i] << " ";
                }
                cout << endl;

            }
            else if (!skaitl && skaitl != 0)
            {
                cout << "Neteisinga ivestis. Iveskite teigiama skaiciu " << endl;
                cin.clear(); //isvaloma neteisinga ivestis
                cin.ignore(10000, '\n'); //ignoruojama ivestis ir taip apsaugoma nuo string ivesties
            }
            else if (skaitl == 0)
            {
                cout << "Tariama, jog studentas namu darbu nedare." << endl;
                break;
            }
            else
            {
                cout << "Neteisinga ivestis. Iveskite teigiama skaiciu. " << endl;
                cin.clear(); //isvaloma neteisinga ivestis
                cin.ignore(10000, '\n'); //ignoruojama ivestis ir taip apsaugoma nuo string ivesties

            }
        } while (skaitl < 0 || !skaitl); //numeriai generuojami tol, kol bus norima

        egzam = dist(mt); //sugeneruojamas egzamino balas nuo 1 iki 10
        cout << "Sugeneruotas atsitiktinis egzamino balas: " << egzam << endl; //Balas parodomas vartotojui
        temp.egz = egzam; //Balas priskiramas studentui
    }
}
void isvestis(Studentas& temp)
{

    cout << setw(20) << temp.vardas << setw(20) << temp.pavarde << setw(17) << std::fixed << std::setprecision(2) << temp.rez
        << temp.med << endl;
}
void isvestis_file(vector <Studentas>& temp)
{

    std::ofstream out_f("Rezultatai.txt");
    string output = "";
    char eilute[1000];

    out_f << left << setw(21) << "Vardas" << left << setw(21) << "Pavarde" << "Galutinis vid. " << "/ Galutinis med.\n";
    out_f << "-------------------------------------------------------------------------\n";
    for (int i = 0; i < temp.size(); i++)
    {
        sprintf_s(eilute, "%-20s %-20s %-16.2lf %-17.2lf\n", temp.at(i).vardas.c_str(), temp.at(i).pavarde.c_str(), temp.at(i).rez, temp.at(i).med);
        output += eilute;
    }
    out_f << output;
    out_f.close();
    cout << "Rezultatai isvesti faile Rezultatai.txt\n";
}
void isvestis_med(Studentas& temp)
{
    cout << setw(20) << temp.vardas << setw(20) << temp.pavarde << setw(17) << std::fixed << std::setprecision(2) << temp.med << endl;
}
void isvestis_vid(Studentas& temp)
{
    cout << setw(20) << temp.vardas << setw(20) << temp.pavarde << setw(17) << std::fixed << std::setprecision(2) << temp.rez << endl;
}
void vidurkis(Studentas& temp)
{
    size_t nd_sk = temp.nd.size(); //kiek yra namu darbu pazymiu
    double nd_vid;
    if (nd_sk != 0)
    {
        nd_vid = (double)temp.sum / nd_sk; //skaicuojamas vidurkis
    }
    else nd_vid = 0;
    temp.rez = 0.4 * nd_vid + 0.6 * temp.egz; //skaiciuojamas galutinis balas
}
void mediana(Studentas& temp)
{
    double med;
    if (temp.nd.size() >= 1)
    {
        sort(temp.nd.begin(), temp.nd.end()); //isrusiuojamas vector konteineris didejimo tvarka
        if (temp.nd.size() % 2 == 0) //jei yra lyginis skaicius elementy
        {
            med = (temp.nd[temp.nd.size() / 2 - 1] + temp.nd[temp.nd.size() / 2]) / 2; //sudedami 2 viduriniai elementai ir dalinama is 2
        }
        else //jei nelyginis skaicius elementu, paimamas vidurinis elementas
        {
            med = temp.nd[temp.nd.size() / 2];
        }
    }
    else
    {
        med = 0;
    }
    temp.med = 0.4 * med + 0.6 * temp.egz; //skaiciuojamas galutinis balas
}
bool vardas_sort(const Studentas& a, const Studentas& b)
{
    if (a.vardas == b.vardas)
        return a.pavarde < b.pavarde;
    return a.vardas < b.vardas;
}