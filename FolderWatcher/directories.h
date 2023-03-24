#pragma once

void file_information(char*, int, char*);

/*

������������ ���������� � ��������� �����:

������ ������ - ��� � ������ �����
������ ������ - ������ ����� � ������
������ ������ - ����� � ���� ���������� �������
��������� ������ - ����� � ���� ��������� �����������
����� ������ - ����� � ���� ���������� ��������� �������

������:

hello.txt
11
17-03-2023 13:29:40
16-03-2023 23:36:54
14-03-2023 23:22:19

*/

//������ ��� �������� � ������
#define _NAME 0x1
#define _SIZE 0x2
#define _TIME_OF_LAST_ACCESS 0x4
#define _TIME_OF_LAST_DATA_MODIFICATION 0x8
#define _TIME_OF_LAST_STATUS_CHANGE 0x10

//�����������: ���� ��� �����
#define _FOLDER 0x69
#define _FILE 0x96