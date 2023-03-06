#include "low.h"
void WhatToDo(std::bitset<MAX_MATRIX_LENGTH>& inp, unsigned char codeword_length, bool encode,  bool parity_bit) {
    if (encode) {
        Encoding(inp, codeword_length, parity_bit);
    }
    else {
        Decoding(inp, codeword_length, parity_bit);
    }
}