#include "includes_collection.h"

int show_snapshot(TCHAR* path)
{
	FILE* file_read = _wfopen(path, TEXT("r"));
	char stroka[4096];

	fgets(stroka, 8, file_read);
	if (!(stroka[0] == 7 && stroka[1] == 3 && stroka[2] == 5 && stroka[3] == 9 && stroka[4] == 2 && stroka[5] == 7 && stroka[6] == '\n')) {
		//возвращаемое значение 0 - файл не был создан нами
		return 0;
	}

	bool attributes[7] = { 0 };
	fgets(stroka, 9, file_read);
	for (int i = 0; i < 7; i++) {
		if (stroka[i] == '1')
			attributes[i] = true;
		else
			attributes[i] = false;
	}

	//вызов функции из фронта, которая принимает массив содержащий true и false. каждый индекс соответствует атрибуту из check_box. Если true - такой столбец есть, false - нет
	//names_of_columns(attributes);

	// по порядку отпраляются данные нужных атрибутов. Остальные пропускаются
	for (;;) {
		fgets(stroka, 4096, file_read);
		//проверка на конец файла
		if (strlen(stroka) == 7 && stroka[0] == 7 && stroka[1] == 3 && stroka[2] == 5 && stroka[3] == 9 && stroka[4] == 2 && stroka[5] == 7 && stroka[6] == '\n')
			return 1;
		// имя
		if (attributes[0]) {
			stroka[strlen(stroka) - 1] = 0;
			//fill_cell(stroka); //функция на прием во фронтенде
		}

		//размер
		fgets(stroka, 4096, file_read);
		if (attributes[1]) {
			stroka[strlen(stroka) - 1] = 0;
			//fill_cell(stroka); //функция на прием во фронтенде
		}

		//атрибуты безопасности
		fgets(stroka, 4096, file_read);
		if (attributes[2]) {
			stroka[strlen(stroka) - 2] = 0;
			//fill_cell(stroka); //функция на прием во фронтенде
		}

		//альтернативные потоки
		fgets(stroka, 4096, file_read);
		if (attributes[3]) {
			stroka[strlen(stroka) - 1] = 0;
			//fill_cell(stroka); //функция на прием во фронтенде
		}

		//время1
		fgets(stroka, 4096, file_read);
		if (attributes[4]) {
			stroka[strlen(stroka) - 1] = 0;
			//fill_cell(stroka); //функция на прием во фронтенде
		}

		//время2
		fgets(stroka, 4096, file_read);
		if (attributes[5]) {
			stroka[strlen(stroka) - 1] = 0;
			//fill_cell(stroka); //функция на прием во фронтенде
		}

		//время3
		fgets(stroka, 4096, file_read);
		if (attributes[6]) {
			stroka[strlen(stroka) - 1] = 0;
			//fill_cell(stroka); //функция на прием во фронтенде
		}
		fgets(stroka, 4096, file_read);
		fgets(stroka, 4096, file_read);
		fgets(stroka, 4096, file_read);
		fgets(stroka, 4096, file_read);
		fgets(stroka, 4096, file_read);
		fgets(stroka, 4096, file_read);
	}
	
	return 1;
}
