#include "general.h"
unsigned long long ITERATIONS = 0;
bool ERROR = false;
std::bitset<MAX_MATRIX_LENGTH> matrix[MAX_MATRIX_HEIGHT];
void CreateMatrix() {
    for (int i = 0; i < MAX_MATRIX_HEIGHT; i++) {
        std::bitset<MAX_MATRIX_LENGTH> temp (0);
        int bin = static_cast<int> (pow(2, i));
        int j = bin - 1;
        while (j < MAX_MATRIX_LENGTH - 1) {
            for(int k = 0; k < bin; k++) {
                temp[j] = true;
                j++;
            }
            j += bin;
        }
        matrix[i] = temp;
    }
}