#pragma once
#pragma warning(disable : 4996)
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream> //for std::ostringstream
#include <iomanip> //for std::setw, std::hex, and std::setfill

#include <openssl/evp.h> //for all other OpenSSL function calls
#include <openssl/sha.h>
#include <openssl/md5.h>

int hashes_file(char*, char*,char*);