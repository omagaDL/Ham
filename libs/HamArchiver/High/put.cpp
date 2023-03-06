#include "high.h"
void Meta::Put(std::ofstream& output) {
    WritingMeta(std::bitset<MAX_MATRIX_LENGTH> (codeword_length), output, 1);
    WritingMeta(std::bitset<MAX_MATRIX_LENGTH> (parity_bit), output, 1);
    WritingMeta(std::bitset<MAX_MATRIX_LENGTH> (filename_size), output, 1);
    WritingMeta(std::bitset<MAX_MATRIX_LENGTH> (file_size), output, 8);
    for (unsigned char i = 0; i < filename_size; i++) {
        WritingMeta(std::bitset<MAX_MATRIX_LENGTH> (filename[i]), output, 1);
    }
}