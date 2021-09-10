#include <iostream>
#include <vector>
#include "./lib/libcore.h"
#include "./data/datacenter.h"
#include <sstream> 
#include <string.h> 
int main(int argc, char** argv)
{
   datacenter d;
   libcore core(&d);
   char symbol = '\n';
   char clientinput[256];
   std::string strclient;
   char pausebtn;
   if (strcmp(argv[argc-1], "clean") == 0)
   {
      core.cleanfile(d.outputFile);
   } else {
      pausebtn = 'y';
   };
   std::vector<std::string> keywordarr {};
   std::string clientinputsplit;
   while (pausebtn == 'y')
   {
         std::cout << "your keyword is: " << std::endl;
         std::cin.getline(clientinput, 256);
         std::cout << "continue? (y/n) " << std::endl;
         std::cin >> pausebtn;
         strclient = clientinput;
         std::stringstream c(strclient);
      while (std::getline(c, clientinputsplit, ' '))
      {
         keywordarr.push_back(clientinputsplit);
      }
   }
   core.parsefile(symbol, d.dataFile);
   core.writefile(d.outputFile, keywordarr);
};