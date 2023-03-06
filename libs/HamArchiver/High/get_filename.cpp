#include "high.h"
std::string GetFilename(const char* path) {
    std::string filename;
    for (int i = 0; i < strlen(path); i++) {
        filename.push_back(path[i]);
        if (path[i] == '\\') {
            filename.clear();
        }
    }
    return filename;
}