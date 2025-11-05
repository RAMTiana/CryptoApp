#pragma once
#include <string>

class HashUtils {
public:
    static std::string md5(const std::string& input);
    static std::string sha256(const std::string& input);
};
