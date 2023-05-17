#pragma once

#define _CRT_SECURE_NO_WARNINGS

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

int is_file_or_folder(TCHAR*);
void file_information(TCHAR*, TCHAR*);
void next_file(FILE* file_read);

/*
* button1 - browse
* button2 - snapshot
* button3 - refresh
* button4 - import
* button5 - parameters
* button6 - logs
* button7 - compare
*/
