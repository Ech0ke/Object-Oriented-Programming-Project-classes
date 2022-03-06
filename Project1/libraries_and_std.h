#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::vector;
using std::setw;
using std::left;
using std::right;
using std::mt19937;
using std::stringstream;
using hrClock = std::chrono::high_resolution_clock;
typedef std::uniform_int_distribution<int>  int_distribution;