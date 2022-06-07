#include <iostream>
#include <map>
#include <vector>
#include <string>
#include "functions.h"

int main()
{
    std::setlocale(LC_ALL, "Lithuanian");
    std::map <string, vector<int>> word;
    std::vector<string> url;
    zodziai(word, url);
    print(word, url);

    return 0;
}