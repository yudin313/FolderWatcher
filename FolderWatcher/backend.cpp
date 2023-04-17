#include "backend.h"

int backend_main(std::string str_name,char* folderwathcher_path)
{
	char* name = new char[str_name.length() + 1];
	strcpy(name, str_name.c_str());
	
	int constants = 0x1F;
	file_information(name, constants, folderwathcher_path);

	delete[] name;

	return 0;
}