#include "low.h"
void Buffer::Finish(std::ofstream& output, Buffer& buf, unsigned char codeword_length, bool encode, bool parity_inp, unsigned long long max_iter) {
    if (buffer_iter) {
        Send(body, output, buf, codeword_length, encode, parity_inp, max_iter);
        if (reading) {
            if (encode) {
                buf.Finish(output, buf, codeword_length, encode, parity_inp, max_iter);
            }
        }
    }
}
