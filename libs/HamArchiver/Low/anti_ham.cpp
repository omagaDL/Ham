#include "low.h"
void AntiHam(std::bitset<MAX_MATRIX_LENGTH>& inp, unsigned char codeword_length) {
    std::bitset<MAX_MATRIX_LENGTH> out (0);
    unsigned char parity = static_cast<unsigned char> (ceil(log2f(codeword_length)));
    unsigned char out_iter = 0;
    unsigned char inp_iter = 0;
    for (int i = 0; i <= parity; i++) {
        while (inp_iter + 1 != static_cast<int> (pow(2, i))) {
            out[out_iter] = inp[inp_iter];
            inp_iter++;
            out_iter++;
        }
        inp_iter++;
    }
    inp = out;
}