#include "low.h"
void Buffer::Append(std::bitset<MAX_MATRIX_LENGTH>& inp, std::ofstream& output, Buffer& buf, unsigned char codeword_length, bool encode, bool parity_inp, unsigned long long max_iter) {
    std::bitset<MAX_MATRIX_LENGTH> temp;
    if (input_size >= size) {
        temp = body | (inp << MAX_MATRIX_LENGTH - ((size + 1) - buffer_iter) >> (MAX_MATRIX_LENGTH - (size + 1)));
        Send(temp, output, buf, codeword_length, encode, parity_inp, max_iter);
        for (int i = 0; i < ((input_size + 1) - ((size + 1) - buffer_iter)) / (size + 1); i++) {
            temp = inp >> ((size + 1) - buffer_iter) << MAX_MATRIX_LENGTH - (size + 1) * (i + 1) >> (MAX_MATRIX_LENGTH - (size + 1));
            Send(temp, output, buf, codeword_length, encode, parity_inp, max_iter);
        }
        buffer_iter = ((input_size + 1) - ((size + 1) - buffer_iter)) % (size + 1);
        body = inp >> ((input_size + 1) - buffer_iter);
    }
    else {
        if (buffer_iter + input_size <= size) {
            body = body | (inp << buffer_iter);
            buffer_iter = (buffer_iter + (input_size + 1)) % (size + 1);
        }
        else {
            temp = body | (inp << MAX_MATRIX_LENGTH - ((input_size + 1) - (buffer_iter + (input_size + 1)) % (size + 1)) >> (MAX_MATRIX_LENGTH - (size + 1)));
            Send(temp, output, buf, codeword_length, encode, parity_inp, max_iter);
            buffer_iter = (buffer_iter + (input_size + 1)) % (size + 1);
            body = inp >> ((input_size + 1) - buffer_iter);
        }
        if (!buffer_iter) {
            temp = body;
            Send(temp, output, buf, codeword_length, encode, parity_inp, max_iter);
            body = body >> MAX_MATRIX_LENGTH;
        }
    }
}
