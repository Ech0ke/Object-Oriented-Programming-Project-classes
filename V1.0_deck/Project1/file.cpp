#include "functions.h"
#include "file.h"
void File()
{
    deque <Studentas> sar;
    string a = "kursiokai.txt";
    try
    {
        std::ifstream fd(a);
        if (fd)
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
                sort(sar.begin(), sar.end(), vardas_sort);
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