#include "includes_collection.h"

namespace fs = std::filesystem;

int check_unlimited = 0; //проверка, что переменная глубина unlimited
int start_length_name = 0; //индекс, с которого сохранять путь до файла
int counter = 0;


/////////////// определение объекта работы //////////////

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


//////////////////// работа с файлом /////////////////////

void if_file(TCHAR* NAME, FILE* output_file)
{
    char timeStr[100];
    struct stat buf;
    int64_t _file_size = 0;

    counter++;

    //открываем файл для чтения таким образом, чтобы позже узнать размер файла
    HANDLE hFile;
    hFile = CreateFile(NAME, GENERIC_READ, 0, NULL, OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL | FILE_FLAG_OVERLAPPED, NULL);

    //запись имени и формата файла
    if (check_box[0])
        fprintf(output_file, "%ws\n", &NAME[start_length_name]);
    else
        fprintf(output_file, "-1\n"); 

    //запись размера
    if (check_box[1]) {
        LARGE_INTEGER u_winFsz;
        GetFileSizeEx(hFile, &u_winFsz);
        CloseHandle(hFile);
        _file_size = u_winFsz.QuadPart;
        fprintf(output_file, "%lld\n", _file_size);
    }
    else
        fprintf(output_file, "-1\n");

    //атрибуты
    if (check_box[2]) {
        DWORD dwAttrs;
        dwAttrs = GetFileAttributes(NAME);
        if (dwAttrs & FILE_ATTRIBUTE_ARCHIVE)
            fprintf(output_file, "archive "); //Файл архивный.
        if (dwAttrs & FILE_ATTRIBUTE_COMPRESSED)
            fprintf(output_file, "compressed "); //Файл сжатый.
        if (dwAttrs & FILE_ATTRIBUTE_ENCRYPTED)
            fprintf(output_file, "encrypted "); //Файл зашифрованный.
        if (dwAttrs & FILE_ATTRIBUTE_HIDDEN)
            fprintf(output_file, "hidden "); //Файл скрытый.
        if (dwAttrs & FILE_ATTRIBUTE_NORMAL)
            fprintf(output_file, "normal "); //Файл не имеет других установленных атрибутов.
        if (dwAttrs & FILE_ATTRIBUTE_READONLY)
            fprintf(output_file, "readonly "); //Файл только для чтения.
        if (dwAttrs & FILE_ATTRIBUTE_OFFLINE)
            fprintf(output_file, "offline "); //Данные файла доступны не сразу.
        if (dwAttrs & FILE_ATTRIBUTE_SPARSE_FILE)
            fprintf(output_file, "sparse_file "); //Файл разреженный.
        if (dwAttrs & FILE_ATTRIBUTE_SYSTEM)
            fprintf(output_file, "system "); //Файл частично или исключительно используется операционной системой.
        if (dwAttrs & FILE_ATTRIBUTE_TEMPORARY)
            fprintf(output_file, "temporary "); //Файл используется для временного хранения.
        fprintf(output_file, "\n");
    }
    else
        fprintf(output_file, "-1\n");

    //перечисление альтернативных потоков файла: размер и имя
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

    //в структуре stat с именем buf записываются метаданные файла
    stat(CH_NAME, &buf);

    delete[] CH_NAME;

    //запись времени и даты последнего изменения статуса
    if (check_box[4]) {
        strftime(timeStr, 100, "%d-%m-%Y %H:%M:%S", localtime(&buf.st_ctime));
        fprintf(output_file, "%s\n", timeStr);
    }
    else
        fprintf(output_file, "-1\n");

    //запись времени и даты последней модификации 
    if (check_box[5]) {
        strftime(timeStr, 100, "%d-%m-%Y %H:%M:%S", localtime(&buf.st_mtime));
        fprintf(output_file, "%s\n", timeStr);
    }
    else
        fprintf(output_file, "-1\n");

    //запись времени и даты последнего доступа
    if (check_box[6]) {
        strftime(timeStr, 100, "%d-%m-%Y %H:%M:%S", localtime(&buf.st_atime));
        fprintf(output_file, "%s\n", timeStr);
    }
    else
        fprintf(output_file, "-1\n");

    hashes_file(output_file, NAME); //собираем хэши

    return;
}

/////////////////////////////////////////////////////////


//////////////////// работа с папкой /////////////////////

void if_folder(TCHAR* NAME, int depth_no_global, FILE* output_file)
{
    depth_no_global--; //уменьшаем глубину

    TCHAR* file;

    for (const auto& entry : fs::directory_iterator(NAME)) {
        file = new TCHAR[4096];
        wcscpy(file, entry.path().c_str());

        if (is_file_or_folder(file) == _FILE)
            if_file(file, output_file);
        else if (depth_no_global != -1 || check_unlimited) //если не конец глубины
            if_folder(file, depth_no_global, output_file);

        delete[] file;
    }

    return;
}

/////////////////////////////////////////////////////////


//////////////////// это база /////////////////////

void file_information(TCHAR* NAME, TCHAR* NAME_EXIT)
{
    counter = 0;

    FILE* output_file = _wfopen(NAME_EXIT, TEXT("w"));

    fprintf(output_file, "%c%c%c%c%c%c\n", 7, 3, 5, 9, 2, 7); //строка идентифицирующая слепок

    //список параметров: 1 - есть параметр, 2 - нет параметра. Соответсвенное расположению в check_box
    fprintf(output_file, "%c", (check_box[0]) ? '1' : '0');
    fprintf(output_file, "%c", (check_box[1]) ? '1' : '0');
    fprintf(output_file, "%c", (check_box[2]) ? '1' : '0');
    fprintf(output_file, "%c", (check_box[3]) ? '1' : '0');
    fprintf(output_file, "%c", (check_box[4]) ? '1' : '0');
    fprintf(output_file, "%c", (check_box[5]) ? '1' : '0');
    fprintf(output_file, "%c\n", (check_box[6]) ? '1' : '0');

    int depth_no_global = depth; //переменная, отвечающая за глубину в данном файле, чтобы не менять глобальную

    start_length_name = wcslen(NAME);

    if (depth_no_global == 0) //проверка, что переменная unlimited
        check_unlimited = 1; // если unlimited

    depth_no_global--; //уменьшаем глубину, если папка
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
