#include "high.h"
bool ExtractingOverwritingDialog(bool call, std::string& filename) {
    if (!call) {
        return true;
    }
    std::cout << filename << " already exists in the directory." << '\n';
    char inp;
    while (true) {
        std::cout << "Do you want to overwrite it? [ y / n ]" << '\n';
        std::cin >> inp;
        if (inp == 'y') {
            return true;
        }
        if (inp == 'n') {
            return false;
        }
    }
}
