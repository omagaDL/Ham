#include "high.h"
void Concatenate(const char* archive, std::vector<const char*>& filenames) {
    std::ofstream output(archive, std::ios::binary | std::ios::app);
    std::set<std::string> list = GetList(archive);
    for (const char* filename : filenames) {
        if (GetExtension(filename) != "haf") {
            std::cout << GetFilename(filename) << " is not an .haf archive" << '\n';
        }
        else {
            std::cout << "Concatenating " << GetFilename(filename) << " ..." << '\n';
            Concatenating(output, list, archive, filename);
            std::cout << GetFilename(filename) << " was concatenated to " << GetFilename(archive) << " as much as it possible" << '\n';
        }
        std::cout << '\n';
    }
    output.close();
}
