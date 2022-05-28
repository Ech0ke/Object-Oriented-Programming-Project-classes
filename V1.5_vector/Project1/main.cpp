#include "studentas.h"

int main()

{
    int choice;
    cout << "Irasykite 1, jei duomenis nuskaityti is failo.\nIrasykite 2, jei norite duomenis rasyti ranka.\nIrasykite 3, jei norite sugeneruoti 2 failus, kuriuose studentai suskirstyti pagal pazanguma.\n";
    do
    {
        cin >> choice;
        switch (choice)
        {
        case 1:
            File();
            system("pause");
            break;
        case 2:
            Manual();
            break;
        case 3:
        {
            create_file();
            break;
        }
        default:

            cout << "Neteisinga ivestis. Iveskite 1, 2 arba 3. " << endl;
            cin.clear(); //isvaloma neteisinga ivestis
            cin.ignore(10000, '\n'); //ignoruojama ivestis ir taip apsaugoma nuo string ivesties
            break;
        }
    } while (choice != 1 && choice != 2  && choice != 3);

}