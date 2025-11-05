#pragma once
#include <vector>
#include <string>

class FileManager {
public:
    static std::vector<unsigned char> readFile(const std::string& path);
    static void writeFile(const std::string& path, const std::vector<unsigned char>& data);
};
