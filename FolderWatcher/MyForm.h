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

#include <msclr\marshal_cppstd.h>
#pragma comment(lib, "shell32.lib")
bool button5_first = 0;
bool button5_first_click = 0;

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

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
	private: System::Windows::Forms::ToolStripMenuItem^ darkModeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripStatusLabel^ toolStripStatusLabel2;
	private: System::Windows::Forms::ToolStripStatusLabel^ toolStripStatusLabel3;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;


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




	//private: System::DirectoryServices::DirectoryEntry^ directoryEntry1;

	private: System::Windows::Forms::ToolTip^ toolTip1;


	private: System::Windows::Forms::ToolStripStatusLabel^ toolStripStatusLabel1;
	private: System::Windows::Forms::ToolStripStatusLabel^ toolStripStatusLabel4;
	private: System::Windows::Forms::StatusStrip^ statusStrip1;



	private:

	public:
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
				checkBox1->ForeColor = Color::White;
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
					for (int j = 0; j < 6; j++) {
						dataGridView1->Rows[t]->Cells[j]->Style->BackColor = Color::DimGray;
						dataGridView1->Rows[t]->Cells[j]->Style->ForeColor = Color::White;
					}
				if (hightlightEvenRowsToolStripMenuItem->CheckState == System::Windows::Forms::CheckState::Checked) {
					for (int t = 0; t < dataGridView1->RowCount; t++)
						if (t % 2 == 0)
							for (int j = 0; j < 6; j++)
								dataGridView1->Rows[t]->Cells[j]->Style->BackColor = Color::Gray;
				}
				else
					for (int t = 0; t < dataGridView1->RowCount; t++)
						for (int j = 0; j < 6; j++)
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
				checkBox1->ForeColor = Color::Black;
				dataGridView1->ForeColor = Color::Black;
				dataGridView1->BackgroundColor = System::Drawing::SystemColors::Info;
				for (int t = 0; t < dataGridView1->RowCount; t++)
					for (int j = 0; j < 6; j++) {
						dataGridView1->Rows[t]->Cells[j]->Style->BackColor = Color::White;
						dataGridView1->Rows[t]->Cells[j]->Style->ForeColor = Color::Black;
					}
				if (hightlightEvenRowsToolStripMenuItem->CheckState == System::Windows::Forms::CheckState::Checked) {
					for (int t = 0; t < dataGridView1->RowCount; t++)
						if (t % 2 == 0)
							for (int j = 0; j < 6; j++)
								dataGridView1->Rows[t]->Cells[j]->Style->BackColor = Color::Bisque;
				}
				else
					for (int t = 0; t < dataGridView1->RowCount; t++)
						for (int j = 0; j < 6; j++)
							dataGridView1->Rows[t]->Cells[j]->Style->BackColor = Color::White;
				if (showGridLinesToolStripMenuItem->CheckState == System::Windows::Forms::CheckState::Checked)
					for (int t = 0; t < dataGridView1->RowCount; t++)
						dataGridView1->GridColor = Color::Silver;
				else
					for (int t = 0; t < dataGridView1->RowCount; t++)
						dataGridView1->GridColor = Color::White;
				dataGridView1->DefaultCellStyle->SelectionBackColor = Color::White;
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


private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel3;
private: System::Windows::Forms::TextBox^ textBox2;
private: System::Windows::Forms::CheckBox^ checkBox1;
private: System::Windows::Forms::ListBox^ listBox1;


private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel4;
private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel5;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column4;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column5;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column6;
private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel6;
private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel7;


private: System::Windows::Forms::CheckBox^ checkBox2;
private: System::Windows::Forms::CheckBox^ checkBox5;

