#include "inclusion.h"
int main(int argc, char** argv) {
    bool_parameters bool_arg;
    parameters arg;
    const option commands[10] = {
            {"--create", false, 'c'},
            {"--file", true, 'f'},
            {"--list", false, 'l'},
            {"--extract", false, 'x'},
            {"--append", false, 'a'},
            {"--delete", false, 'd'},
            {"--concatenate", false, 'A'},
            {"--word", true, 'w'},
            {"--parity", true, 'p'},
            {nullptr, false, ' '}
    };
    std::vector<const char*> files;
    std::vector<std::pair<char, char*>> arguments = Getting(argc, argv, const_cast<option*>(commands), files);
    Handling(arguments, bool_arg, arg, files);
    CreateMatrix();
    Running(bool_arg, arg);
    return 0;
}
