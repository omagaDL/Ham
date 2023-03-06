#include "high.h"
std::bitset<MAX_MATRIX_LENGTH> Meta::ReadingMeta(std::ifstream& input, char bytes_quantity) {
    std::bitset<MAX_MATRIX_LENGTH> temp;
    std::bitset<MAX_MATRIX_LENGTH> out;
    std::bitset<MAX_MATRIX_LENGTH> inp;
    char bit;
    for (unsigned char i = 0; i < bytes_quantity * 2; i++) {
        input.get(bit);
        temp = std::bitset<MAX_MATRIX_LENGTH>(bit) << MAX_MATRIX_LENGTH - BIT_SIZE >> (MAX_MATRIX_LENGTH - BIT_SIZE);
        Decoding(temp, 7, true);
        out = out | (temp << (BIT_SIZE / 2) * i);
    }
    return out;
}
