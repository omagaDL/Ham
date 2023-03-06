#include "get_options.h"
void Choose(std::queue<char>& order, std::vector<const char*>& free, char* optarg, std::vector<std::pair<char, char*>>& out) {
    if (order.empty()) {
        free.push_back(optarg);
    }
    else {
        out.push_back(std::make_pair(order.front(), optarg));
        order.pop();
    }
}