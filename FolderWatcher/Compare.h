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
	private: System::Windows::Forms::ToolTip^ toolTip1;
		   System::String^ second_path;
	public:
		Compare(System::ComponentModel::ComponentResourceManager^ resources, String^ path_for_first_grid,String^ path_for_second_grid)
		{
			//System::String^ new_path = msclr::interop::marshal_as<System::String^>(path);
			first_path = path_for_first_grid;
			second_path = path_for_second_grid;
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
		void Add_Column_Headers() {
			int sum = 0;
			for (int i = 0; i < 7; i++)
				sum += check_box[i];
			if (sum > 1) {
				dataGridView1->Columns->Add("FileName", "File Name");
				dataGridView1->Columns[dataGridView1->ColumnCount - 1]->Width = dataGridView1->Width * 0.35;
				dataGridView2->Columns->Add("FileName", "File Name");
				dataGridView2->Columns[dataGridView2->ColumnCount - 1]->Width = dataGridView2->Width * 0.35;
				sum--;
				if (check_box[1] == true) {
					dataGridView1->Columns->Add("Size", "Size");
					dataGridView1->Columns[dataGridView1->ColumnCount - 1]->Width = dataGridView1->Width * 0.65 / sum;
					dataGridView2->Columns->Add("Size", "Size");
					dataGridView2->Columns[dataGridView2->ColumnCount - 1]->Width = dataGridView2->Width * 0.65 / sum;
				}
				if (check_box[2] == true) {
					dataGridView1->Columns->Add("Attributes", "Attributes");
					dataGridView1->Columns[dataGridView1->ColumnCount - 1]->Width = dataGridView1->Width * 0.65 / sum;
					dataGridView2->Columns->Add("Attributes", "Attributes");
					dataGridView2->Columns[dataGridView2->ColumnCount - 1]->Width = dataGridView2->Width * 0.65 / sum;
				}
				if (check_box[3] == true) {
					dataGridView1->Columns->Add("Streams", "Streams");
					dataGridView1->Columns[dataGridView1->ColumnCount - 1]->Width = dataGridView1->Width * 0.65 / sum;
					dataGridView2->Columns->Add("Streams", "Streams");
					dataGridView2->Columns[dataGridView2->ColumnCount - 1]->Width = dataGridView2->Width * 0.65 / sum;
				}
				if (check_box[4] == true) {
					dataGridView1->Columns->Add("CreationTime", "Creation Time");
					dataGridView1->Columns[dataGridView1->ColumnCount - 1]->Width = dataGridView1->Width * 0.65 / sum;
					dataGridView2->Columns->Add("CreationTime", "Creation Time");
					dataGridView2->Columns[dataGridView2->ColumnCount - 1]->Width = dataGridView2->Width * 0.65 / sum;
				}
				if (check_box[5] == true) {
					dataGridView1->Columns->Add("ModificationTime", "Modification Time");
					dataGridView1->Columns[dataGridView1->ColumnCount - 1]->Width = dataGridView1->Width * 0.65 / sum;
					dataGridView2->Columns->Add("ModificationTime", "Modification Time");
					dataGridView2->Columns[dataGridView2->ColumnCount - 1]->Width = dataGridView2->Width * 0.65 / sum;
				}
				if (check_box[6] == true) {
					dataGridView1->Columns->Add("AccessTime", "Access Time");
					dataGridView1->Columns[dataGridView1->ColumnCount - 1]->Width = dataGridView1->Width * 0.65 / sum;
					dataGridView2->Columns->Add("AccessTime", "Access Time");
					dataGridView2->Columns[dataGridView2->ColumnCount - 1]->Width = dataGridView2->Width * 0.65 / sum;
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
		void InitializeComponent()
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
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
			this->toolTip1->SetToolTip(this->dataGridView1, L"Hello");
			this->dataGridView1->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Compare::dataGridView1_CellClick);
			this->dataGridView1->CellDoubleClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Compare::dataGridView1_CellDoubleClick);
			this->dataGridView1->CellMouseEnter += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Compare::dataGridView1_CellMouseEnter);
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
			// toolTip1
			// 
			this->toolTip1->Active = false;
			this->toolTip1->AutomaticDelay = 0;
			this->toolTip1->IsBalloon = true;
			this->toolTip1->ShowAlways = true;
			this->toolTip1->ToolTipIcon = System::Windows::Forms::ToolTipIcon::Info;
			this->toolTip1->ToolTipTitle = L"Info";
			// 
			// Compare
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1123, 538);
			this->Controls->Add(this->splitContainer1);
			this->MinimumSize = System::Drawing::Size(1141, 585);
			this->Name = L"Compare";
			this->Text = L"Compare";
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

	std::string temp = msclr::interop::marshal_as<std::string>(first_path->Substring(0));
	char* path1 = new char[temp.length() + 1];
	strcpy(path1, temp.c_str());

	temp = msclr::interop::marshal_as<std::string>(second_path->Substring(0));
	char* path2 = new char[temp.length() + 1];
	strcpy(path2, temp.c_str());

	char* stroka1 = new char[4096];
	char* stroka2 = new char[4096];
	char* NAME1 = new char[4096];
	char* NAME2 = new char[4096];
	int count1 = 0, count2 = 0;

	FILE* file_read1, * file_read2;

	if (is_file_or_folder(path1) == _FOLDER) {
		char* char_snap_path = new char[1024];
		wcstombs(char_snap_path, TempSnapShot1, 1024);

		file_information(path1, char_snap_path);
		file_read1 = fopen(char_snap_path, "r");
		fgets(stroka1, 8, file_read1);
		strcpy(NAME1, char_snap_path);

		delete[] char_snap_path;
	}
	else {
		file_read1 = fopen(path1, "r");
		fgets(stroka1, 8, file_read1);
		if (!(stroka1[0] == 7 && stroka1[1] == 3 && stroka1[2] == 5 && stroka1[3] == 9 && stroka1[4] == 2 && stroka1[5] == 7 && stroka1[6] == '\n')) {
			//MessageBox::Show("Incorrect snapshot", "Error",
			//	MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
			//delete[] NAME2;
			//delete[] NAME1;
			//delete[] stroka2;
			//delete[] stroka1;
			//delete[] path2;
			//delete[] path1;
			//return;
		}
		strcpy(NAME1, path1);
	}

	fgets(stroka1, 9, file_read1);
	for (int i = 0; i < 7; i++) {
		if (stroka1[i] == '1')
			check_box[i] = true;
		else
			check_box[i] = false;
	}

	if (is_file_or_folder(path2) == _FOLDER) {
		char* char_snap_path = new char[1024];
		wcstombs(char_snap_path, TempSnapShot2, 1024);

		file_information(path2, char_snap_path);
		file_read2 = fopen(char_snap_path, "r");
		fgets(stroka2, 8, file_read2);
		strcpy(NAME2, char_snap_path);

		delete[] char_snap_path;
	}
	else {
		file_read2 = fopen(path2, "r");
		fgets(stroka2, 8, file_read2);
		if (!(stroka2[0] == 7 && stroka2[1] == 3 && stroka2[2] == 5 && stroka2[3] == 9 && stroka2[4] == 2 && stroka2[5] == 7 && stroka2[6] == '\n')) {
			//MessageBox::Show("Incorrect snapshot", "Error",
			//	MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
			//delete[] NAME2;
			//delete[] NAME1;
			//delete[] stroka2;
			//delete[] stroka1;
			//delete[] path2;
			//delete[] path1;
			//return;
		}
		strcpy(NAME2, path2);
	}

	fgets(stroka2, 9, file_read2);
	for (int i = 0; i < 7; i++)
		if (stroka2[i] == '0')
			check_box[i] = false;

	Add_Column_Headers();

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

	bool* checked_file1 = new bool[count1]();
	bool* checked_file2 = new bool[count2]();

	file_read1 = fopen(NAME1, "r");
	file_read2 = fopen(NAME2, "r");
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

			dataGridView1->Rows->Add();
			dataGridView2->Rows->Add();

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
				dataGridView2->Rows[row_cnt]->Cells[col_cnt]->Value = gcnew String(stroka2);
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
				dataGridView2->Rows[row_cnt]->Cells[col_cnt]->Value = gcnew String(stroka2);
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
				dataGridView2->Rows[row_cnt]->Cells[col_cnt]->Value = gcnew String(stroka2);
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
				dataGridView2->Rows[row_cnt]->Cells[col_cnt]->Value = gcnew String(stroka2);
				if (strcmp(stroka1, stroka2)) {
					dataGridView1->Rows[row_cnt]->Cells[col_cnt]->Style->BackColor = Color::LightCoral;
					dataGridView2->Rows[row_cnt]->Cells[col_cnt]->Style->BackColor = Color::LightCoral;
				}
				col_cnt++;
			}

			fgets(stroka1, 4096, file_read1);
			fgets(stroka2, 4096, file_read2);
			if (strcmp(stroka1, stroka2)) {
				//fill_row_compare(); //если хэш изменилс€
			}

			fgets(stroka1, 4096, file_read1);
			fgets(stroka2, 4096, file_read2);
			if (strcmp(stroka1, stroka2)) {
				//fill_row_compare(); //если хэш изменилс€
			}

			fgets(stroka1, 4096, file_read1);
			fgets(stroka2, 4096, file_read2);
			if (strcmp(stroka1, stroka2)) {
				//fill_row_compare(); //если хэш изменилс€
			}

			fgets(stroka1, 4096, file_read1);
			fgets(stroka2, 4096, file_read2);
			if (strcmp(stroka1, stroka2)) {
				dataGridView1->Rows[row_cnt]->Cells[0]->Style->BackColor = Color::HotPink;
				dataGridView2->Rows[row_cnt]->Cells[0]->Style->BackColor = Color::HotPink;
			}

			fgets(stroka1, 4096, file_read1);
			fgets(stroka2, 4096, file_read2);
			if (strcmp(stroka1, stroka2)) {
				dataGridView1->Rows[row_cnt]->Cells[0]->Style->BackColor = Color::HotPink;
				dataGridView2->Rows[row_cnt]->Cells[0]->Style->BackColor = Color::HotPink;
			}

			fgets(stroka1, 4096, file_read1);
			fgets(stroka2, 4096, file_read2);
			if (strcmp(stroka1, stroka2)) {
				dataGridView1->Rows[row_cnt]->Cells[0]->Style->BackColor = Color::HotPink;
				dataGridView2->Rows[row_cnt]->Cells[0]->Style->BackColor = Color::HotPink;
			}

			fclose(file_read2);
			file_read2 = fopen(NAME2, "r");
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

	file_read1 = fopen(NAME1, "r");
	fgets(stroka1, 4096, file_read1);
	fgets(stroka1, 4096, file_read1);
	fgets(stroka1, 4096, file_read1);

	for (int i = 0; i < count1; i++) {
		if (!checked_file1[i]) {

			col_cnt = 0;
			dataGridView1->Rows->Add();

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
				dataGridView1->Rows[row_cnt1]->Cells[col_cnt]->Style->BackColor = Color::LightYellow;
				col_cnt++;
			}

			//врем€1
			fgets(stroka1, 4096, file_read1);
			if (check_box[4]) {
				stroka1[strlen(stroka1) - 1] = 0;
				dataGridView1->Rows[row_cnt1]->Cells[col_cnt]->Value = gcnew String(stroka1);
				dataGridView1->Rows[row_cnt1]->Cells[col_cnt]->Style->BackColor = Color::LightYellow;
				col_cnt++;
			}

			//врем€2
			fgets(stroka1, 4096, file_read1);
			if (check_box[5]) {
				stroka1[strlen(stroka1) - 1] = 0;
				dataGridView1->Rows[row_cnt1]->Cells[col_cnt]->Value = gcnew String(stroka1);
				dataGridView1->Rows[row_cnt1]->Cells[col_cnt]->Style->BackColor = Color::LightYellow;
				col_cnt++;
			}

			//врем€3
			fgets(stroka1, 4096, file_read1);
			if (check_box[6]) {
				stroka1[strlen(stroka1) - 1] = 0;
				dataGridView1->Rows[row_cnt1]->Cells[col_cnt]->Value = gcnew String(stroka1);
				dataGridView1->Rows[row_cnt1]->Cells[col_cnt]->Style->BackColor = Color::LightYellow;
				col_cnt++;
			}
			fgets(stroka1, 4096, file_read1);
			fgets(stroka1, 4096, file_read1);
			fgets(stroka1, 4096, file_read1);
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

	file_read2 = fopen(NAME2, "r");
	fgets(stroka2, 4096, file_read2);
	fgets(stroka2, 4096, file_read2);
	fgets(stroka2, 4096, file_read2);

	for (int i = 0; i < count2; i++) {
		if (!checked_file2[i]) {

			col_cnt = 0;
			dataGridView2->Rows->Add();

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
				dataGridView2->Rows[row_cnt2]->Cells[col_cnt]->Style->BackColor = Color::LightYellow;
				col_cnt++;
			}

			//врем€1
			fgets(stroka2, 4096, file_read2);
			if (check_box[4]) {
				stroka2[strlen(stroka2) - 1] = 0;
				dataGridView2->Rows[row_cnt2]->Cells[col_cnt]->Value = gcnew String(stroka2);
				dataGridView2->Rows[row_cnt2]->Cells[col_cnt]->Style->BackColor = Color::LightYellow;
				col_cnt++;
			}

			//врем€2
			fgets(stroka2, 4096, file_read2);
			if (check_box[5]) {
				stroka2[strlen(stroka2) - 1] = 0;
				dataGridView2->Rows[row_cnt2]->Cells[col_cnt]->Value = gcnew String(stroka2);
				dataGridView2->Rows[row_cnt2]->Cells[col_cnt]->Style->BackColor = Color::LightYellow;
				col_cnt++;
			}

			//врем€3
			fgets(stroka2, 4096, file_read2);
			if (check_box[6]) {
				stroka2[strlen(stroka2) - 1] = 0;
				dataGridView2->Rows[row_cnt2]->Cells[col_cnt]->Value = gcnew String(stroka2);
				dataGridView2->Rows[row_cnt2]->Cells[col_cnt]->Style->BackColor = Color::LightYellow;
				col_cnt++;
			}
			fgets(stroka2, 4096, file_read2);
			fgets(stroka2, 4096, file_read2);
			fgets(stroka2, 4096, file_read2);
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

	delete[] NAME2;
	delete[] NAME1;
	delete[] stroka2;
	delete[] stroka1;

	dataGridView1->ClearSelection();
	dataGridView2->ClearSelection();

	delete[] path2;
	delete[] path1;
}
private: System::Void dataGridView1_SizeChanged(System::Object^ sender, System::EventArgs^ e) {
	if (!dataGridView1->ColumnCount) return;
	int sum = 0, count = dataGridView1->ColumnCount;
	for (int i = 0; i < 7; i++)
		sum += check_box[i];
	if (!dataGridView1->ColumnCount)
		return;
	if (sum > 1) {
		dataGridView1->Columns[dataGridView1->ColumnCount - count]->Width = dataGridView1->Width * 0.35;
		sum--;
		count--;
		if (check_box[1] == true) {
			dataGridView1->Columns[dataGridView1->ColumnCount - count]->Width = dataGridView1->Width * 0.65 / sum;
			count--;
		}
		if (check_box[2] == true) {
			dataGridView1->Columns[dataGridView1->ColumnCount - count]->Width = dataGridView1->Width * 0.65 / sum;
			count--;
		}
		if (check_box[3] == true) {
			dataGridView1->Columns[dataGridView1->ColumnCount - count]->Width = dataGridView1->Width * 0.65 / sum;
			count--;
		}
		if (check_box[4] == true) {
			dataGridView1->Columns[dataGridView1->ColumnCount - count]->Width = dataGridView1->Width * 0.65 / sum;
			count--;
		}
		if (check_box[5] == true) {
			dataGridView1->Columns[dataGridView1->ColumnCount - count]->Width = dataGridView1->Width * 0.65 / sum;
			count--;
		}
		if (check_box[6] == true) {
			dataGridView1->Columns[dataGridView1->ColumnCount - count]->Width = dataGridView1->Width * 0.65 / sum;
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
	if (sum > 1) {
		dataGridView2->Columns[dataGridView1->ColumnCount - count]->Width = dataGridView2->Width * 0.35;
		sum--;
		count--;
		if (check_box[1] == true) {
			dataGridView2->Columns[dataGridView2->ColumnCount - count]->Width = dataGridView2->Width * 0.65 / sum;
			count--;
		}
		if (check_box[2] == true) {
			dataGridView2->Columns[dataGridView2->ColumnCount - count]->Width = dataGridView2->Width * 0.65 / sum;
			count--;
		}
		if (check_box[3] == true) {
			dataGridView2->Columns[dataGridView2->ColumnCount - count]->Width = dataGridView2->Width * 0.65 / sum;
			count--;
		}
		if (check_box[4] == true) {
			dataGridView2->Columns[dataGridView2->ColumnCount - count]->Width = dataGridView2->Width * 0.65 / sum;
			count--;
		}
		if (check_box[5] == true) {
			dataGridView2->Columns[dataGridView2->ColumnCount - count]->Width = dataGridView2->Width * 0.65 / sum;
			count--;
		}
		if (check_box[6] == true) {
			dataGridView2->Columns[dataGridView2->ColumnCount - count]->Width = dataGridView2->Width * 0.65 / sum;
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
private: System::Void dataGridView1_CellMouseEnter(System::Object^ sender, DataGridViewCellEventArgs^ e) {
	toolTip1->Active = true;
	//if (e->RowIndex >= 0) // провер€ем, что мышь наведена на реальную строку, а не на заголовок
	//{
		//String^ tooltip = "ѕодсказка дл€ строки " + e->RowIndex; // текст подсказки
		//ToolTip^ tooltipControl = gcnew ToolTip(); // создаем экземпл€р класса ToolTip
		//tooltipControl->SetToolTip(dataGridView1, tooltip); // устанавливаем подсказку дл€ всего DataGridView
	//}
}

};
}
