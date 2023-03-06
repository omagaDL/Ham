#include "high.h"
void List(const char* archive) {
    Meta meta;
    unsigned long long archive_size = GetFileSize(archive);
    std::ifstream input(archive, std::ios::binary);
    std::cout << "The archive " << GetFilename(archive) << " contains the following files:" << '\n';
    while((input.tellg() != archive_size) && (input.tellg() != -1)) {
        meta.Get(input);
        std::cout << " - " << meta.filename << '\n';
        input.seekg(static_cast<unsigned long long> (input.tellg()) + GetNewSize(meta.file_size, meta.codeword_length, meta.parity_bit));
    }
    input.close();
}
