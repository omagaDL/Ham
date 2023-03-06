#include "high.h"
std::string GetPath(const char* path) {
    std::string new_path(path);
    for (int i = new_path.length() - 1; i >= 0 ; i--) {
        if (new_path[i] == '\\') {
            break;
        }
        new_path.pop_back();
    }
    return new_path;
}