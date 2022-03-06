#include "libraries_and_std.h"
#include "functions.h"
#include "manual.h"
#include "file.h"
#include "struct.h"

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