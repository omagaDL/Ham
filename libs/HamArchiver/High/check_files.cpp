#include "high.h"
bool CheckFiles(std::set<std::string>& must_be_deleted, const char* archive) {
    bool any = false;
    std::set<std::string> files = GetList(archive);
    for (std::string filename : must_be_deleted) {
        if (files.find(filename) != files.end()) {
            any = true;
        }
        else {
            std::cout << "There is no file " << filename << " in the archive " << GetFilename(archive) << '\n';
        }
    }
    return any;
}