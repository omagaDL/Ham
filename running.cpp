#include "inclusion.h"
void Running (bool_parameters& bool_arg, parameters& arg) {
    if (bool_arg.bools[0]) {
        Create(arg.file);
    }
    else if (bool_arg.bools[2]) {
        List(arg.file);
    }
    else if (bool_arg.bools[3]) {
        Extract(arg.file, arg.filenames);
    }
    else if (bool_arg.bools[4]) {
        Append(arg.file, arg.filenames, arg.codeword_length, arg.parity_bit);
    }
    else if (bool_arg.bools[5]) {
        Delete(arg.file, arg.filenames);
    }
    else if (bool_arg.bools[6]) {
        Concatenate(arg.file, arg.filenames);
    }
}