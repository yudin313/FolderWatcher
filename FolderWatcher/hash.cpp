#include "hash.h"

using namespace std;

inline string SHA256(char* path)
{
    ifstream fp(path, ios::in | ios::binary);

    if (!fp.good()) {
        ostringstream os;
        os << "Cannot open \"" << path << "\": " << strerror(errno) << ".";
        throw runtime_error(os.str());
    }

    constexpr const size_t buffer_size{ 1 << 12 };
    char buffer[buffer_size];

    unsigned char hash[SHA256_DIGEST_LENGTH] = { 0 };

    SHA256_CTX ctx;
    SHA256_Init(&ctx);

    while (fp.good()) {
        fp.read(buffer, buffer_size);
        SHA256_Update(&ctx, buffer, (size_t)fp.gcount());
    }

    SHA256_Final(hash, &ctx);
    fp.close();

    ostringstream os;
    os << hex << setfill('0');

    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        os << setw(2) << static_cast<unsigned int>(hash[i]);
    }

    return os.str();
}

inline string MD5(char* path)
{
    ifstream fp(path, ios::in | ios::binary);

    if (!fp.good()) {
        ostringstream os;
        os << "Cannot open \"" << path << "\": " << strerror(errno) << ".";
        throw runtime_error(os.str());
    }

    constexpr const size_t buffer_size{ 1 << 12 };
    char buffer[buffer_size];

    unsigned char hash[MD5_DIGEST_LENGTH] = { 0 };

    MD5state_st ctx;
    MD5_Init(&ctx);

    while (fp.good()) {
        fp.read(buffer, buffer_size);
        MD5_Update(&ctx, buffer, (size_t)fp.gcount());
    }

    MD5_Final(hash, &ctx);
    fp.close();

    ostringstream os;
    os << hex << setfill('0');

    for (int i = 0; i < MD5_DIGEST_LENGTH; ++i) {
        os << setw(2) << static_cast<unsigned int>(hash[i]);
    }

    return os.str();
}

int hashes_file(char* name_path, char* hash_path)
{
    ofstream fout;
    fout.open(hash_path, ios::out);

    try {
        fout << "SHA256:" << SHA256(name_path) << endl;
        fout << "MD5:" << MD5(name_path) << endl;
    }
    catch (const exception& e) {
        cerr << "[fatal] " << e.what() << endl;
    }

    fout.close();

    return EXIT_SUCCESS;
}
