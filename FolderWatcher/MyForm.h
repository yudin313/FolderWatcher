#pragma once
#include<iostream>
#include<Windows.h>
#include <filesystem>
#include <fstream>
#include <string>
#include<vcclr.h>
#include <shlobj.h>
#include "Form_Journal.h"
#include "Parameters.h"
#include "backend.h"
#include "globals.h"
#include <msclr\marshal_cppstd.h>
#include<vector>
#include <Shlwapi.h>
#include <ShlObj.h>
#include <filesystem>


#pragma comment(lib, "shell32.lib")
bool button5_first = 0;
bool button5_first_click = 0;
char* save_path;
char* last_saved_path;
bool parameters_flag = true;
namespace Example {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Media;
	using namespace System::Globalization;
	using namespace System::Reflection;
	using namespace System::Collections::Generic;
	using namespace Microsoft::Office::Interop::Excel;
	namespace fs = std::filesystem;
	using namespace System::Diagnostics;
	using namespace Microsoft::Win32;
	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
	private: System::Windows::Forms::ToolStripMenuItem^ darkModeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripStatusLabel^ toolStripStatusLabel2;
	private: System::Windows::Forms::ToolStripStatusLabel^ toolStripStatusLabel3;

	private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;

	
	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ deleteToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ openToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ refreshToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ exportToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ propetiesToolStripMenuItem;







