#include "high.h"
void Meta::Get(std::ifstream& input) {
    codeword_length = UnBin(ReadingMeta(input, 1), 1 * BIT_SIZE);
    parity_bit = UnBin(ReadingMeta(input, 1), 1 * BIT_SIZE);
    filename_size = UnBin(ReadingMeta(input, 1), 1 * BIT_SIZE);
    file_size = UnBin(ReadingMeta(input, 8), 8 * BIT_SIZE);
    filename.resize(filename_size);
    for (unsigned char i = 0; i < filename_size; i++) {
        filename[i] = static_cast<char> (UnBin(ReadingMeta(input, 1), 1 * BIT_SIZE));
    }
}