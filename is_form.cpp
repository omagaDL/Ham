#include "inclusion.h"
bool IsForm(int str) {
    if (str > 255 | str < 0) {
        return false;
    }
    return codewords.find(str) != codewords.end();
}