	public:
		Color GridColor = Color::Silver;
		MyForm(void)
		{
			InitializeComponent();

			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::FolderBrowserDialog^ folderBrowserDialog1;

	private:

	private: System::Windows::Forms::MenuStrip^ menuStrip1;

	private: System::Windows::Forms::ToolStripMenuItem^ viewToolStripMenuItem;



	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;

	private: System::Windows::Forms::ToolStripMenuItem^ helpToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ parametersToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ contentToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ infoToolStripMenuItem;










	private: System::Windows::Forms::DataGridView^ dataGridView1;




	private: System::Windows::Forms::ToolTip^ toolTip1;


	private: System::Windows::Forms::ToolStripStatusLabel^ toolStripStatusLabel1;
	private: System::Windows::Forms::ToolStripStatusLabel^ toolStripStatusLabel4;
	private: System::Windows::Forms::StatusStrip^ statusStrip1;



	private:

	public:
		void delete_selected_items() {
			for (int i = 0; i < dataGridView1->SelectedCells->Count; i++) {
				if (dataGridView1->SelectedCells[0]->ColumnIndex != 0)
					return;
				System::Object^ tmp = dataGridView1->SelectedCells[i]->Value;
				struct stat s;
				pin_ptr<const wchar_t> wname;
				try {
					wname = PtrToStringChars(textBox1->Text + "\\" + tmp);
				}
				catch (ArgumentOutOfRangeException^) {
					return;
				}
				char Path[256];
				sprintf(Path, "%ws", wname);
				if (stat(Path, &s) == 0 && s.st_mode & S_IFDIR) {
					try
					{
						fs::remove_all(Path); // удаление папки
					}
					catch (fs::filesystem_error const& e)
					{
					}
				}
				else {
					std::remove(Path);
				}
			}
		}
		void export_selected_items(bool select_all) {
			SaveFileDialog^ SaveFileDialog;
			SaveFileDialog = gcnew System::Windows::Forms::SaveFileDialog;
			SaveFileDialog->FileName = "Export_Table";
			SaveFileDialog->DefaultExt = "xlsx";
			SaveFileDialog->Filter = "Excel files (*.xlsx)|*.xlsx";
			SaveFileDialog->FilterIndex = 1;
			SaveFileDialog->CheckPathExists = true;
			SaveFileDialog->AddExtension = false;
			SaveFileDialog->OverwritePrompt = false;
			System::Windows::Forms::DialogResult result = SaveFileDialog->ShowDialog();

			String^ path = SaveFileDialog->FileName;

			if (File::Exists(path))
			{
				int i = 1;
				while (File::Exists(path))
				{
					path = SaveFileDialog->FileName->Substring(0, SaveFileDialog->FileName->LastIndexOf(".")) + "(" + i + ")" +
						SaveFileDialog->FileName->Substring(SaveFileDialog->FileName->LastIndexOf("."));
					i++;
				}
			}
			SaveFileDialog->FileName = path;
			if (result == System::Windows::Forms::DialogResult::OK) {
				Microsoft::Office::Interop::Excel::Application^ app
					= gcnew Microsoft::Office::Interop::Excel::ApplicationClass();
				app->Visible = false;

				Microsoft::Office::Interop::Excel::Workbook^ workbook
					= app->Workbooks->Add(System::Type::Missing);
				Microsoft::Office::Interop::Excel::Worksheet^ worksheet
					= safe_cast<Microsoft::Office::Interop::Excel::Worksheet^>(app->ActiveSheet);
				worksheet->Name = "List";
				int col = 1;
				int row = 1;
				for each (DataGridViewColumn ^ column in dataGridView1->Columns) {
					worksheet->Cells[row, col++] = column->HeaderText;
				}
				row++;
				if(select_all==true)
					for each (DataGridViewRow ^ datarow in dataGridView1->Rows) {
						col = 1;
						for each (DataGridViewCell ^ cell in datarow->Cells) {
							worksheet->Cells[row, col++] = cell->Value;
						}
						row++;
					}
				else {
					for each (DataGridViewCell ^ cell in dataGridView1->SelectedCells) {
						if (cell->Value != nullptr)
							worksheet->Cells[cell->RowIndex+2, cell->ColumnIndex+1] = cell->Value;
					}
				}
				worksheet->Cells->EntireColumn->AutoFit();
				workbook->SaveAs(SaveFileDialog->FileName,
					System::Type::Missing, System::Type::Missing, System::Type::Missing, false, false,
					Microsoft::Office::Interop::Excel::XlSaveAsAccessMode::xlShared,
					false, false,
					System::Type::Missing, System::Type::Missing, System::Type::Missing
				);
				workbook->Close(false, System::Type::Missing, System::Type::Missing);
				System::Runtime::InteropServices::Marshal::ReleaseComObject(workbook);

				app->Quit();
			}
		}
		void refresh() {
			toolStripStatusLabel4->Image = Image::FromFile("Images\\ready.png");
			toolStripStatusLabel4->Text = "Ready";
			if (textBox1->Text == "") {
				MessageBox::Show("Путь к каталогу не выбран", "Информация",
					MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
				return;
			}
			listBox2->Items->Clear();
			dataGridView1->Rows->Clear();
			if (parameters_flag) {
				dataGridView1->Columns->Clear();
				Add_Column_Headers();
				parameters_flag = false;
			}

			WIN32_FIND_DATAW wfd;
			pin_ptr<const wchar_t> wname = PtrToStringChars(textBox1->Text + "\\*");
			HANDLE const hFind = FindFirstFileW(wname, &wfd);
			setlocale(LC_ALL, "");
			ULONGLONG Size = (static_cast<ULONGLONG>(wfd.nFileSizeHigh) <<
				sizeof(wfd.nFileSizeLow) * 8) |
				wfd.nFileSizeLow;
			ULONGLONG s = (wfd.nFileSizeHigh * (uint64_t)MAXDWORD) + wfd.nFileSizeLow;
			if (INVALID_HANDLE_VALUE != hFind && check_box[0] == true)
			{
				int i = 0;
				DataGridViewRow^ r = gcnew DataGridViewRow();
				array <String^>^ Values = gcnew array <String^>(dataGridView1->ColumnCount);
				do
				{
					dataGridView1->Rows->Add(gcnew String(wfd.cFileName));
					Size += (static_cast<ULONGLONG>(wfd.nFileSizeHigh) <<
						sizeof(wfd.nFileSizeLow) * 8) |
						wfd.nFileSizeLow;
				} while (NULL != FindNextFileW(hFind, &wfd));

				FindClose(hFind);
			}
			ListSortDirection direction = ListSortDirection::Ascending;
			dataGridView1->Sort(dataGridView1->Columns[0], direction);
			if (GridColor == Color::Silver)
				for (int t = 0; t < dataGridView1->RowCount; t++)
					dataGridView1->GridColor = GridColor;
			ChangeMode();
			dataGridView1->Visible = true;
		}
		void copy() {
			List<String^>^ selectedCells = gcnew List<String^>();
			int tmp = dataGridView1->ColumnCount;
			int i = 0;
			for each (DataGridViewCell ^ cell in dataGridView1->SelectedCells)
			{
				if (cell->Value != nullptr)
				{
					if (i == tmp) {
						selectedCells->Add(cell->Value->ToString() + "\n");
						i = 0;
					}
					else
						selectedCells->Add(cell->Value->ToString() + "\t");
				}
				else
				{
					if (i == tmp) {
						selectedCells->Add("\n");
						i = 0;
					}
					else
						selectedCells->Add("");
				}
				i++;
			}
			selectedCells->Reverse();
			if (selectedCells->Count > 0)
			{
				String^ allCellsText = "";
				for each (String ^ cellText in selectedCells)
				{
					allCellsText += cellText;
				}
				Clipboard::SetText(allCellsText->TrimEnd('\t'));

				MessageBox::Show(allCellsText);
			}
		}
		void Add_Column_Headers() {
			int sum = 0;
			for (int i = 0; i < 7; i++)
				sum += check_box[i];
			if (check_box[0] == true) {
				if (sum > 1) {
					dataGridView1->Columns->Add("FileName", "File Name");
					dataGridView1->Columns[dataGridView1->ColumnCount - 1]->Width = dataGridView1->Width * 0.35;
					sum--;
					if (check_box[1] == true) {
						dataGridView1->Columns->Add("Size", "Size");
						dataGridView1->Columns[dataGridView1->ColumnCount - 1]->Width = dataGridView1->Width * 0.65 / sum;
					}
					if (check_box[2] == true) {
						dataGridView1->Columns->Add("Attributes", "Attributes");
						dataGridView1->Columns[dataGridView1->ColumnCount - 1]->Width = dataGridView1->Width * 0.65 / sum;
					}
					if (check_box[3] == true) {
						dataGridView1->Columns->Add("Streams", "Streams");
						dataGridView1->Columns[dataGridView1->ColumnCount - 1]->Width = dataGridView1->Width * 0.65 / sum;
					}
					if (check_box[4] == true) {
						dataGridView1->Columns->Add("CreationTime", "Creation Time");
						dataGridView1->Columns[dataGridView1->ColumnCount - 1]->Width = dataGridView1->Width * 0.65 / sum;
					}
					if (check_box[5] == true) {
						dataGridView1->Columns->Add("ModificationTime", "Modification Time");
						dataGridView1->Columns[dataGridView1->ColumnCount - 1]->Width = dataGridView1->Width * 0.65 / sum;
					}
					if (check_box[6] == true) {
						dataGridView1->Columns->Add("AccessTime", "Access Time");
						dataGridView1->Columns[dataGridView1->ColumnCount - 1]->Width = dataGridView1->Width * 0.65 / sum;
					}
				}
				else {
					dataGridView1->Columns->Add("FileName", "File Name");
					dataGridView1->Columns[0]->Width = dataGridView1->Width;
				}
			}
			else {
				if (check_box[1] == true) {
					dataGridView1->Columns->Add("Size", "Size");
					dataGridView1->Columns[dataGridView1->ColumnCount - 1]->Width = dataGridView1->Width / sum;
				}
				if (check_box[2] == true) {
					dataGridView1->Columns->Add("Attributes", "Attributes");
					dataGridView1->Columns[dataGridView1->ColumnCount - 1]->Width = dataGridView1->Width / sum;
				}
				if (check_box[3] == true) {
					dataGridView1->Columns->Add("Streams", "Streams");
					dataGridView1->Columns[dataGridView1->ColumnCount - 1]->Width = dataGridView1->Width / sum;
				}
				if (check_box[4] == true) {
					dataGridView1->Columns->Add("CreationTime", "Creation Time");
					dataGridView1->Columns[dataGridView1->ColumnCount - 1]->Width = dataGridView1->Width / sum;
				}
				if (check_box[5] == true) {
					dataGridView1->Columns->Add("ModificationTime", "Modification Time");
					dataGridView1->Columns[dataGridView1->ColumnCount - 1]->Width = dataGridView1->Width / sum;
				}
				if (check_box[6] == true) {
					dataGridView1->Columns->Add("AccessTime", "Access Time");
					dataGridView1->Columns[dataGridView1->ColumnCount - 1]->Width = dataGridView1->Width / sum;
				}
			}
		}
		void ChangeMode() {
			if (darkModeToolStripMenuItem->CheckState == System::Windows::Forms::CheckState::Checked) {//тёмная тема
				this->BackColor = Color::FromArgb(25, 25, 25);
				button1->ForeColor = Color::White;
				button2->ForeColor = Color::White;
				button3->ForeColor = Color::White;
				button4->ForeColor = Color::White;
				button5->ForeColor = Color::White;
				button6->ForeColor = Color::White;
				button7->ForeColor = Color::White;
				button1->BackColor = Color::DimGray;
				button2->BackColor = Color::DimGray;
				button3->BackColor = Color::DimGray;
				button4->BackColor = Color::DimGray;
				button5->BackColor = Color::DimGray;
				button6->BackColor = Color::DimGray;
				button7->BackColor = Color::DimGray;
				textBox1->BackColor = Color::DimGray;
				textBox1->ForeColor = Color::White;
				dataGridView1->BackgroundColor = Color::Silver;
				for (int t = 0; t < dataGridView1->RowCount; t++)
					for (int j = 0; j < dataGridView1->ColumnCount; j++) {
						dataGridView1->Rows[t]->Cells[j]->Style->BackColor = Color::DimGray;
						dataGridView1->Rows[t]->Cells[j]->Style->ForeColor = Color::White;
					}
				if (hightlightEvenRowsToolStripMenuItem->CheckState == System::Windows::Forms::CheckState::Checked) {
					for (int t = 0; t < dataGridView1->RowCount; t++)
						if (t % 2 == 0)
							for (int j = 0; j < dataGridView1->ColumnCount; j++)
								dataGridView1->Rows[t]->Cells[j]->Style->BackColor = Color::Gray;
				}
				else
					for (int t = 0; t < dataGridView1->RowCount; t++)
						for (int j = 0; j < dataGridView1->ColumnCount; j++)
							dataGridView1->Rows[t]->Cells[j]->Style->BackColor = Color::DimGray;
				if (showGridLinesToolStripMenuItem->CheckState == System::Windows::Forms::CheckState::Checked)
					for (int t = 0; t < dataGridView1->RowCount; t++)
						dataGridView1->GridColor = Color::Silver;
				else
					for (int t = 0; t < dataGridView1->RowCount; t++)
						dataGridView1->GridColor = Color::DimGray;
				dataGridView1->DefaultCellStyle->SelectionBackColor = Color::DimGray;
				pictureBox1->Image = Image::FromFile("Images\\image_black.png");
			}
			else {//светлая тема
				this->BackColor = Color::WhiteSmoke;
				button1->ForeColor = Color::Black;
				button6->ForeColor = Color::Black;
				button3->ForeColor = Color::Black;
				button4->ForeColor = Color::Black;
				button5->ForeColor = Color::Black;
				button7->ForeColor = Color::Black;
				button2->ForeColor = Color::Black;
				button1->BackColor = Color::Silver;
				button2->BackColor = Color::Silver;
				button3->BackColor = Color::Silver;
				button4->BackColor = Color::Silver;
				button5->BackColor = Color::Silver;
				button6->BackColor = Color::Silver;
				button7->BackColor = Color::Silver;
				textBox1->BackColor = SystemColors::Info;
				textBox1->ForeColor = Color::Black;
				dataGridView1->ForeColor = Color::Black;
				dataGridView1->BackgroundColor = Color::WhiteSmoke;
				for (int t = 0; t < dataGridView1->RowCount; t++)
					for (int j = 0; j < dataGridView1->ColumnCount; j++) {
						dataGridView1->Rows[t]->Cells[j]->Style->BackColor = Color::White;
						dataGridView1->Rows[t]->Cells[j]->Style->ForeColor = Color::Black;
					}
				if (hightlightEvenRowsToolStripMenuItem->CheckState == System::Windows::Forms::CheckState::Checked) {
					for (int t = 0; t < dataGridView1->RowCount; t++)
						if (t % 2 == 0)
							for (int j = 0; j < dataGridView1->ColumnCount; j++)
								dataGridView1->Rows[t]->Cells[j]->Style->BackColor = Color::Bisque;
				}
				else
					for (int t = 0; t < dataGridView1->RowCount; t++)
						for (int j = 0; j < dataGridView1->ColumnCount; j++)
							dataGridView1->Rows[t]->Cells[j]->Style->BackColor = Color::White;
				if (showGridLinesToolStripMenuItem->CheckState == System::Windows::Forms::CheckState::Checked)
					for (int t = 0; t < dataGridView1->RowCount; t++)
						dataGridView1->GridColor = Color::Silver;
				else
					for (int t = 0; t < dataGridView1->RowCount; t++)
						dataGridView1->GridColor = Color::White;
				dataGridView1->DefaultCellStyle->SelectionBackColor = Color::LightGray;
				dataGridView1->DefaultCellStyle->SelectionForeColor = Color::Black;
				pictureBox1->Image = Image::FromFile("Images\\image_white.png");
			}
		}


	private: System::Windows::Forms::Button^ button1;

	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel2;
	private: System::Windows::Forms::TextBox^ textBox1;
		   System::String^ textBox1_saved;


	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Button^ button2;


	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button7;








	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel4;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel5;






	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel6;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel7;













	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel9;
	private: System::DirectoryServices::DirectorySearcher^ directorySearcher1;
	private: System::Windows::Forms::FolderBrowserDialog^ folderBrowserDialog2;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog2;
	private: System::IO::FileSystemWatcher^ fileSystemWatcher1;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::ListBox^ listBox2;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::ToolStripMenuItem^ instrumentsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ runAsAdministratorToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ findToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ exportTableToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ selectAllToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ deselectAllToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ showToolTipsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ showGridLinesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ exitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ hightlightEvenRowsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ exportSelectedItemsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ deleteSelectedItemsToolStripMenuItem;







	private: System::ComponentModel::IContainer^ components;

	protected:


	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle5 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->folderBrowserDialog1 = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->parametersToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->viewToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->selectAllToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->deselectAllToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->showToolTipsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->showGridLinesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->hightlightEvenRowsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->darkModeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->instrumentsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->runAsAdministratorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->findToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exportTableToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exportSelectedItemsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->deleteSelectedItemsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->contentToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->infoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->deleteToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->refreshToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exportToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->propetiesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->toolStripStatusLabel1 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->toolStripStatusLabel4 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->toolStripStatusLabel2 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->toolStripStatusLabel3 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel4 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel6 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->tableLayoutPanel5 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->listBox2 = (gcnew System::Windows::Forms::ListBox());
			this->tableLayoutPanel7 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->tableLayoutPanel9 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->directorySearcher1 = (gcnew System::DirectoryServices::DirectorySearcher());
			this->folderBrowserDialog2 = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->openFileDialog2 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->fileSystemWatcher1 = (gcnew System::IO::FileSystemWatcher());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->contextMenuStrip1->SuspendLayout();
			this->statusStrip1->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->tableLayoutPanel1->SuspendLayout();
			this->tableLayoutPanel4->SuspendLayout();
			this->tableLayoutPanel6->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->tableLayoutPanel5->SuspendLayout();
			this->tableLayoutPanel7->SuspendLayout();
			this->panel2->SuspendLayout();
			this->tableLayoutPanel9->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fileSystemWatcher1))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->fileToolStripMenuItem,
					this->viewToolStripMenuItem, this->instrumentsToolStripMenuItem, this->helpToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1243, 28);
			this->menuStrip1->TabIndex = 19;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->parametersToolStripMenuItem,
					this->exitToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(46, 24);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// parametersToolStripMenuItem
			// 
			this->parametersToolStripMenuItem->Name = L"parametersToolStripMenuItem";
			this->parametersToolStripMenuItem->Size = System::Drawing::Size(165, 26);
			this->parametersToolStripMenuItem->Text = L"Parameters";
			this->parametersToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::parametersToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(165, 26);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::exitToolStripMenuItem_Click);
			// 
			// viewToolStripMenuItem
			// 
			this->viewToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				this->selectAllToolStripMenuItem,
					this->deselectAllToolStripMenuItem, this->showToolTipsToolStripMenuItem, this->showGridLinesToolStripMenuItem, this->hightlightEvenRowsToolStripMenuItem,
					this->darkModeToolStripMenuItem
			});
			this->viewToolStripMenuItem->Name = L"viewToolStripMenuItem";
			this->viewToolStripMenuItem->Size = System::Drawing::Size(55, 24);
			this->viewToolStripMenuItem->Text = L"View";
			// 
			// selectAllToolStripMenuItem
			// 
			this->selectAllToolStripMenuItem->Name = L"selectAllToolStripMenuItem";
			this->selectAllToolStripMenuItem->Size = System::Drawing::Size(233, 26);
			this->selectAllToolStripMenuItem->Text = L"Select All";
			this->selectAllToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::selectAllToolStripMenuItem_Click);
			// 
			// deselectAllToolStripMenuItem
			// 
			this->deselectAllToolStripMenuItem->Name = L"deselectAllToolStripMenuItem";
			this->deselectAllToolStripMenuItem->Size = System::Drawing::Size(233, 26);
			this->deselectAllToolStripMenuItem->Text = L"Deselect All";
			this->deselectAllToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::deselectAllToolStripMenuItem_Click);
			// 
			// showToolTipsToolStripMenuItem
			// 
			this->showToolTipsToolStripMenuItem->Checked = true;
			this->showToolTipsToolStripMenuItem->CheckOnClick = true;
			this->showToolTipsToolStripMenuItem->CheckState = System::Windows::Forms::CheckState::Checked;
			this->showToolTipsToolStripMenuItem->Name = L"showToolTipsToolStripMenuItem";
			this->showToolTipsToolStripMenuItem->Size = System::Drawing::Size(233, 26);
			this->showToolTipsToolStripMenuItem->Text = L"Show ToolTips";
			this->showToolTipsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::showToolTipsToolStripMenuItem_Click);
			// 
			// showGridLinesToolStripMenuItem
			// 
			this->showGridLinesToolStripMenuItem->Checked = true;
			this->showGridLinesToolStripMenuItem->CheckOnClick = true;
			this->showGridLinesToolStripMenuItem->CheckState = System::Windows::Forms::CheckState::Checked;
			this->showGridLinesToolStripMenuItem->Name = L"showGridLinesToolStripMenuItem";
			this->showGridLinesToolStripMenuItem->Size = System::Drawing::Size(233, 26);
			this->showGridLinesToolStripMenuItem->Text = L"Show GridLines";
			this->showGridLinesToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::showGridLinesToolStripMenuItem_Click);
			// 
			// hightlightEvenRowsToolStripMenuItem
			// 
			this->hightlightEvenRowsToolStripMenuItem->CheckOnClick = true;
			this->hightlightEvenRowsToolStripMenuItem->Name = L"hightlightEvenRowsToolStripMenuItem";
			this->hightlightEvenRowsToolStripMenuItem->Size = System::Drawing::Size(233, 26);
			this->hightlightEvenRowsToolStripMenuItem->Text = L"Hightlight Even Rows";
			this->hightlightEvenRowsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::hightlightEvenRowsToolStripMenuItem_Click);
			// 
			// darkModeToolStripMenuItem
			// 
			this->darkModeToolStripMenuItem->CheckOnClick = true;
			this->darkModeToolStripMenuItem->Name = L"darkModeToolStripMenuItem";
			this->darkModeToolStripMenuItem->Size = System::Drawing::Size(233, 26);
			this->darkModeToolStripMenuItem->Text = L"Dark Mode";
			this->darkModeToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::darkModeToolStripMenuItem_Click);
			// 
			// instrumentsToolStripMenuItem
			// 
			this->instrumentsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->runAsAdministratorToolStripMenuItem,
					this->findToolStripMenuItem, this->exportTableToolStripMenuItem, this->exportSelectedItemsToolStripMenuItem, this->deleteSelectedItemsToolStripMenuItem
			});
			this->instrumentsToolStripMenuItem->Name = L"instrumentsToolStripMenuItem";
			this->instrumentsToolStripMenuItem->Size = System::Drawing::Size(99, 24);
			this->instrumentsToolStripMenuItem->Text = L"Instruments";
			// 
			// runAsAdministratorToolStripMenuItem
			// 
			this->runAsAdministratorToolStripMenuItem->Name = L"runAsAdministratorToolStripMenuItem";
			this->runAsAdministratorToolStripMenuItem->Size = System::Drawing::Size(237, 26);
			this->runAsAdministratorToolStripMenuItem->Text = L"Run as Administrator";
			this->runAsAdministratorToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::runAsAdministratorToolStripMenuItem_Click);
			// 
			// findToolStripMenuItem
			// 
			this->findToolStripMenuItem->Name = L"findToolStripMenuItem";
			this->findToolStripMenuItem->Size = System::Drawing::Size(237, 26);
			this->findToolStripMenuItem->Text = L"Find";
			// 
			// exportTableToolStripMenuItem
			// 
			this->exportTableToolStripMenuItem->Name = L"exportTableToolStripMenuItem";
			this->exportTableToolStripMenuItem->Size = System::Drawing::Size(237, 26);
			this->exportTableToolStripMenuItem->Text = L"Export Table";
			this->exportTableToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::exportTableToolStripMenuItem_Click);
			// 
			// exportSelectedItemsToolStripMenuItem
			// 
			this->exportSelectedItemsToolStripMenuItem->Name = L"exportSelectedItemsToolStripMenuItem";
			this->exportSelectedItemsToolStripMenuItem->Size = System::Drawing::Size(237, 26);
			this->exportSelectedItemsToolStripMenuItem->Text = L"Export Selected Items";
			this->exportSelectedItemsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::exportSelectedItemsToolStripMenuItem_Click);
			// 
			// deleteSelectedItemsToolStripMenuItem
			// 
			this->deleteSelectedItemsToolStripMenuItem->Name = L"deleteSelectedItemsToolStripMenuItem";
			this->deleteSelectedItemsToolStripMenuItem->Size = System::Drawing::Size(237, 26);
			this->deleteSelectedItemsToolStripMenuItem->Text = L"Delete Selected Items";
			this->deleteSelectedItemsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::deleteSelectedItemsToolStripMenuItem_Click);
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->contentToolStripMenuItem,
					this->infoToolStripMenuItem
			});
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(55, 24);
			this->helpToolStripMenuItem->Text = L"Help";
			// 
			// contentToolStripMenuItem
			// 
			this->contentToolStripMenuItem->Name = L"contentToolStripMenuItem";
			this->contentToolStripMenuItem->Size = System::Drawing::Size(144, 26);
			this->contentToolStripMenuItem->Text = L"Content";
			this->contentToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::справкаToolStripMenuItem_Click);
			// 
			// infoToolStripMenuItem
			// 
			this->infoToolStripMenuItem->Name = L"infoToolStripMenuItem";
			this->infoToolStripMenuItem->Size = System::Drawing::Size(144, 26);
			this->infoToolStripMenuItem->Text = L"About";
			this->infoToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::оПрограммеToolStripMenuItem_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			dataGridViewCellStyle1->BackColor = System::Drawing::Color::White;
			this->dataGridView1->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView1->BackgroundColor = System::Drawing::Color::WhiteSmoke;
			this->dataGridView1->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::TopLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::Color::Silver;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::Color::Gray;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle2;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->ContextMenuStrip = this->contextMenuStrip1;
			dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle3->BackColor = System::Drawing::Color::Black;
			dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			dataGridViewCellStyle3->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle3->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle3->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView1->DefaultCellStyle = dataGridViewCellStyle3;
			this->dataGridView1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView1->EnableHeadersVisualStyles = false;
			this->dataGridView1->GridColor = System::Drawing::Color::Silver;
			this->dataGridView1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->dataGridView1->Location = System::Drawing::Point(86, 3);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
			dataGridViewCellStyle4->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle4->BackColor = System::Drawing::Color::White;
			dataGridViewCellStyle4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			dataGridViewCellStyle4->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle4->SelectionBackColor = System::Drawing::Color::White;
			dataGridViewCellStyle4->SelectionForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle4->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->RowHeadersDefaultCellStyle = dataGridViewCellStyle4;
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->RowHeadersWidth = 51;
			dataGridViewCellStyle5->BackColor = System::Drawing::Color::White;
			dataGridViewCellStyle5->ForeColor = System::Drawing::Color::Black;
			dataGridViewCellStyle5->SelectionBackColor = System::Drawing::Color::LightGray;
			dataGridViewCellStyle5->SelectionForeColor = System::Drawing::Color::Black;
			this->dataGridView1->RowsDefaultCellStyle = dataGridViewCellStyle5;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::CellSelect;
			this->dataGridView1->Size = System::Drawing::Size(1065, 401);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->Visible = false;
			this->dataGridView1->CellDoubleClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellDoubleClick);
			this->dataGridView1->SizeChanged += gcnew System::EventHandler(this, &MyForm::dataGridView1_SizeChanged);
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->contextMenuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				this->toolStripMenuItem1,
					this->deleteToolStripMenuItem, this->openToolStripMenuItem, this->refreshToolStripMenuItem, this->exportToolStripMenuItem, this->propetiesToolStripMenuItem
			});
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(141, 148);
			// 
			// toolStripMenuItem1
			// 
			this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
			this->toolStripMenuItem1->Size = System::Drawing::Size(140, 24);
			this->toolStripMenuItem1->Text = L"Copy";
			this->toolStripMenuItem1->Click += gcnew System::EventHandler(this, &MyForm::toolStripMenuItem1_Click);
			// 
			// deleteToolStripMenuItem
			// 
			this->deleteToolStripMenuItem->Name = L"deleteToolStripMenuItem";
			this->deleteToolStripMenuItem->Size = System::Drawing::Size(140, 24);
			this->deleteToolStripMenuItem->Text = L"Delete";
			this->deleteToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::deleteToolStripMenuItem_Click);
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->Size = System::Drawing::Size(140, 24);
			this->openToolStripMenuItem->Text = L"Open";
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::openToolStripMenuItem_Click);
			// 
			// refreshToolStripMenuItem
			// 
			this->refreshToolStripMenuItem->Name = L"refreshToolStripMenuItem";
			this->refreshToolStripMenuItem->Size = System::Drawing::Size(140, 24);
			this->refreshToolStripMenuItem->Text = L"Refresh";
			this->refreshToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::refreshToolStripMenuItem_Click);
			// 
			// exportToolStripMenuItem
			// 
			this->exportToolStripMenuItem->Name = L"exportToolStripMenuItem";
			this->exportToolStripMenuItem->Size = System::Drawing::Size(140, 24);
			this->exportToolStripMenuItem->Text = L"Export";
			this->exportToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::exportToolStripMenuItem_Click);
			// 
			// propetiesToolStripMenuItem
			// 
			this->propetiesToolStripMenuItem->Name = L"propetiesToolStripMenuItem";
			this->propetiesToolStripMenuItem->Size = System::Drawing::Size(140, 24);
			this->propetiesToolStripMenuItem->Text = L"Propeties";
			this->propetiesToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::propetiesToolStripMenuItem_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Silver;
			this->button1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button1->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::Control;
			this->button1->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::Control;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button1->Location = System::Drawing::Point(3, 3);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(201, 34);
			this->button1->TabIndex = 0;
			this->button1->Tag = L"";
			this->button1->Text = L"Browse";
			this->toolTip1->SetToolTip(this->button1, L"Select Folder to Scan:");
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::SystemColors::Info;
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(3, 17);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(621, 24);
			this->textBox1->TabIndex = 0;
			this->toolTip1->SetToolTip(this->textBox1, L"Select Folder to Scan:");
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// button7
			// 
			this->button7->AutoSize = true;
			this->button7->BackColor = System::Drawing::Color::Silver;
			this->button7->Enabled = false;
			this->button7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button7->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button7->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button7->Location = System::Drawing::Point(3, 3);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(160, 28);
			this->button7->TabIndex = 0;
			this->button7->Text = L"   Compare";
			this->toolTip1->SetToolTip(this->button7, L"Start comparasing");
			this->button7->UseVisualStyleBackColor = false;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// button4
			// 
			this->button4->AutoSize = true;
			this->button4->BackColor = System::Drawing::Color::Silver;
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button4->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button4->Location = System::Drawing::Point(325, 3);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(150, 28);
			this->button4->TabIndex = 16;
			this->button4->Text = L"   Export";
			this->toolTip1->SetToolTip(this->button4, L"Export existed snapshots");
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button5
			// 
			this->button5->AutoSize = true;
			this->button5->BackColor = System::Drawing::Color::Silver;
			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button5->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button5->Location = System::Drawing::Point(481, 3);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(160, 28);
			this->button5->TabIndex = 15;
			this->button5->Text = L"   Parameters";
			this->toolTip1->SetToolTip(this->button5, L"Parametrs of comparasing and making snapshots");
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// button2
			// 
			this->button2->AutoSize = true;
			this->button2->BackColor = System::Drawing::Color::Silver;
			this->button2->Enabled = false;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button2->Location = System::Drawing::Point(169, 3);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(150, 28);
			this->button2->TabIndex = 12;
			this->button2->Text = L"   Snapshot";
			this->toolTip1->SetToolTip(this->button2, L"Make new snapshot");
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->AutoSize = true;
			this->button3->BackColor = System::Drawing::Color::Silver;
			this->button3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button3->Enabled = false;
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button3->Location = System::Drawing::Point(210, 3);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(201, 34);
			this->button3->TabIndex = 1;
			this->button3->Text = L"Refresh";
			this->toolTip1->SetToolTip(this->button3, L"Update table info");
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button6
			// 
			this->button6->BackColor = System::Drawing::Color::Silver;
			this->button6->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button6->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button6->Location = System::Drawing::Point(417, 3);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(201, 34);
			this->button6->TabIndex = 2;
			this->button6->Text = L"Logs";
			this->toolTip1->SetToolTip(this->button6, L"Watch Event Journal");
			this->button6->UseVisualStyleBackColor = false;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// toolStripStatusLabel1
			// 
			this->toolStripStatusLabel1->Name = L"toolStripStatusLabel1";
			this->toolStripStatusLabel1->Size = System::Drawing::Size(56, 20);
			this->toolStripStatusLabel1->Text = L"Status: ";
			// 
			// toolStripStatusLabel4
			// 
			this->toolStripStatusLabel4->AutoSize = false;
			this->toolStripStatusLabel4->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->toolStripStatusLabel4->Name = L"toolStripStatusLabel4";
			this->toolStripStatusLabel4->Size = System::Drawing::Size(90, 20);
			this->toolStripStatusLabel4->Text = L"Ready";
			// 
			// statusStrip1
			// 
			this->statusStrip1->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->statusStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->toolStripStatusLabel1,
					this->toolStripStatusLabel4, this->toolStripStatusLabel2, this->toolStripStatusLabel3
			});
			this->statusStrip1->Location = System::Drawing::Point(0, 633);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(1243, 26);
			this->statusStrip1->TabIndex = 6;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// toolStripStatusLabel2
			// 
			this->toolStripStatusLabel2->Name = L"toolStripStatusLabel2";
			this->toolStripStatusLabel2->Size = System::Drawing::Size(0, 20);
			// 
			// toolStripStatusLabel3
			// 
			this->toolStripStatusLabel3->Name = L"toolStripStatusLabel3";
			this->toolStripStatusLabel3->Size = System::Drawing::Size(0, 20);
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 1;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel2->Controls->Add(this->tableLayoutPanel1, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->tableLayoutPanel5, 0, 1);
			this->tableLayoutPanel2->Controls->Add(this->tableLayoutPanel7, 0, 2);
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel2->Location = System::Drawing::Point(0, 28);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 3;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 18.53147F)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 68.18182F)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 13.11189F)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(1243, 605);
			this->tableLayoutPanel2->TabIndex = 18;
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->AutoSize = true;
			this->tableLayoutPanel1->ColumnCount = 3;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel4, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->pictureBox1, 2, 1);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(3, 3);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 3;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel1->Size = System::Drawing::Size(1237, 106);
			this->tableLayoutPanel1->TabIndex = 18;
			// 
			// tableLayoutPanel4
			// 
			this->tableLayoutPanel4->ColumnCount = 1;
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel4->Controls->Add(this->textBox1, 0, 1);
			this->tableLayoutPanel4->Controls->Add(this->tableLayoutPanel6, 0, 2);
			this->tableLayoutPanel4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel4->Location = System::Drawing::Point(3, 3);
			this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
			this->tableLayoutPanel4->RowCount = 4;
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 10.78432F)));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 20.96774F)));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 34.55882F)));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 34.55882F)));
			this->tableLayoutPanel4->Size = System::Drawing::Size(627, 136);
			this->tableLayoutPanel4->TabIndex = 4;
			// 
			// tableLayoutPanel6
			// 
			this->tableLayoutPanel6->ColumnCount = 3;
			this->tableLayoutPanel6->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				33.33333F)));
			this->tableLayoutPanel6->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				33.33333F)));
			this->tableLayoutPanel6->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				33.33333F)));
			this->tableLayoutPanel6->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				20)));
			this->tableLayoutPanel6->Controls->Add(this->button1, 0, 0);
			this->tableLayoutPanel6->Controls->Add(this->button3, 1, 0);
			this->tableLayoutPanel6->Controls->Add(this->button6, 2, 0);
			this->tableLayoutPanel6->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel6->Location = System::Drawing::Point(3, 45);
			this->tableLayoutPanel6->Name = L"tableLayoutPanel6";
			this->tableLayoutPanel6->RowCount = 1;
			this->tableLayoutPanel6->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel6->Size = System::Drawing::Size(621, 40);
			this->tableLayoutPanel6->TabIndex = 2;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->pictureBox1->Location = System::Drawing::Point(639, 3);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(595, 136);
			this->pictureBox1->TabIndex = 5;
			this->pictureBox1->TabStop = false;
			// 
			// tableLayoutPanel5
			// 
			this->tableLayoutPanel5->ColumnCount = 3;
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				6.716418F)));
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				86.65009F)));
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				6.633499F)));
			this->tableLayoutPanel5->Controls->Add(this->dataGridView1, 1, 0);
			this->tableLayoutPanel5->Controls->Add(this->listBox2, 2, 0);
			this->tableLayoutPanel5->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel5->Location = System::Drawing::Point(3, 115);
			this->tableLayoutPanel5->Name = L"tableLayoutPanel5";
			this->tableLayoutPanel5->RowCount = 1;
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel5->Size = System::Drawing::Size(1237, 407);
			this->tableLayoutPanel5->TabIndex = 19;
			// 
			// listBox2
			// 
			this->listBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->listBox2->FormattingEnabled = true;
			this->listBox2->ItemHeight = 18;
			this->listBox2->Location = System::Drawing::Point(1157, 3);
			this->listBox2->Name = L"listBox2";
			this->listBox2->Size = System::Drawing::Size(75, 22);
			this->listBox2->TabIndex = 6;
			this->listBox2->Visible = false;
			// 
			// tableLayoutPanel7
			// 
			this->tableLayoutPanel7->ColumnCount = 3;
			this->tableLayoutPanel7->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				10.67961F)));
			this->tableLayoutPanel7->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				89.32039F)));
			this->tableLayoutPanel7->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				505)));
			this->tableLayoutPanel7->Controls->Add(this->panel2, 1, 0);
			this->tableLayoutPanel7->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel7->Location = System::Drawing::Point(3, 528);
			this->tableLayoutPanel7->Name = L"tableLayoutPanel7";
			this->tableLayoutPanel7->RowCount = 1;
			this->tableLayoutPanel7->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel7->Size = System::Drawing::Size(1237, 74);
			this->tableLayoutPanel7->TabIndex = 20;
			// 
			// panel2
			// 
			this->panel2->AutoSize = true;
			this->panel2->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->panel2->Controls->Add(this->tableLayoutPanel9);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel2->Location = System::Drawing::Point(81, 3);
			this->panel2->MaximumSize = System::Drawing::Size(1000, 150);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(647, 68);
			this->panel2->TabIndex = 17;
			// 
			// tableLayoutPanel9
			// 
			this->tableLayoutPanel9->AutoSize = true;
			this->tableLayoutPanel9->ColumnCount = 4;
			this->tableLayoutPanel9->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel9->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel9->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel9->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel9->Controls->Add(this->button7, 0, 0);
			this->tableLayoutPanel9->Controls->Add(this->button5, 3, 0);
			this->tableLayoutPanel9->Controls->Add(this->button4, 2, 0);
			this->tableLayoutPanel9->Controls->Add(this->button2, 1, 0);
			this->tableLayoutPanel9->Location = System::Drawing::Point(0, 16);
			this->tableLayoutPanel9->Name = L"tableLayoutPanel9";
			this->tableLayoutPanel9->RowCount = 1;
			this->tableLayoutPanel9->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel9->Size = System::Drawing::Size(644, 34);
			this->tableLayoutPanel9->TabIndex = 22;
			// 
			// directorySearcher1
			// 
			this->directorySearcher1->ClientTimeout = System::TimeSpan::Parse(L"-00:00:01");
			this->directorySearcher1->ServerPageTimeLimit = System::TimeSpan::Parse(L"-00:00:01");
			this->directorySearcher1->ServerTimeLimit = System::TimeSpan::Parse(L"-00:00:01");
			// 
			// openFileDialog2
			// 
			this->openFileDialog2->FileName = L"openFileDialog2";
			// 
			// fileSystemWatcher1
			// 
			this->fileSystemWatcher1->EnableRaisingEvents = true;
			this->fileSystemWatcher1->IncludeSubdirectories = true;
			this->fileSystemWatcher1->SynchronizingObject = this;
			this->fileSystemWatcher1->Changed += gcnew System::IO::FileSystemEventHandler(this, &MyForm::fileSystemWatcher1_Changed_1);
			this->fileSystemWatcher1->Created += gcnew System::IO::FileSystemEventHandler(this, &MyForm::fileSystemWatcher1_Created_1);
			this->fileSystemWatcher1->Deleted += gcnew System::IO::FileSystemEventHandler(this, &MyForm::fileSystemWatcher1_Deleted_1);
			this->fileSystemWatcher1->Renamed += gcnew System::IO::RenamedEventHandler(this, &MyForm::fileSystemWatcher1_Renamed_1);
			// 
			// backgroundWorker1
			// 
			this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MyForm::backgroundWorker1_DoWork);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoValidate = System::Windows::Forms::AutoValidate::EnablePreventFocusChange;
			this->BackColor = System::Drawing::Color::WhiteSmoke;
			this->ClientSize = System::Drawing::Size(1243, 659);
			this->Controls->Add(this->tableLayoutPanel2);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->menuStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MinimumSize = System::Drawing::Size(1261, 706);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"FolderWatcher";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->contextMenuStrip1->ResumeLayout(false);
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			this->tableLayoutPanel2->ResumeLayout(false);
			this->tableLayoutPanel2->PerformLayout();
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel4->ResumeLayout(false);
			this->tableLayoutPanel4->PerformLayout();
			this->tableLayoutPanel6->ResumeLayout(false);
			this->tableLayoutPanel6->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->tableLayoutPanel5->ResumeLayout(false);
			this->tableLayoutPanel7->ResumeLayout(false);
			this->tableLayoutPanel7->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->tableLayoutPanel9->ResumeLayout(false);
			this->tableLayoutPanel9->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fileSystemWatcher1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		toolStripStatusLabel4->Image = Image::FromFile("Images\\ready.png");
		toolStripStatusLabel4->Text = "Ready";
		listBox2->Items->Clear();
		FolderBrowserDialog^ folderBrowserDialog1;
		folderBrowserDialog1 = gcnew System::Windows::Forms::FolderBrowserDialog;

		System::Windows::Forms::DialogResult result = folderBrowserDialog1->ShowDialog();

		textBox1->Text = folderBrowserDialog1->SelectedPath;
		if (textBox1->Text == "") {
			MessageBox::Show("Путь к каталогу не выбран", "Информация",
				MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
			return;
		}

		WIN32_FIND_DATAW wfd;
		pin_ptr<const wchar_t> wname = PtrToStringChars(textBox1->Text + "\\*");
		HANDLE const hFind = FindFirstFileW(wname, &wfd);
		setlocale(LC_ALL, "");
		dataGridView1->Rows->Clear();
		if (parameters_flag) {
			dataGridView1->Columns->Clear();
			Add_Column_Headers();
			parameters_flag = false;
		}
		if (INVALID_HANDLE_VALUE != hFind && check_box[0] == true)
		{
			int i = 0;
			DataGridViewRow^ r = gcnew DataGridViewRow();
			array <String^>^ Values = gcnew array <String^>(dataGridView1->ColumnCount);
			do
			{
				dataGridView1->Rows->Add(gcnew String(wfd.cFileName));
			} while (NULL != FindNextFileW(hFind, &wfd));
			FindClose(hFind);
		}
		ListSortDirection direction = ListSortDirection::Ascending;
		dataGridView1->Sort(dataGridView1->Columns[0], direction);
		this->fileSystemWatcher1->Path = textBox1->Text;
		ChangeMode();
		dataGridView1->Visible = true;
		dataGridView1->ClearSelection();
		button7->Enabled = true;
		
	}
	private: System::Void закрытьToolStripMenuItem_Click_1(System::Object^ sender, System::EventArgs^ e) {
		exit(0);
	}
	private: System::Void справкаToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		MessageBox::Show("Краткое описание функционала", "Справка",
			MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
	}
	private: System::Void оПрограммеToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		MessageBox::Show("Данное приложение разработано в рамках проекта по ОПД в 2023", "О программе",
			MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		toolStripStatusLabel4->Image = Image::FromFile("Images\\ready.png");
		toolStripStatusLabel4->Text = "Ready";
		OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog();
		openFileDialog1->Filter = "All files (*.*)|*.*";
		std::string path;
		if (last_saved_path == NULL) {
			wchar_t Folder[1024];
			HRESULT hr = SHGetFolderPathW(0, CSIDL_MYDOCUMENTS, 0, 0, Folder);
			if (SUCCEEDED(hr))
			{
				char str[1024];
				wcstombs(str, Folder, 1023);
			}
			char tmp[17] = "\\FolderWatcher";
			int Folder_len = 0;
			for (int i = 0; Folder[i] != '\0'; i++)
			{
				path += Folder[i];
				Folder_len++;
			}
			for (int i = 0; i < 17; i++) {
				path += wchar_t(tmp[i]);
			}
		}
		else {
			int len = strlen(last_saved_path);
			for (int i = 0; i < len; i++) {
				path += wchar_t(last_saved_path[i]);
			}
			path = path.substr(0, path.find_last_of("\\"));
		}
		System::String^ new_path = msclr::interop::marshal_as<System::String^>(path);
		openFileDialog1->InitialDirectory = new_path;
		openFileDialog1->ShowDialog();
		String^ fileName = openFileDialog1->FileName;
	}
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
		toolStripStatusLabel4->Image = Image::FromFile("Images\\ready.png");
		toolStripStatusLabel4->Text = "Ready";
		New::Parameters^ f = gcnew New::Parameters(gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
		f->ShowDialog();
		parameters_flag = true;
	}
	private: System::Void fileSystemWatcher1_Created_1(System::Object^ sender, System::IO::FileSystemEventArgs^ e) {
		ChangeMode();
		WIN32_FIND_DATAW wfd;
		pin_ptr<const wchar_t> wname = PtrToStringChars(textBox1->Text + "\\*");
		HANDLE const hFind = FindFirstFileW(wname, &wfd);
		setlocale(LC_ALL, "");
		if (INVALID_HANDLE_VALUE != hFind)
		{
			int i = 0;
			DataGridViewRow^ r = gcnew DataGridViewRow();
			array <String^>^ Values = gcnew array <String^>(dataGridView1->ColumnCount);
			do
			{

				if (e->Name == gcnew String(wfd.cFileName)) {
					dataGridView1->Rows->Add(gcnew String(wfd.cFileName));
					ListSortDirection direction = ListSortDirection::Ascending;
					dataGridView1->Sort(dataGridView1->Columns[0], direction);
					for (int j = 0; j < dataGridView1->ColumnCount; j++)
						dataGridView1->Rows[i]->Cells[j]->Style->BackColor = Color::LightCoral;
					SYSTEMTIME stUTC, stLocal;
					FileTimeToSystemTime(&wfd.ftCreationTime, &stUTC);
					SystemTimeToTzSpecificLocalTime(NULL, &stUTC, &stLocal);

					char buffer[80];
					sprintf_s(buffer, 80, "%04d-%02d-%02d %02d:%02d:%02d",
						stLocal.wYear, stLocal.wMonth, stLocal.wDay,
						stLocal.wHour, stLocal.wMinute, stLocal.wSecond);

					System::String^ result = gcnew String(buffer);
					System::String^ log = "Created | " + result + " | " + e->FullPath->ToString();
					listBox2->Items->Add(log);
				}
				i++;
			} while (NULL != FindNextFileW(hFind, &wfd));
			FindClose(hFind);
			toolStripStatusLabel4->Text = "Completed";

		}
	}
	private: System::Void fileSystemWatcher1_Deleted_1(System::Object^ sender, System::IO::FileSystemEventArgs^ e) {
		for (int t = 0; t < dataGridView1->RowCount; t++) {
			if (dataGridView1->Rows[t]->Cells[0]->Value->ToString() == e->Name) {
				dataGridView1->Rows->RemoveAt(dataGridView1->Rows[t]->Index);
			}
		}
		WIN32_FIND_DATAW wfd;
		pin_ptr<const wchar_t> wname = PtrToStringChars(e->FullPath);
		HANDLE const hFind = FindFirstFileW(wname, &wfd);
		SYSTEMTIME stUTC, stLocal;
		FileTimeToSystemTime(&wfd.ftCreationTime, &stUTC);
		SystemTimeToTzSpecificLocalTime(NULL, &stUTC, &stLocal);

		char buffer[80];
		sprintf_s(buffer, 80, "%04d-%02d-%02d %02d:%02d:%02d",
			stLocal.wYear, stLocal.wMonth, stLocal.wDay,
			stLocal.wHour, stLocal.wMinute, stLocal.wSecond);
		DateTime currentTime = DateTime::Now;
		String^ currentTimeStr = currentTime.ToString("yyyy-MM-dd HH:mm:ss", CultureInfo::InvariantCulture);
		System::String^ result = gcnew String(buffer);
		System::String^ log = "Deleted | " + currentTimeStr + " | " + e->FullPath->ToString();
		listBox2->Items->Add(log);
		ChangeMode();
	}
	private: System::Void fileSystemWatcher1_Renamed_1(System::Object^ sender, RenamedEventArgs^ e) {
		ChangeMode();
		WIN32_FIND_DATAW wfd;
		pin_ptr<const wchar_t> wname = PtrToStringChars(textBox1->Text + "\\*");
		HANDLE const hFind = FindFirstFileW(wname, &wfd);
		setlocale(LC_ALL, "");
		if (INVALID_HANDLE_VALUE != hFind)
		{
			int i = 0;
			DataGridViewRow^ r = gcnew DataGridViewRow();
			array <String^>^ Values = gcnew array <String^>(dataGridView1->ColumnCount);
			int count_hiden = 0, neccesary_row;
			do
			{
				if (e->Name == gcnew String(wfd.cFileName)) {
					neccesary_row = i;
					dataGridView1->Rows[i]->Cells[0]->Value = e->Name;
					ListSortDirection direction = ListSortDirection::Ascending;
					dataGridView1->Sort(dataGridView1->Columns[0], direction);
					for (int t = 0; t < dataGridView1->RowCount; t++) {
						if (dataGridView1->Rows[t]->Cells[0]->Value == e->Name) {
							for (int j = 0; j < dataGridView1->ColumnCount; j++)
								dataGridView1->Rows[t]->Cells[j]->Style->BackColor = Color::LightCoral;
						}
						if (dataGridView1->Rows[t]->Cells[0]->Value->ToString() == e->OldName) {
							dataGridView1->Rows->RemoveAt(dataGridView1->Rows[t]->Index);
						}
					}
					SYSTEMTIME stUTC, stLocal;
					FileTimeToSystemTime(&wfd.ftCreationTime, &stUTC);
					SystemTimeToTzSpecificLocalTime(NULL, &stUTC, &stLocal);

					char buffer[80];
					sprintf_s(buffer, 80, "%04d-%02d-%02d %02d:%02d:%02d",
						stLocal.wYear, stLocal.wMonth, stLocal.wDay,
						stLocal.wHour, stLocal.wMinute, stLocal.wSecond);

					System::String^ result = gcnew String(buffer);
					System::String^ log = "Renamed | " + result + " | " + e->FullPath->ToString();
					listBox2->Items->Add(log);
				}
				if (wfd.dwFileAttributes == 34) {
					count_hiden++;
				}
				i++;
			} while (NULL != FindNextFileW(hFind, &wfd));

			FindClose(hFind);
			toolStripStatusLabel4->Text = "Completed";
		}

	}
	private: System::Void fileSystemWatcher1_Changed_1(System::Object^ sender, System::IO::FileSystemEventArgs^ e) {
		ChangeMode();
		int k = e->Name->IndexOf("\\");
		if (k == -1) {
			for (int t = 0; t < dataGridView1->RowCount; t++) {
				if (dataGridView1->Rows[t]->Cells[0]->Value->ToString() == e->Name) {
					for (int j = 0; j < dataGridView1->ColumnCount; j++)
						dataGridView1->Rows[t]->Cells[j]->Style->BackColor = Color::LightCoral;
				}
			}
		}
		else {
			System::String^ tmp = e->Name->Substring(0,e->Name->IndexOf("\\"));
			for (int t = 0; t < dataGridView1->RowCount; t++) {
				if (dataGridView1->Rows[t]->Cells[0]->Value->ToString() == tmp) {
					for (int j = 0; j < dataGridView1->ColumnCount; j++)
						dataGridView1->Rows[t]->Cells[j]->Style->BackColor = Color::LightCoral;
				}
			}
		}
		WIN32_FIND_DATAW wfd;
		pin_ptr<const wchar_t> wname = PtrToStringChars(e->FullPath);
		HANDLE const hFind = FindFirstFileW(wname, &wfd);
		SYSTEMTIME stUTC, stLocal;
		FileTimeToSystemTime(&wfd.ftCreationTime, &stUTC);
		SystemTimeToTzSpecificLocalTime(NULL, &stUTC, &stLocal);

		char buffer[80];
		sprintf_s(buffer, 80, "%04d-%02d-%02d %02d:%02d:%02d",
			stLocal.wYear, stLocal.wMonth, stLocal.wDay,
			stLocal.wHour, stLocal.wMinute, stLocal.wSecond);

		System::String^ result = gcnew String(buffer);
		System::String^ log = "Changed | " + result + " | " + e->FullPath->ToString();
		listBox2->Items->Add(log);
	}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	refresh();
	dataGridView1->ClearSelection();
}

