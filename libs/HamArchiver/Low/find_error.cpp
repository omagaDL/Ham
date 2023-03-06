#include "low.h"
unsigned char FindError(std::bitset<MAX_MATRIX_LENGTH>& inp, unsigned char codeword_length) {
    int parity = static_cast<unsigned char> (ceil(log2f(codeword_length)));
    std::bitset<MAX_MATRIX_LENGTH> out (0);
    for (int i = 0; i < parity; i++) {
        out[i] = (inp & matrix[i]).count() % 2;
    }
    return UnBin(out, parity);
}