private: System::Windows::Forms::CheckBox^ checkBox4;
private: System::Windows::Forms::CheckBox^ checkBox3;
private: System::Windows::Forms::CheckBox^ checkBox6;
private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel3;
private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel8;
private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel4;
private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;
private: System::Windows::Forms::CheckBox^ checkBox7;
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
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
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
			this->tableLayoutPanel8 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox7 = (gcnew System::Windows::Forms::CheckBox());
			this->flowLayoutPanel4 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->checkBox6 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->flowLayoutPanel3 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->checkBox5 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox4 = (gcnew System::Windows::Forms::CheckBox());
			this->directorySearcher1 = (gcnew System::DirectoryServices::DirectorySearcher());
			this->folderBrowserDialog2 = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->openFileDialog2 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->fileSystemWatcher1 = (gcnew System::IO::FileSystemWatcher());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->tableLayoutPanel3->SuspendLayout();
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
			this->tableLayoutPanel8->SuspendLayout();
			this->flowLayoutPanel1->SuspendLayout();
			this->flowLayoutPanel4->SuspendLayout();
			this->flowLayoutPanel3->SuspendLayout();
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
			// 
			// deselectAllToolStripMenuItem
			// 
			this->deselectAllToolStripMenuItem->Name = L"deselectAllToolStripMenuItem";
			this->deselectAllToolStripMenuItem->Size = System::Drawing::Size(233, 26);
			this->deselectAllToolStripMenuItem->Text = L"Deselect All";
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
			// 
			// exportSelectedItemsToolStripMenuItem
			// 
			this->exportSelectedItemsToolStripMenuItem->Name = L"exportSelectedItemsToolStripMenuItem";
			this->exportSelectedItemsToolStripMenuItem->Size = System::Drawing::Size(237, 26);
			this->exportSelectedItemsToolStripMenuItem->Text = L"Export Selected Items";
			// 
			// deleteSelectedItemsToolStripMenuItem
			// 
			this->deleteSelectedItemsToolStripMenuItem->Name = L"deleteSelectedItemsToolStripMenuItem";
			this->deleteSelectedItemsToolStripMenuItem->Size = System::Drawing::Size(237, 26);
			this->deleteSelectedItemsToolStripMenuItem->Text = L"Delete Selected Items";
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
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::Info;
			this->dataGridView1->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::TopLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::Color::Silver;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Impact", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle2;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->Column1,
					this->Column2, this->Column3, this->Column4, this->Column5, this->Column6
			});
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
			dataGridViewCellStyle5->SelectionBackColor = System::Drawing::Color::White;
			dataGridViewCellStyle5->SelectionForeColor = System::Drawing::Color::Black;
			this->dataGridView1->RowsDefaultCellStyle = dataGridViewCellStyle5;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(1065, 401);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->Visible = false;
			this->dataGridView1->CellDoubleClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellDoubleClick);
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Filename";
			this->Column1->MinimumWidth = 6;
			this->Column1->Name = L"Column1";
			this->Column1->Width = 405;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Stream Name";
			this->Column2->MinimumWidth = 6;
			this->Column2->Name = L"Column2";
			this->Column2->Width = 175;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Stream Type";
			this->Column3->MinimumWidth = 6;
			this->Column3->Name = L"Column3";
			this->Column3->Width = 175;
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Content Type";
			this->Column4->MinimumWidth = 6;
			this->Column4->Name = L"Column4";
			this->Column4->Width = 175;
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"Base Type";
			this->Column5->MinimumWidth = 6;
			this->Column5->Name = L"Column5";
			this->Column5->Width = 175;
			// 
			// Column6
			// 
			this->Column6->HeaderText = L"Size";
			this->Column6->MinimumWidth = 6;
			this->Column6->Name = L"Column6";
			this->Column6->Width = 175;
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
			this->button7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button7->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button7->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button7->Location = System::Drawing::Point(3, 3);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(160, 28);
			this->button7->TabIndex = 0;
			this->button7->Text = L"   Start";
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
			// tableLayoutPanel3
			// 
			this->tableLayoutPanel3->AutoSize = true;
			this->tableLayoutPanel3->ColumnCount = 2;
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				46.33508F)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				53.66492F)));
			this->tableLayoutPanel3->Controls->Add(this->textBox2, 1, 1);
			this->tableLayoutPanel3->Controls->Add(this->checkBox1, 0, 1);
			this->tableLayoutPanel3->Controls->Add(this->listBox1, 0, 2);
			this->tableLayoutPanel3->Location = System::Drawing::Point(3, 3);
			this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			this->tableLayoutPanel3->RowCount = 3;
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 10.85271F)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 22.48062F)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 64.84375F)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel3->Size = System::Drawing::Size(77, 131);
			this->tableLayoutPanel3->TabIndex = 3;
			this->toolTip1->SetToolTip(this->tableLayoutPanel3, L"Enter the depth");
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::SystemColors::Info;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox2->Location = System::Drawing::Point(38, 17);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(34, 24);
			this->textBox2->TabIndex = 0;
			this->textBox2->Visible = false;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->checkBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->checkBox1->Location = System::Drawing::Point(3, 17);
			this->checkBox1->MaximumSize = System::Drawing::Size(200, 40);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(29, 23);
			this->checkBox1->TabIndex = 8;
			this->checkBox1->Text = L"Scan Sub Directories";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->Visible = false;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged);
			// 
			// listBox1
			// 
			this->listBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 18;
			this->listBox1->Items->AddRange(gcnew cli::array< System::Object^  >(10) {
				L"1", L"2", L"3", L"4", L"5", L"6", L"7", L"8",
					L"9", L"10"
			});
			this->listBox1->Location = System::Drawing::Point(3, 46);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(28, 58);
			this->listBox1->TabIndex = 9;
			this->toolTip1->SetToolTip(this->listBox1, L"Enter the depth");
			this->listBox1->Visible = false;
			this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::listBox1_SelectedIndexChanged);
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
			this->toolStripStatusLabel3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripStatusLabel3.BackgroundImage")));
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
			this->tableLayoutPanel5->Controls->Add(this->tableLayoutPanel3, 0, 0);
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
				7.85124F)));
			this->tableLayoutPanel7->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				92.14876F)));
			this->tableLayoutPanel7->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				372)));
			this->tableLayoutPanel7->Controls->Add(this->panel2, 1, 0);
			this->tableLayoutPanel7->Controls->Add(this->tableLayoutPanel8, 2, 0);
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
			this->panel2->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->panel2->Controls->Add(this->tableLayoutPanel9);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel2->Location = System::Drawing::Point(70, 3);
			this->panel2->MaximumSize = System::Drawing::Size(1000, 150);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(791, 68);
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
			// tableLayoutPanel8
			// 
			this->tableLayoutPanel8->AutoSize = true;
			this->tableLayoutPanel8->ColumnCount = 3;
			this->tableLayoutPanel8->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				19.95661F)));
			this->tableLayoutPanel8->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				32.07171F)));
			this->tableLayoutPanel8->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				48.20717F)));
			this->tableLayoutPanel8->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				20)));
			this->tableLayoutPanel8->Controls->Add(this->flowLayoutPanel1, 2, 0);
			this->tableLayoutPanel8->Controls->Add(this->flowLayoutPanel4, 0, 0);
			this->tableLayoutPanel8->Controls->Add(this->flowLayoutPanel3, 1, 0);
			this->tableLayoutPanel8->Location = System::Drawing::Point(867, 3);
			this->tableLayoutPanel8->Name = L"tableLayoutPanel8";
			this->tableLayoutPanel8->RowCount = 1;
			this->tableLayoutPanel8->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel8->Size = System::Drawing::Size(367, 62);
			this->tableLayoutPanel8->TabIndex = 21;
			this->tableLayoutPanel8->Visible = false;
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->AutoSize = true;
			this->flowLayoutPanel1->Controls->Add(this->checkBox3);
			this->flowLayoutPanel1->Controls->Add(this->checkBox7);
			this->flowLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->flowLayoutPanel1->Location = System::Drawing::Point(193, 3);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(171, 56);
			this->flowLayoutPanel1->TabIndex = 23;
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->checkBox3->Location = System::Drawing::Point(3, 3);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(177, 22);
			this->checkBox3->TabIndex = 1;
			this->checkBox3->Text = L"Время модификации";
			this->checkBox3->UseVisualStyleBackColor = true;
			// 
			// checkBox7
			// 
			this->checkBox7->AutoSize = true;
			this->checkBox7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->checkBox7->Location = System::Drawing::Point(3, 31);
			this->checkBox7->Name = L"checkBox7";
			this->checkBox7->Size = System::Drawing::Size(211, 22);
			this->checkBox7->TabIndex = 22;
			this->checkBox7->Text = L"Время изменения статуса";
			this->checkBox7->UseVisualStyleBackColor = true;
			// 
			// flowLayoutPanel4
			// 
			this->flowLayoutPanel4->AutoSize = true;
			this->flowLayoutPanel4->Controls->Add(this->checkBox6);
			this->flowLayoutPanel4->Controls->Add(this->checkBox2);
			this->flowLayoutPanel4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->flowLayoutPanel4->Location = System::Drawing::Point(3, 3);
			this->flowLayoutPanel4->Name = L"flowLayoutPanel4";
			this->flowLayoutPanel4->Size = System::Drawing::Size(67, 56);
			this->flowLayoutPanel4->TabIndex = 20;
			// 
			// checkBox6
			// 
			this->checkBox6->AutoSize = true;
			this->checkBox6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->checkBox6->Location = System::Drawing::Point(3, 3);
			this->checkBox6->Name = L"checkBox6";
			this->checkBox6->Size = System::Drawing::Size(60, 22);
			this->checkBox6->TabIndex = 19;
			this->checkBox6->Text = L"Имя";
			this->checkBox6->UseVisualStyleBackColor = true;
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->checkBox2->Location = System::Drawing::Point(3, 31);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(83, 22);
			this->checkBox2->TabIndex = 0;
			this->checkBox2->Text = L"Размер";
			this->checkBox2->UseVisualStyleBackColor = true;
			// 
			// flowLayoutPanel3
			// 
			this->flowLayoutPanel3->AutoSize = true;
			this->flowLayoutPanel3->Controls->Add(this->checkBox5);
			this->flowLayoutPanel3->Controls->Add(this->checkBox4);
			this->flowLayoutPanel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->flowLayoutPanel3->Location = System::Drawing::Point(76, 3);
			this->flowLayoutPanel3->Name = L"flowLayoutPanel3";
			this->flowLayoutPanel3->Size = System::Drawing::Size(111, 56);
			this->flowLayoutPanel3->TabIndex = 18;
			// 
			// checkBox5
			// 
			this->checkBox5->AutoSize = true;
			this->checkBox5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->checkBox5->Location = System::Drawing::Point(3, 3);
			this->checkBox5->Name = L"checkBox5";
			this->checkBox5->Size = System::Drawing::Size(133, 22);
			this->checkBox5->TabIndex = 3;
			this->checkBox5->Text = L"Права доступа";
			this->checkBox5->UseVisualStyleBackColor = true;
			// 
			// checkBox4
			// 
			this->checkBox4->AutoSize = true;
			this->checkBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->checkBox4->Location = System::Drawing::Point(3, 31);
			this->checkBox4->Name = L"checkBox4";
			this->checkBox4->Size = System::Drawing::Size(156, 22);
			this->checkBox4->TabIndex = 2;
			this->checkBox4->Text = L"Время обращения";
			this->checkBox4->UseVisualStyleBackColor = true;
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
			this->tableLayoutPanel3->ResumeLayout(false);
			this->tableLayoutPanel3->PerformLayout();
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
			this->tableLayoutPanel5->PerformLayout();
			this->tableLayoutPanel7->ResumeLayout(false);
			this->tableLayoutPanel7->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->tableLayoutPanel9->ResumeLayout(false);
			this->tableLayoutPanel9->PerformLayout();
			this->tableLayoutPanel8->ResumeLayout(false);
			this->tableLayoutPanel8->PerformLayout();
			this->flowLayoutPanel1->ResumeLayout(false);
			this->flowLayoutPanel1->PerformLayout();
			this->flowLayoutPanel4->ResumeLayout(false);
			this->flowLayoutPanel4->PerformLayout();
			this->flowLayoutPanel3->ResumeLayout(false);
			this->flowLayoutPanel3->PerformLayout();
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
		dataGridView1->Visible = true;
		WIN32_FIND_DATAW wfd;
		pin_ptr<const wchar_t> wname = PtrToStringChars(textBox1->Text + "\\*");
		HANDLE const hFind = FindFirstFileW(wname, &wfd);
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
		}
		ListSortDirection direction = ListSortDirection::Ascending;
		dataGridView1->Sort(dataGridView1->Columns[0], direction);
		
		this->fileSystemWatcher1->Path = textBox1->Text;
		ChangeMode();
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
	private: System::Void listBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		System::Object^ depth=listBox1->SelectedItem;
		textBox2->Text= "Depth: "+depth->ToString();
		textBox2->Visible = true;
		listBox1->Visible = false;
	}
