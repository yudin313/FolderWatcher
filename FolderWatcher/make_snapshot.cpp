#include "includes_collection.h"

namespace fs = std::filesystem;

int check_unlimited = 0; //��������, ��� ���������� ������� unlimited
int start_length_name = 0; //������, � �������� ��������� ���� �� �����
int counter = 0;


/////////////// ����������� ������� ������ //////////////

int is_file_or_folder(TCHAR* NAME)
{
    HANDLE hFile;
    hFile = CreateFile(NAME, GENERIC_READ, 0, NULL, OPEN_EXISTING,
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

void if_file(TCHAR* NAME, FILE* output_file)
{
    char timeStr[100];
    struct stat buf;
    int64_t _file_size = 0;

    counter++;

    //��������� ���� ��� ������ ����� �������, ����� ����� ������ ������ �����
    HANDLE hFile;
    hFile = CreateFile(NAME, GENERIC_READ, 0, NULL, OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL | FILE_FLAG_OVERLAPPED, NULL);

    //������ ����� � ������� �����
    if (check_box[0])
        fprintf(output_file, "%ws\n", &NAME[start_length_name]);
    else
        fprintf(output_file, "-1\n"); 

    //������ �������
    if (check_box[1]) {
        LARGE_INTEGER u_winFsz;
        GetFileSizeEx(hFile, &u_winFsz);
        CloseHandle(hFile);
        _file_size = u_winFsz.QuadPart;
        fprintf(output_file, "%lld\n", _file_size);
    }
    else
        fprintf(output_file, "-1\n");

    //��������
    if (check_box[2]) {
        DWORD dwAttrs;
        dwAttrs = GetFileAttributes(NAME);
        if (dwAttrs & FILE_ATTRIBUTE_ARCHIVE)
            fprintf(output_file, "archive "); //���� ��������.
        if (dwAttrs & FILE_ATTRIBUTE_COMPRESSED)
            fprintf(output_file, "compressed "); //���� ������.
        if (dwAttrs & FILE_ATTRIBUTE_ENCRYPTED)
            fprintf(output_file, "encrypted "); //���� �������������.
        if (dwAttrs & FILE_ATTRIBUTE_HIDDEN)
            fprintf(output_file, "hidden "); //���� �������.
        if (dwAttrs & FILE_ATTRIBUTE_NORMAL)
            fprintf(output_file, "normal "); //���� �� ����� ������ ������������� ���������.
        if (dwAttrs & FILE_ATTRIBUTE_READONLY)
            fprintf(output_file, "readonly "); //���� ������ ��� ������.
        if (dwAttrs & FILE_ATTRIBUTE_OFFLINE)
            fprintf(output_file, "offline "); //������ ����� �������� �� �����.
        if (dwAttrs & FILE_ATTRIBUTE_SPARSE_FILE)
            fprintf(output_file, "sparse_file "); //���� �����������.
        if (dwAttrs & FILE_ATTRIBUTE_SYSTEM)
            fprintf(output_file, "system "); //���� �������� ��� ������������� ������������ ������������ ��������.
        if (dwAttrs & FILE_ATTRIBUTE_TEMPORARY)
            fprintf(output_file, "temporary "); //���� ������������ ��� ���������� ��������.
        fprintf(output_file, "\n");
    }
    else
        fprintf(output_file, "-1\n");

    //������������ �������������� ������� �����: ������ � ���
    if (check_box[3]) {
        WIN32_FIND_STREAM_DATA fsd;
        HANDLE hFind = NULL;

        hFind = ::FindFirstStreamW(NAME, FindStreamInfoStandard, &fsd, 0);
        if (hFind == INVALID_HANDLE_VALUE) throw ::GetLastError();

        for (;;) {
            fprintf(output_file, "%I64u-%wS%wS ", fsd.StreamSize, &NAME[start_length_name], fsd.cStreamName);
            if (!::FindNextStreamW(hFind, &fsd)) {
                DWORD dr = ::GetLastError();
                if (dr != ERROR_HANDLE_EOF) throw dr;
                break;
            }
        }

        if (hFind != NULL) ::FindClose(hFind);
        fprintf(output_file, "\n");
    }
    else
        fprintf(output_file, "-1\n");

    char* CH_NAME = new char[4096];
    sprintf(CH_NAME, "%ws", NAME);

    //� ��������� stat � ������ buf ������������ ���������� �����
    stat(CH_NAME, &buf);

    delete[] CH_NAME;

    //������ ������� � ���� ���������� ��������� �������
    if (check_box[4]) {
        strftime(timeStr, 100, "%d-%m-%Y %H:%M:%S", localtime(&buf.st_ctime));
        fprintf(output_file, "%s\n", timeStr);
    }
    else
        fprintf(output_file, "-1\n");

    //������ ������� � ���� ��������� ����������� 
    if (check_box[5]) {
        strftime(timeStr, 100, "%d-%m-%Y %H:%M:%S", localtime(&buf.st_mtime));
        fprintf(output_file, "%s\n", timeStr);
    }
    else
        fprintf(output_file, "-1\n");

    //������ ������� � ���� ���������� �������
    if (check_box[6]) {
        strftime(timeStr, 100, "%d-%m-%Y %H:%M:%S", localtime(&buf.st_atime));
        fprintf(output_file, "%s\n", timeStr);
    }
    else
        fprintf(output_file, "-1\n");

    hashes_file(output_file, NAME); //�������� ����

    return;
}

/////////////////////////////////////////////////////////


//////////////////// ������ � ������ /////////////////////

void if_folder(TCHAR* NAME, int depth_no_global, FILE* output_file)
{
    depth_no_global--; //��������� �������

    TCHAR* file;

    for (const auto& entry : fs::directory_iterator(NAME)) {
        file = new TCHAR[4096];
        wcscpy(file, entry.path().c_str());

        if (is_file_or_folder(file) == _FILE)
            if_file(file, output_file);
        else if (depth_no_global != -1 || check_unlimited) //���� �� ����� �������
            if_folder(file, depth_no_global, output_file);

        delete[] file;
    }

    return;
}

/////////////////////////////////////////////////////////


//////////////////// ��� ���� /////////////////////

void file_information(TCHAR* NAME, TCHAR* NAME_EXIT)
{
    counter = 0;

    FILE* output_file = _wfopen(NAME_EXIT, TEXT("w"));

    fprintf(output_file, "%c%c%c%c%c%c\n", 7, 3, 5, 9, 2, 7); //������ ���������������� ������

    //������ ����������: 1 - ���� ��������, 2 - ��� ���������. �������������� ������������ � check_box
    fprintf(output_file, "%c", (check_box[0]) ? '1' : '0');
    fprintf(output_file, "%c", (check_box[1]) ? '1' : '0');
    fprintf(output_file, "%c", (check_box[2]) ? '1' : '0');
    fprintf(output_file, "%c", (check_box[3]) ? '1' : '0');
    fprintf(output_file, "%c", (check_box[4]) ? '1' : '0');
    fprintf(output_file, "%c", (check_box[5]) ? '1' : '0');
    fprintf(output_file, "%c\n", (check_box[6]) ? '1' : '0');

    int depth_no_global = depth; //����������, ���������� �� ������� � ������ �����, ����� �� ������ ����������

    start_length_name = wcslen(NAME);

    if (depth_no_global == 0) //��������, ��� ���������� unlimited
        check_unlimited = 1; // ���� unlimited

    depth_no_global--; //��������� �������, ���� �����
    if_folder(NAME, depth_no_global, output_file);

    fprintf(output_file, "%c%c%c%c%c%c\n", 7, 3, 5, 9, 2, 7);
    fprintf(output_file, "%i", counter);

    fclose(output_file);

    return;
}

/////////////////////////////////////////////////////////

void next_file(FILE* file_read)
{
    char* stro = new char[4096];
    fgets(stro, 4096, file_read);
    fgets(stro, 4096, file_read);
    fgets(stro, 4096, file_read);
    fgets(stro, 4096, file_read);
    fgets(stro, 4096, file_read);
    fgets(stro, 4096, file_read);
    fgets(stro, 4096, file_read);
    fgets(stro, 4096, file_read);
    fgets(stro, 4096, file_read);
    delete[] stro;
}
