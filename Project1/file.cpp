#include "functions.h"
#include "file.h"
void File()
{
    vector <Studentas> sar;
    Studentas st;
    string line;
    int nd, egz, lines;
    try
    {
        std::ifstream fd("kursiokai.txt");
        if (fd.is_open())
        {
            fd.peek();
            if (fd.eof())
            {
                cout << "kursiokai.txt egzistuoja, taciau failas yra tuscias" << endl;
            }
            else
            {
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
        }
        else throw "Failas \"kursiokai.txt\" nerastas";
    }
    catch (char const* e)
    {
        cout << e << endl;
    }

}