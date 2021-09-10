#include "libcore.h"
#include "../data/datacenter.h"
libcore::libcore(datacenter* dc) {
   this->data = dc;
};
std::ifstream libcore::readfile(std::string filepath)
{
  std::ifstream targetfile(filepath);
  return targetfile;
};
void libcore::parsefile(char symbol, std::string dataFilePath)
{
   std::string content;
   std::ifstream datafile(dataFilePath);
   while (std::getline(datafile, content, symbol))
   {
      this->data->linetext.push_back(content);
   };
   datafile.close();
};
std::string libcore::findlinebykey(std::string keyword)
{
   std::vector<std::string> lines = this->data->linetext;
   std::string keyvalue;
   std::vector<std::string> keywords;
   std::stringstream testchunk(lines[0]);
   std::string targetline;
   for (int i=0;i<lines.size();i++)
   {
      if (lines[i].find(keyword) != std::string::npos)
      {
          targetline = lines[i];
      };
   };
   // for (int i=0;i<keywords.size();i++)
   // {
   //    if (keywords[i] == keyword)
   //    {
   //       keyvalue = keywords[i+1];
   //    };
   // };
   return targetline;
   // std::getline(testchunk, keyvalue, ' ');
   // std::cout << keyvalue << std::endl;
   // for (int i=0;i<lines.size();i++)
   // {
   //    if (this->parselinestr(i, ' ')[0] != "")
   //    {
   //        keywords = this->parselinestr(i, ' ');
   //    };
   //    if (keywords[0] == keyword)
   //    {
   //       keyvalue = keywords[1];
   //    };
   // };
   // return keyvalue;
};
std::string libcore::getstrfromline(std::string line)
{
   std::string str;
   std::vector<std::string> splitstring;
   std::stringstream strchunk(line);
   std::string targetvalue;
   while (std::getline(strchunk, str, ' '))
   {
      splitstring.push_back(str);
   };
   splitstring.erase(splitstring.begin());
   for (int i = 0; i < splitstring.size(); i++)
   {
      targetvalue = targetvalue+" "+splitstring[i];
   };
   return targetvalue;
};
std::vector<std::string> libcore::parselinestr(int linenumber, char delimiter)
{
   std::string t = this->data->linetext[linenumber];
   std::stringstream texts(t);
   std::string text;
   std::vector<std::string> stringinline;
   while (std::getline(texts, text, delimiter))
   {
         stringinline.push_back(text);
   }
      return stringinline;
};
void libcore::writefile(std::string targetfilepath, std::vector<std::string> keywords)
{
   std::ofstream targetfile(targetfilepath, std::ios_base::app);
   this->getcurrtime();
   char *t = std::ctime(&this->data->timenow);
   if (t[strlen(t)-1] == '\n') t[strlen(t)-1] = '\0';
   for (int i = 0; i < keywords.size(); i++)
   {
      std::cout << "writing keyword [" << keywords[i] << "] to " << targetfilepath << std::endl;
      targetfile << "[" << t << "]" << this->getstrfromline(this->findlinebykey(keywords[i])) << "\n";
   };
};
void libcore::cleanfile(std::string targetfilepath)
{
  std::ofstream ofs;
  ofs.open(targetfilepath, std::ofstream::out | std::ofstream::trunc);
  ofs.close();
}
void libcore::getcurrtime()
{
   auto start = std::chrono::system_clock::now();
   auto end = std::chrono::system_clock::now();
   std::chrono::duration<double> seconds = end-start;
   std::time_t end_time = std::chrono::system_clock::to_time_t(end);
   this->data->timenow = end_time; 
}