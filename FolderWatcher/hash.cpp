#include "hash.h"
using namespace std;
//helper function to print the digest bytes as a hex string
string bytes_to_hex_string(const vector<uint8_t>& bytes)
{
    ostringstream stream;
    for (uint8_t b : bytes)
    {
        stream << setw(2) << setfill('0') << hex << static_cast<int>(b);
    }
    return stream.str();
}

//perform the SHA3-512 hash
string sha3_512(const string& input)
{
    uint32_t digest_length = SHA512_DIGEST_LENGTH;
    const EVP_MD* algorithm = EVP_sha3_512();
    uint8_t* digest = static_cast<uint8_t*>(OPENSSL_malloc(digest_length));
    EVP_MD_CTX* context = EVP_MD_CTX_new();
    EVP_DigestInit_ex(context, algorithm, nullptr);
    EVP_DigestUpdate(context, input.c_str(), input.size());
    EVP_DigestFinal_ex(context, digest, &digest_length);
    EVP_MD_CTX_destroy(context);
    string output = bytes_to_hex_string(vector<uint8_t>(digest, digest + digest_length));
    OPENSSL_free(digest);
    return output;
}

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

inline string SHA512(char* path)
{
    ifstream fp(path, ios::in | ios::binary);

    if (!fp.good()) {
        ostringstream os;
        os << "Cannot open \"" << path << "\": " << strerror(errno) << ".";
        throw runtime_error(os.str());
    }

    constexpr const size_t buffer_size{ 1 << 12 };
    char buffer[buffer_size];

    unsigned char hash[SHA512_DIGEST_LENGTH] = { 0 };

    SHA512state_st ctx;
    SHA512_Init(&ctx);

    while (fp.good()) {
        fp.read(buffer, buffer_size);
        SHA512_Update(&ctx, buffer, (size_t)fp.gcount());
    }

    SHA512_Final(hash, &ctx);
    fp.close();

    ostringstream os;
    os << hex << setfill('0');

    for (int i = 0; i < SHA512_DIGEST_LENGTH; ++i) {
        os << setw(2) << static_cast<unsigned int>(hash[i]);
    }

    return os.str();
}

inline string SHA384(char* path)
{
    ifstream fp(path, ios::in | ios::binary);

    if (!fp.good()) {
        ostringstream os;
        os << "Cannot open \"" << path << "\": " << strerror(errno) << ".";
        throw runtime_error(os.str());
    }

    constexpr const size_t buffer_size{ 1 << 12 };
    char buffer[buffer_size];

    unsigned char hash[SHA384_DIGEST_LENGTH] = { 0 };

    SHA512state_st ctx;
    SHA384_Init(&ctx);

    while (fp.good()) {
        fp.read(buffer, buffer_size);
        SHA384_Update(&ctx, buffer, (size_t)fp.gcount());
    }

    SHA384_Final(hash, &ctx);
    fp.close();

    ostringstream os;
    os << hex << setfill('0');

    for (int i = 0; i < SHA384_DIGEST_LENGTH; ++i) {
        os << setw(2) << static_cast<unsigned int>(hash[i]);
    }

    return os.str();
}

bool readfile(std::string& s, const char* filename) {
    std::ifstream fp(filename);
    if (!fp.is_open())
        return false;

    char nil = '\0';
    std::getline(fp, s, nil);
    fp.close();
    return (s.length() > 0);
}

int hashes_file(char* cast_path, char* hash_path, char* file_path)
{
    ofstream fout;
    fout.open(hash_path, ios::out);
    std::string s;
    readfile(s, cast_path);
    try {
        fout << "SHA256-snapshot:" << SHA256(cast_path) << endl;
        fout << "SHA512-snapshot:" << SHA512(cast_path) << endl;
        std::string output = sha3_512(s);
        fout << "SHA3-512-snapshot:" << output << endl;
    }
    catch (const exception& e) {
        cerr << "[fatal] " << e.what() << endl;
    }
    readfile(s, file_path);
    try {
        fout << "SHA256-file:" << SHA256(file_path) << endl;
        fout << "SHA512-file:" << SHA512(file_path) << endl;
        std::string output = sha3_512(s);
        fout << "SHA3-512-file:" << output << endl;
    }
    catch (const exception& e) {
        cerr << "[fatal] " << e.what() << endl;
    }

    fout.close();

    return EXIT_SUCCESS;
}
