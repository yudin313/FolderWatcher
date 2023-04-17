#include <filesystem>
#include <stdint.h> // ��� int64_t
#include <inttypes.h> // ��� ����������� ������ int64_t � printf

#include "directories.h"
#include "hash.h"

namespace fs = std::filesystem;

#ifdef _WIN32

// ��� ���� ���� ����� �� ��������������
// ��� ������������� ������� GetFileSizeEx()
#define WINVER 0x0501
#define _WIN32_WINNT WINVER

#include <windows.h>
#include <sys\stat.h>
#endif

/////////////// ����������� ������� ������ //////////////

int is_file_or_folder(char* NAME)
{
    wchar_t* wString = new wchar_t[4096];
    MultiByteToWideChar(CP_ACP, 0, NAME, -1, wString, 4096);

    HANDLE hFile;
    hFile = CreateFile(wString, GENERIC_READ, 0, NULL, OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL | FILE_FLAG_OVERLAPPED, NULL);

    if (hFile == INVALID_HANDLE_VALUE) {
        CloseHandle(hFile);
        return _FOLDER;
    }
    CloseHandle(hFile);
    return _FILE;
}

/////////////////////////////////////////////////////////




//////////////////// ������ � ������ /////////////////////

void if_file(char* NAME, int constants, char* NAME_EXIT)
{
    char timeStr[100];
    struct stat buf;
    int64_t _file_size = 0;

    //������ ������ txt
    char NAME_EXIT_CURRENT[4096] = "";
    strncat(NAME_EXIT_CURRENT, NAME_EXIT, strlen(NAME_EXIT));
    strncat(NAME_EXIT_CURRENT, ".txt", 4);

    FILE* file_write = fopen(NAME_EXIT_CURRENT, "w");

    //��������� ��� ������� ����� ��� �������� char* � LPCWSTR
    wchar_t* wString = new wchar_t[4096];
    MultiByteToWideChar(CP_ACP, 0, NAME, -1, wString, 4096);


    //��������� ���� ��� ������ ����� �������, ����� ����� ������ ������ �����
    HANDLE hFile;
    hFile = CreateFile(wString, GENERIC_READ, 0, NULL, OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL | FILE_FLAG_OVERLAPPED, NULL);

    //������ ����� � ������� �����
    if (constants & _NAME) fprintf(file_write, "%s\n", strrchr(NAME, '\\') + 1);

    //������ �������
    if (constants & _SIZE) {
        LARGE_INTEGER u_winFsz;
        GetFileSizeEx(hFile, &u_winFsz);
        CloseHandle(hFile);
        _file_size = u_winFsz.QuadPart;
        fprintf(file_write, "%" PRId64 "\n", _file_size);
    }

    //� ��������� stat � ������ buf ������������ ���������� �����
    stat(NAME, &buf);

    //������ ������� � ���� ���������� �������
    if (constants & _TIME_OF_LAST_ACCESS) {
        strftime(timeStr, 100, "%d-%m-%Y %H:%M:%S", localtime(&buf.st_atime));
        fprintf(file_write, "%s\n", timeStr);
    }

    //������ ������� � ���� ��������� ����������� 
    if (constants & _TIME_OF_LAST_DATA_MODIFICATION) {
        strftime(timeStr, 100, "%d-%m-%Y %H:%M:%S", localtime(&buf.st_mtime));
        fprintf(file_write, "%s\n", timeStr);
    }

    //������ ������� � ���� ���������� ��������� �������
    if (constants & _TIME_OF_LAST_STATUS_CHANGE) {
        strftime(timeStr, 100, "%d-%m-%Y %H:%M:%S", localtime(&buf.st_ctime));
        fprintf(file_write, "%s\n", timeStr);
    }

    fclose(file_write);

    //�������� � ������ ���������� �������
    char HASH_EXIT_CURRENT[4096] = "";
    strncat(HASH_EXIT_CURRENT, NAME_EXIT, strlen(NAME_EXIT));
    strncat(HASH_EXIT_CURRENT, "_hash", 5);
    strncat(HASH_EXIT_CURRENT, ".txt", 4);

    //hashes_file(NAME_EXIT_CURRENT, HASH_EXIT_CURRENT);
}

/////////////////////////////////////////////////////////



//////////////////// ������ � ������ /////////////////////

void if_folder(char* NAME, int constants, char* NAME_EXIT) {
    struct stat st = { 0 };
    char CREATE_NEW_FOLDER[4096] = "";
    //���� �� Documents + ��������� � ����� ���� ��� ����� �� NAME 
    strncat(CREATE_NEW_FOLDER, NAME_EXIT, strlen(NAME_EXIT));
    strncat(CREATE_NEW_FOLDER, strrchr(NAME, '\\'), strlen(strrchr(NAME, '\\')));


    //���������� ����� � �����, ���� �� ���
    if (stat(CREATE_NEW_FOLDER, &st) == -1) {
        wchar_t* wString = new wchar_t[4096];
        MultiByteToWideChar(CP_ACP, 0, CREATE_NEW_FOLDER, -1, wString, 4096);
        CreateDirectory(wString, NULL);
    }


    std::string path = NAME;
    for (const auto& entry : fs::directory_iterator(path)) {
        //��������� ��� ������ ����� ��� ��������������� entry �� ���� filesystem::path � wchar_t*
        char file[4096];
        wcstombs(file, entry.path().c_str(), 4096);

        //��������� ����
        char NAME_EXIT_CURRENT[4096] = "";
        strncat(NAME_EXIT_CURRENT, CREATE_NEW_FOLDER, strlen(CREATE_NEW_FOLDER));

        if (is_file_or_folder(file) == _FILE) {
            //��������� � ���� ��� �����
            strncat(NAME_EXIT_CURRENT, strrchr(file, '\\'), strlen(strrchr(file, '\\')));
            if_file(file, constants, NAME_EXIT_CURRENT);
        }
        else {
            if_folder(file, constants, NAME_EXIT_CURRENT);
        }
    }
}

/////////////////////////////////////////////////////////


//////////////////// ��� ���� /////////////////////

void file_information(char* NAME, int constants, char* NAME_EXIT) {

    if (is_file_or_folder(NAME) == _FILE) {
        if_file(NAME, constants, NAME_EXIT);
    }

    else {
        if_folder(NAME, constants, NAME_EXIT);
    }
}

/////////////////////////////////////////////////////////