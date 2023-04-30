#include "includes_collection.h"

void next_file(FILE* file_read)
{
	char stro[4096];
	fgets(stro, 4096, file_read);
	fgets(stro, 4096, file_read);
	fgets(stro, 4096, file_read);
	fgets(stro, 4096, file_read);
	fgets(stro, 4096, file_read);
	fgets(stro, 4096, file_read);
	fgets(stro, 4096, file_read);
	fgets(stro, 4096, file_read);
	fgets(stro, 4096, file_read);
	fgets(stro, 4096, file_read);
	fgets(stro, 4096, file_read);
	fgets(stro, 4096, file_read);
}

int compare(char* path1, char* path2)
{
	char* stroka1 = new char[4096];
	char* stroka2 = new char[4096];
	char* NAME1 = new char[4096];
	char* NAME2 = new char[4096];
	int is_path1_folder = 0, is_path2_folder = 0;
	bool attributes1[7] = { 0 }, attributes2[7] = { 0 }, common_attributes[7] = { 0 };
	int count1 = 0, count2 = 0;

	FILE* file_read1, *file_read2;

	if (is_file_or_folder(path1) == _FOLDER) {
		file_information(path1, "C:\\Users\\DELL\\AppData\\Local\\FolderWatcher\\path1.txt");
		file_read1 = fopen("C:\\Users\\DELL\\AppData\\Local\\FolderWatcher\\path1.txt", "r");
		fgets(stroka1, 8, file_read1);
		strcpy(NAME1, "C:\\Users\\DELL\\AppData\\Local\\FolderWatcher\\path1.txt");
		is_path1_folder = 1;
	}
	else {
		file_read1 = fopen(path1, "r");

		fgets(stroka1, 8, file_read1);
		if (stroka1[0] == 7 && stroka1[1] == 3 && stroka1[2] == 5 && stroka1[3] == 9 && stroka1[4] == 2 && stroka1[5] == 7 && stroka1[6] == '\n') {
			_asm {
				nop;
			}
		}
		else return 0; //выбран некорректный файл
		strcpy(NAME1, path1);
	}
	fgets(stroka1, 9, file_read1);
	for (int i = 0; i < 7; i++) {
		if (stroka1[i] == '1')
			attributes1[i] = true;
		else
			attributes1[i] = false;
	}


	if (is_file_or_folder(path2) == _FOLDER) {
		file_information(path2, "C:\\Users\\DELL\\AppData\\Local\\FolderWatcher\\path2.txt");
		file_read2 = fopen("C:\\Users\\DELL\\AppData\\Local\\FolderWatcher\\path2.txt", "r");
		fgets(stroka2, 8, file_read2);
		strcpy(NAME2, "C:\\Users\\DELL\\AppData\\Local\\FolderWatcher\\path2.txt");
		is_path2_folder = 1;
	}
	else {
		file_read2 = fopen(path2, "r");

		fgets(stroka2, 8, file_read2);
		if (stroka2[0] == 7 && stroka2[1] == 3 && stroka2[2] == 5 && stroka2[3] == 9 && stroka2[4] == 2 && stroka2[5] == 7 && stroka2[6] == '\n') {
			_asm {
				nop;
			}
		}
		else return 0; //выбран некорректный файл
		strcpy(NAME2, path2);
	}
	fgets(stroka2, 9, file_read2);
	for (int i = 0; i < 7; i++) {
		if (stroka2[i] == '1')
			attributes2[i] = true;
		else
			attributes2[i] = false;
	}

	for (int i = 0; i < 7; i++) {
		if (stroka1[i] && stroka2[i])
			common_attributes[i] = true;
		else
			common_attributes[i] = false;
	}

	//вызов функции из фронта, которая принимает массив содержащий true и false. каждый индекс соответствует атрибуту из check_box. Если true - такой столбец есть, false - нет
	//names_of_columns_compare(common_attributes);

	for (;;) {
		fgets(stroka1, 4096, file_read1);
		if (stroka1[0] == 7 && stroka1[1] == 3 && stroka1[2] == 5 && stroka1[3] == 9 && stroka1[4] == 2 && stroka1[5] == 7 && stroka1[6] == '\n') {
			fclose(file_read1);
			break;
		}
		else {
			next_file(file_read1);
			count1++;
		}
	}

	for (;;) {
		fgets(stroka2, 4096, file_read2);
		if (stroka2[0] == 7 && stroka2[1] == 3 && stroka2[2] == 5 && stroka2[3] == 9 && stroka2[4] == 2 && stroka2[5] == 7 && stroka2[6] == '\n') {
			fclose(file_read2);
			break;
		}
		else {
			next_file(file_read2);
			count2++;
		}
	}

	bool* checked_file1 = (bool*)malloc(count1 * sizeof(bool));
	for (int i = 0; i < count1; i++)
		checked_file1[i] = false;
	bool* checked_file2 = (bool*)malloc(count2 * sizeof(bool));
	for (int i = 0; i < count2; i++)
		checked_file2[i] = false;

	file_read1 = fopen(NAME1, "r");
	file_read2 = fopen(NAME2, "r");
	fgets(stroka2, 4096, file_read2);
	fgets(stroka2, 4096, file_read2);
	fgets(stroka1, 4096, file_read1);
	fgets(stroka1, 4096, file_read1);
	fgets(stroka1, 4096, file_read1);

	int i1 = 0, i2 = 0;

	for (;;) {
		fgets(stroka2, 4096, file_read2);
		if (stroka1[0] == 7 && stroka1[1] == 3 && stroka1[2] == 5 && stroka1[3] == 9 && stroka1[4] == 2 && stroka1[5] == 7 && stroka1[6] == '\n') {
			fclose(file_read1);
			fclose(file_read2);
			i1 = 0; 
			i2 = 0;
			break;
		}
		if (stroka2[0] == 7 && stroka2[1] == 3 && stroka2[2] == 5 && stroka2[3] == 9 && stroka2[4] == 2 && stroka2[5] == 7 && stroka2[6] == '\n') {
			fclose(file_read2);
			file_read2 = fopen(NAME2, "r");
			fgets(stroka2, 4096, file_read2);
			fgets(stroka2, 4096, file_read2);
			next_file(file_read1);
			fgets(stroka1, 4096, file_read1);
			i1++;
			i2 = 0;
			continue;
		}
		if (!strcmp(stroka1, stroka2)) {
			checked_file1[i1] = true;
			checked_file2[i2] = true;
			if (common_attributes[0]) {
				stroka1[strlen(stroka1) - 1] = 0;
				stroka2[strlen(stroka2) - 1] = 0;
				//fill_cell_compare(stroka1, stroka2, 0); //функция на прием во фронтенде, принимающая две строки и режим: 0 - совпадение, 1 - разногласие
			}

			//размер
			fgets(stroka1, 4096, file_read1);
			fgets(stroka2, 4096, file_read2);
			if (common_attributes[1]) {
				if (!strcmp(stroka1, stroka2)) {
					stroka1[strlen(stroka1) - 1] = 0;
					stroka2[strlen(stroka2) - 1] = 0;
					//fill_cell_compare(stroka1, stroka2, 0); //функция на прием во фронтенде
				}
				else {
					stroka1[strlen(stroka1) - 1] = 0;
					stroka2[strlen(stroka2) - 1] = 0;
					//fill_cell_compare(stroka1, stroka2, 1);
				}
			}

			//атрибуты безопасности
			fgets(stroka1, 4096, file_read1);
			fgets(stroka2, 4096, file_read2);
			if (common_attributes[2]) {
				if (!strcmp(stroka1, stroka2)) {
					stroka1[strlen(stroka1) - 1] = 0;
					stroka2[strlen(stroka2) - 1] = 0;
					//fill_cell_compare(stroka1, stroka2, 0); //функция на прием во фронтенде
				}
				else {
					stroka1[strlen(stroka1) - 1] = 0;
					stroka2[strlen(stroka2) - 1] = 0;
					//fill_cell_compare(stroka1, stroka2, 1);
				}
			}

			//альтернативные потоки
			fgets(stroka1, 4096, file_read1);
			fgets(stroka2, 4096, file_read2);
			if (common_attributes[3]) {
				if (!strcmp(stroka1, stroka2)) {
					stroka1[strlen(stroka1) - 1] = 0;
					stroka2[strlen(stroka2) - 1] = 0;
					//fill_cell_compare(stroka1, stroka2, 0); //функция на прием во фронтенде
				}
				else {
					stroka1[strlen(stroka1) - 1] = 0;
					stroka2[strlen(stroka2) - 1] = 0;
					//fill_cell_compare(stroka1, stroka2, 1);
				}
			}

			//время1
			fgets(stroka1, 4096, file_read1);
			fgets(stroka2, 4096, file_read2);
			if (common_attributes[4]) {
				if (!strcmp(stroka1, stroka2)) {
					stroka1[strlen(stroka1) - 1] = 0;
					stroka2[strlen(stroka2) - 1] = 0;
					//fill_cell_compare(stroka1, stroka2, 0); //функция на прием во фронтенде
				}
				else {
					stroka1[strlen(stroka1) - 1] = 0;
					stroka2[strlen(stroka2) - 1] = 0;
					//fill_cell_compare(stroka1, stroka2, 1);
				}
			}

			//время2
			fgets(stroka1, 4096, file_read1);
			fgets(stroka2, 4096, file_read2);
			if (common_attributes[5]) {
				if (!strcmp(stroka1, stroka2)) {
					stroka1[strlen(stroka1) - 1] = 0;
					stroka2[strlen(stroka2) - 1] = 0;
					//fill_cell_compare(stroka1, stroka2, 0); //функция на прием во фронтенде
				}
				else {
					stroka1[strlen(stroka1) - 1] = 0;
					stroka2[strlen(stroka2) - 1] = 0;
					//fill_cell_compare(stroka1, stroka2, 1);
				}
			}

			//время3
			fgets(stroka1, 4096, file_read1);
			fgets(stroka2, 4096, file_read2);
			if (common_attributes[6]) {
				if (!strcmp(stroka1, stroka2)) {
					stroka1[strlen(stroka1) - 1] = 0;
					stroka2[strlen(stroka2) - 1] = 0;
					//fill_cell_compare(stroka1, stroka2, 0); //функция на прием во фронтенде
				}
				else {
					stroka1[strlen(stroka1) - 1] = 0;
					stroka2[strlen(stroka2) - 1] = 0;
					//fill_cell_compare(stroka1, stroka2, 1);
				}
			}

			fgets(stroka1, 4096, file_read1);
			fgets(stroka2, 4096, file_read2);
			if (strcmp(stroka1, stroka2)) {
				//fill_row_compare(); //если хэш изменился
			}

			fgets(stroka1, 4096, file_read1);
			fgets(stroka2, 4096, file_read2);
			if (strcmp(stroka1, stroka2)) {
				//fill_row_compare(); //если хэш изменился
			}

			fgets(stroka1, 4096, file_read1);
			fgets(stroka2, 4096, file_read2);
			if (strcmp(stroka1, stroka2)) {
				//fill_row_compare(); //если хэш изменился
			}

			fgets(stroka1, 4096, file_read1);
			fgets(stroka2, 4096, file_read2);
			if (strcmp(stroka1, stroka2)) {
				//fill_row_compare(); //если хэш изменился
			}

			fgets(stroka1, 4096, file_read1);
			fgets(stroka2, 4096, file_read2);
			if (strcmp(stroka1, stroka2)) {
				//fill_row_compare(); //если хэш изменился
			}

			fgets(stroka1, 4096, file_read1);
			fgets(stroka2, 4096, file_read2);
			if (strcmp(stroka1, stroka2)) {
				//fill_row_compare(); //если хэш изменился
			}

			fclose(file_read2);
			file_read2 = fopen(NAME2, "r");
			fgets(stroka2, 4096, file_read2);
			fgets(stroka2, 4096, file_read2);
			fgets(stroka1, 4096, file_read1);
			i1++;
			i2 = 0;
		}

		else {
			next_file(file_read2);
			i2++;
		}
	}

	file_read1 = fopen(NAME1, "r");
	fgets(stroka1, 4096, file_read1);
	fgets(stroka1, 4096, file_read1);
	fgets(stroka1, 4096, file_read1);

	for (int i = 0; i < count1; i++) {
		if (!checked_file1[i]) {
			if (common_attributes[0]) {
				stroka1[strlen(stroka1) - 1] = 0;
				//fill_compare1(stroka1); //функция на прием во фронтенде
			}

			//размер
			fgets(stroka1, 4096, file_read1);
			if (common_attributes[1]) {
				stroka1[strlen(stroka1) - 1] = 0;
				//fill_compare1(stroka1);
			}

			//атрибуты безопасности
			fgets(stroka1, 4096, file_read1);
			if (common_attributes[2]) {
				stroka1[strlen(stroka1) - 1] = 0;
				//fill_compare1(stroka1);
			}

			//альтернативные потоки
			fgets(stroka1, 4096, file_read1);
			if (common_attributes[3]) {
				stroka1[strlen(stroka1) - 1] = 0;
				//fill_compare1(stroka1);
			}

			//время1
			fgets(stroka1, 4096, file_read1);
			if (common_attributes[4]) {
				stroka1[strlen(stroka1) - 1] = 0;
				//fill_compare1(stroka1);
			}

			//время2
			fgets(stroka1, 4096, file_read1);
			if (common_attributes[5]) {
				stroka1[strlen(stroka1) - 1] = 0;
				//fill_compare1(stroka1);
			}

			//время3
			fgets(stroka1, 4096, file_read1);
			if (common_attributes[6]) {
				stroka1[strlen(stroka1) - 1] = 0;
				//fill_compare1(stroka1);
			}
			fgets(stroka1, 4096, file_read1);
			fgets(stroka1, 4096, file_read1);
			fgets(stroka1, 4096, file_read1);
			fgets(stroka1, 4096, file_read1);
			fgets(stroka1, 4096, file_read1);
			fgets(stroka1, 4096, file_read1);
			fgets(stroka1, 4096, file_read1);
		}
		else {
			next_file(file_read1);
			fgets(stroka1, 4096, file_read1);
		}
	}
	fclose(file_read1);

	file_read2 = fopen(NAME2, "r");
	fgets(stroka2, 4096, file_read2);
	fgets(stroka2, 4096, file_read2);
	fgets(stroka2, 4096, file_read2);

	for (int i = 0; i < count2; i++) {
		if (!checked_file2[i]) {
			if (common_attributes[0]) {
				stroka2[strlen(stroka2) - 1] = 0;
				//fill_compare2(stroka2); //функция на прием во фронтенде
			}

			//размер
			fgets(stroka2, 4096, file_read2);
			if (common_attributes[1]) {
				stroka2[strlen(stroka2) - 1] = 0;
				//fill_compare2(stroka2);
			}

			//атрибуты безопасности
			fgets(stroka2, 4096, file_read2);
			if (common_attributes[2]) {
				stroka2[strlen(stroka2) - 1] = 0;
				//fill_compare2(stroka2);
			}

			//альтернативные потоки
			fgets(stroka2, 4096, file_read2);
			if (common_attributes[3]) {
				stroka2[strlen(stroka2) - 1] = 0;
				//fill_compare2(stroka2);
			}

			//время1
			fgets(stroka2, 4096, file_read2);
			if (common_attributes[4]) {
				stroka2[strlen(stroka2) - 1] = 0;
				//fill_compare2(stroka2);
			}

			//время2
			fgets(stroka2, 4096, file_read2);
			if (common_attributes[5]) {
				stroka2[strlen(stroka2) - 1] = 0;
				//fill_compare2(stroka2);
			}

			//время3
			fgets(stroka2, 4096, file_read2);
			if (common_attributes[6]) {
				stroka2[strlen(stroka2) - 1] = 0;
				//fill_compare2(stroka2);
			}
			fgets(stroka2, 4096, file_read2);
			fgets(stroka2, 4096, file_read2);
			fgets(stroka2, 4096, file_read2);
			fgets(stroka2, 4096, file_read2);
			fgets(stroka2, 4096, file_read2);
			fgets(stroka2, 4096, file_read2);
			fgets(stroka2, 4096, file_read2);
		}
		else {
			next_file(file_read2);
			fgets(stroka2, 4096, file_read2);
		}
	}
	fclose(file_read2);

	if (is_path1_folder)
		remove(NAME1);
	if (is_path2_folder)
		remove(NAME2);

	delete[] NAME2;
	delete[] NAME1;
	delete[] stroka2;
	delete[] stroka1;

	return 1; //означает конец сравнения
}
