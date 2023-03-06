#include "high.h"
void Extracting(const char* archive, const char* filename, std::vector<std::string>& must_be_deleted, char all) {
    Meta meta;
    std::ifstream input(archive, std::ios::binary);
    std::string path = GetPath(archive);
    if (all) {
        unsigned long long archive_size = GetFileSize(archive);
        while((input.tellg() != archive_size) && (input.tellg() != -1)) {
            meta.Get(input);
            std::cout << "Extracting " << meta.filename << " ..." << '\n';
            if (ExtractingOverwritingDialog(std::filesystem::exists(path + meta.filename), meta.filename)) {
                std::ofstream output(path + meta.filename, std::ios::binary);
                DataHandling(input, output, GetNewSize(meta.file_size, meta.codeword_length, meta.parity_bit), meta.codeword_length, false, meta.parity_bit, meta.file_size);
                ITERATIONS = 0;
                output.close();
                if (ExtractingDeletingDialog(ERROR, meta.filename)) {
                    std::filesystem::remove(path + meta.filename);
                }
                else {
                    std::cout << meta.filename << " was successfully extracted" << '\n';
                }
                must_be_deleted.push_back(meta.filename);
                ERROR = false;
            }
            else {
                std::cout << meta.filename << " was not extracted" << '\n';
                input.seekg(static_cast<unsigned long long> (input.tellg()) + GetNewSize(meta.file_size, meta.codeword_length, meta.parity_bit));
            }
        }
    }
    else {
        if (!FindFile(input, meta, GetFileSize(archive), filename)) {
            std::cout << "There is no file " << filename << " in the archive " << GetFilename(archive) << '\n';
        }
        else {
            std::cout << "Extracting " << meta.filename << " ..." << '\n';
            if (ExtractingOverwritingDialog(std::filesystem::exists(path + meta.filename), meta.filename)) {
                std::ofstream output(path + meta.filename, std::ios::binary);
                DataHandling(input, output, GetNewSize(meta.file_size, meta.codeword_length, meta.parity_bit), meta.codeword_length, false, meta.parity_bit, meta.file_size);
                ITERATIONS = 0;
                output.close();
                if (ExtractingDeletingDialog(ERROR, meta.filename)) {
                    std::filesystem::remove(path + meta.filename);
                }
                else {
                    std::cout << meta.filename << " was successfully extracted" << '\n';
                }
                ERROR = false;
                must_be_deleted.push_back(meta.filename);
            }
            else {
                std::cout << meta.filename << " was not extracted" << '\n';
            }
        }
    }
    input.close();
}
