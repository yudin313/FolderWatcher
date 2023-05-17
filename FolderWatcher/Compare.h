#pragma once

#include "includes_collection.h"

namespace New {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ Compare
	/// </summary>
	public ref class Compare : public System::Windows::Forms::Form
	{
	System::String^ first_path;
	System::String^ second_path;
	public:
		Compare(System::ComponentModel::ComponentResourceManager^ resources, String^ path_for_first_grid,String^ path_for_second_grid)
		{
			//System::String^ new_path = msclr::interop::marshal_as<System::String^>(path);
			first_path = path_for_first_grid;
			second_path = path_for_second_grid;
			InitializeComponent(resources);
			//
			//TODO: добавьте код конструктора
			//
		}
		void Add_Column_Headers() {
			int sum = 0;
			dataGridView1->Columns->Add("grid1_count_row", "є");
			dataGridView2->Columns->Add("grid2_count_row", "є");
			for (int i = 0; i < 7; i++)
				sum += check_box[i];
			if (sum > 1) {
				dataGridView1->Columns->Add("FileName", "File Name");
				dataGridView2->Columns->Add("FileName", "File Name");
				sum--;
				if (check_box[1] == true) {
					dataGridView1->Columns->Add("Size", "Size");
					dataGridView2->Columns->Add("Size", "Size");
				}
				if (check_box[2] == true) {
					dataGridView1->Columns->Add("Attributes", "Attributes");
					dataGridView2->Columns->Add("Attributes", "Attributes");
				}
				if (check_box[3] == true) {
					dataGridView1->Columns->Add("Streams", "Streams");
					dataGridView2->Columns->Add("Streams", "Streams");
				}
				if (check_box[4] == true) {
					dataGridView1->Columns->Add("CreationTime", "Creation Time");
					dataGridView2->Columns->Add("CreationTime", "Creation Time");
				}
				if (check_box[5] == true) {
					dataGridView1->Columns->Add("ModificationTime", "Modification Time");
					dataGridView2->Columns->Add("ModificationTime", "Modification Time");
				}
				if (check_box[6] == true) {
					dataGridView1->Columns->Add("AccessTime", "Access Time");
					dataGridView2->Columns->Add("AccessTime", "Access Time");
				}
			}
			else {
				dataGridView1->Columns->Add("FileName", "File Name");
				dataGridView1->Columns[0]->Width = dataGridView1->Width;
				dataGridView2->Columns->Add("FileName", "File Name");
				dataGridView2->Columns[0]->Width = dataGridView2->Width;
			}
		}
	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~Compare()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::SplitContainer^ splitContainer1;
	protected:
	private: System::Windows::Forms::DataGridView^ dataGridView2;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		/// System::ComponentModel::ComponentResourceManager^ resources
		void InitializeComponent(System::ComponentModel::ComponentResourceManager^ resources)
		{
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->components = (gcnew System::ComponentModel::Container());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->BeginInit();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			this->SuspendLayout();
			// 
			// splitContainer1
			// 
			this->splitContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer1->Location = System::Drawing::Point(0, 0);
			this->splitContainer1->Name = L"splitContainer1";
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->Controls->Add(this->dataGridView1);
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->Controls->Add(this->dataGridView2);
			this->splitContainer1->Size = System::Drawing::Size(1090, 538);
			this->splitContainer1->SplitterDistance = 543;
			this->splitContainer1->TabIndex = 0;
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::None;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::Color::Silver;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView1->DefaultCellStyle = dataGridViewCellStyle2;
			this->dataGridView1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView1->GridColor = System::Drawing::Color::Gray;
			this->dataGridView1->Location = System::Drawing::Point(0, 0);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
			dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle3->BackColor = System::Drawing::Color::LightCoral;
			dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			dataGridViewCellStyle3->ForeColor = System::Drawing::Color::LightCoral;
			dataGridViewCellStyle3->NullValue = L"1";
			dataGridViewCellStyle3->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle3->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->RowHeadersDefaultCellStyle = dataGridViewCellStyle3;
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->RowHeadersWidth = 15;
			this->dataGridView1->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridView1->Size = System::Drawing::Size(543, 538);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Compare::dataGridView1_CellClick);
			this->dataGridView1->CellDoubleClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Compare::dataGridView1_CellDoubleClick);
			this->dataGridView1->SizeChanged += gcnew System::EventHandler(this, &Compare::dataGridView1_SizeChanged);
			// 
			// dataGridView2
			// 
			this->dataGridView2->AllowUserToAddRows = false;
			this->dataGridView2->AllowUserToDeleteRows = false;
			this->dataGridView2->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView2->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::None;
			dataGridViewCellStyle4->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle4->BackColor = System::Drawing::Color::Silver;
			dataGridViewCellStyle4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			dataGridViewCellStyle4->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle4->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle4->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle4->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView2->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle4;
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView2->Location = System::Drawing::Point(0, 0);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->ReadOnly = true;
			this->dataGridView2->RowHeadersVisible = false;
			this->dataGridView2->RowHeadersWidth = 51;
			this->dataGridView2->RowTemplate->Height = 24;
			this->dataGridView2->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::CellSelect;
			this->dataGridView2->Size = System::Drawing::Size(543, 538);
			this->dataGridView2->TabIndex = 0;
			this->dataGridView2->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Compare::dataGridView2_CellClick);
			this->dataGridView2->CellDoubleClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Compare::dataGridView2_CellDoubleClick);
			this->dataGridView2->SizeChanged += gcnew System::EventHandler(this, &Compare::dataGridView2_SizeChanged);
			// 
			// Compare
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1123, 538);
			this->Controls->Add(this->splitContainer1);
			this->MinimumSize = System::Drawing::Size(1141, 585);
			this->Name = L"Compare";
			this->Text = first_path + " ____ " + second_path;
			this->Load += gcnew System::EventHandler(this, &Compare::Compare_Load);
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->EndInit();
			this->splitContainer1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void Compare_Load(System::Object^ sender, System::EventArgs^ e) {

	bool f1 = false, f2 = false;
	std::wstring str;

	str = msclr::interop::marshal_as<std::wstring>(first_path->Substring(0));
	TCHAR* path1 = new TCHAR[str.length() + 1];
	wcscpy(path1, str.c_str());

	str = msclr::interop::marshal_as<std::wstring>(second_path->Substring(0));
	TCHAR* path2 = new TCHAR[str.length() + 1];
	wcscpy(path2, str.c_str());

	char* stroka1 = new char[4096];
	char* stroka2 = new char[4096];
	int count1 = 0, count2 = 0;
	bool ff1 = false, ff2 = false;

	FILE* file_read1, * file_read2;

	if (is_file_or_folder(path1) == _FOLDER) {
		ff1 = true;
		file_information(path1, TempSnapShot1);
		file_read1 = _wfopen(TempSnapShot1, TEXT("r"));
		fgets(stroka1, 8, file_read1);
	}
	else {
		file_read1 = _wfopen(path1, TEXT("r"));
		fgets(stroka1, 8, file_read1);
		if (!(stroka1[0] == 7 && stroka1[1] == 3 && stroka1[2] == 5 && stroka1[3] == 9 && stroka1[4] == 2 && stroka1[5] == 7 && stroka1[6] == '\n'))
			f1 = true;
	}

	fgets(stroka1, 9, file_read1);
	for (int i = 0; i < 7; i++) {
		if (stroka1[i] == '1')
			check_box[i] = true;
		else
			check_box[i] = false;
	}

	if (is_file_or_folder(path2) == _FOLDER) {
		ff2 = true;
		file_information(path2, TempSnapShot2);
		file_read2 = _wfopen(TempSnapShot2, TEXT("r"));
		fgets(stroka2, 8, file_read2);
	}
	else {
		file_read2 = _wfopen(path2, TEXT("r"));
		fgets(stroka2, 8, file_read2);
		if (!(stroka2[0] == 7 && stroka2[1] == 3 && stroka2[2] == 5 && stroka2[3] == 9 && stroka2[4] == 2 && stroka2[5] == 7 && stroka2[6] == '\n'))
			f2 = true;
	}

	fgets(stroka2, 9, file_read2);
	for (int i = 0; i < 7; i++)
		if (stroka2[i] == '0')
			check_box[i] = false;

	if (f1 == false && f2 == false) {

		Add_Column_Headers();

		char c;
		fseek(file_read1, -1, SEEK_END);
		while ((c = fgetc(file_read1)) != '\n')
			fseek(file_read1, -2, SEEK_CUR);
		int res = fscanf(file_read1, "%i", &count1);
		fseek(file_read1, 0, SEEK_SET);

		fseek(file_read2, -1, SEEK_END);
		while ((c = fgetc(file_read2)) != '\n')
			fseek(file_read2, -2, SEEK_CUR);
		res = fscanf(file_read2, "%i", &count2);
		fseek(file_read2, 0, SEEK_SET);

		bool* checked_file1 = new bool[count1]();
		bool* checked_file2 = new bool[count2]();

		fgets(stroka1, 4096, file_read1);
		fgets(stroka1, 4096, file_read1);
		fgets(stroka1, 4096, file_read1);
		fgets(stroka2, 4096, file_read2);
		fgets(stroka2, 4096, file_read2);

		int i1 = 0, i2 = 0;
		int row_cnt = 0;
		int col_cnt = 0;

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
				fseek(file_read2, 0, SEEK_SET);
				fgets(stroka2, 4096, file_read2);
				fgets(stroka2, 4096, file_read2);
				next_file(file_read1);
				fgets(stroka1, 4096, file_read1);
				i1++;
				i2 = 0;
				continue;
			}
			if (!strcmp(stroka1, stroka2)) {

				dataGridView1->Rows->Add();
				dataGridView2->Rows->Add();
				dataGridView1->Rows[row_cnt]->Cells[col_cnt]->Value = row_cnt + 1;
				dataGridView2->Rows[row_cnt]->Cells[col_cnt]->Value = row_cnt + 1;
				col_cnt++;

				checked_file1[i1] = true;
				checked_file2[i2] = true;
				if (check_box[0]) {
					stroka1[strlen(stroka1) - 1] = 0;
					stroka2[strlen(stroka2) - 1] = 0;
					dataGridView1->Rows[row_cnt]->Cells[col_cnt]->Value = gcnew String(stroka1);
					dataGridView2->Rows[row_cnt]->Cells[col_cnt]->Value = gcnew String(stroka2);
					col_cnt++;
				}

				//размер
				fgets(stroka1, 4096, file_read1);
				fgets(stroka2, 4096, file_read2);
				if (check_box[1]) {
					stroka1[strlen(stroka1) - 1] = 0;
					stroka2[strlen(stroka2) - 1] = 0;
					dataGridView1->Rows[row_cnt]->Cells[col_cnt]->Value = gcnew String(stroka1);
					dataGridView2->Rows[row_cnt]->Cells[col_cnt]->Value = gcnew String(stroka2);
					if (strcmp(stroka1, stroka2)) {
						dataGridView1->Rows[row_cnt]->Cells[col_cnt]->Style->BackColor = Color::LightCoral;
						dataGridView2->Rows[row_cnt]->Cells[col_cnt]->Style->BackColor = Color::LightCoral;
					}
					col_cnt++;
				}

				//атрибуты безопасности
				fgets(stroka1, 4096, file_read1);
				fgets(stroka2, 4096, file_read2);
				if (check_box[2]) {
					stroka1[strlen(stroka1) - 2] = 0;
					stroka2[strlen(stroka2) - 2] = 0;
					dataGridView1->Rows[row_cnt]->Cells[col_cnt]->Value = gcnew String(stroka1);
					dataGridView2->Rows[row_cnt]->Cells[col_cnt]->Value = gcnew String(stroka2);
					if (strcmp(stroka1, stroka2)) {
						dataGridView1->Rows[row_cnt]->Cells[col_cnt]->Style->BackColor = Color::LightCoral;
						dataGridView2->Rows[row_cnt]->Cells[col_cnt]->Style->BackColor = Color::LightCoral;
					}
					col_cnt++;
				}

				//альтернативные потоки
				fgets(stroka1, 4096, file_read1);
				fgets(stroka2, 4096, file_read2);
				if (check_box[3]) {
					stroka1[strlen(stroka1) - 2] = 0;
					stroka2[strlen(stroka2) - 2] = 0;
					dataGridView1->Rows[row_cnt]->Cells[col_cnt]->Value = gcnew String(stroka1);
					dataGridView1->Rows[row_cnt]->Cells[col_cnt]->Style->WrapMode = DataGridViewTriState::True;
					dataGridView2->Rows[row_cnt]->Cells[col_cnt]->Value = gcnew String(stroka2);
					dataGridView2->Rows[row_cnt]->Cells[col_cnt]->Style->WrapMode = DataGridViewTriState::True;
					if (strcmp(stroka1, stroka2)) {
						dataGridView1->Rows[row_cnt]->Cells[col_cnt]->Style->BackColor = Color::LightCoral;
						dataGridView2->Rows[row_cnt]->Cells[col_cnt]->Style->BackColor = Color::LightCoral;
					}
					col_cnt++;
				}

				//врем€1
				fgets(stroka1, 4096, file_read1);
				fgets(stroka2, 4096, file_read2);
				if (check_box[4]) {
					stroka1[strlen(stroka1) - 1] = 0;
					stroka2[strlen(stroka2) - 1] = 0;
					dataGridView1->Rows[row_cnt]->Cells[col_cnt]->Value = gcnew String(stroka1);
					dataGridView1->Rows[row_cnt]->Cells[col_cnt]->Style->WrapMode = DataGridViewTriState::True;
					dataGridView2->Rows[row_cnt]->Cells[col_cnt]->Value = gcnew String(stroka2);
					dataGridView2->Rows[row_cnt]->Cells[col_cnt]->Style->WrapMode = DataGridViewTriState::True;
					if (strcmp(stroka1, stroka2)) {
						dataGridView1->Rows[row_cnt]->Cells[col_cnt]->Style->BackColor = Color::LightCoral;
						dataGridView2->Rows[row_cnt]->Cells[col_cnt]->Style->BackColor = Color::LightCoral;
					}
					col_cnt++;
				}

				//врем€2
				fgets(stroka1, 4096, file_read1);
				fgets(stroka2, 4096, file_read2);
				if (check_box[5]) {
					stroka1[strlen(stroka1) - 1] = 0;
					stroka2[strlen(stroka2) - 1] = 0;
					dataGridView1->Rows[row_cnt]->Cells[col_cnt]->Value = gcnew String(stroka1);
					dataGridView1->Rows[row_cnt]->Cells[col_cnt]->Style->WrapMode = DataGridViewTriState::True;
					dataGridView2->Rows[row_cnt]->Cells[col_cnt]->Value = gcnew String(stroka2);
					dataGridView2->Rows[row_cnt]->Cells[col_cnt]->Style->WrapMode = DataGridViewTriState::True;
					if (strcmp(stroka1, stroka2)) {
						dataGridView1->Rows[row_cnt]->Cells[col_cnt]->Style->BackColor = Color::LightCoral;
						dataGridView2->Rows[row_cnt]->Cells[col_cnt]->Style->BackColor = Color::LightCoral;
					}
					col_cnt++;
				}

				//врем€3
				fgets(stroka1, 4096, file_read1);
				fgets(stroka2, 4096, file_read2);
				if (check_box[6]) {
					stroka1[strlen(stroka1) - 1] = 0;
					stroka2[strlen(stroka2) - 1] = 0;
					dataGridView1->Rows[row_cnt]->Cells[col_cnt]->Value = gcnew String(stroka1);
					dataGridView1->Rows[row_cnt]->Cells[col_cnt]->Style->WrapMode = DataGridViewTriState::True;
					dataGridView2->Rows[row_cnt]->Cells[col_cnt]->Value = gcnew String(stroka2);
					dataGridView2->Rows[row_cnt]->Cells[col_cnt]->Style->WrapMode = DataGridViewTriState::True;
					if (strcmp(stroka1, stroka2)) {
						dataGridView1->Rows[row_cnt]->Cells[col_cnt]->Style->BackColor = Color::LightCoral;
						dataGridView2->Rows[row_cnt]->Cells[col_cnt]->Style->BackColor = Color::LightCoral;
					}
					col_cnt++;
				}

				fgets(stroka1, 4096, file_read1);
				fgets(stroka2, 4096, file_read2);
				if (strcmp(stroka1, stroka2)) {
					dataGridView1->Rows[row_cnt]->Cells[1]->Style->BackColor = Color::HotPink;
					dataGridView2->Rows[row_cnt]->Cells[1]->Style->BackColor = Color::HotPink;
				}

				fgets(stroka1, 4096, file_read1);
				fgets(stroka2, 4096, file_read2);
				if (strcmp(stroka1, stroka2)) {
					dataGridView1->Rows[row_cnt]->Cells[1]->Style->BackColor = Color::HotPink;
					dataGridView2->Rows[row_cnt]->Cells[1]->Style->BackColor = Color::HotPink;
				}

				fgets(stroka1, 4096, file_read1);
				fgets(stroka2, 4096, file_read2);
				if (strcmp(stroka1, stroka2)) {
					dataGridView1->Rows[row_cnt]->Cells[1]->Style->BackColor = Color::HotPink;
					dataGridView2->Rows[row_cnt]->Cells[1]->Style->BackColor = Color::HotPink;
				}

				fseek(file_read2, 0, SEEK_SET);
				fgets(stroka2, 4096, file_read2);
				fgets(stroka2, 4096, file_read2);
				fgets(stroka1, 4096, file_read1);
				row_cnt++;
				col_cnt = 0;
				i1++;
				i2 = 0;
			}
			else {
				next_file(file_read2);
				i2++;
			}
		}

		int row_cnt1 = row_cnt;
		int row_cnt2 = row_cnt;

		if (ff1)
			file_read1 = _wfopen(TempSnapShot1, TEXT("r"));
		else
			file_read1 = _wfopen(path1, TEXT("r"));
		fgets(stroka1, 4096, file_read1);
		fgets(stroka1, 4096, file_read1);
		fgets(stroka1, 4096, file_read1);

		for (int i = 0; i < count1; i++) {
			if (!checked_file1[i]) {

				col_cnt = 0;
				dataGridView1->Rows->Add();
				dataGridView1->Rows[row_cnt1]->Cells[col_cnt]->Value = row_cnt1 + 1;
				dataGridView1->Rows[row_cnt1]->Cells[col_cnt]->Style->BackColor = Color::LightYellow;
				col_cnt++;

				if (check_box[0]) {
					stroka1[strlen(stroka1) - 1] = 0;
					dataGridView1->Rows[row_cnt1]->Cells[col_cnt]->Value = gcnew String(stroka1);
					dataGridView1->Rows[row_cnt1]->Cells[col_cnt]->Style->BackColor = Color::LightYellow;
					col_cnt++;
				}

				//размер
				fgets(stroka1, 4096, file_read1);
				if (check_box[1]) {
					stroka1[strlen(stroka1) - 1] = 0;
					dataGridView1->Rows[row_cnt1]->Cells[col_cnt]->Value = gcnew String(stroka1);
					dataGridView1->Rows[row_cnt1]->Cells[col_cnt]->Style->BackColor = Color::LightYellow;
					col_cnt++;
				}

				//атрибуты безопасности
				fgets(stroka1, 4096, file_read1);
				if (check_box[2]) {
					stroka1[strlen(stroka1) - 2] = 0;
					dataGridView1->Rows[row_cnt1]->Cells[col_cnt]->Value = gcnew String(stroka1);
					dataGridView1->Rows[row_cnt1]->Cells[col_cnt]->Style->BackColor = Color::LightYellow;
					col_cnt++;
				}

				//альтернативные потоки
				fgets(stroka1, 4096, file_read1);
				if (check_box[3]) {
					stroka1[strlen(stroka1) - 2] = 0;
					dataGridView1->Rows[row_cnt1]->Cells[col_cnt]->Value = gcnew String(stroka1);
					dataGridView1->Rows[row_cnt1]->Cells[col_cnt]->Style->WrapMode = DataGridViewTriState::True;
					dataGridView1->Rows[row_cnt1]->Cells[col_cnt]->Style->BackColor = Color::LightYellow;
					col_cnt++;
				}

				//врем€1
				fgets(stroka1, 4096, file_read1);
				if (check_box[4]) {
					stroka1[strlen(stroka1) - 1] = 0;
					dataGridView1->Rows[row_cnt1]->Cells[col_cnt]->Value = gcnew String(stroka1);
					dataGridView1->Rows[row_cnt1]->Cells[col_cnt]->Style->WrapMode = DataGridViewTriState::True;
					dataGridView1->Rows[row_cnt1]->Cells[col_cnt]->Style->BackColor = Color::LightYellow;
					col_cnt++;
				}

				//врем€2
				fgets(stroka1, 4096, file_read1);
				if (check_box[5]) {
					stroka1[strlen(stroka1) - 1] = 0;
					dataGridView1->Rows[row_cnt1]->Cells[col_cnt]->Value = gcnew String(stroka1);
					dataGridView1->Rows[row_cnt1]->Cells[col_cnt]->Style->WrapMode = DataGridViewTriState::True;
					dataGridView1->Rows[row_cnt1]->Cells[col_cnt]->Style->BackColor = Color::LightYellow;
					col_cnt++;
				}

				//врем€3
				fgets(stroka1, 4096, file_read1);
				if (check_box[6]) {
					stroka1[strlen(stroka1) - 1] = 0;
					dataGridView1->Rows[row_cnt1]->Cells[col_cnt]->Value = gcnew String(stroka1);
					dataGridView1->Rows[row_cnt1]->Cells[col_cnt]->Style->WrapMode = DataGridViewTriState::True;
					dataGridView1->Rows[row_cnt1]->Cells[col_cnt]->Style->BackColor = Color::LightYellow;
					col_cnt++;
				}
				fgets(stroka1, 4096, file_read1);
				fgets(stroka1, 4096, file_read1);
				fgets(stroka1, 4096, file_read1);
				fgets(stroka1, 4096, file_read1);

				row_cnt1++;
			}
			else {
				next_file(file_read1);
				fgets(stroka1, 4096, file_read1);
			}
		}
		fclose(file_read1);

		if (ff2)
			file_read2 = _wfopen(TempSnapShot2, TEXT("r"));
		else
			file_read2 = _wfopen(path2, TEXT("r"));
		fgets(stroka2, 4096, file_read2);
		fgets(stroka2, 4096, file_read2);
		fgets(stroka2, 4096, file_read2);

		for (int i = 0; i < count2; i++) {
			if (!checked_file2[i]) {

				col_cnt = 0;
				dataGridView2->Rows->Add();
				dataGridView2->Rows[row_cnt2]->Cells[col_cnt]->Value = row_cnt2 + 1;
				dataGridView2->Rows[row_cnt2]->Cells[col_cnt]->Style->BackColor = Color::LightYellow;
				col_cnt++;

				if (check_box[0]) {
					stroka2[strlen(stroka2) - 1] = 0;
					dataGridView2->Rows[row_cnt2]->Cells[col_cnt]->Value = gcnew String(stroka2);
					dataGridView2->Rows[row_cnt2]->Cells[col_cnt]->Style->BackColor = Color::LightYellow;
					col_cnt++;
				}

				//размер
				fgets(stroka2, 4096, file_read2);
				if (check_box[1]) {
					stroka2[strlen(stroka2) - 1] = 0;
					dataGridView2->Rows[row_cnt2]->Cells[col_cnt]->Value = gcnew String(stroka2);
					dataGridView2->Rows[row_cnt2]->Cells[col_cnt]->Style->BackColor = Color::LightYellow;
					col_cnt++;
				}

				//атрибуты безопасности
				fgets(stroka2, 4096, file_read2);
				if (check_box[2]) {
					stroka2[strlen(stroka2) - 2] = 0;
					dataGridView2->Rows[row_cnt2]->Cells[col_cnt]->Value = gcnew String(stroka2);
					dataGridView2->Rows[row_cnt2]->Cells[col_cnt]->Style->BackColor = Color::LightYellow;
					col_cnt++;
				}

				//альтернативные потоки
				fgets(stroka2, 4096, file_read2);
				if (check_box[3]) {
					stroka2[strlen(stroka2) - 2] = 0;
					dataGridView2->Rows[row_cnt2]->Cells[col_cnt]->Value = gcnew String(stroka2);
					dataGridView2->Rows[row_cnt2]->Cells[col_cnt]->Style->WrapMode = DataGridViewTriState::True;
					dataGridView2->Rows[row_cnt2]->Cells[col_cnt]->Style->BackColor = Color::LightYellow;
					col_cnt++;
				}

				//врем€1
				fgets(stroka2, 4096, file_read2);
				if (check_box[4]) {
					stroka2[strlen(stroka2) - 1] = 0;
					dataGridView2->Rows[row_cnt2]->Cells[col_cnt]->Value = gcnew String(stroka2);
					dataGridView2->Rows[row_cnt2]->Cells[col_cnt]->Style->WrapMode = DataGridViewTriState::True;
					dataGridView2->Rows[row_cnt2]->Cells[col_cnt]->Style->BackColor = Color::LightYellow;
					col_cnt++;
				}

				//врем€2
				fgets(stroka2, 4096, file_read2);
				if (check_box[5]) {
					stroka2[strlen(stroka2) - 1] = 0;
					dataGridView2->Rows[row_cnt2]->Cells[col_cnt]->Value = gcnew String(stroka2);
					dataGridView2->Rows[row_cnt2]->Cells[col_cnt]->Style->WrapMode = DataGridViewTriState::True;
					dataGridView2->Rows[row_cnt2]->Cells[col_cnt]->Style->BackColor = Color::LightYellow;
					col_cnt++;
				}

				//врем€3
				fgets(stroka2, 4096, file_read2);
				if (check_box[6]) {
					stroka2[strlen(stroka2) - 1] = 0;
					dataGridView2->Rows[row_cnt2]->Cells[col_cnt]->Value = gcnew String(stroka2);
					dataGridView2->Rows[row_cnt2]->Cells[col_cnt]->Style->WrapMode = DataGridViewTriState::True;
					dataGridView2->Rows[row_cnt2]->Cells[col_cnt]->Style->BackColor = Color::LightYellow;
					col_cnt++;
				}
				fgets(stroka2, 4096, file_read2);
				fgets(stroka2, 4096, file_read2);
				fgets(stroka2, 4096, file_read2);
				fgets(stroka2, 4096, file_read2);

				row_cnt2++;
			}
			else {
				next_file(file_read2);
				fgets(stroka2, 4096, file_read2);
			}
		}
		fclose(file_read2);

		delete[] stroka2;
		delete[] stroka1;

		dataGridView1->ClearSelection();
		dataGridView2->ClearSelection();

		dataGridView1->AutoResizeRows();
		dataGridView2->AutoResizeRows();

		delete[] path2;
		delete[] path1;
	}
	else {
		fclose(file_read1);
		fclose(file_read2);
		delete[] stroka2;
		delete[] stroka1;
		delete[] path2;
		delete[] path1;
		MessageBox::Show("The snapshot(s) is(are) corrupted", "Error", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
	}
}
private: System::Void dataGridView1_SizeChanged(System::Object^ sender, System::EventArgs^ e) {
	if (!dataGridView1->ColumnCount) return;
	int sum = 0, count = dataGridView1->ColumnCount;
	for (int i = 0; i < 7; i++)
		sum += check_box[i];
	if (!dataGridView1->ColumnCount)
		return;
	dataGridView1->Columns[dataGridView1->ColumnCount - count]->Width = 40;
	count--;
	int width = dataGridView1->Width - 40;
	if (sum > 1) {
		dataGridView1->Columns[dataGridView1->ColumnCount - count]->Width = width * 0.25;
		sum--;
		count--;
		if (check_box[1] == true) {
			dataGridView1->Columns[dataGridView1->ColumnCount - count]->Width = width * 0.75 / sum;
			count--;
		}
		if (check_box[2] == true) {
			dataGridView1->Columns[dataGridView1->ColumnCount - count]->Width = width * 0.75 / sum;
			count--;
		}
		if (check_box[3] == true) {
			dataGridView1->Columns[dataGridView1->ColumnCount - count]->Width = width * 0.75 / sum;
			count--;
		}
		if (check_box[4] == true) {
			dataGridView1->Columns[dataGridView1->ColumnCount - count]->Width = width * 0.75 / sum;
			count--;
		}
		if (check_box[5] == true) {
			dataGridView1->Columns[dataGridView1->ColumnCount - count]->Width = width * 0.75 / sum;
			count--;
		}
		if (check_box[6] == true) {
			dataGridView1->Columns[dataGridView1->ColumnCount - count]->Width = width * 0.75 / sum;
		}
	}
	else
		dataGridView1->Columns[0]->Width = dataGridView1->Width;
}
private: System::Void dataGridView2_SizeChanged(System::Object^ sender, System::EventArgs^ e) {
	if (!dataGridView2->ColumnCount) return;
	int sum = 0, count = dataGridView2->ColumnCount;
	for (int i = 0; i < 7; i++)
		sum += check_box[i];
	if (!dataGridView2->ColumnCount)
		return;
	dataGridView2->Columns[dataGridView1->ColumnCount - count]->Width = 40;
	count--;
	int width = dataGridView2->Width - 40;
	if (sum > 1) {
		dataGridView2->Columns[dataGridView1->ColumnCount - count]->Width = width * 0.25;
		sum--;
		count--;
		if (check_box[1] == true) {
			dataGridView2->Columns[dataGridView2->ColumnCount - count]->Width = width * 0.75 / sum;
			count--;
		}
		if (check_box[2] == true) {
			dataGridView2->Columns[dataGridView2->ColumnCount - count]->Width = width * 0.75 / sum;
			count--;
		}
		if (check_box[3] == true) {
			dataGridView2->Columns[dataGridView2->ColumnCount - count]->Width = width * 0.75 / sum;
			count--;
		}
		if (check_box[4] == true) {
			dataGridView2->Columns[dataGridView2->ColumnCount - count]->Width = width * 0.75 / sum;
			count--;
		}
		if (check_box[5] == true) {
			dataGridView2->Columns[dataGridView2->ColumnCount - count]->Width = width * 0.75 / sum;
			count--;
		}
		if (check_box[6] == true) {
			dataGridView2->Columns[dataGridView2->ColumnCount - count]->Width = width * 0.75 / sum;
		}
	}
	else
		dataGridView2->Columns[0]->Width = dataGridView2->Width;
}
private: System::Void dataGridView1_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	dataGridView1->ClearSelection();
}
private: System::Void dataGridView1_CellDoubleClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	dataGridView1->ClearSelection();
}
private: System::Void dataGridView2_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	dataGridView2->ClearSelection();
}
private: System::Void dataGridView2_CellDoubleClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	dataGridView2->ClearSelection();
}
};
}
