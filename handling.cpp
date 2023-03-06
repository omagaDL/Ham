#include "inclusion.h"
void Handling(std::vector<std::pair<char, char*>>& arguments, bool_parameters& bool_arg, parameters& arg, std::vector<const char*>& free) {
    char optchar;
    char* optarg;
    for (int argument = 0; argument < arguments.size(); argument++) {
        optchar = arguments[argument].first;
        optarg = arguments[argument].second;
        switch (optchar) {
            case 'c': {
                bool_arg.bools[0] = true;
                break;
            }
            case 'f': {
                bool_arg.bools[1] = true;
                arg.file = optarg;
                break;
            }
            case 'l': {
                bool_arg.bools[2] = true;
                break;
            }
            case 'x': {
                bool_arg.bools[3] = true;
                break;
            }
            case 'a': {
                bool_arg.bools[4] = true;
                break;
            }
            case 'd': {
                bool_arg.bools[5] = true;
                break;
            }
            case 'A': {
                bool_arg.bools[6] = true;
                break;
            }
            case 'w': {
                bool_arg.bools[7] = true;
                if (!IsDigit(optarg)) {
                    std::cout << "The length of the codeword must be a number from 3 to 255 inclusive, and have the form 2^n - 1" << "\n";
                    exit(1);
                }
                if (!IsForm(std::stoi(optarg))) {
                    std::cout << "The length of the codeword must be a number from 3 to 255 inclusive, and have the form 2^n - 1" << "\n";
                    exit(1);
                }
                arg.codeword_length = static_cast<unsigned char> (std::stoi(optarg));
                break;
            }
            case 'p': {
                bool_arg.bools[8] = true;
                if (!IsDigit(optarg)) {
                    std::cout << "The presence of an additional parity bit must be specified as 0 or 1" << "\n";
                    exit(1);
                }
                if (std::stoi(optarg) != 1 && std::stoi(optarg) != 0) {
                    std::cout << "The presence of an additional parity bit must be specified as 0 or 1" << "\n";
                    exit(1);
                }
                arg.parity_bit = static_cast<bool> (std::stoi(optarg));
                break;
            }
            case '?': {
                std::cout << "Unknown option\n";
                break;
            }
            default: {
                break;
            }
        }
    }
    if (!bool_arg.bools[1]) {
        std::cout << "The archive is not specified" << "\n";
        exit(1);
    }
    int only_one = bool_arg.bools.count() - bool_arg.bools[7] - bool_arg.bools[8];
    if (only_one != 2) {
        if (only_one == 1) {
            std::cout << "The operation must be specified" << "\n";
        }
        else {
            std::cout << "The application can only perform one operation per request" << "\n";
        }
        exit(1);
    }
    if (GetExtension(arg.file) != "haf") {
        std::cout << GetFilename(arg.file) << " is not an .haf archive" << '\n';
        exit(1);
    }
    if (!bool_arg.bools[0] && !std::filesystem::exists(arg.file)) {
        std::cout << "The archive " << arg.file << " does not exist" << "\n";
        exit(1);
    }
    if (bool_arg.bools[0] && std::filesystem::exists(arg.file)) {
        std::cout << "The archive " << arg.file << " already exist" << "\n";
        exit(1);
    }
    for (const char* filename : free) {
        if (!(bool_arg.bools[3] | bool_arg.bools[5])) {
            if (!std::filesystem::exists(filename)) {
                std::cout << "The file " << filename << " does not exist" << "\n";
            }
            else {
                arg.filenames.push_back(filename);
            }
        }
        else {
            arg.filenames.push_back(filename);
        }
    }
}
