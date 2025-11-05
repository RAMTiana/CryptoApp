#ifndef AESUTILS_H
#define AESUTILS_H

#include <string>
#include <vector>

class AESUtils {
public:
    // AES-256-CBC encrypt: key must be 16/24/32 bytes (we will use 32 for AES-256)
    // Returns ciphertext with iv prepended (IV length = 16)
    static std::vector<unsigned char> encrypt(const std::string& plaintext, const std::string& key);
    // Expects ciphertext with IV prepended
    static std::string decrypt(const std::vector<unsigned char>& ciphertextWithIv, const std::string& key);
};

#endif // AESUTILS_H