private: System::Void dataGridView1_CellDoubleClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	if (e->ColumnIndex != 0) return;
	struct stat s;
	pin_ptr<const wchar_t> wname;
	try {
		wname = PtrToStringChars(textBox1->Text + "\\" + dataGridView1->Rows[e->RowIndex]->Cells[e->ColumnIndex]->Value);
	}
	catch (ArgumentOutOfRangeException^) {
		return;
	}
	char output[256];
	sprintf(output, "%ws", wname);
	if (stat(output, &s) == 0 && e->RowIndex > 0)
	{
		if (s.st_mode & S_IFDIR)
		{
			dataGridView1->Rows->Clear();
			WIN32_FIND_DATAW wfd;
			System::String^ folderName = gcnew System::String(wname);
			textBox1->Clear();
			if (e->RowIndex == 1) {

				int k = folderName->Length - 1;
				int i, count_slash;
				for (i = k; count_slash != 2 && i >= 0; i--) {
					if (folderName[i] == '\\')
						count_slash++;
				}
				folderName = folderName->Substring(0, i + 1);
			}
			textBox1->Text = folderName;
			pin_ptr<const wchar_t> out = PtrToStringChars(textBox1->Text + "\\*");
			HANDLE const hFind = FindFirstFileW(out, &wfd);
			setlocale(LC_ALL, "");
			dataGridView1->Rows->Clear();
			if (INVALID_HANDLE_VALUE != hFind)
			{
				int i = 0;
				DataGridViewRow^ r = gcnew DataGridViewRow();
				array <String^>^ Values = gcnew array <String^>(dataGridView1->ColumnCount);
				do
				{
					dataGridView1->Rows->Add(gcnew String(wfd.cFileName));
				} while (NULL != FindNextFileW(hFind, &wfd));

				FindClose(hFind);
				toolStripStatusLabel4->Text = "Completed";
			}
			try {
				this->fileSystemWatcher1->Path = textBox1->Text;
				textBox1_saved = folderName;
			}
			catch (ArgumentException^) {
				textBox1->Text = textBox1_saved;
			}
			catch (FileNotFoundException^) {
				textBox1->Text = textBox1_saved;
			}

		}
	}
	ChangeMode();
	dataGridView1->ClearSelection();
}

