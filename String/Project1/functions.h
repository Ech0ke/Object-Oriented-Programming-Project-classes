#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
#include <locale>
#include <sstream>
#include <regex>
#include <iomanip>

using std::string;
using std::vector;
using std::regex;
using std::endl;
using std::setw;
bool yraUrl(string Temp)
{
    bool index = 0;

    if (std::regex_match(Temp, regex("https?:\\/\\/(www\\.)?[-a-zA-Z0-9@:%._\\+~#=]{2,256}\\.[a-z]{2,6}\\b([-a-zA-Z0-9@:%_\\+.~#?&//=]*)")))
        index = 1;
    if (std::regex_match(Temp, regex("[-a-zA-Z0-9@:%._\\+~#=]{2,256}\\.[a-z]{2,6}\\b([-a-zA-Z0-9@:%_\\+.~#?&//=]*)")))
        index = 1;

    return index;
}

string converter(string& Temp)
{
    for (size_t i = 0; i <= Temp.size(); i++)
        if (Temp[i] >= 65 && Temp[i] <= 90)
            Temp[i] = Temp[i] + 32;

    return Temp;
}

string trintiSimbolius(string& Temp)
{
    for (size_t i = 0; i < Temp.size(); i++)
        if (ispunct(Temp[i]))
            Temp.erase(i, 1);

    for (size_t i = 0; i <= Temp.size(); i++)
        if (Temp[i] >= 65 && Temp[i] <= 90)
            Temp[i] = Temp[i] + 32;

    std::size_t found = Temp.find(" ");

    if (found != string::npos)
        Temp.erase(found, 1);

    return Temp;
}

void zodziai(std::map<string, vector<int>>& word, vector<string>& url)
{
    std::ifstream fd("text.txt");
    string line, temp;
    int lineNumber = 1;

    while (!fd.eof())
    {
        std::getline(fd, line);
        std::istringstream x(line);

        while (x >> temp)
        {
            if (yraUrl(temp) == 1)
                url.push_back(temp);
            else
            {
                temp = converter(temp);
                temp = trintiSimbolius(temp);

                if (!temp.empty())
                    word[temp].push_back(lineNumber);
            }
        }

        lineNumber++;
    }

    fd.close();
}

void print(std::map<string, vector<int>>& word, vector<string>& url)
{
    std::ofstream fr("rezultatai.txt");

    if (!url.empty())
    {
        fr << "Rasti URL: \n";
        for (size_t i = 0; i < url.size(); i++)
            fr << url[i] << "\n";
    }
    else
    {
        fr << "URL nerasta\n";
    }

    fr << "\n";
    fr << setw(31) << "|            Zodis            |" << std::left<<setw(9) << " Kartai |"<<setw(40)<<"                Eil. nr."<<"|"<<"\n";
    fr << "---------------------------------------------------------------------------------\n";
    for (auto j = word.begin(); j != word.end(); j++) {
        if (j->second.size() > 1)
        {
            fr << std::left<<setw(30)<<"|"+ j->first <<"|" <<std::right<<setw(8)<< j->second.size()<<"| " ;
            for (size_t x = 0; x < j->second.size(); x++)
                fr << j->second[x] << " ";
            fr << "\n---------------------------------------------------------------------------------\n";
        }
    }

    fr.close();
    std::cout << "Rezultatai isvesti faile \"rezultatai.txt\"\n";
    std::system("pause");
}
