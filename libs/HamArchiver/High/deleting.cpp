#include "high.h"
void Deleting(std::ifstream& input, std::ofstream& output, std::set<std::string>& must_be_deleted) {
    Meta meta;
    char bit;
    std::bitset<MAX_MATRIX_LENGTH> temp;
    meta.Get(input);
    unsigned long long size = GetNewSize(meta.file_size, meta.codeword_length, meta.parity_bit);
    if (must_be_deleted.find(meta.filename) == must_be_deleted.end()) {
        meta.Put(output);
        for (unsigned long long i = 0; i < size; i++){
            input.get(bit);
            temp = std::bitset<MAX_MATRIX_LENGTH> ( bit ) << MAX_MATRIX_LENGTH - BIT_SIZE >> (MAX_MATRIX_LENGTH - BIT_SIZE);
            Write(temp, output);
        }
    }
    else {
        input.seekg(static_cast<unsigned long long> (input.tellg()) + size);
    }
}