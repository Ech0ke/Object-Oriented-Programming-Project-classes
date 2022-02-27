#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <random>
#include <algorithm>
using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::vector;
using std::setw;
using std::left;
using std::right;
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

void ivestis(Studentas& temp);
void isvestis(Studentas& temp);
void isvestis_med(Studentas& temp);
void isvestis_vid(Studentas& temp);
void vidurkis(Studentas& temp);
void mediana(Studentas& temp);
int main()
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
        return 0;
    }
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
            if (nd) //tikrinama, ar ivestas skaicius
            {
                if (nd > 0 && nd <= 10) //tikrinama, ar pazymys yra nuo 1 iki 10
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
                if (egzam > 0 && egzam <= 10) //Jei ivestas egzamino balas yra tarp 1 ir 10, tesiama
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
        } while (!egzam || (egzam <= 0 || egzam > 10)); //tol, kol neivestas skaicius arba kol skaicius nepatenka i intervala nuo 1 iki 10
        temp.egz = egzam; //ivestas egzamino balas issaugomas strukturoje


    }
    else //jei vartotojas pasirenka generuoti skaicius (choice==2)
    {
        do
        {
            srand((unsigned int)time(NULL)); //pasirenkamas pradzios generavimo laikas
            nd = (rand() % 10) + 1; //sugeneruojamas balas
            cout << "Sugeneruotas " << i + 1 << "-as pazymys: " << nd << endl; //parodomas sugeneruotas balas
            temp.nd.push_back(nd); //balas pridedamas i studento vector konteineri
            temp.sum += nd; //sumuojami pazymiai
            i++;
            cout << "Ar dar yra pazymiu? T-taip, N-ne: "; cin >> stop;
            if ((stop != "T" && stop != "t") && (stop != "N" && stop != "n")) //Jei gaunama neteisinga ivestis, pranesama apie tai ir bandoma gauti teisinga atsakyma
                do
                {
                    cout << "Neteisinga ivestis" << endl;
                    cout << "Ar dar yra pazymiu? T-taip, N-ne: "; cin >> stop;
                } while ((stop != "T" && stop != "t") && (stop != "N" && stop != "n"));
        } while (stop != "N" && stop != "n"); //numeriai generuojami tol, kol bus norima

        egzam = (rand() % 10) + 1; //sugeneruojamas egzamino balas nuo 1 iki 10
        cout << "Sugeneruotas atsitiktinis egzamino balas: " << egzam << endl; //Balas parodomas vartotojui
        temp.egz = egzam; //Balas priskiramas studentui
    }
}
void isvestis(Studentas& temp)
{

    cout << setw(20) << temp.vardas << setw(20) << temp.pavarde << setw(17) << std::fixed << std::setprecision(2) << temp.rez
        << temp.med << endl;
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
    double nd_vid = (double)temp.sum / nd_sk; //skaicuojamas vidurkis
    temp.rez = 0.4 * nd_vid + 0.6 * temp.egz; //skaiciuojamas galutinis balas

}
void mediana(Studentas& temp)
{
    double med;
    sort(temp.nd.begin(), temp.nd.end()); //isrusiuojamas vector konteineris didejimo tvarka
    if (temp.nd.size() % 2 == 0) //jei yra lyginis skaicius elementy
    {
        med = (temp.nd[temp.nd.size() / 2 - 1] + temp.nd[temp.nd.size() / 2]) / 2; //sudedami 2 viduriniai elementai ir dalinama is 2
    }
    else //jei nelyginis skaicius elementu, paimamas vidurinis elementas
    {
        med = temp.nd[temp.nd.size() / 2];
    }
    temp.med = 0.4 * med + 0.6 * temp.egz; //skaiciuojamas galutinis balas
}