#pragma once

#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>

#include <openssl/sha.h>
#include <openssl/md5.h>

int hashes_file(char*, char*);