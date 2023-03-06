#include "general.h"
unsigned long long Ceiling(unsigned long long a, int b) {
    return (a + (b - 1)) / b;
}