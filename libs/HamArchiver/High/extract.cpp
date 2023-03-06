#include "high.h"
void Extract(const char* archive, std::vector<const char*>& filenames) {
    std::vector<std::string> must_be_deleted;
    if (filenames.size()) {
        for (const char* filename : filenames) {
            Extracting(archive, filename, must_be_deleted);
        }
    }
    else {
        Extracting(archive, " ", must_be_deleted, true);
    }
    std::vector<const char*> temp;
    for (int i = 0; i < must_be_deleted.size(); i++){
        temp.push_back(must_be_deleted[i].c_str());
    }
    Delete(archive, temp, true);
}
