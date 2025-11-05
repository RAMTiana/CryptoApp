#include "RSAUtils.h"
#include <openssl/pem.h>
#include <openssl/err.h>
#include <stdexcept>
#include <vector>
#include <cstdio>

static RSA* loadPublicKey(const std::string& path) {
    FILE* fp = fopen(path.c_str(), "rb");
    if(!fp) throw std::runtime_error("Impossible d'ouvrir la clé publique: " + path);
    RSA* rsa = PEM_read_RSA_PUBKEY(fp, nullptr, nullptr, nullptr);
    fclose(fp);
    if(!rsa) throw std::runtime_error("Erreur lecture clé publique: " + path);
    return rsa;
}

static RSA* loadPrivateKey(const std::string& path) {
    FILE* fp = fopen(path.c_str(), "rb");
    if(!fp) throw std::runtime_error("Impossible d'ouvrir la clé privée: " + path);
    RSA* rsa = PEM_read_RSAPrivateKey(fp, nullptr, nullptr, nullptr);
    fclose(fp);
    if(!rsa) throw std::runtime_error("Erreur lecture clé privée: " + path);
    return rsa;
}

std::vector<unsigned char> RSAUtils::encrypt(const std::string& data, const std::string& publicKeyPath) {
    RSA* rsa = loadPublicKey(publicKeyPath);
    int rsa_len = RSA_size(rsa);
    std::vector<unsigned char> out(rsa_len);

    int len = RSA_public_encrypt(
        static_cast<int>(data.size()),
        reinterpret_cast<const unsigned char*>(data.data()),
        out.data(),
        rsa,
        RSA_PKCS1_OAEP_PADDING
    );
    RSA_free(rsa);
    if(len == -1) {
        unsigned long err = ERR_get_error();
        throw std::runtime_error("RSA encrypt error: " + std::string(ERR_error_string(err, nullptr)));
    }
    out.resize(len);
    return out;
}

std::string RSAUtils::decrypt(const std::vector<unsigned char>& encryptedData, const std::string& privateKeyPath) {
    RSA* rsa = loadPrivateKey(privateKeyPath);
    int rsa_len = RSA_size(rsa);
    std::vector<unsigned char> out(rsa_len);

    int len = RSA_private_decrypt(
        static_cast<int>(encryptedData.size()),
        encryptedData.data(),
        out.data(),
        rsa,
        RSA_PKCS1_OAEP_PADDING
    );
    RSA_free(rsa);
    if(len == -1) {
        unsigned long err = ERR_get_error();
        throw std::runtime_error("RSA decrypt error: " + std::string(ERR_error_string(err, nullptr)));
    }
    return std::string(reinterpret_cast<char*>(out.data()), len);
}
