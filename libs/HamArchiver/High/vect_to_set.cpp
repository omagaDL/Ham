#include "high.h"
std::set<std::string> VectToSet(std::vector<const char*>& filenames) {
    std::set<std::string> temp;
    for (const char* i: filenames) {
        std::string str(i);
        temp.insert(str);
    }
    return temp;
}