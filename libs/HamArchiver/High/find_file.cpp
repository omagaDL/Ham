#include "high.h"
bool FindFile(std::ifstream& input, Meta& meta, unsigned long long archive_size, const char* filename) {
    while((input.tellg() != archive_size) | (input.tellg() != archive_size)) {
        meta.Get(input);
        if (filename == meta.filename) {
            return true;
        }
        input.seekg(static_cast<unsigned long long> (input.tellg()) + GetNewSize(meta.file_size, meta.codeword_length, meta.parity_bit));
    }
    return false;
}
