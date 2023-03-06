#include "low.h"
void Decoding(std::bitset<MAX_MATRIX_LENGTH>& inp, unsigned char codeword_length,  bool parity_bit) {
    bool to_be_continued = !ERROR;
    int error = FindError(inp, codeword_length);
    if (!parity_bit) {
        if (error) {
            inp = inp.flip(error - 1);
        }
    }
    else {
        if (error) {
            if (inp.count() % 2) {
                inp = inp.flip(error - 1);
            }
            else {
                to_be_continued = false;
            }
        }
    }
    AntiHam(inp, codeword_length);
    ERROR = !to_be_continued;
}