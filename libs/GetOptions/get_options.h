#ifndef LABWORK_3_ONEBEATTRUE_GET_OPTIONS_H
#define LABWORK_3_ONEBEATTRUE_GET_OPTIONS_H
#include <iostream>
#include <filesystem>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
struct option {
    char* name;
    bool has_arguments;
    char value;
    option(char* opt_name, bool opt_has_arguments, char opt_value): name(opt_name), has_arguments(opt_has_arguments), value(opt_value) {}
};
void Choose(std::queue<char>& order, std::vector<const char*>& free, char* optarg, std::vector<std::pair<char, char*>>& out);
std::vector<std::pair<char, char*>> Getting (int argc, char** argv, option* opts, std::vector<const char*>& free);
#endif //LABWORK_3_ONEBEATTRUE_GET_OPTIONS_H
