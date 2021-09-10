#ifndef DATACENTER_H
#define DATACENTER_H
#include <string>
#include <vector>
class datacenter
{
private:
public:
    std::string dataFile = "dataConfig.conf";
    std::string outputFile = "record.txt";
    std::vector<std::string> linetext;
    std::time_t timenow;
    datacenter();
};
#endif