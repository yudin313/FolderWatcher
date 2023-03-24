#include "backend.h"

//int backend_main()
//{
//	char name[] = "C:\\Users\\Andrey-PC\\Documents\\Atmel Studio";
//	char exit_name[] = "C:\\Users\\Andrey-PC\\Documents\\FolderWatcher";
//	int constants = 0x1F;
//	file_information(name, constants, exit_name);
//
//	return 0;
//}


int backend_main(std::string str_name)
{
	//char name[] = "C:\\Users\\Andrey-PC\\Documents\\Atmel Studio";

	char* name = new char[str_name.length() + 1];
	strcpy(name, str_name.c_str());
	char exit_name[] = "C:\\Users\\Andrey-PC\\Documents\\FolderWatcher";
	int constants = 0x1F;
	file_information(name, constants, exit_name);

	delete[] name;

	return 0;
}