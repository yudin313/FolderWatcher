#pragma once

namespace New {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Parameters
	/// </summary>
	public ref class Parameters : public System::Windows::Forms::Form
	{
	public:
		Parameters(void)
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
		~Parameters()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel3;
	protected:
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel8;
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;
	private: System::Windows::Forms::CheckBox^ checkBox3;
	private: System::Windows::Forms::CheckBox^ checkBox7;
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel4;
	private: System::Windows::Forms::CheckBox^ checkBox6;
	private: System::Windows::Forms::CheckBox^ checkBox2;
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel3;
	private: System::Windows::Forms::CheckBox^ checkBox5;
	private: System::Windows::Forms::CheckBox^ checkBox4;
	private: System::Windows::Forms::CheckedListBox^ checkedListBox1;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
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
			this->checkedListBox1 = (gcnew System::Windows::Forms::CheckedListBox());
			this->tableLayoutPanel3->SuspendLayout();
			this->tableLayoutPanel8->SuspendLayout();
			this->flowLayoutPanel1->SuspendLayout();
			this->flowLayoutPanel4->SuspendLayout();
			this->flowLayoutPanel3->SuspendLayout();
			this->SuspendLayout();
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
			this->tableLayoutPanel3->Location = System::Drawing::Point(3, 12);
			this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			this->tableLayoutPanel3->RowCount = 3;
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 10.85271F)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 22.48062F)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 64.84375F)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel3->Size = System::Drawing::Size(380, 131);
			this->tableLayoutPanel3->TabIndex = 4;
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::SystemColors::Info;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox2->Location = System::Drawing::Point(179, 17);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(34, 24);
			this->textBox2->TabIndex = 0;
			this->textBox2->Visible = false;
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
			this->checkBox1->Size = System::Drawing::Size(170, 23);
			this->checkBox1->TabIndex = 8;
			this->checkBox1->Text = L"Scan Sub Directories";
			this->checkBox1->UseVisualStyleBackColor = true;
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
			this->listBox1->Size = System::Drawing::Size(170, 58);
			this->listBox1->TabIndex = 9;
			this->listBox1->Visible = false;
			// 
			// tableLayoutPanel8
			// 
			this->tableLayoutPanel8->AutoSize = true;
			this->tableLayoutPanel8->ColumnCount = 3;
			this->tableLayoutPanel8->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				19.85428F)));
			this->tableLayoutPanel8->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				31.32969F)));
			this->tableLayoutPanel8->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				48.20717F)));
			this->tableLayoutPanel8->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				20)));
			this->tableLayoutPanel8->Controls->Add(this->flowLayoutPanel1, 2, 0);
			this->tableLayoutPanel8->Controls->Add(this->flowLayoutPanel4, 0, 0);
			this->tableLayoutPanel8->Controls->Add(this->flowLayoutPanel3, 1, 0);
			this->tableLayoutPanel8->Location = System::Drawing::Point(10, 204);
			this->tableLayoutPanel8->Name = L"tableLayoutPanel8";
			this->tableLayoutPanel8->RowCount = 1;
			this->tableLayoutPanel8->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel8->Size = System::Drawing::Size(533, 62);
			this->tableLayoutPanel8->TabIndex = 22;
			this->tableLayoutPanel8->Visible = false;
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->AutoSize = true;
			this->flowLayoutPanel1->Controls->Add(this->checkBox3);
			this->flowLayoutPanel1->Controls->Add(this->checkBox7);
			this->flowLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->flowLayoutPanel1->Location = System::Drawing::Point(277, 3);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(253, 56);
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
			this->flowLayoutPanel4->Size = System::Drawing::Size(100, 56);
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
			this->flowLayoutPanel3->Location = System::Drawing::Point(109, 3);
			this->flowLayoutPanel3->Name = L"flowLayoutPanel3";
			this->flowLayoutPanel3->Size = System::Drawing::Size(162, 56);
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
			// checkedListBox1
			// 
			this->checkedListBox1->FormattingEnabled = true;
			this->checkedListBox1->Items->AddRange(gcnew cli::array< System::Object^  >(7) {
				L"Name", L"Size", L"Attributes", L"Alternative Streams",
					L"Creation Time", L"Modification Time", L"Access Time"
			});
			this->checkedListBox1->Location = System::Drawing::Point(447, 59);
			this->checkedListBox1->Name = L"checkedListBox1";
			this->checkedListBox1->Size = System::Drawing::Size(187, 157);
			this->checkedListBox1->TabIndex = 23;
			// 
			// Parameters
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(646, 326);
			this->Controls->Add(this->checkedListBox1);
			this->Controls->Add(this->tableLayoutPanel8);
			this->Controls->Add(this->tableLayoutPanel3);
			this->Name = L"Parameters";
			this->Text = L"Parameters";
			this->Load += gcnew System::EventHandler(this, &Parameters::Parameters_Load);
			this->tableLayoutPanel3->ResumeLayout(false);
			this->tableLayoutPanel3->PerformLayout();
			this->tableLayoutPanel8->ResumeLayout(false);
			this->tableLayoutPanel8->PerformLayout();
			this->flowLayoutPanel1->ResumeLayout(false);
			this->flowLayoutPanel1->PerformLayout();
			this->flowLayoutPanel4->ResumeLayout(false);
			this->flowLayoutPanel4->PerformLayout();
			this->flowLayoutPanel3->ResumeLayout(false);
			this->flowLayoutPanel3->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Parameters_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
