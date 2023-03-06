#include "high.h"
std::set<std::string> GetList(const char* archive) {
    std::set<std::string> list;
    Meta meta;
    unsigned long long archive_size = GetFileSize(archive);
    std::ifstream input(archive, std::ios::binary);
    while((input.tellg() != archive_size) && (input.tellg() != -1)) {
        meta.Get(input);
        list.insert(meta.filename);
        input.seekg(static_cast<unsigned long long> (input.tellg()) + GetNewSize(meta.file_size, meta.codeword_length, meta.parity_bit));
    }
    input.close();
    return list;
}
