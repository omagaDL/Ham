#include <bitset>
#include <set>
#include <iostream>
#include <fstream>
#include <experimental/filesystem>
#include "libs/GetOptions/get_options.h"
#include "libs/HamArchiver/ham_archiver.h"
const int NUMBER_OF_ARGUMENTS = 9;
const std::set<int> codewords = {3, 7, 15, 31, 63, 127, 255};
struct bool_parameters {
    std::bitset<NUMBER_OF_ARGUMENTS> bools = std::bitset<NUMBER_OF_ARGUMENTS> ( 0 );
};
struct parameters {
    char* file;
    bool parity_bit = true;
    unsigned char codeword_length = 7;
    std::vector<const char *> filenames;
};
bool IsDigit(char* str);
bool IsForm(int str);
void Handling(std::vector<std::pair<char, char*>>& arguments, bool_parameters& bool_arg, parameters& arg, std::vector<const char*>& free);
void Running(bool_parameters& bool_arg, parameters& arg);