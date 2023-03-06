#include "low.h"
void Encoding(std::bitset<MAX_MATRIX_LENGTH>& inp, unsigned char codeword_length,  bool parity_bit) {
    Ham(inp, codeword_length);
    if (parity_bit) {
        inp[codeword_length] = inp.count() % 2;
    }
}