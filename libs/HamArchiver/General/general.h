#include <iostream>
#include <fstream>
#include <bitset>
#include <cmath>
#include <cstring>
#include <string>
#include <set>
#include <filesystem>
#include <vector>
const unsigned long long MAX_FILE_SIZE = 18446744073551615;
const int MAX_MATRIX_LENGTH = 256;
const int MAX_MATRIX_HEIGHT = 8;
const int METADATA_SIZE = 11;
const int BIT_SIZE = 8;
extern unsigned long long ITERATIONS;
extern bool ERROR;
extern std::bitset<MAX_MATRIX_LENGTH> matrix[MAX_MATRIX_HEIGHT];
unsigned long long UnBin (std::bitset<MAX_MATRIX_LENGTH> inp, unsigned long long  size);
unsigned long long Ceiling (unsigned long long a, int b);
void CreateMatrix();