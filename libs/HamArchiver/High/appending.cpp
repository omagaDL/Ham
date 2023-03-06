#include "high.h"
bool Appending (std::ofstream& output, const char* archive, const char* file, std::set<std::string>& list, unsigned char codeword_length, bool parity_bit) {
    Meta meta;
    meta.file_size = GetFileSize(file);
    meta.filename = GetFilename(file);
    meta.filename_size = meta.filename.size();
    meta.parity_bit = parity_bit;
    meta.codeword_length = codeword_length;
    unsigned long long size = GetNewSize(meta.file_size, meta.codeword_length, meta.parity_bit);
    if ((size < meta.file_size) | (size + (METADATA_SIZE + meta.filename_size) * 2 > MAX_FILE_SIZE - GetFileSize(archive))) {
        std::cout << "The file " << meta.filename << " is too large to be appended" << '\n';
        return false;
    }
    if (list.find(meta.filename) != list.end()) {
        std::cout << "The archive already contains a file with the name "  << meta.filename << '\n';
        return false;
    }
    std::ifstream input(file, std::ios::binary);
    meta.Put(output);
    DataHandling(input, output, meta.file_size, meta.codeword_length, true, meta.parity_bit, 0);
    input.close();
    return true;
}