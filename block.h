#ifndef BLOCK
#define BLOCK
#include <string>
#include <ctime>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <openssl/sha.h>

class block{
    private:
        std::string prev_hash;
        std::string data;
        std::time_t timestamp;

        std::string hashString(std::string data){
            unsigned char hash[SHA256_DIGEST_LENGTH];
            SHA256_CTX sha256;
            SHA256_Init(&sha256);
            SHA256_Update(&sha256, data.c_str(), data.length());
            SHA256_Final(hash, &sha256);

            std::stringstream ss;
            for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
                ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(hash[i]);
            }

            return ss.str();
        }


    public:
        std::string hash;
        block(std::string dat, std::string prev) : prev_hash(prev), data(dat)
        {
            timestamp = std::time(nullptr);
            hash = calculateHash();
        };

        std::string calculateHash (){
            return hashString(data + std::to_string(timestamp)  + prev_hash);
        }

};

#endif