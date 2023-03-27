#include "backend.h"

int backend_main(std::string str_name,char* folderwathcher_path)
{
	//char name[] = "C:\\Users\\Andrey-PC\\Documents\\Atmel Studio";

	char* name = new char[str_name.length() + 1];
	strcpy(name, str_name.c_str());
	char exit_name[] = "C:\\Users\\Andrey-PC\\Documents\\FolderWatcher";
	
	int constants = 0x1F;
	file_information(name, constants, folderwathcher_path);

	delete[] name;

	return 0;
}