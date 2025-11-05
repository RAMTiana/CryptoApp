#include "FileManager.h"
#include <fstream>
#include <stdexcept>

std::vector<unsigned char> FileManager::readFile(const std::string& path) {
    std::ifstream file(path, std::ios::binary);
    if(!file) throw std::runtime_error("Impossible d'ouvrir le fichier");

    std::vector<unsigned char> data((std::istreambuf_iterator<char>(file)), {});
    return data;
}

void FileManager::writeFile(const std::string& path, const std::vector<unsigned char>& data) {
    std::ofstream file(path, std::ios::binary);
    if(!file) throw std::runtime_error("Impossible d'écrire le fichier");

    file.write((char*)data.data(), data.size());
}
