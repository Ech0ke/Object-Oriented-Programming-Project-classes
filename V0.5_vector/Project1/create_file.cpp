#include "libraries_and_std.h"
#include "functions.h"
#include "struct.h"
void create_file()
{
    int choice;
    vector <zmogus> a;
    vector <Studentas> sar;
    zmogus zm;
    int sk, nd;
    cout << "Irasykite 1, jei norite atlikti spartos analize.\nIrasykite 2, jei norite sugeneruoti faila. \n";
    do
    {
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            string f1 = "kursiokai1000.txt";
            string f2 = "kursiokai10000.txt";
            string f3 = "kursiokai100000.txt";
            string f4 = "kursiokai1000000.txt";
            string f5 = "kursiokai10000000.txt";
            string a1 = "Silpnuciai1000.txt";
            string a2 = "Silpnuciai10000.txt";
            string a3 = "Silpnuciai100000.txt";
            string a4 = "Silpnuciai1000000.txt";
            string a5 = "Silpnuciai10000000.txt";
            string b1 = "Einsteinai1000.txt";
            string b2 = "Einsteinai10000.txt";
            string b3 = "Einsteinai100000.txt";
            string b4 = "Einsteinai1000000.txt";
            string b5 = "Einsteinai10000000.txt";
            try
            {
                std::ifstream fd("kursiokai1000.txt");
                if (fd)
                {
                    fd.close();
                    auto starta = std::chrono::high_resolution_clock::now();
                    read_file(sar, f1);  
                    sort(sar.begin(), sar.end(), pazymiai_sort);
                    isvestis_2files(sar, a1, b1);
                    auto enda = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double> diffa = enda - starta;
                    cout << "Visas apdorojimu laikas: " << diffa.count() << " s\n\n";
                    system("pause");
                }
                else throw "Failas \"kursiokai1000.txt\" nerastas\n";
            }
            catch (char const* e)
            {
                cout << e << endl;
            }

            try
            {
                std::ifstream fd("kursiokai10000.txt");
                if (fd)
                {
                    fd.close();
                    auto startb = std::chrono::high_resolution_clock::now();
                    read_file(sar, f2);
                   
                    sort(sar.begin(), sar.end(), pazymiai_sort);
                    isvestis_2files(sar, a2, b2);
                    auto endb = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double> diffb = endb - startb;
                    cout << "Visas apdorojimu laikas: " << diffb.count() << " s\n\n";
                    system("pause");
                }
                else throw "Failas \"kursiokai10000.txt\" nerastas\n";
            }
            catch (char const* e)
            {
                cout << e << endl;
            }

            try
            {
                std::ifstream fd("kursiokai100000.txt");
                if (fd)
                {
                    auto startc = std::chrono::high_resolution_clock::now();
                    read_file(sar, f3);
                    sort(sar.begin(), sar.end(), pazymiai_sort);
                    isvestis_2files(sar, a3, b3);
                    auto endc = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double> diffc = endc - startc;
                    cout << "Visas apdorojimu laikas: " << diffc.count() << " s\n\n";
                    system("pause");
                }
                else throw "Failas \"kursiokai100000.txt\" nerastas\n";
            }
            catch (char const* e)
            {
                cout << e << endl;
            }

            try
            {
                std::ifstream fd("kursiokai1000000.txt");
                if (fd)
                {
                    auto startd = std::chrono::high_resolution_clock::now();
                    read_file(sar, f4);
                    sort(sar.begin(), sar.end(), pazymiai_sort);
                    isvestis_2files(sar, a4, b4);
                    auto endd = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double> diffd = endd - startd;
                    cout << "Visas apdorojimu laikas: " << diffd.count() << " s\n\n";
                    system("pause");
                }
                else throw "Failas \"kursiokai1000000.txt\" nerastas\n";
            }
            catch (char const* e)
            {
                cout << e << endl;
            }

            try
            {
                std::ifstream fd("kursiokai10000000.txt");
                if (fd)
                {
                    auto starte = std::chrono::high_resolution_clock::now();
                    read_file(sar, f5);
                    sort(sar.begin(), sar.end(), pazymiai_sort);
                    isvestis_2files(sar, a5, b5);
                    auto ende = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double> diffe = ende - starte;
                    cout << "Visas apdorojimu laikas: " << diffe.count() << " s\n\n";
                }
                else throw "Failas \"kursiokai10000000.txt\" nerastas\n";
            }
            catch (char const* e)
            {
                cout << e << endl;
            }
            break;
        }
        case 2:
        {cout << "Kiek bus studentu?\n";
        cin >> sk;
        do
        {
            if (sk) //tikrinama, ar ivestas skaicius
            {
                if (sk >= 0)
                {
                    continue;
                }
                else //kitaip pranesama apie neteisinga ivesti ir bandoma is naujo gauti teisinga ivesti
                {
                    do
                    {
                        cin.clear();
                        cin.ignore(10000, '\n');
                        cout << "Neteisinga ivestis. Bandykite is naujo.\n";
                        cin >> sk;
                    } while (sk < 0);
                }
            }
            else
            {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Neteisinga ivestis. Bandykite is naujo.\n";
                cin >> sk;
            }
        } while (sk < 0 || !sk);
        cout << "Kiek is viso bus pazymiu? (Iskaitant ir egzaminmo bala)\n";
        cin >> nd;
        do
        {
            if (nd)
            {
                if (nd >= 0 && nd <= 30)
                {
                    continue;
                }
                else
                {
                    do
                    {
                        cin.clear();
                        cin.ignore(10000, '\n');
                        cout << "Neteisinga ivestis. Maksimaliai leidziama 30 pazymiu.\n";
                        cin >> nd;
                    } while (nd < 0 || nd > 30 || !nd);
                }
            }
            else
            {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Neteisinga ivestis. Bandykite is naujo.\n";
                cin >> nd;
            }
        } while (nd < 0 || nd > 30 || !nd);
        a.reserve(sk);
        naujas_failas(zm, nd, sk);
        break;
        }
        default:

            cout << "Neteisinga ivestis. Iveskite 1 arba 2. " << endl;
            cin.clear(); //isvaloma neteisinga ivestis
            cin.ignore(10000, '\n'); //ignoruojama ivestis ir taip apsaugoma nuo string ivesties
            break;
        }
    } while (choice != 1 && choice != 2);
}