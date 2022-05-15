#include "studentas.h"
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
            ivestis(st);
            vidurkis(st); //skaiciuojamas studento vidurkis
            mediana(st); //skaiciuojamas studento vidurkis, naudojant mediana//perduodami studento duomenys i ivesties funkcija
            st.clearND();
            st.setSum(0);
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