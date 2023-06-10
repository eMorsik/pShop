#pragma once

namespace pShop {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для pEdit
	/// </summary>
	public ref class pEdit : public System::Windows::Forms::Form
	{
	public: static bool backup = false;
	public:
		pEdit(void)
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
		~pEdit()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Button^ btnDeleteAllProduct;
	protected:

	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::NumericUpDown^ nudEdit;


	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ btnEditProduct;

	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::NumericUpDown^ nudDelete;


	private: System::Windows::Forms::Button^ btnDeleteProduct;

	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::Button^ btnAddProduct;


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
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->btnDeleteAllProduct = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->nudEdit = (gcnew System::Windows::Forms::NumericUpDown());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->btnEditProduct = (gcnew System::Windows::Forms::Button());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->nudDelete = (gcnew System::Windows::Forms::NumericUpDown());
			this->btnDeleteProduct = (gcnew System::Windows::Forms::Button());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->btnAddProduct = (gcnew System::Windows::Forms::Button());
			this->panel3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudEdit))->BeginInit();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudDelete))->BeginInit();
			this->panel4->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->panel3->Controls->Add(this->btnDeleteAllProduct);
			this->panel3->Location = System::Drawing::Point(25, 343);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(290, 66);
			this->panel3->TabIndex = 8;
			// 
			// btnDeleteAllProduct
			// 
			this->btnDeleteAllProduct->BackColor = System::Drawing::Color::Teal;
			this->btnDeleteAllProduct->Enabled = false;
			this->btnDeleteAllProduct->FlatAppearance->BorderSize = 0;
			this->btnDeleteAllProduct->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
			this->btnDeleteAllProduct->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightSeaGreen;
			this->btnDeleteAllProduct->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnDeleteAllProduct->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnDeleteAllProduct->ForeColor = System::Drawing::Color::White;
			this->btnDeleteAllProduct->Location = System::Drawing::Point(14, 13);
			this->btnDeleteAllProduct->Name = L"btnDeleteAllProduct";
			this->btnDeleteAllProduct->Size = System::Drawing::Size(264, 37);
			this->btnDeleteAllProduct->TabIndex = 3;
			this->btnDeleteAllProduct->Text = L"Удалить все данные";
			this->btnDeleteAllProduct->UseVisualStyleBackColor = false;
			this->btnDeleteAllProduct->Click += gcnew System::EventHandler(this, &pEdit::btnDeleteAllProduct_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(44)),
				static_cast<System::Int32>(static_cast<System::Byte>(44)), static_cast<System::Int32>(static_cast<System::Byte>(65)));
			this->dataGridView1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle3->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			dataGridViewCellStyle3->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle3->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle3->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle3;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			dataGridViewCellStyle4->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle4->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			dataGridViewCellStyle4->ForeColor = System::Drawing::Color::Black;
			dataGridViewCellStyle4->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle4->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle4->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView1->DefaultCellStyle = dataGridViewCellStyle4;
			this->dataGridView1->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(44)), static_cast<System::Int32>(static_cast<System::Byte>(44)),
				static_cast<System::Int32>(static_cast<System::Byte>(65)));
			this->dataGridView1->Location = System::Drawing::Point(376, 20);
			this->dataGridView1->MaximumSize = System::Drawing::Size(750, 1000);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->dataGridView1->Size = System::Drawing::Size(720, 524);
			this->dataGridView1->TabIndex = 7;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->panel1->Controls->Add(this->nudEdit);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->btnEditProduct);
			this->panel1->Location = System::Drawing::Point(25, 101);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(290, 106);
			this->panel1->TabIndex = 6;
			// 
			// nudEdit
			// 
			this->nudEdit->Enabled = false;
			this->nudEdit->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->nudEdit->Location = System::Drawing::Point(200, 60);
			this->nudEdit->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->nudEdit->Name = L"nudEdit";
			this->nudEdit->Size = System::Drawing::Size(77, 30);
			this->nudEdit->TabIndex = 5;
			this->nudEdit->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(9, 62);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(126, 23);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Номер товара:";
			// 
			// btnEditProduct
			// 
			this->btnEditProduct->BackColor = System::Drawing::Color::Teal;
			this->btnEditProduct->Enabled = false;
			this->btnEditProduct->FlatAppearance->BorderSize = 0;
			this->btnEditProduct->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
			this->btnEditProduct->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightSeaGreen;
			this->btnEditProduct->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnEditProduct->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnEditProduct->ForeColor = System::Drawing::Color::White;
			this->btnEditProduct->Location = System::Drawing::Point(13, 13);
			this->btnEditProduct->Name = L"btnEditProduct";
			this->btnEditProduct->Size = System::Drawing::Size(264, 37);
			this->btnEditProduct->TabIndex = 1;
			this->btnEditProduct->Text = L"Изменить данные товара";
			this->btnEditProduct->UseVisualStyleBackColor = false;
			this->btnEditProduct->Click += gcnew System::EventHandler(this, &pEdit::btnEditProduct_Click);
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->panel2->Controls->Add(this->label1);
			this->panel2->Controls->Add(this->nudDelete);
			this->panel2->Controls->Add(this->btnDeleteProduct);
			this->panel2->Location = System::Drawing::Point(25, 222);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(290, 106);
			this->panel2->TabIndex = 5;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(14, 62);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(126, 23);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Номер товара:";
			// 
			// nudDelete
			// 
			this->nudDelete->Enabled = false;
			this->nudDelete->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->nudDelete->Location = System::Drawing::Point(200, 60);
			this->nudDelete->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->nudDelete->Name = L"nudDelete";
			this->nudDelete->Size = System::Drawing::Size(77, 30);
			this->nudDelete->TabIndex = 1;
			this->nudDelete->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// btnDeleteProduct
			// 
			this->btnDeleteProduct->BackColor = System::Drawing::Color::Teal;
			this->btnDeleteProduct->Enabled = false;
			this->btnDeleteProduct->FlatAppearance->BorderSize = 0;
			this->btnDeleteProduct->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
			this->btnDeleteProduct->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightSeaGreen;
			this->btnDeleteProduct->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnDeleteProduct->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnDeleteProduct->ForeColor = System::Drawing::Color::White;
			this->btnDeleteProduct->Location = System::Drawing::Point(13, 13);
			this->btnDeleteProduct->Name = L"btnDeleteProduct";
			this->btnDeleteProduct->Size = System::Drawing::Size(264, 37);
			this->btnDeleteProduct->TabIndex = 0;
			this->btnDeleteProduct->Text = L"Удалить данные товара";
			this->btnDeleteProduct->UseVisualStyleBackColor = false;
			this->btnDeleteProduct->Click += gcnew System::EventHandler(this, &pEdit::btnDeleteProduct_Click);
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->panel4->Controls->Add(this->btnAddProduct);
			this->panel4->Location = System::Drawing::Point(25, 20);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(290, 66);
			this->panel4->TabIndex = 9;
			// 
			// btnAddProduct
			// 
			this->btnAddProduct->BackColor = System::Drawing::Color::Teal;
			this->btnAddProduct->FlatAppearance->BorderSize = 0;
			this->btnAddProduct->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
			this->btnAddProduct->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightSeaGreen;
			this->btnAddProduct->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnAddProduct->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnAddProduct->ForeColor = System::Drawing::Color::White;
			this->btnAddProduct->Location = System::Drawing::Point(14, 13);
			this->btnAddProduct->Name = L"btnAddProduct";
			this->btnAddProduct->Size = System::Drawing::Size(264, 37);
			this->btnAddProduct->TabIndex = 3;
			this->btnAddProduct->Text = L"Добавить товар на склад";
			this->btnAddProduct->UseVisualStyleBackColor = false;
			this->btnAddProduct->Click += gcnew System::EventHandler(this, &pEdit::btnAddProduct_Click);
			// 
			// pEdit
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(44)), static_cast<System::Int32>(static_cast<System::Byte>(44)),
				static_cast<System::Int32>(static_cast<System::Byte>(65)));
			this->ClientSize = System::Drawing::Size(1130, 573);
			this->Controls->Add(this->panel4);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->panel2);
			this->Name = L"pEdit";
			this->Text = L"pEdit";
			this->Load += gcnew System::EventHandler(this, &pEdit::pEdit_Load);
			this->panel3->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudEdit))->EndInit();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudDelete))->EndInit();
			this->panel4->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void pEdit_Load(System::Object^ sender, System::EventArgs^ e);
	   void HeaderEdit();
	   void ShowEdit();
	   void DataReaderEdit();
private: System::Void dataGridView_Load();
private: System::Void btnAddProduct_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void btnEditProduct_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void btnDeleteProduct_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void btnDeleteAllProduct_Click(System::Object^ sender, System::EventArgs^ e);
};
}