private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	toolStripStatusLabel4->Image = Image::FromFile("Images\\ready.png");
	toolStripStatusLabel4->Text = "Ready";
	New::MyForm1^ f = gcnew New::MyForm1(listBox2, gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
	for (int i = 0; i < listBox2->Items->Count; i++)
	{
		f->listBox1->Items->Add(listBox2->Items[i]);
	}
	if (listBox2->Items->Count != 0)
		f->ShowDialog();
	else
	{
		MessageBox::Show("Журнал событий пуст", "Информация",
			MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
	}
}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		struct stat s;
		pin_ptr<const wchar_t> wname;
		try {
			wname = PtrToStringChars(textBox1->Text + "");
		}
		catch (ArgumentOutOfRangeException^) {
			return;
		}
		char output[256];
		sprintf(output, "%ws", wname);
		if (stat(output, &s) == 0 && s.st_mode & S_IFDIR) {
			button2->Enabled = true;
			button7->Enabled = true;
			button3->Enabled = true;
		}
		else {
			button2->Enabled = false;
			button7->Enabled = false;
			button3->Enabled = false;
		}
	}
	private: System::Void hightlightEvenRowsToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		ChangeMode();
	}
	private: System::Void showToolTipsToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		if (showToolTipsToolStripMenuItem->CheckState == System::Windows::Forms::CheckState::Checked)
			this->toolTip1->Active = true;
		else
			this->toolTip1->Active = false;
	}
	private: System::Void showGridLinesToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		ChangeMode();
	}
	private: System::Void exitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		exit(0);
	}
	private: System::Void darkModeToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		ChangeMode();
	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		exitToolStripMenuItem->Image = Image::FromFile("Images\\exit.png");;
		parametersToolStripMenuItem->Image = Image::FromFile("Images\\browse.png");
		findToolStripMenuItem->Image = Image::FromFile("Images\\find.png");
		button1->Image = Image::FromFile("Images\\browse.png");
		button3->Image = Image::FromFile("Images\\refresh.png");
		button6->Image = Image::FromFile("Images\\logs.png");
		button7->Image = Image::FromFile("Images\\start.png");
		button2->Image = Image::FromFile("Images\\snapshot.png");
		button4->Image = Image::FromFile("Images\\export.png");
		button5->Image = Image::FromFile("Images\\parametrs.png");
		pictureBox1->Image = Image::FromFile("Images\\image_white.png");
		contentToolStripMenuItem->Image = Image::FromFile("Images\\help.png");
		infoToolStripMenuItem->Image = Image::FromFile("Images\\info.png");
		toolStripStatusLabel4->Image = Image::FromFile("Images\\ready.png");
	}
	private: System::Void parametersToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		New::Parameters^ f = gcnew New::Parameters(gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
		f->ShowDialog();
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		SaveFileDialog^ SaveFileDialog;
		SaveFileDialog = gcnew System::Windows::Forms::SaveFileDialog;
		SaveFileDialog->FileName = "Snapshot";
		SaveFileDialog->DefaultExt = "xml";
		SaveFileDialog->Filter = "Xml files (*.xml)|*.xml";
		SaveFileDialog->FilterIndex = 1;
		SaveFileDialog->CheckPathExists = true;
		SaveFileDialog->AddExtension = false;
		System::Windows::Forms::DialogResult result = SaveFileDialog->ShowDialog();
		save_path = (char*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(SaveFileDialog->FileName).ToPointer();
		last_saved_path = save_path;
		if (result != System::Windows::Forms::DialogResult::Cancel)
			backgroundWorker1->RunWorkerAsync();
	}
	private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
		toolStripStatusLabel4->Image = Image::FromFile("Images\\ready.png");
		toolStripStatusLabel4->Text = "Ready";
	}
	private: System::Void backgroundWorker1_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e) {
		toolStripStatusLabel4->Text = "Running";
		toolStripStatusLabel4->Image = Image::FromFile("Images\\progress.gif");
		// Converting from System::String^ to std::string
		std::string vitalik_path = msclr::interop::marshal_as<std::string>(textBox1->Text);

		//сейчас кнопка снапшот не работает, так как Виталику в качестве save_path передаётся полный путь к файлу сохранения
		// а не к папке назначения, как было до этого
		//backend_main(vitalik_path, save_path);

		toolStripStatusLabel4->Text = "Completed";
		toolStripStatusLabel4->Image = Image::FromFile("Images\\completed.png");
	}
	private: System::Void dataGridView1_SizeChanged(System::Object^ sender, System::EventArgs^ e) {
		if (!dataGridView1->ColumnCount) return;

		int sum = 0, count = dataGridView1->ColumnCount;
		for (int i = 0; i < 7; i++)
			sum += check_box[i];
		if (!dataGridView1->ColumnCount) return;
		if (check_box[0] == true) {
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
		else {
			if (check_box[1] == true) {
				dataGridView1->Columns[dataGridView1->ColumnCount - count]->Width = dataGridView1->Width / sum;
				count--;
			}
			if (check_box[2] == true) {
				dataGridView1->Columns[dataGridView1->ColumnCount - count]->Width = dataGridView1->Width / sum;
				count--;
			}
			if (check_box[3] == true) {
				dataGridView1->Columns[dataGridView1->ColumnCount - count]->Width = dataGridView1->Width / sum;
				count--;
			}
			if (check_box[4] == true) {
				dataGridView1->Columns[dataGridView1->ColumnCount - count]->Width = dataGridView1->Width / sum;
				count--;
			}
			if (check_box[5] == true) {
				dataGridView1->Columns[dataGridView1->ColumnCount - count]->Width = dataGridView1->Width / sum;
				count--;
			}
			if (check_box[6] == true) {
				dataGridView1->Columns[dataGridView1->ColumnCount - count]->Width = dataGridView1->Width / sum;
				count--;
			}
		}
	}
private: System::Void selectAllToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	dataGridView1->SelectAll();
}
private: System::Void deselectAllToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	dataGridView1->ClearSelection();
}
private: System::Void exportTableToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	export_selected_items(true);
}
private: System::Void runAsAdministratorToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	std::vector<TOKEN_ELEVATION> tokenElevation(1);
	DWORD dwSize = 0;
	HANDLE hProcess = GetCurrentProcess();
	HANDLE hToken = NULL;
	BOOL bResult = OpenProcessToken(hProcess, TOKEN_QUERY, &hToken);
	if (bResult)
	{
		bResult = GetTokenInformation(hToken, TokenElevation, tokenElevation.data(), static_cast<DWORD>(sizeof(TOKEN_ELEVATION)), &dwSize);
		if (!bResult)
		{
			if (GetLastError() == ERROR_INSUFFICIENT_BUFFER)
			{
				tokenElevation.resize(dwSize / sizeof(TOKEN_ELEVATION));
				bResult = GetTokenInformation(hToken, TokenElevation, tokenElevation.data(), dwSize, &dwSize);
			}
		}
		CloseHandle(hToken);
	}

	if (bResult)
	{
		if (tokenElevation[0].TokenIsElevated)
			return;
	}

	SHELLEXECUTEINFO sei = { sizeof(sei) };
	sei.lpVerb = L"runas";
	WCHAR path[MAX_PATH];
	GetModuleFileNameW(NULL, path, MAX_PATH);
	sei.lpFile = path;
	sei.lpParameters = GetCommandLineW();
	sei.nShow = SW_SHOW;
	if (ShellExecuteEx(&sei))
	{
		ExitProcess(0);
	}
}
private: System::Void toolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e) {
	copy();
}
private: System::Void refreshToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	refresh();
}
private: System::Void exportToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	export_selected_items(false);
}
private: System::Void exportSelectedItemsToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	export_selected_items(false);
}
private: System::Void openToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	if (dataGridView1->SelectedCells[0]->ColumnIndex != 0)
		return;
	System::Object^ tmp = dataGridView1->SelectedCells[0]->Value;
	struct stat s;
	pin_ptr<const wchar_t> wname;
	try {
		wname = PtrToStringChars(textBox1->Text + "\\" + tmp);
	}
	catch (ArgumentOutOfRangeException^) {
		return;
	}
	char Path[256];
	sprintf(Path, "%ws", wname);
	if (stat(Path, &s) == 0 && s.st_mode & S_IFDIR) {
		try{
			System::String^ path_to_open = msclr::interop::marshal_as<System::String^>(Path);
			Process^ myProcess = gcnew Process;
			myProcess->StartInfo->FileName = "explorer.exe";
			myProcess->StartInfo->Arguments = "\"" + path_to_open + "\"";
			myProcess->Start();
		}
		catch (...){
		}
	}
	else {
		System::String^ path_to_open = msclr::interop::marshal_as<System::String^>(Path);
		System::String^ tmp = path_to_open->Substring(path_to_open->LastIndexOf("\\"));
		tmp=tmp->Substring(tmp->LastIndexOf("."));
		Process^ myProcess = gcnew Process;
		if(tmp==".docx")
			myProcess->StartInfo->FileName = "winword.exe";
		else if (tmp == ".xlsx")
			myProcess->StartInfo->FileName = "excel.exe";
		else if (tmp == ".pdf")
			myProcess->StartInfo->FileName = "acrobat.exe";
		else if (tmp == ".pptx")
			myProcess->StartInfo->FileName = "powerpnt.exe";
		else if (tmp == ".lnk") {
			myProcess->StartInfo->UseShellExecute = true;
			try {
				myProcess->StartInfo->FileName = "\"" + path_to_open + "\"";
				myProcess->Start();
				return;
			}
			catch (...){
			}
			try {
				myProcess->StartInfo->FileName = path_to_open;
				myProcess->Start();
			}
			catch (...) {
			}
			return;
		}
		else if (tmp == ".exe") {
			myProcess->StartInfo->FileName = path_to_open;
			myProcess->Start();
			return;
		}
		else if (tmp == ".png"||tmp==".jpg") {
			Process::Start(path_to_open);
			return;
		}
		myProcess->StartInfo->Arguments = "\"" + path_to_open + "\"";
		try {
			myProcess->Start();
		}
		catch (...) {

		}
	}
}
private: System::Void deleteToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	//добавить подтверждение - messagebox
	delete_selected_items();
}
private: System::Void deleteSelectedItemsToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	//добавить подтверждение - messagebox
	delete_selected_items();
}
private: System::Void propetiesToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	if (dataGridView1->SelectedCells->Count!=1&&dataGridView1->SelectedCells[0]->ColumnIndex != 0)
		return;
	System::Object^ tmp = dataGridView1->SelectedCells[0]->Value;
	struct stat s;
	pin_ptr<const wchar_t> wname;
	try {
		wname = PtrToStringChars(textBox1->Text + "\\" + tmp);
	}
	catch (ArgumentOutOfRangeException^) {
		return;
	}
	char Path[256];
	sprintf(Path, "%ws", wname);
	if (stat(Path, &s) == 0 && s.st_mode & S_IFDIR || stat(Path, &s) == 0 && s.st_mode & S_IFREG) {
		LPCWSTR filePath = wname; 
		SHELLEXECUTEINFO shellInfo = { 0 };
		shellInfo.cbSize = sizeof(SHELLEXECUTEINFO);
		shellInfo.fMask = SEE_MASK_INVOKEIDLIST;
		shellInfo.lpVerb = L"properties";
		shellInfo.lpFile = filePath;
		shellInfo.nShow = SW_SHOW;
		ShellExecuteEx(&shellInfo);
	}
}
};
}