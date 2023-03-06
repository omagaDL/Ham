#include "high.h"
unsigned long long GetFileSize(const char* filename) {
    std::ifstream file(filename, std::ios::binary | std::ios::ate);
    unsigned long long size = file.tellg();
    file.close();
    return size;
}