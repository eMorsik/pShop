#pragma once

namespace pShop {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для CartAdd
	/// </summary>
	public ref class pAddCart : public System::Windows::Forms::Form
	{
	public: static bool ConfirmAdd;
	public:
		pAddCart(void)
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
		~pAddCart()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Panel^ panelAddCart;
	protected:

	private: System::Windows::Forms::NumericUpDown^ nudAddCart;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ btnAddCart;

	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Panel^ panelDeleteCart;


	private: System::Windows::Forms::NumericUpDown^ nudDeleteCart;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ btnDeleteCart;

	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::Label^ lbCashCart;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ btnConfirm;
	private: System::Windows::Forms::Panel^ panelCash;


	private: System::Windows::Forms::Panel^ panel7;
	private: System::Windows::Forms::DataGridView^ dataGridView2;
	private: System::Windows::Forms::Panel^ panel6;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->panelAddCart = (gcnew System::Windows::Forms::Panel());
			this->nudAddCart = (gcnew System::Windows::Forms::NumericUpDown());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->btnAddCart = (gcnew System::Windows::Forms::Button());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->panelCash = (gcnew System::Windows::Forms::Panel());
			this->lbCashCart = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->panelDeleteCart = (gcnew System::Windows::Forms::Panel());
			this->nudDeleteCart = (gcnew System::Windows::Forms::NumericUpDown());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnDeleteCart = (gcnew System::Windows::Forms::Button());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->btnConfirm = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->panelAddCart->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudAddCart))->BeginInit();
			this->panel2->SuspendLayout();
			this->panel7->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			this->panel6->SuspendLayout();
			this->panelCash->SuspendLayout();
			this->panelDeleteCart->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudDeleteCart))->BeginInit();
			this->panel4->SuspendLayout();
			this->SuspendLayout();
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
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
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
			dataGridViewCellStyle2->ForeColor = System::Drawing::Color::Black;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView1->DefaultCellStyle = dataGridViewCellStyle2;
			this->dataGridView1->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(44)), static_cast<System::Int32>(static_cast<System::Byte>(44)),
				static_cast<System::Int32>(static_cast<System::Byte>(65)));
			this->dataGridView1->Location = System::Drawing::Point(10, 10);
			this->dataGridView1->MaximumSize = System::Drawing::Size(750, 1000);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->dataGridView1->Size = System::Drawing::Size(717, 231);
			this->dataGridView1->TabIndex = 9;
			// 
			// panelAddCart
			// 
			this->panelAddCart->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->panelAddCart->Controls->Add(this->nudAddCart);
			this->panelAddCart->Controls->Add(this->label2);
			this->panelAddCart->Controls->Add(this->btnAddCart);
			this->panelAddCart->Enabled = false;
			this->panelAddCart->Location = System::Drawing::Point(14, 13);
			this->panelAddCart->Name = L"panelAddCart";
			this->panelAddCart->Size = System::Drawing::Size(290, 106);
			this->panelAddCart->TabIndex = 8;
			// 
			// nudAddCart
			// 
			this->nudAddCart->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->nudAddCart->Location = System::Drawing::Point(200, 60);
			this->nudAddCart->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->nudAddCart->Name = L"nudAddCart";
			this->nudAddCart->Size = System::Drawing::Size(77, 30);
			this->nudAddCart->TabIndex = 5;
			this->nudAddCart->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
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
			// btnAddCart
			// 
			this->btnAddCart->BackColor = System::Drawing::Color::Teal;
			this->btnAddCart->FlatAppearance->BorderSize = 0;
			this->btnAddCart->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
			this->btnAddCart->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightSeaGreen;
			this->btnAddCart->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnAddCart->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnAddCart->ForeColor = System::Drawing::Color::White;
			this->btnAddCart->Location = System::Drawing::Point(13, 13);
			this->btnAddCart->Name = L"btnAddCart";
			this->btnAddCart->Size = System::Drawing::Size(264, 37);
			this->btnAddCart->TabIndex = 1;
			this->btnAddCart->Text = L"Добавить товар в корзину";
			this->btnAddCart->UseVisualStyleBackColor = false;
			this->btnAddCart->Click += gcnew System::EventHandler(this, &pAddCart::btnAddCart_Click);
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->panel7);
			this->panel2->Controls->Add(this->panel6);
			this->panel2->Controls->Add(this->panelCash);
			this->panel2->Controls->Add(this->panelDeleteCart);
			this->panel2->Controls->Add(this->panel4);
			this->panel2->Controls->Add(this->panelAddCart);
			this->panel2->Location = System::Drawing::Point(15, 12);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1063, 575);
			this->panel2->TabIndex = 10;
			// 
			// panel7
			// 
			this->panel7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->panel7->Controls->Add(this->dataGridView2);
			this->panel7->Location = System::Drawing::Point(322, 285);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(738, 256);
			this->panel7->TabIndex = 15;
			// 
			// dataGridView2
			// 
			this->dataGridView2->AllowUserToDeleteRows = false;
			this->dataGridView2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->dataGridView2->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView2->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(44)),
				static_cast<System::Int32>(static_cast<System::Byte>(44)), static_cast<System::Int32>(static_cast<System::Byte>(65)));
			this->dataGridView2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle3->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			dataGridViewCellStyle3->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle3->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle3->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView2->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle3;
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			dataGridViewCellStyle4->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle4->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			dataGridViewCellStyle4->ForeColor = System::Drawing::Color::Black;
			dataGridViewCellStyle4->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle4->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle4->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView2->DefaultCellStyle = dataGridViewCellStyle4;
			this->dataGridView2->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(44)), static_cast<System::Int32>(static_cast<System::Byte>(44)),
				static_cast<System::Int32>(static_cast<System::Byte>(65)));
			this->dataGridView2->Location = System::Drawing::Point(10, 10);
			this->dataGridView2->MaximumSize = System::Drawing::Size(750, 1000);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders;
			this->dataGridView2->RowTemplate->Height = 24;
			this->dataGridView2->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->dataGridView2->Size = System::Drawing::Size(717, 231);
			this->dataGridView2->TabIndex = 9;
			// 
			// panel6
			// 
			this->panel6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->panel6->Controls->Add(this->dataGridView1);
			this->panel6->Location = System::Drawing::Point(322, 11);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(738, 256);
			this->panel6->TabIndex = 14;
			// 
			// panelCash
			// 
			this->panelCash->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->panelCash->Controls->Add(this->lbCashCart);
			this->panelCash->Controls->Add(this->label3);
			this->panelCash->Enabled = false;
			this->panelCash->Location = System::Drawing::Point(14, 395);
			this->panelCash->Name = L"panelCash";
			this->panelCash->Size = System::Drawing::Size(290, 50);
			this->panelCash->TabIndex = 13;
			// 
			// lbCashCart
			// 
			this->lbCashCart->AutoSize = true;
			this->lbCashCart->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->lbCashCart->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F));
			this->lbCashCart->ForeColor = System::Drawing::Color::White;
			this->lbCashCart->Location = System::Drawing::Point(196, 13);
			this->lbCashCart->Name = L"lbCashCart";
			this->lbCashCart->Size = System::Drawing::Size(29, 23);
			this->lbCashCart->TabIndex = 6;
			this->lbCashCart->Text = L"0р";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->ForeColor = System::Drawing::Color::White;
			this->label3->Location = System::Drawing::Point(9, 13);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(123, 23);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Общая сумма:";
			// 
			// panelDeleteCart
			// 
			this->panelDeleteCart->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->panelDeleteCart->Controls->Add(this->nudDeleteCart);
			this->panelDeleteCart->Controls->Add(this->label1);
			this->panelDeleteCart->Controls->Add(this->btnDeleteCart);
			this->panelDeleteCart->Enabled = false;
			this->panelDeleteCart->Location = System::Drawing::Point(14, 285);
			this->panelDeleteCart->Name = L"panelDeleteCart";
			this->panelDeleteCart->Size = System::Drawing::Size(290, 103);
			this->panelDeleteCart->TabIndex = 11;
			// 
			// nudDeleteCart
			// 
			this->nudDeleteCart->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->nudDeleteCart->Location = System::Drawing::Point(200, 60);
			this->nudDeleteCart->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->nudDeleteCart->Name = L"nudDeleteCart";
			this->nudDeleteCart->Size = System::Drawing::Size(77, 30);
			this->nudDeleteCart->TabIndex = 5;
			this->nudDeleteCart->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(9, 62);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(126, 23);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Номер товара:";
			// 
			// btnDeleteCart
			// 
			this->btnDeleteCart->BackColor = System::Drawing::Color::Teal;
			this->btnDeleteCart->FlatAppearance->BorderSize = 0;
			this->btnDeleteCart->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
			this->btnDeleteCart->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightSeaGreen;
			this->btnDeleteCart->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnDeleteCart->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnDeleteCart->ForeColor = System::Drawing::Color::White;
			this->btnDeleteCart->Location = System::Drawing::Point(13, 13);
			this->btnDeleteCart->Name = L"btnDeleteCart";
			this->btnDeleteCart->Size = System::Drawing::Size(264, 37);
			this->btnDeleteCart->TabIndex = 1;
			this->btnDeleteCart->Text = L"Убрать товар из корзины";
			this->btnDeleteCart->UseVisualStyleBackColor = false;
			this->btnDeleteCart->Click += gcnew System::EventHandler(this, &pAddCart::btnDeleteCart_Click);
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->panel4->Controls->Add(this->btnConfirm);
			this->panel4->Location = System::Drawing::Point(14, 452);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(290, 65);
			this->panel4->TabIndex = 10;
			// 
			// btnConfirm
			// 
			this->btnConfirm->BackColor = System::Drawing::Color::Teal;
			this->btnConfirm->Enabled = false;
			this->btnConfirm->FlatAppearance->BorderSize = 0;
			this->btnConfirm->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
			this->btnConfirm->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightSeaGreen;
			this->btnConfirm->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnConfirm->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnConfirm->ForeColor = System::Drawing::Color::White;
			this->btnConfirm->Location = System::Drawing::Point(12, 13);
			this->btnConfirm->Name = L"btnConfirm";
			this->btnConfirm->Size = System::Drawing::Size(264, 37);
			this->btnConfirm->TabIndex = 3;
			this->btnConfirm->Text = L"Подтвердить покупку";
			this->btnConfirm->UseVisualStyleBackColor = false;
			this->btnConfirm->Click += gcnew System::EventHandler(this, &pAddCart::btnConfirm_Click);
			// 
			// pAddCart
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(44)), static_cast<System::Int32>(static_cast<System::Byte>(44)),
				static_cast<System::Int32>(static_cast<System::Byte>(65)));
			this->ClientSize = System::Drawing::Size(1130, 599);
			this->Controls->Add(this->panel2);
			this->Name = L"pAddCart";
			this->Text = L"CartAdd";
			this->Load += gcnew System::EventHandler(this, &pAddCart::pAddCart_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->panelAddCart->ResumeLayout(false);
			this->panelAddCart->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudAddCart))->EndInit();
			this->panel2->ResumeLayout(false);
			this->panel7->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			this->panel6->ResumeLayout(false);
			this->panelCash->ResumeLayout(false);
			this->panelCash->PerformLayout();
			this->panelDeleteCart->ResumeLayout(false);
			this->panelDeleteCart->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudDeleteCart))->EndInit();
			this->panel4->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void pAddCart_Load(System::Object^ sender, System::EventArgs^ e);
		   void HeaderAll();
		   void ShowAll();
		   void DataReaderAll();
		   void dataGridView_LoadAll();
		   void HeaderCart();
		   void ShowCart();
		   void DataReaderCart();
		   void dataGridView_LoadCart();
	private: System::Void btnAddCart_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void btnDeleteCart_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void btnConfirm_Click(System::Object^ sender, System::EventArgs^ e);

	};
}
