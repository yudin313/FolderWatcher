#pragma once

void file_information(char*, int, char*);

/*

расположение информации в текстовом файле:

первая строка - имя и формат файла
вторая строка - размер файла в байтах
третья строка - время и дата последнего доступа
четвертая строка - время и дата последней модификации
пятая строка - время и дата последнего изменения статуса

ПРИМЕР:

hello.txt
11
17-03-2023 13:29:40
16-03-2023 23:36:54
14-03-2023 23:22:19

*/

//данные для внесения в слепок
#define _NAME 0x1
#define _SIZE 0x2
#define _TIME_OF_LAST_ACCESS 0x4
#define _TIME_OF_LAST_DATA_MODIFICATION 0x8
#define _TIME_OF_LAST_STATUS_CHANGE 0x10

//определение: файл или папка
#define _FOLDER 0x69
#define _FILE 0x96