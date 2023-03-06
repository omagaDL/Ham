#include "high.h"
void Delete(const char* archive, std::vector<const char*>& filenames, bool from_extraction) {
    std::set<std::string> must_be_deleted = VectToSet(filenames);
    if (from_extraction) {
        if(must_be_deleted.empty()) {
            return;
        }
    }
    if (!CheckFiles(must_be_deleted, archive)) {
        return;
    }
    std::string temp_archive = GetPath(archive) + "temp";
    unsigned long long archive_size = GetFileSize(archive);
    std::ifstream input(archive, std::ios::binary);
    std::ofstream output(temp_archive, std::ios::binary);
    std::cout << "Deleting ..." << '\n';
    while((input.tellg() != archive_size) && (input.tellg() != -1)) {
        Deleting(input, output, must_be_deleted);
    }
    output.close();
    input.close();
    std::filesystem::remove(archive);
    std::filesystem::rename(temp_archive, archive);
    std::cout << "Deleting finished" << '\n';
}