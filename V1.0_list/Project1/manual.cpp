#include "functions.h"
#include "manual.h"
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
        list <Studentas> sar;
        Studentas st;
        //sar.reserve(s);
        for (int i = 0; i < s; i++)
        {
            ivestis(st);
            vidurkis(st); //skaiciuojamas studento vidurkis
            mediana(st); //skaiciuojamas studento vidurkis, naudojant mediana//perduodami studento duomenys i ivesties funkcija
            st.nd.clear();
            st.sum = 0;
            sar.push_back(st);
        }
        cout << "Irasykite 1, jei norite spausdinti vidurki.\nIrasykite 2, jei norite spausdinti mediana.\nIrasykite 3, jei norite spausdinti abu.\n";
        do
        {
            cin >> choice; //pagal naudotojo ivesti, bus pateikiamas rezultatu atspausdinimo metodas
            switch (choice)
            {
            case 1: //Spausdinamas tik vidurkis
                cout << left << setw(20) << "Vardas" << left << setw(20) << "Pavarde" << "Galutinis vid. " << endl;
                for (auto &r: sar)
                {
                    isvestis_vid(r);
                }
                break;
            case 2: //Spausdinama tik mediana
                cout << left << setw(20) << "Vardas" << left << setw(20) << "Pavarde" << "Galutinis med." << endl;
                for (auto& r : sar)
                {
                    isvestis_med(r);
                }
                break;
            case 3: //Spausdinamas vidurkis ir mediana
                cout << left << setw(20) << "Vardas" << left << setw(20) << "Pavarde" << "Galutinis vid. " << "/ Galutinis med." << endl;
                for (auto& r : sar)
                {
                    isvestis(r);
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