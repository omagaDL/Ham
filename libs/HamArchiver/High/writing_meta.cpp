#include "high.h"
void Meta::WritingMeta(std::bitset<MAX_MATRIX_LENGTH> inp, std::ofstream& output, char bytes_quantity) {
    std::bitset<MAX_MATRIX_LENGTH> temp;
    for (unsigned char i = 0; i < bytes_quantity * 2; i++) {
        temp = inp << MAX_MATRIX_LENGTH - (BIT_SIZE / 2) * (i + 1) >> (MAX_MATRIX_LENGTH - (BIT_SIZE / 2));
        Encoding(temp, 7, true);
        Write(temp, output);
    }
}