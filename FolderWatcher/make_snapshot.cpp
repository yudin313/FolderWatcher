#include "includes_collection.h"

namespace fs = std::filesystem;

int check_unlimited = 0; //проверка, что переменная глубина unlimited
int start_lenth_name = 0; //индекс, с которого сохранять путь до файла


/////////////// определение объекта работы //////////////

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


//////////////////// работа с файлом /////////////////////

void if_file(char* NAME, FILE* output_file)
{
    char timeStr[100];
    struct stat buf;
    int64_t _file_size = 0;

    FILE* file_write = _wfopen(SnapShotPath, TEXT("w"));

    //следующие две строчки нужны для перевода char* в LPCWSTR
    wchar_t* wString = new wchar_t[4096];
    MultiByteToWideChar(CP_ACP, 0, NAME, -1, wString, 4096);

    //открываем файл для чтения таким образом, чтобы позже узнать размер файла
    HANDLE hFile;
    hFile = CreateFile(wString, GENERIC_READ, 0, NULL, OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL | FILE_FLAG_OVERLAPPED, NULL);

    //запись имени и формата файла
    if (check_box[0]) {
        fprintf(output_file, "%s\n", &NAME[start_lenth_name]);
        fprintf(file_write, "%s\n", &NAME[start_lenth_name]);
    }
    else { 
        fprintf(output_file, "-1\n"); 
        fprintf(file_write, "-1\n");
    }

    //запись размера
    if (check_box[1]) {
        LARGE_INTEGER u_winFsz;
        GetFileSizeEx(hFile, &u_winFsz);
        CloseHandle(hFile);
        _file_size = u_winFsz.QuadPart;
        fprintf(output_file, "%lld\n", _file_size);
        fprintf(file_write, "%lld\n", _file_size);
    }
    else {
        fprintf(output_file, "-1\n");
        fprintf(file_write, "-1\n");
    }

    //атрибуты безопасности
    if (check_box[2]) {
        DWORD dwAttrs;
        dwAttrs = GetFileAttributes(wString);
        if (dwAttrs & FILE_ATTRIBUTE_ARCHIVE) {
            fprintf(output_file, "archive "); //Файл  - архивные.
            fprintf(file_write, "archive ");
        }
        if (dwAttrs & FILE_ATTRIBUTE_COMPRESSED) {
            fprintf(output_file, "compressed "); //Файл  сжатые.
            fprintf(file_write, "compressed ");
        }
        if (dwAttrs & FILE_ATTRIBUTE_ENCRYPTED) {
            fprintf(output_file, "encrypted "); //Файл  - зашифрованные.
            fprintf(file_write, "encrypted ");
        }
        if (dwAttrs & FILE_ATTRIBUTE_HIDDEN) {
            fprintf(output_file, "hidden "); //Файл скрытые.
            fprintf(file_write, "hidden ");
        }
        if (dwAttrs & FILE_ATTRIBUTE_NORMAL) {
            fprintf(output_file, "normal "); //Файл  не имеют других установленных атрибутов.
            fprintf(file_write, "normal ");
        }
        if (dwAttrs & FILE_ATTRIBUTE_READONLY) {
            fprintf(output_file, "readonly "); //Файл  только для чтения.
            fprintf(file_write, "readonly ");
        }
        if (dwAttrs & FILE_ATTRIBUTE_OFFLINE) {
            fprintf(output_file, "offline "); //Данные файла доступны не сразу.
            fprintf(file_write, "offline ");
        }
        if (dwAttrs & FILE_ATTRIBUTE_SPARSE_FILE) {
            fprintf(output_file, "sparse_file "); //Файл - разреженный файл.
            fprintf(file_write, "sparse_file ");
        }
        if (dwAttrs & FILE_ATTRIBUTE_SYSTEM) {
            fprintf(output_file, "system "); //Файл  - частично или исключительно используются  операционной системой.
            fprintf(file_write, "system ");
        }
        if (dwAttrs & FILE_ATTRIBUTE_TEMPORARY) {
            fprintf(output_file, "temporary "); //Файл используется для временного хранения.
            fprintf(file_write, "temporary ");
        }
        fprintf(output_file, "\n");
        fprintf(file_write, "\n");
    }
    else {
        fprintf(output_file, "-1\n");
        fprintf(file_write, "-1\n");
    }

    //перечисление альтернативных потоков файла: размер и имя
    if (check_box[3]) {
        WIN32_FIND_STREAM_DATA fsd;
        HANDLE hFind = NULL;

        hFind = ::FindFirstStreamW(wString, FindStreamInfoStandard, &fsd, 0);
        if (hFind == INVALID_HANDLE_VALUE) throw ::GetLastError();

        for (;;) {

            fprintf(output_file, "%-12I64u%S%S ", fsd.StreamSize, &wString[start_lenth_name], fsd.cStreamName);
            fprintf(file_write, "%-12I64u%S%S ", fsd.StreamSize, &wString[start_lenth_name], fsd.cStreamName);
            if (!::FindNextStreamW(hFind, &fsd)) {
                DWORD dr = ::GetLastError();
                if (dr != ERROR_HANDLE_EOF) throw dr;
                break;
            }
        }

        if (hFind != NULL) ::FindClose(hFind);
        fprintf(output_file, "\n");
        fprintf(file_write, "\n");
    }
    else {
        fprintf(output_file, "-1\n");
        fprintf(file_write, "-1\n");
    }

    //в структуре stat с именем buf записываются метаданные файла
    stat(NAME, &buf);

    //запись времени и даты последнего изменения статуса
    if (check_box[4]) {
        strftime(timeStr, 100, "%d-%m-%Y %H:%M:%S", localtime(&buf.st_ctime));
        fprintf(output_file, "%s\n", timeStr);
        fprintf(file_write, "%s\n", timeStr);
    }
    else {
        fprintf(output_file, "-1\n");
        fprintf(file_write, "-1\n");
    }

    //запись времени и даты последней модификации 
    if (check_box[5]) {
        strftime(timeStr, 100, "%d-%m-%Y %H:%M:%S", localtime(&buf.st_mtime));
        fprintf(output_file, "%s\n", timeStr);
        fprintf(file_write, "%s\n", timeStr);
    }
    else {
        fprintf(output_file, "-1\n");
        fprintf(file_write, "-1\n");
    }

    //запись времени и даты последнего доступа
    if (check_box[6]) {
        strftime(timeStr, 100, "%d-%m-%Y %H:%M:%S", localtime(&buf.st_atime));
        fprintf(output_file, "%s\n", timeStr);
        fprintf(file_write, "%s\n", timeStr);
    }
    else {
        fprintf(output_file, "-1\n");
        fprintf(file_write, "-1\n");
    }

    fclose(file_write);

    hashes_file(SnapShotPath, output_file, NAME); //собираем хэши

    return;
}

