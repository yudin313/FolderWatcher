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

extern TCHAR* FolderWatcherPath;
extern TCHAR* SnapShotPath;
extern TCHAR* TempSnapShot1;
extern TCHAR* TempSnapShot2;
void setup(void);
void deinit(void);

void file_information(char*, char*);
int is_file_or_folder(char*);

void next_file(FILE* file_read);
