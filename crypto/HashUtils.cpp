#include "HashUtils.h"
#include <openssl/md5.h>
#include <openssl/sha.h>
#include <sstream>
#include <iomanip>

std::string HashUtils::md5(const std::string& input) {
    unsigned char digest[MD5_DIGEST_LENGTH];
    MD5((unsigned char*)input.c_str(), input.size(), digest);
    std::ostringstream oss;
    for(int i=0;i<MD5_DIGEST_LENGTH;i++)
        oss << std::hex << std::setw(2) << std::setfill('0') << (int)digest[i];
    return oss.str();
}

std::string HashUtils::sha256(const std::string& input) {
    unsigned char digest[SHA256_DIGEST_LENGTH];
    SHA256((unsigned char*)input.c_str(), input.size(), digest);
    std::ostringstream oss;
    for(int i=0;i<SHA256_DIGEST_LENGTH;i++)
        oss << std::hex << std::setw(2) << std::setfill('0') << (int)digest[i];
    return oss.str();
}
