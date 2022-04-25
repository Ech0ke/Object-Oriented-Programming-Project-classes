#include "functions.h"
#include "file.h"
void File()
{
    list <Studentas> sar;
    string a = "kursiokai.txt";
    try
    {
        std::ifstream fd("kursiokai.txt");
        if (fd)//pakeisti i fd
        {
            fd.peek();
            if (fd.eof())
            {
                cout << "kursiokai.txt egzistuoja, taciau failas yra tuscias" << endl;
                fd.close();
            }
            else
            {
                fd.close();
                read_file(sar, a);
                sar.sort(vardas_sort);
                isvestis_file(sar);
                sar.clear();
            }
        }
        else throw "Failas \"kursiokai.txt\" nerastas";
    }
    catch (char const* e)
    {
        cout << e << endl;
    }

}