private: System::Void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (checkBox1->Checked) {
		listBox1->Visible = true;
	}
	else {
		listBox1->Visible = false;
		textBox2->Visible = false;
	}
}
private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	listBox1->Visible = false;
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	toolStripStatusLabel4->Image = Image::FromFile("Images\\ready.png");
	toolStripStatusLabel4->Text = "Ready";
	OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog();
	openFileDialog1->Filter = "All files (*.*)|*.*";
	wchar_t Folder[1024];
	HRESULT hr = SHGetFolderPathW(0, CSIDL_MYDOCUMENTS, 0, 0, Folder);
	if (SUCCEEDED(hr))
	{
		char str[1024];
		wcstombs(str, Folder, 1023);
	}
	char tmp[17] = "\\FolderWatcher";
	int Folder_len = 0;
	System::String^ new_path;
	for (int i = 0; Folder[i] != '\0'; i++)
	{
		new_path += Folder[i];
		Folder_len++;
	}
	for (int i = 0; i < 17; i++) {
		new_path += wchar_t(tmp[i]);
	}
	openFileDialog1->InitialDirectory = new_path;
	openFileDialog1->ShowDialog();
	String^ fileName = openFileDialog1->FileName;
}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	toolStripStatusLabel4->Image = Image::FromFile("Images\\ready.png");
	toolStripStatusLabel4->Text = "Ready";
	New::Parameters^ f = gcnew New::Parameters();
	f->ShowDialog();
	if (button5_first_click == 0) {
		checkBox6->Checked = true;
		checkBox2->Checked = true;
		checkBox5->Checked = true;
		checkBox4->Checked = true;
		checkBox3->Checked = true;
		checkBox7->Checked = true;
		button5_first_click = 1;
	}
	if (button5_first == 0) {
		tableLayoutPanel8->Visible = true;
		button5_first = 1;
	}
	else {
		tableLayoutPanel8->Visible = false;
		button5_first = 0;
	}
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
				for (int j = 0; j < 6; j++)
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
		int count_hiden = 0,neccesary_row;
		do
		{
			if (e->Name == gcnew String(wfd.cFileName)) {
				neccesary_row = i;
				dataGridView1->Rows[i]->Cells[0]->Value = e->Name;
				ListSortDirection direction = ListSortDirection::Ascending;
				dataGridView1->Sort(dataGridView1->Columns[0], direction);
				for (int t = 0; t < dataGridView1->RowCount; t++) {
					if (dataGridView1->Rows[t]->Cells[0]->Value == e->Name) {
						for (int j = 0; j < 6; j++)
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
	for (int t = 0; t < dataGridView1->RowCount; t++) {
		if (dataGridView1->Rows[t]->Cells[0]->Value->ToString() == e->Name) {
			for (int j = 0; j < 6; j++)
				dataGridView1->Rows[t]->Cells[j]->Style->BackColor = Color::LightCoral;
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
	toolStripStatusLabel4->Image = Image::FromFile("Images\\ready.png");
	toolStripStatusLabel4->Text = "Ready";
	if (textBox1->Text=="") {
		MessageBox::Show("Путь к каталогу не выбран", "Информация",
			MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		return;
	}
	listBox2->Items->Clear();
	dataGridView1->Rows->Clear();
	dataGridView1->Visible = true;
	WIN32_FIND_DATAW wfd,k;
	pin_ptr<const wchar_t> wname = PtrToStringChars(textBox1->Text + "\\*");
	pin_ptr<const wchar_t> dop = PtrToStringChars("C:\\Users\\Егор\\Desktop\\");
	HANDLE const hFind = FindFirstFileW(wname, &wfd);
	HANDLE const h = FindFirstFileW(dop, &k);
	setlocale(LC_ALL, "");
	ULONGLONG Size= (static_cast<ULONGLONG>(wfd.nFileSizeHigh) <<
		sizeof(wfd.nFileSizeLow) * 8) |
		wfd.nFileSizeLow;
	ULONGLONG FileSize = (static_cast<ULONGLONG>(k.nFileSizeHigh) <<
		sizeof(k.nFileSizeLow) * 8) |
		k.nFileSizeLow;
	ULONGLONG s=(k.nFileSizeHigh * (uint64_t)MAXDWORD) + k.nFileSizeLow;
	dataGridView1->Rows->Clear();
	if (INVALID_HANDLE_VALUE != hFind)
	{
		int i = 0;
		DataGridViewRow^ r = gcnew DataGridViewRow();
		array <String^>^ Values = gcnew array <String^>(dataGridView1->ColumnCount);
		do
		{
			dataGridView1->Rows->Add(gcnew String(wfd.cFileName));
			Size+= (static_cast<ULONGLONG>(wfd.nFileSizeHigh) <<
				sizeof(wfd.nFileSizeLow) * 8) |
				wfd.nFileSizeLow;
		} while (NULL != FindNextFileW(hFind, &wfd));

		FindClose(hFind);
	}
	ListSortDirection direction = ListSortDirection::Ascending;
	dataGridView1->Sort(dataGridView1->Columns[0], direction);

	if(GridColor==Color::Silver)
		for (int t = 0; t < dataGridView1->RowCount; t++)
			dataGridView1->GridColor = GridColor;
	ChangeMode();
}

private: System::Void dataGridView1_CellDoubleClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
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
				int i,count_slash;
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
}

private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	toolStripStatusLabel4->Image = Image::FromFile("Images\\ready.png");
	toolStripStatusLabel4->Text = "Ready";
	New::MyForm1^ f = gcnew New::MyForm1(listBox2);
	for (int i = 0; i<listBox2->Items->Count; i++)
	{
		f->listBox1->Items->Add(listBox2->Items[i]);
	}
	if(listBox2->Items->Count!=0)
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
		wname = PtrToStringChars(textBox1->Text+"");
	}
	catch (ArgumentOutOfRangeException^) {
		return;
	}
	char output[256];
	sprintf(output, "%ws", wname);
	if (stat(output, &s) == 0&& s.st_mode & S_IFDIR)
		button2->Enabled = true;
	else
		button2->Enabled = false;
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
	button1->Image= Image::FromFile("Images\\browse.png");
	button3->Image = Image::FromFile("Images\\refresh.png");
	button6->Image = Image::FromFile("Images\\logs.png");
	button7->Image = Image::FromFile("Images\\start.png");
	button2->Image = Image::FromFile("Images\\snapshot.png");
	button4->Image = Image::FromFile("Images\\export.png");
	button5->Image = Image::FromFile("Images\\parametrs.png");
	pictureBox1->Image= Image::FromFile("Images\\image_white.png");
	contentToolStripMenuItem->Image = Image::FromFile("Images\\help.png");
	infoToolStripMenuItem->Image = Image::FromFile("Images\\info.png");
	toolStripStatusLabel4->Image = Image::FromFile("Images\\ready.png");
}
private: System::Void parametersToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	New::Parameters^ f = gcnew New::Parameters();
	f->ShowDialog();
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
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

	///определение пути к Documents\FolderWatcher
	wchar_t Folder[1024];
	char folderwathcher_path[1024];
	HRESULT hr = SHGetFolderPathW(0, CSIDL_MYDOCUMENTS, 0, 0, Folder);
	if (SUCCEEDED(hr))
		wcstombs(folderwathcher_path, Folder, 1023);

	char tmp[17] = "\\FolderWatcher";
	strcat(folderwathcher_path, tmp);


	backend_main(vitalik_path, folderwathcher_path);

	toolStripStatusLabel4->Text = "Completed";
	toolStripStatusLabel4->Image = Image::FromFile("Images\\completed.png");
}
private: System::Void dataGridView1SelectionChanged(System::Object^ sender, System::EventArgs^ e) {
	printf("");
}
};
}