#ifndef BLOWFISHUTILS_H
#define BLOWFISHUTILS_H

#include <string>
#include <vector>

class BlowfishUtils {
public:
    // Returns ciphertext with IV prepended
    static std::vector<unsigned char> encrypt(const std::string& plaintext, const std::string& key);
    static std::string decrypt(const std::vector<unsigned char>& ciphertextWithIv, const std::string& key);
};

#endif // BLOWFISHUTILS_H
