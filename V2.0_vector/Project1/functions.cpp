﻿#include "studentas.h"
void ivestis(Studentas& temp)
{
    int nd, egzam;
    string choice; //namu darbu rezultatu ivesties pasirinkimas
    int i = 0;
    string stop; //Triggeris, kuris parodys, kada vartotojas jau nebenori toliau ivedineti namu darbu rezultatu
    string vardas, pavarde;
    cout << "Iveskite varda: "; cin >> vardas;
    temp.setVardas(vardas);
    cout << "Iveskite pavarde: "; cin >> pavarde;
    temp.setPavarde(pavarde);
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
                if (nd >= 0 && nd <= 10) //tikrinama, ar pazymys yra nuo 0 iki 10
                {

                    temp.setNd(nd); //pazymys pridedamas i vector konteineri
                    temp.addSum(nd); //sumuojami pazymiai
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
            cout << "Iveskite egzamino iverti: "; cin >> egzam;
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
        temp.setEgz(egzam); //ivestas egzamino balas issaugomas strukturoje


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
                    temp.setNd(nd); //pazymys pridedamas i vector konteineri
                    temp.addSum(nd);
                }
                cout << "Sugeneruoti pazymiai: ";
                for (int i = 0; i < temp.sizeNd(); i++)
                {
                    cout << temp.getNd(i) << " ";
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
        temp.setEgz(egzam); //Balas priskiramas studentui
    }
}
void isvestis(Studentas& temp)
{

    cout << setw(20) << temp.getVardas() << setw(20) << temp.getPavarde() << setw(17) << std::fixed << std::setprecision(2) << temp.getRez()
        << temp.getMed() << endl;
}
void isvestis_file(vector <Studentas>& temp)
{

    std::ofstream out_f("Rezultatai.txt");
    stringstream output;
    out_f << left << setw(20) << "Vardas" << left << setw(20) << "Pavarde" << "Galutinis vid. " << "/ Galutinis med.\n";
    out_f << "-------------------------------------------------------------------------\n";
    for (int i = 0; i < temp.size(); i++)
    {
        output << left << setw(20) << temp.at(i).getVardas() << left << setw(20) << temp.at(i).getPavarde() << std::fixed << std::setprecision(2) << setw(17) << temp.at(i).getRez() << std::fixed << std::setprecision(2) << setw(20) << temp.at(i).getMed() << "\n";
    }
    out_f << output.str();
    out_f.close();
    cout << "Rezultatai isvesti faile Rezultatai.txt\n";
}
void isvestis_med(Studentas& temp)
{
    cout << setw(20) << temp.getVardas() << setw(20) << temp.getPavarde() << setw(17) << std::fixed << std::setprecision(2) << temp.getMed() << endl;
}
void isvestis_vid(Studentas& temp)
{
    cout << setw(20) << temp.getVardas() << setw(20) << temp.getPavarde() << setw(17) << std::fixed << std::setprecision(2) << temp.getRez() << endl;
}
void vidurkis(Studentas & temp)
{
    size_t nd_sk = temp.sizeNd(); //kiek yra namu darbu pazymiu
    double nd_vid;
    if (nd_sk != 0)
    {
        nd_vid = (double)temp.getSum() / nd_sk; //skaicuojamas vidurkis
    }
    else nd_vid = 0;
    double rez = 0.4 * nd_vid + 0.6 * temp.getEgz(); //skaiciuojamas galutinis balas
    temp.setRez(rez);
}
void mediana(Studentas & temp)
{
    double med;
    if (temp.sizeNd() >= 1)
    {
        temp.sortNd(); //isrusiuojamas vector konteineris didejimo tvarka
        if (temp.sizeNd() % 2 == 0) //jei yra lyginis skaicius elementy
        {
            med = (temp.getNd(temp.sizeNd() / 2 - 1) + temp.getNd(temp.sizeNd() / 2)) / 2; //sudedami 2 viduriniai elementai ir dalinama is 2
        }
        else //jei nelyginis skaicius elementu, paimamas vidurinis elementas
        {
            med = temp.getNd(temp.sizeNd() / 2);
        }
    }
    else
    {
        med = 0;
    }
    temp.setMed(0.4 * med + 0.6 * temp.getEgz()); //skaiciuojamas galutinis balas
}
bool vardas_sort(const Studentas& a, const Studentas& b)
{
    if (a.getVardas() == b.getVardas())
    return a.getPavarde() < b.getPavarde();
    return a.getVardas() < b.getVardas();
}
bool pazymiai_sort(const Studentas& a, const Studentas& b)
{
    if (a.getRez() == b.getRez()) return a.getPavarde() < b.getPavarde();
    return a.getRez() > b.getRez();
}
void gen_map(zmogus& temp)
{

    mt19937 mt(static_cast<long unsigned int>(hrClock::now().time_since_epoch().count()));
    int_distribution dist(100, 129);
    map<int, string> vardai, pavardes_m, pavardes_v;
    vardai[100] = "Irma";
    vardai[101] = "Alma";
    vardai[102] = "Irena";
    vardai[103] = "Egle";
    vardai[104] = "Jolanta";
    vardai[105] = "Roze";
    vardai[106] = "Kornelija";
    vardai[107] = "Laima";
    vardai[108] = "Vaiva";
    vardai[109] = "Vaida";
    vardai[110] = "Ugne";
    vardai[111] = "Gabija";
    vardai[112] = "Gabriele";
    vardai[113] = "Karina";
    vardai[114] = "Ona";
    vardai[115] = "Petras";
    vardai[116] = "Jonas";
    vardai[117] = "Ignas";
    vardai[118] = "Darius";
    vardai[119] = "Simas";
    vardai[120] = "Marius";
    vardai[121] = "Aidas";
    vardai[122] = "Matas";
    vardai[123] = "Sigitas";
    vardai[124] = "Julius";
    vardai[125] = "Benas";
    vardai[126] = "Paulius";
    vardai[127] = "Tadas";
    vardai[128] = "Vytas";
    vardai[129] = "Antanas";

    pavardes_m[200] = "Pavardaite1";
    pavardes_m[201] = "Pavardaite2";
    pavardes_m[202] = "Pavardaite3";
    pavardes_m[203] = "Pavardaite4";
    pavardes_m[204] = "Pavardaite5";
    pavardes_m[205] = "Pavardaite6";
    pavardes_m[206] = "Pavardaite7";
    pavardes_m[207] = "Pavardaite8";
    pavardes_m[208] = "Pavardaite9";
    pavardes_m[209] = "Pavardaite10";
    pavardes_m[210] = "Pavardaite11";
    pavardes_m[211] = "Pavardaite12";
    pavardes_m[212] = "Pavardaite13";
    pavardes_m[213] = "Pavardaite14";
    pavardes_m[214] = "Pavardaite15";
    pavardes_m[215] = "Pavardaite16";
    pavardes_m[216] = "Pavardaite17";
    pavardes_m[217] = "Pavardaite18";
    pavardes_m[218] = "Pavardaite19";
    pavardes_m[219] = "Pavardaite20";
    pavardes_m[220] = "Pavardaite21";
    pavardes_m[221] = "Pavardaite22";
    pavardes_m[222] = "Pavardaite23";
    pavardes_m[223] = "Pavardaite24";
    pavardes_m[224] = "Pavardaite25";
    pavardes_m[225] = "Pavardaite26";
    pavardes_m[226] = "Pavardaite27";
    pavardes_m[227] = "Pavardaite28";
    pavardes_m[228] = "Pavardaite29";
    pavardes_m[229] = "Pavardaite30";

    pavardes_v[300] = "Pavardenis1";
    pavardes_v[301] = "Pavardenis2";
    pavardes_v[302] = "Pavardenis3";
    pavardes_v[303] = "Pavardenis4";
    pavardes_v[304] = "Pavardenis5";
    pavardes_v[305] = "Pavardenis6";
    pavardes_v[306] = "Pavardenis7";
    pavardes_v[307] = "Pavardenis8";
    pavardes_v[308] = "Pavardenis9";
    pavardes_v[309] = "Pavardenis10";
    pavardes_v[310] = "Pavardenis11";
    pavardes_v[311] = "Pavardenis12";
    pavardes_v[312] = "Pavardenis13";
    pavardes_v[313] = "Pavardenis14";
    pavardes_v[314] = "Pavardenis15";
    pavardes_v[315] = "Pavardenis16";
    pavardes_v[316] = "Pavardenis17";
    pavardes_v[317] = "Pavardenis18";
    pavardes_v[318] = "Pavardenis19";
    pavardes_v[319] = "Pavardenis20";
    pavardes_v[320] = "Pavardenis21";
    pavardes_v[321] = "Pavardenis22";
    pavardes_v[322] = "Pavardenis23";
    pavardes_v[323] = "Pavardenis24";
    pavardes_v[324] = "Pavardenis25";
    pavardes_v[325] = "Pavardenis26";
    pavardes_v[326] = "Pavardenis27";
    pavardes_v[327] = "Pavardenis28";
    pavardes_v[328] = "Pavardenis29";
    pavardes_v[329] = "Pavardenis30";

    temp.setVardas(vardai[dist(mt)]);

    switch (*temp.getVardas().rbegin()) 
    {
    case 's':
        temp.setPavarde(pavardes_v[200 + dist(mt)]);
        break;
    default:
        temp.setPavarde(pavardes_m[100 + dist(mt)]);
        break;
    };
}
void naujas_failas(zmogus zm, int nd, int sk)
{
    std::ofstream out_f("kursiokai.txt");
    stringstream output;
    mt19937 mt(static_cast<long unsigned int>(hrClock::now().time_since_epoch().count()));
    int_distribution val(0, 10);
    int pazym;
    output << left << setw(20) << "Vardas" << left << setw(20) << "Pavarde";

    for (int i = 0; i < nd - 1; i++)
    {
        auto number = "ND" + std::to_string(i + 1);
        output << left << setw(5) << number;
    }
    output << left << setw(5) << "Egz" << "\n";
    for (int i = 0; i < sk; i++)
    {
        gen_map(zm);
        output << left << setw(20) << zm.getVardas() << setw(20) << zm.getPavarde();
        for (int j = 0; j < nd; j++)
        {
            pazym = val(mt);
            output << left << setw(5) << pazym;
        }
        output << "\n";
    }
    out_f << output.str();
    out_f.close();
    cout << "Sugeneruotas failas kursiokai.txt\n";
}

