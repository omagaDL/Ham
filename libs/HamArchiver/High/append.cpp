#include "high.h"
void Append(const char* archive, std::vector<const char*>& filenames, unsigned char codeword_length, bool parity_bit) {
    std::ofstream output(archive, std::ios::binary | std::ios::app);
    std::set<std::string> list = GetList(archive);
    for (const char* filename : filenames) {
        if (GetFilename(archive) == GetFilename(filename)) {
            std::cout << GetFilename(filename) << " cannot be added because its name matches the name of the archive" << '\n';
        }
        else {
            std::cout << "Appending " << GetFilename(filename) << " ..." << '\n';
            if (Appending(output, archive, filename, list, codeword_length, parity_bit)) {
                std::cout << GetFilename(filename) << " was successfully appended" << '\n';
            }
        }
    }
    output.close();
}
