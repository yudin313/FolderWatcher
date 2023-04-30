#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <shlobj.h>
#include <msclr\marshal_cppstd.h>

#include <filesystem>

#include "hash.h"
#include "globals.h"

//определение: файл или папка
#define _FOLDER 0x69
#define _FILE 0x96

#define _UNLIMITED -1

void file_information(char*, char*);
int is_file_or_folder(char*);

int show_snapshot(TCHAR*);

int compare(char*, char*);

//show_snapshot("C:\\Users\\DELL\\OneDrive\\Документы\\FolderWatcher\\output.txt");
//compare("D:\\Background2\\output.txt", "D:\\3rd semester");