void read_file(vector <Studentas>& sar, string a)
{
    
    Studentas st;
    string line, vardas, pavarde;
    int nd, egz, lines;
    auto start = std::chrono::high_resolution_clock::now(); auto stt = start;
    std::ifstream fd(a);
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
        my_buffer >> vardas;
        st.setVardas(vardas);
        my_buffer >> pavarde;
        st.setPavarde(pavarde);
        for (int i = 0; i < how_many_columns - 3; i++)
        {

            my_buffer >> nd;
            st.setNd(nd);
            st.addSum(nd);

        }
        my_buffer >> egz;
        st.setEgz(egz);
        vidurkis(st);
        mediana(st);
        st.setSum(0);
        st.clearND();
        sar.push_back(st);

    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    cout << "Failo is " << lines << " eiluciu nuskaitymas ir sudejimas i vektoriu uztruko : " << diff.count() << " s\n";
}

void isvestis_2files(vector <Studentas>& temp, string a, string b)
{
    stringstream output;
    vector <Studentas> bad;
    int dydis = temp.size();
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = dydis - 1; i >= 0; i--)
    {
        if (temp.at(i).getRez() < 5)
        {
            bad.push_back(temp.at(i));
            temp.pop_back();
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    cout << dydis << " irasu dalijimas i dvi grupes uztruko: " << diff.count() << " s\n";
    std::ofstream out_f(a);
    out_f << left << setw(21) << "Vardas" << left << setw(21) << "Pavarde" << "Galutinis vid. " << "/ Galutinis med.\n";
    out_f << "-------------------------------------------------------------------------\n";
    for (int i = 0; i < bad.size(); i++)
    {
        output << left << setw(20) << bad.at(i).getVardas() << left << setw(20) << bad.at(i).getPavarde() << std::fixed << std::setprecision(2) << setw(17) << bad.at(i).getRez() << std::fixed << std::setprecision(2) << setw(20) << bad.at(i).getMed() << "\n";
    }
    out_f << output.str();
    out_f.close();
    bad.clear();
    output.clear();
    stringstream output2;
    std::ofstream out_f2(b);
    out_f2 << left << setw(21) << "Vardas" << left << setw(21) << "Pavarde" << "Galutinis vid. " << "/ Galutinis med.\n";
    out_f2 << "-------------------------------------------------------------------------\n";
    for (int i = temp.size() - 1; i >= 0; i--)
    {
        output2 << left << setw(20) << temp.at(i).getVardas() << left << setw(20) << temp.at(i).getPavarde() << std::fixed << std::setprecision(2) << setw(17) << temp.at(i).getRez() << std::fixed << std::setprecision(2) << setw(20) << temp.at(i).getMed() << "\n";
    }
    out_f2 << output2.str();
    out_f2.close();
    temp.clear();
    output2.clear();
}


