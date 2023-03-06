#include "high.h"
void Concatenating(std::ofstream& output, std::set<std::string>& list, const char* archive, const char* concatenating_archive) {
    Meta meta;
    unsigned long long archive_size = GetFileSize(concatenating_archive);
    std::ifstream input(concatenating_archive, std::ios::binary);
    while((input.tellg() != archive_size) && (input.tellg() != -1)) {
        meta.Get(input);
        std::cout << "Appending " << meta.filename << " ..." << '\n';
        if (ConcatenatingFile(output, input, archive, list, meta)) {
            std::cout << meta.filename << " was successfully appended" << '\n';
            list.insert(meta.filename);
        }
    }
    input.close();
}
