#include "includes_collection.h"

TCHAR* FolderWatcherPath;
TCHAR* SnapShotPath;
TCHAR* TempSnapShot1;
TCHAR* TempSnapShot2;

void setup()
{
    FolderWatcherPath = new TCHAR[1024];

    if (SUCCEEDED(SHGetFolderPath(NULL, CSIDL_LOCAL_APPDATA, NULL, 0, FolderWatcherPath))) {
        wcsncpy(FolderWatcherPath + wcslen(FolderWatcherPath), TEXT("\\FolderWatcher"), 15);
    }

    DWORD dwAttrib = GetFileAttributes(FolderWatcherPath);

    if (!(dwAttrib != INVALID_FILE_ATTRIBUTES && (dwAttrib & FILE_ATTRIBUTE_DIRECTORY))) {
        CreateDirectory(FolderWatcherPath, NULL);
    }

    SnapShotPath = new TCHAR[1024];
    wcsncpy(SnapShotPath, FolderWatcherPath, 1024);
    wcsncpy(SnapShotPath + wcslen(SnapShotPath), TEXT("\\snap.txt"), 10);

    TempSnapShot1 = new TCHAR[1024];
    wcsncpy(TempSnapShot1, FolderWatcherPath, 1024);
    wcsncpy(TempSnapShot1 + wcslen(TempSnapShot1), TEXT("\\tmp1.snpsht"), 13);

    TempSnapShot2 = new TCHAR[1024];
    wcsncpy(TempSnapShot2, FolderWatcherPath, 1024);
    wcsncpy(TempSnapShot2 + wcslen(TempSnapShot2), TEXT("\\tmp2.snpsht"), 13);

	return;
}

void deinit()
{
    delete[] TempSnapShot2;
    delete[] TempSnapShot1;
    delete[] SnapShotPath;
    delete[] FolderWatcherPath;

    return;
}