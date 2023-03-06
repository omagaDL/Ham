#include "high.h"
bool ConcatenatingFile(std::ofstream& output, std::ifstream& input, const char* archive, std::set<std::string>& list, Meta& meta) {
    unsigned long long size = GetNewSize(meta.file_size, meta.codeword_length, meta.parity_bit);
    if ((size < meta.file_size) | (size + (METADATA_SIZE + meta.filename_size) * 2 > MAX_FILE_SIZE - GetFileSize(archive))) {
        std::cout << "The file " << meta.filename << " is too large to be appended" << '\n';
        input.seekg(static_cast<unsigned long long> (input.tellg()) + size);
        return false;
    }
    if (list.find(meta.filename) != list.end()) {
        std::cout << "The archive already contains a file with the name "  << meta.filename << '\n';
        input.seekg(static_cast<unsigned long long> (input.tellg()) + size);
        return false;
    }
    char bit;
    std::bitset<MAX_MATRIX_LENGTH> temp;
    meta.Put(output);
    for (unsigned long long i = 0; i < size; i++){
        input.get(bit);
        temp = std::bitset<MAX_MATRIX_LENGTH> ( bit ) << MAX_MATRIX_LENGTH - BIT_SIZE >> MAX_MATRIX_LENGTH - BIT_SIZE;
        Write(temp, output);
    }
    return true;
}
