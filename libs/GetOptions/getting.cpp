#include "get_options.h"
std::vector<std::pair<char, char*>> Getting(int argc, char** argv, option* opts, std::vector<const char*>& free) {
    int argument = 1;
    std::vector<std::pair<char, char*>> out;
    std::queue<char> order;
    int arglen;
    while (argument < argc) {
        arglen = strlen(argv[argument]);
        if (argv[argument][0] == '-') {
            if (!argv[argument][1]) {
                Choose(order, free, argv[argument], out);
            }
            else if (argv[argument][1] == '-') { // long names
                bool is_complex = false;
                for (int i = 1; i < arglen; i++) {
                    if (argv[argument][i] == '=') {
                        if (!argv[argument][i + 1]) {
                            Choose(order, free, argv[argument], out);
                            break;
                        }
                        is_complex = true;

                        char optstr[i];
                        for (int j = 0; j < i; j++) {
                            optstr[j] = argv[argument][j];
                        }
                        char* optarg = &argv[argument][i + 1];
                        bool flag = false;
                        option *opt = opts;
                        while (opt->name) {
                            if (!strcmp(optstr, opt->name)) {
                                flag = true;
                                if (!opt->has_arguments) {
                                    std::cout << "The option " << optstr << " should have no arguments" << "\n";
                                    exit(1);
                                }
                                out.push_back(std::make_pair(opt->value, optarg));
                                break;
                            }
                            opt++;
                        }
                        if (!flag) {
                            Choose(order, free, argv[argument], out);
                        }
                        break;
                    }
                }
                if (!is_complex) {
                    bool flag = false;
                    option *opt = opts;
                    while (opt->name) {
                        if (!strcmp(argv[argument], opt->name)) {
                            flag = true;
                            if (!opt->has_arguments) {
                                out.push_back(std::make_pair(opt->value, nullptr));
                            } else {
                                order.push(opt->value);
                            }
                            break;
                        }
                        opt++;
                    }
                    if (!flag) {
                        Choose(order, free, argv[argument], out);
                    }
                }
            }
            else { // short names
                bool is_correct = true;
                for (int i = 1; i < arglen; i++) {
                    bool flag = false;
                    option* opt = opts;
                    while (opt->name) {
                        if (argv[argument][i] == opt->value) {
                            flag = true;
                            break;
                        }
                        opt++;
                    }
                    is_correct = flag;
                    if (!is_correct) {
                        Choose(order, free, argv[argument], out);
                        break;
                    }
                }
                if (is_correct) {
                    for (int i = 1; i < arglen; i++) {
                        option* opt = opts;
                        while (opt->name) {
                            if (argv[argument][i] == opt->value) {
                                if (!opt->has_arguments) {
                                    out.push_back(std::make_pair(opt->value, nullptr));
                                }
                                else {
                                    order.push(opt->value);
                                }
                                break;
                            }
                            opt++;
                        }
                    }
                }
            }
        }
        else {
            Choose(order, free, argv[argument], out);
        }
        argument++;
    }
    if (!order.empty()) {
        std::cout << "Command line arguments are incorrectly specified" << "\n";
        exit(1);
    }
    return out;
}
