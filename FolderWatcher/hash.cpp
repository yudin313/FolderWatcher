#include "hash.h"

//helper function to print the digest bytes as a hex string
std::string bytes_to_hex_string(const std::vector<uint8_t>& bytes)
{
    std::ostringstream stream;
    for (uint8_t b : bytes)
    {
        stream << std::setw(2) << std::setfill('0') << std::hex << static_cast<int>(b);
    }
    return stream.str();
}

//perform the SHA3-512 hash
std::string sha3_512(const std::string& input)
{
    uint32_t digest_length = SHA512_DIGEST_LENGTH;
    const EVP_MD* algorithm = EVP_sha3_512();
    uint8_t* digest = static_cast<uint8_t*>(OPENSSL_malloc(digest_length));
    EVP_MD_CTX* context = EVP_MD_CTX_new();
    EVP_DigestInit_ex(context, algorithm, nullptr);
    EVP_DigestUpdate(context, input.c_str(), input.size());
    EVP_DigestFinal_ex(context, digest, &digest_length);
    EVP_MD_CTX_destroy(context);
    std::string output = bytes_to_hex_string(std::vector<uint8_t>(digest, digest + digest_length));
    OPENSSL_free(digest);
    return output;
}

inline std::string SHA256(char* path)
{
    std::ifstream fp(path, std::ios::in | std::ios::binary);

    if (!fp.good()) {
        std::ostringstream os;
        os << "Cannot open \"" << path << "\": " << strerror(errno) << ".";
        throw std::runtime_error(os.str());
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

    std::ostringstream os;
    os << std::hex << std::setfill('0');

    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        os << std::setw(2) << static_cast<unsigned int>(hash[i]);
    }

    return os.str();
}

inline std::string SHA512(char* path)
{
    std::ifstream fp(path, std::ios::in | std::ios::binary);

    if (!fp.good()) {
        std::ostringstream os;
        os << "Cannot open \"" << path << "\": " << strerror(errno) << ".";
        throw std::runtime_error(os.str());
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

    std::ostringstream os;
    os << std::hex << std::setfill('0');

    for (int i = 0; i < SHA512_DIGEST_LENGTH; ++i) {
        os << std::setw(2) << static_cast<unsigned int>(hash[i]);
    }

    return os.str();
}

int hashes_file(TCHAR* snap_path, TCHAR* hash_path, char* file_path)
{
    char* char_snap_path = new char[1024];
    char* char_hash_path = new char[1024];
    wcstombs(char_snap_path, snap_path, 1024);
    wcstombs(char_hash_path, hash_path, 1024);

    std::ofstream fout;
    fout.open(char_hash_path, std::ios::out);
    std::string s;

    std::ifstream fp1(char_snap_path);
    s = std::string((std::istreambuf_iterator<char>(fp1)), std::istreambuf_iterator<char>());
    fp1.close();

    try {
        fout << "SHA256-snapshot:" << SHA256(char_snap_path) << std::endl;
        fout << "SHA512-snapshot:" << SHA512(char_snap_path) << std::endl;
        std::string output = sha3_512(s);
        fout << "SHA3-512-snapshot:" << output << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "[fatal] " << e.what() << std::endl;
    }

    std::ifstream fp2(file_path);
    s = std::string((std::istreambuf_iterator<char>(fp2)), std::istreambuf_iterator<char>());
    fp2.close();

    try {
        fout << "SHA256-file:" << SHA256(file_path) << std::endl;
        fout << "SHA512-file:" << SHA512(file_path) << std::endl;
        std::string output = sha3_512(s);
        fout << "SHA3-512-file:" << output << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "[fatal] " << e.what() << std::endl;
    }

    fout.close();

    delete[] char_hash_path;
    delete[] char_snap_path;

    return EXIT_SUCCESS;
}
