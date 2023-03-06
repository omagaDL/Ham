#include "inclusion.h"
bool IsDigit(char* str) {
    for (int symbol = 0; symbol < strlen(str); symbol++) {
        if (!std::isdigit(str[symbol])) {
            return false;
        }
    }
    return true;
}
