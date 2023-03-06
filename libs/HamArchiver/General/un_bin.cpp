#include "general.h"
unsigned long long UnBin(std::bitset<MAX_MATRIX_LENGTH> inp, unsigned long long  size) {
    unsigned long long  out = 0;
    for (unsigned long long  i = 0; i < size; i++) {
        out += inp[i] * static_cast<unsigned long long>(pow(2, i));
    }
    return out;
}