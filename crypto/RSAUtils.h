#ifndef RSAUTILS_H
#define RSAUTILS_H

#include <string>
#include <vector>

class RSAUtils {
public:
    // Encrypt using a public key file (PEM). Return binary encrypted bytes.
    static std::vector<unsigned char> encrypt(const std::string& data, const std::string& publicKeyPath);
    // Decrypt using a private key file (PEM). Return cleartext string.
    static std::string decrypt(const std::vector<unsigned char>& encryptedData, const std::string& privateKeyPath);
};

#endif // RSAUTILS_H
