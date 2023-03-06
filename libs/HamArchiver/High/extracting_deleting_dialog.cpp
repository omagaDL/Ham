#include "high.h"
bool ExtractingDeletingDialog(bool call, std::string& filename) {
    if (!call) {
        return false;
    }
    std::cout << "The file " << filename << " was corrupted." << '\n';
    char inp;
    while (true) {
        std::cout << "Do you want to delete it? [ y / n ]" << '\n';
        std::cin >> inp;
        if (inp == 'y') {
            return true;
        }
        if (inp == 'n') {
            return false;
        }
    }
}
