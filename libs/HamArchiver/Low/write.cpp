#include "low.h"
void Write(std::bitset<MAX_MATRIX_LENGTH>& inp, std::ofstream& output, unsigned long long max_iter) {
    if (max_iter) {
        if (ITERATIONS != max_iter) {
            output << static_cast<char> (UnBin(inp, BIT_SIZE));
            ITERATIONS++;
        }
    }
    else {
        ITERATIONS++;
        output << static_cast<char> (UnBin(inp, BIT_SIZE));
    }
}