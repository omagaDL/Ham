#include "../General/general.h"
void Ham(std::bitset<MAX_MATRIX_LENGTH>& inp, unsigned char codeword_length);
void Encoding(std::bitset<MAX_MATRIX_LENGTH>& inp, unsigned char codeword_length,  bool parity_bit);
unsigned char FindError(std::bitset<MAX_MATRIX_LENGTH>& inp, unsigned char codeword_length);
void AntiHam(std::bitset<MAX_MATRIX_LENGTH>& inp, unsigned char codeword_length);
void Decoding(std::bitset<MAX_MATRIX_LENGTH>& inp, unsigned char codeword_length,  bool parity_bit);
void WhatToDo(std::bitset<MAX_MATRIX_LENGTH>& inp, unsigned char codeword_length, bool encode,  bool parity_bit);
void Write(std::bitset<MAX_MATRIX_LENGTH>& inp, std::ofstream& output, unsigned long long max_iter = 0);
struct Buffer {
    std::bitset<MAX_MATRIX_LENGTH> body;
    unsigned char buffer_iter = 0;
    unsigned char size;
    unsigned char input_size;
    bool reading;
    Buffer(unsigned char size, unsigned char input_size, bool reading): size(size), input_size(input_size), reading(reading) {}
    void Append(std::bitset<MAX_MATRIX_LENGTH>& inp, std::ofstream& output, Buffer& buf, unsigned char codeword_length, bool encode, bool parity_inp, unsigned long long max_iter = 0);
    void Finish(std::ofstream& output, Buffer& buf, unsigned char codeword_length, bool encode, bool parity_inp, unsigned long long max_iter = 0);
    void Send(std::bitset<MAX_MATRIX_LENGTH>& temp, std::ofstream& output, Buffer& buf, unsigned char codeword_length, bool encode, bool parity_inp, unsigned long long max_iter = 0);
};
void DataHandling(std::ifstream& input, std::ofstream& output, unsigned long long size, unsigned char codeword_length, bool encode, bool parity_bit, unsigned long long max_iter = 0);

