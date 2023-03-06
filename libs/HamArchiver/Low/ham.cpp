#include "low.h"
void Ham(std::bitset<MAX_MATRIX_LENGTH>& inp, unsigned char codeword_length) {
    std::bitset<MAX_MATRIX_LENGTH> out (0);
    int parity = static_cast<int> (ceil(log2f(codeword_length)));
    int out_iter = 0;
    int inp_iter = 0;
    for (int i = 0; i <= parity; i++) {
        while (out_iter + 1 != static_cast<int> (pow(2, i))) {
            out[out_iter] = inp[inp_iter];
            inp_iter++;
            out_iter++;
        }
        out_iter++;
    }
    for (int i = 0; i < parity; i++) {
        out[static_cast<int>(pow(2, i)) - 1] = (out & matrix[i]).count() % 2;
    }
    inp = out;
}