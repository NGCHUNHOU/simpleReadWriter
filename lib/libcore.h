#ifndef LIBCORE_H
#define LIBCORE_H
#include <string>
#include <chrono>
#include <ctime>
#include <string.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include "../data/datacenter.h"
class libcore
{
private:
public:
    datacenter* data;
    libcore(datacenter* dc);
    std::ifstream readfile(std::string filepath);
    void parsefile(char symbol, std::string dataFilePath);
    std::string findlinebykey(std::string keyword);
    std::string getstrfromline(std::string line);
    std::vector<std::string> parselinestr(int linenumber, char delimiter);
    void writefile(std::string targetfilepath, std::vector<std::string> keywords);
    void cleanfile(std::string targetfilepath);
    void getcurrtime();
};

#endif