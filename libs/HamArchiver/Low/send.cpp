#include "low.h"
void Buffer::Send(std::bitset<MAX_MATRIX_LENGTH>& temp, std::ofstream& output, Buffer& buf, unsigned char codeword_length, bool encode, bool parity_inp, unsigned long long max_iter) {
    if (reading) {
        WhatToDo(temp, codeword_length, encode, parity_inp);
        buf.Append(temp, output, buf, codeword_length, encode, parity_inp, max_iter);
    }
    else {
        Write(temp, output, max_iter);
    }
}
