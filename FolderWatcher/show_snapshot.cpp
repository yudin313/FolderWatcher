#include "includes_collection.h"

int show_snapshot(TCHAR* path)
{
	FILE* file_read = _wfopen(path, TEXT("r"));
	char stroka[4096];

	fgets(stroka, 8, file_read);
	if (!(stroka[0] == 7 && stroka[1] == 3 && stroka[2] == 5 && stroka[3] == 9 && stroka[4] == 2 && stroka[5] == 7 && stroka[6] == '\n')) {
		//������������ �������� 0 - ���� �� ��� ������ ����
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

	//����� ������� �� ������, ������� ��������� ������ ���������� true � false. ������ ������ ������������� �������� �� check_box. ���� true - ����� ������� ����, false - ���
	//names_of_columns(attributes);

	// �� ������� ����������� ������ ������ ���������. ��������� ������������
	for (;;) {
		fgets(stroka, 4096, file_read);
		//�������� �� ����� �����
		if (strlen(stroka) == 7 && stroka[0] == 7 && stroka[1] == 3 && stroka[2] == 5 && stroka[3] == 9 && stroka[4] == 2 && stroka[5] == 7 && stroka[6] == '\n')
			return 1;
		// ���
		if (attributes[0]) {
			stroka[strlen(stroka) - 1] = 0;
			//fill_cell(stroka); //������� �� ����� �� ���������
		}

		//������
		fgets(stroka, 4096, file_read);
		if (attributes[1]) {
			stroka[strlen(stroka) - 1] = 0;
			//fill_cell(stroka); //������� �� ����� �� ���������
		}

		//�������� ������������
		fgets(stroka, 4096, file_read);
		if (attributes[2]) {
			stroka[strlen(stroka) - 2] = 0;
			//fill_cell(stroka); //������� �� ����� �� ���������
		}

		//�������������� ������
		fgets(stroka, 4096, file_read);
		if (attributes[3]) {
			stroka[strlen(stroka) - 1] = 0;
			//fill_cell(stroka); //������� �� ����� �� ���������
		}

		//�����1
		fgets(stroka, 4096, file_read);
		if (attributes[4]) {
			stroka[strlen(stroka) - 1] = 0;
			//fill_cell(stroka); //������� �� ����� �� ���������
		}

		//�����2
		fgets(stroka, 4096, file_read);
		if (attributes[5]) {
			stroka[strlen(stroka) - 1] = 0;
			//fill_cell(stroka); //������� �� ����� �� ���������
		}

		//�����3
		fgets(stroka, 4096, file_read);
		if (attributes[6]) {
			stroka[strlen(stroka) - 1] = 0;
			//fill_cell(stroka); //������� �� ����� �� ���������
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
