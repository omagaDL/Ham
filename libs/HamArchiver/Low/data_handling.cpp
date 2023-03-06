#include "low.h"
void DataHandling(std::ifstream& input, std::ofstream& output, unsigned long long size, unsigned char codeword_length, bool encode, bool parity_bit, unsigned long long max_iter) {
    std::bitset<MAX_MATRIX_LENGTH> temp;
    Buffer buf = {static_cast<unsigned char> (codeword_length + (parity_bit * !encode) - (ceil(log2f(codeword_length))) * (encode) - 1), BIT_SIZE - 1, true};
    Buffer wbuf = {BIT_SIZE - 1, static_cast<unsigned char> (codeword_length + (parity_bit * encode) - (ceil(log2f(codeword_length))) * (!encode) - 1), false};
    char bit;
    for (unsigned long long i = 0; i < size; i++){
        input.get(bit);
        temp = std::bitset<MAX_MATRIX_LENGTH> ( bit ) << MAX_MATRIX_LENGTH - BIT_SIZE >> (MAX_MATRIX_LENGTH - BIT_SIZE);
        buf.Append(temp, output, wbuf, codeword_length, encode, parity_bit, max_iter);
    }
    if (encode) {
        buf.Finish(output, wbuf, codeword_length, encode, parity_bit, max_iter);
    }
}
