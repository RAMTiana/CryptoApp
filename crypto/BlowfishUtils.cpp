#include "BlowfishUtils.h"
#include <cryptopp/blowfish.h>
#include <cryptopp/modes.h>
#include <cryptopp/filters.h>
#include <cryptopp/osrng.h>
using namespace CryptoPP;

std::vector<unsigned char> BlowfishUtils::encrypt(const std::string& plaintext, const std::string& key) {
    AutoSeededRandomPool prng;
    SecByteBlock iv(Blowfish::BLOCKSIZE);
    prng.GenerateBlock(iv, iv.size());

    std::string cipher;
    CBC_Mode<Blowfish>::Encryption enc((const byte*)key.data(), (size_t)key.size(), iv);
    StringSource ss(plaintext, true,
        new StreamTransformationFilter(enc, new StringSink(cipher), StreamTransformationFilter::PKCS_PADDING)
    );

    std::vector<unsigned char> result;
    result.insert(result.end(), iv.begin(), iv.end());
    result.insert(result.end(), cipher.begin(), cipher.end());
    return result;
}

std::string BlowfishUtils::decrypt(const std::vector<unsigned char>& ciphertextWithIv, const std::string& key) {
    if(ciphertextWithIv.size() < Blowfish::BLOCKSIZE) throw std::runtime_error("Ciphertext too short");
    std::string cipherStr(reinterpret_cast<const char*>(ciphertextWithIv.data() + Blowfish::BLOCKSIZE),
                          ciphertextWithIv.size() - Blowfish::BLOCKSIZE);
    SecByteBlock iv((const byte*)ciphertextWithIv.data(), Blowfish::BLOCKSIZE);

    std::string recovered;
    CBC_Mode<Blowfish>::Decryption dec((const byte*)key.data(), (size_t)key.size(), iv);
    StringSource ss(cipherStr, true,
        new StreamTransformationFilter(dec, new StringSink(recovered), StreamTransformationFilter::PKCS_PADDING)
    );
    return recovered;
}
