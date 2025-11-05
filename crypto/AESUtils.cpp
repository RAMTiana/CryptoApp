#include "AESUtils.h"
#include <openssl/evp.h>
#include <openssl/rand.h>
#include <stdexcept>
#include <vector>
#include <cstring>

std::vector<unsigned char> AESUtils::encrypt(const std::string& plaintext, const std::string& key) {
    if(!(key.size()==16 || key.size()==24 || key.size()==32))
        throw std::runtime_error("AES key must be 16, 24 or 32 bytes");

    const int iv_len = 16;
    std::vector<unsigned char> iv(iv_len);
    if(RAND_bytes(iv.data(), iv_len) != 1)
        throw std::runtime_error("Erreur génération IV");

    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
    if(!ctx) throw std::runtime_error("EVP_CIPHER_CTX_new failed");

    const EVP_CIPHER* cipher = nullptr;
    if(key.size() == 16) cipher = EVP_aes_128_cbc();
    else if(key.size() == 24) cipher = EVP_aes_192_cbc();
    else cipher = EVP_aes_256_cbc();

    if(1 != EVP_EncryptInit_ex(ctx, cipher, nullptr, reinterpret_cast<const unsigned char*>(key.data()), iv.data()))
        { EVP_CIPHER_CTX_free(ctx); throw std::runtime_error("EVP_EncryptInit_ex failed"); }

    std::vector<unsigned char> out;
    out.resize(plaintext.size() + EVP_CIPHER_block_size(cipher));

    int outlen1 = 0;
    if(1 != EVP_EncryptUpdate(ctx, out.data(), &outlen1, reinterpret_cast<const unsigned char*>(plaintext.data()), (int)plaintext.size()))
        { EVP_CIPHER_CTX_free(ctx); throw std::runtime_error("EVP_EncryptUpdate failed"); }

    int outlen2 = 0;
    if(1 != EVP_EncryptFinal_ex(ctx, out.data() + outlen1, &outlen2))
        { EVP_CIPHER_CTX_free(ctx); throw std::runtime_error("EVP_EncryptFinal_ex failed"); }

    out.resize(outlen1 + outlen2);

    EVP_CIPHER_CTX_free(ctx);

    // Prepend IV to ciphertext for storage/transport
    std::vector<unsigned char> result;
    result.reserve(iv.size() + out.size());
    result.insert(result.end(), iv.begin(), iv.end());
    result.insert(result.end(), out.begin(), out.end());
    return result;
}

std::string AESUtils::decrypt(const std::vector<unsigned char>& ciphertextWithIv, const std::string& key) {
    if(!(key.size()==16 || key.size()==24 || key.size()==32))
        throw std::runtime_error("AES key must be 16, 24 or 32 bytes");

    const int iv_len = 16;
    if((int)ciphertextWithIv.size() <= iv_len) throw std::runtime_error("Ciphertext too short");

    const unsigned char* iv = ciphertextWithIv.data();
    const unsigned char* ciphertext = ciphertextWithIv.data() + iv_len;
    int ciphertext_len = (int)ciphertextWithIv.size() - iv_len;

    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
    if(!ctx) throw std::runtime_error("EVP_CIPHER_CTX_new failed");

    const EVP_CIPHER* cipher = nullptr;
    if(key.size() == 16) cipher = EVP_aes_128_cbc();
    else if(key.size() == 24) cipher = EVP_aes_192_cbc();
    else cipher = EVP_aes_256_cbc();

    if(1 != EVP_DecryptInit_ex(ctx, cipher, nullptr, reinterpret_cast<const unsigned char*>(key.data()), iv))
        { EVP_CIPHER_CTX_free(ctx); throw std::runtime_error("EVP_DecryptInit_ex failed"); }

    std::vector<unsigned char> out;
    out.resize(ciphertext_len + EVP_CIPHER_block_size(cipher));
    int outlen1 = 0;
    if(1 != EVP_DecryptUpdate(ctx, out.data(), &outlen1, ciphertext, ciphertext_len))
        { EVP_CIPHER_CTX_free(ctx); throw std::runtime_error("EVP_DecryptUpdate failed"); }

    int outlen2 = 0;
    if(1 != EVP_DecryptFinal_ex(ctx, out.data() + outlen1, &outlen2))
        { EVP_CIPHER_CTX_free(ctx); throw std::runtime_error("EVP_DecryptFinal_ex failed (bad key or corrupted data)"); }

    EVP_CIPHER_CTX_free(ctx);
    out.resize(outlen1 + outlen2);
    return std::string(reinterpret_cast<char*>(out.data()), out.size());
}