/////////////////////////////////////////////////////////


//////////////////// работа с папкой /////////////////////

void if_folder(char* NAME, int depth_no_global, FILE* output_file)
{
    depth_no_global--; //уменьшаем глубину

    std::string path = NAME;
    for (const auto& entry : fs::directory_iterator(path)) {
        //следующие две строки нужны для конвертирования entry из типа filesystem::path в wchar_t*
        char file[4096];
        wcstombs(file, entry.path().c_str(), 4096);

        if (is_file_or_folder(file) == _FILE) {
            if_file(file, output_file);
        }
        else if (depth_no_global != -1 || check_unlimited) { //если не конец глубины
            if_folder(file, depth_no_global, output_file);
        }
    }

    return;
}

/////////////////////////////////////////////////////////


//////////////////// это база /////////////////////

void file_information(char* NAME, char* NAME_EXIT)
{
    FILE* output_file = fopen(NAME_EXIT, "w");

    fprintf(output_file, "%c%c%c%c%c%c\n", 7, 3, 5, 9, 2, 7); //строка идентифицирующая слепок

    fprintf(output_file, "%c", (check_box[0]) ? '1' : '0');
    fprintf(output_file, "%c", (check_box[1]) ? '1' : '0');
    fprintf(output_file, "%c", (check_box[2]) ? '1' : '0');
    fprintf(output_file, "%c", (check_box[3]) ? '1' : '0');
    fprintf(output_file, "%c", (check_box[4]) ? '1' : '0');
    fprintf(output_file, "%c", (check_box[5]) ? '1' : '0');
    fprintf(output_file, "%c\n", (check_box[6]) ? '1' : '0'); //список параметров: 1 - есть параметр, 2 - нет параметра. Соответсвенное расположению в check_box

    int depth_no_global = depth; //переменная, отвечающая за глубину в данном файле, чтобы не менять глобальную

    start_lenth_name = strlen(NAME);

    if (depth_no_global == 0) //проверка, что переменная unlimited
        check_unlimited = 1; // если unlimited

    depth_no_global--; //уменьшаем глубину, если папка
    if_folder(NAME, depth_no_global, output_file);

    fprintf(output_file, "%c%c%c%c%c%c\n", 7, 3, 5, 9, 2, 7);

    fclose(output_file);

    return;
}

/////////////////////////////////////////////////////////
