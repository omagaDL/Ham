#include "high.h"
unsigned long long GetNewSize(unsigned long long file_size, unsigned char codeword_length, bool parity_bit) {
    unsigned char enc_codeword_length = codeword_length - ceil(log2f(codeword_length)) - 1;
    unsigned char dec_codeword_length = codeword_length + parity_bit - 1;
    return Ceiling(Ceiling(file_size * 8, enc_codeword_length + 1) * (dec_codeword_length + 1), 8);
}
