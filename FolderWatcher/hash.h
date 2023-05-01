#pragma once

#include <windows.h>

#include <fstream>
#include <iostream>
#include <vector>
#include <sstream> //for std::ostringstream
#include <iomanip> //for std::setw, std::hex, and std::setfill

#include <openssl/evp.h> //for all other OpenSSL function calls
#include <openssl/sha.h>

int hashes_file(TCHAR*, FILE*, char*);
