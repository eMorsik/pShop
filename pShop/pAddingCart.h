#pragma once

namespace pShop {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для pAddingCart
	/// </summary>
	public ref class pAddingCart : public System::Windows::Forms::Form
	{
	public:
		pAddingCart(void)
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
		~pAddingCart()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panelAdd;
	public: System::Windows::Forms::NumericUpDown^ nudCost;
	private: System::Windows::Forms::Label^ lbCost;
	private: System::Windows::Forms::Label^ lbWeight;
	public: System::Windows::Forms::NumericUpDown^ nudValue;
	public: System::Windows::Forms::NumericUpDown^ nudWeight;
	private: System::Windows::Forms::Button^ btnAddCartConfirm;
	private: System::Windows::Forms::Label^ lbValue;
	private: System::Windows::Forms::Label^ lbProdValue;
	private: System::Windows::Forms::Label^ lbName;
	public: System::Windows::Forms::TextBox^ tbName;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(pAddingCart::typeid));
			this->panelAdd = (gcnew System::Windows::Forms::Panel());
			this->nudCost = (gcnew System::Windows::Forms::NumericUpDown());
			this->lbCost = (gcnew System::Windows::Forms::Label());
			this->lbWeight = (gcnew System::Windows::Forms::Label());
			this->nudValue = (gcnew System::Windows::Forms::NumericUpDown());
			this->nudWeight = (gcnew System::Windows::Forms::NumericUpDown());
			this->btnAddCartConfirm = (gcnew System::Windows::Forms::Button());
			this->lbValue = (gcnew System::Windows::Forms::Label());
			this->lbProdValue = (gcnew System::Windows::Forms::Label());
			this->lbName = (gcnew System::Windows::Forms::Label());
			this->tbName = (gcnew System::Windows::Forms::TextBox());
			this->panelAdd->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudCost))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudValue))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudWeight))->BeginInit();
			this->SuspendLayout();
			// 
			// panelAdd
			// 
			this->panelAdd->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom));
			this->panelAdd->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(44)), static_cast<System::Int32>(static_cast<System::Byte>(44)),
				static_cast<System::Int32>(static_cast<System::Byte>(65)));
			this->panelAdd->Controls->Add(this->nudCost);
			this->panelAdd->Controls->Add(this->lbCost);
			this->panelAdd->Controls->Add(this->lbWeight);
			this->panelAdd->Controls->Add(this->nudValue);
			this->panelAdd->Controls->Add(this->nudWeight);
			this->panelAdd->Controls->Add(this->btnAddCartConfirm);
			this->panelAdd->Controls->Add(this->lbValue);
			this->panelAdd->Controls->Add(this->lbProdValue);
			this->panelAdd->Controls->Add(this->lbName);
			this->panelAdd->Controls->Add(this->tbName);
			this->panelAdd->Location = System::Drawing::Point(15, 12);
			this->panelAdd->MaximumSize = System::Drawing::Size(571, 236);
			this->panelAdd->Name = L"panelAdd";
			this->panelAdd->Size = System::Drawing::Size(571, 236);
			this->panelAdd->TabIndex = 2;
			// 
			// nudCost
			// 
			this->nudCost->DecimalPlaces = 1;
			this->nudCost->Enabled = false;
			this->nudCost->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->nudCost->Location = System::Drawing::Point(166, 186);
			this->nudCost->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->nudCost->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->nudCost->Name = L"nudCost";
			this->nudCost->Size = System::Drawing::Size(126, 27);
			this->nudCost->TabIndex = 33;
			this->nudCost->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// lbCost
			// 
			this->lbCost->AutoSize = true;
			this->lbCost->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lbCost->ForeColor = System::Drawing::Color::White;
			this->lbCost->Location = System::Drawing::Point(23, 186);
			this->lbCost->Name = L"lbCost";
			this->lbCost->Size = System::Drawing::Size(99, 23);
			this->lbCost->TabIndex = 31;
			this->lbCost->Text = L"Стоимость:";
			// 
			// lbWeight
			// 
			this->lbWeight->AutoSize = true;
			this->lbWeight->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lbWeight->ForeColor = System::Drawing::Color::White;
			this->lbWeight->Location = System::Drawing::Point(23, 133);
			this->lbWeight->Name = L"lbWeight";
			this->lbWeight->Size = System::Drawing::Size(138, 23);
			this->lbWeight->TabIndex = 27;
			this->lbWeight->Text = L"В килограммах:";
			// 
			// nudValue
			// 
			this->nudValue->Enabled = false;
			this->nudValue->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->nudValue->Location = System::Drawing::Point(167, 100);
			this->nudValue->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->nudValue->Name = L"nudValue";
			this->nudValue->Size = System::Drawing::Size(125, 27);
			this->nudValue->TabIndex = 12;
			this->nudValue->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->nudValue->ValueChanged += gcnew System::EventHandler(this, &pAddingCart::nudValue_ValueChanged);
			// 
			// nudWeight
			// 
			this->nudWeight->DecimalPlaces = 1;
			this->nudWeight->Enabled = false;
			this->nudWeight->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->nudWeight->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 65536 });
			this->nudWeight->Location = System::Drawing::Point(27, 100);
			this->nudWeight->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
			this->nudWeight->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 65536 });
			this->nudWeight->Name = L"nudWeight";
			this->nudWeight->Size = System::Drawing::Size(132, 27);
			this->nudWeight->TabIndex = 11;
			this->nudWeight->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->nudWeight->ValueChanged += gcnew System::EventHandler(this, &pAddingCart::nudWeight_ValueChanged);
			// 
			// btnAddCartConfirm
			// 
			this->btnAddCartConfirm->BackColor = System::Drawing::Color::Teal;
			this->btnAddCartConfirm->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->btnAddCartConfirm->FlatAppearance->BorderSize = 0;
			this->btnAddCartConfirm->FlatAppearance->MouseDownBackColor = System::Drawing::Color::WhiteSmoke;
			this->btnAddCartConfirm->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightSeaGreen;
			this->btnAddCartConfirm->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnAddCartConfirm->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnAddCartConfirm->ForeColor = System::Drawing::Color::White;
			this->btnAddCartConfirm->Location = System::Drawing::Point(318, 39);
			this->btnAddCartConfirm->Margin = System::Windows::Forms::Padding(30, 3, 30, 3);
			this->btnAddCartConfirm->Name = L"btnAddCartConfirm";
			this->btnAddCartConfirm->Size = System::Drawing::Size(235, 55);
			this->btnAddCartConfirm->TabIndex = 0;
			this->btnAddCartConfirm->Text = L"Добавить в корзину";
			this->btnAddCartConfirm->UseVisualStyleBackColor = false;
			this->btnAddCartConfirm->Click += gcnew System::EventHandler(this, &pAddingCart::btnAddCartConfirm_Click);
			// 
			// lbValue
			// 
			this->lbValue->AutoSize = true;
			this->lbValue->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lbValue->ForeColor = System::Drawing::Color::White;
			this->lbValue->Location = System::Drawing::Point(167, 133);
			this->lbValue->Name = L"lbValue";
			this->lbValue->Size = System::Drawing::Size(86, 23);
			this->lbValue->TabIndex = 9;
			this->lbValue->Text = L"В штуках:";
			// 
			// lbProdValue
			// 
			this->lbProdValue->AutoSize = true;
			this->lbProdValue->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lbProdValue->ForeColor = System::Drawing::Color::White;
			this->lbProdValue->Location = System::Drawing::Point(23, 71);
			this->lbProdValue->Name = L"lbProdValue";
			this->lbProdValue->Size = System::Drawing::Size(129, 23);
			this->lbProdValue->TabIndex = 8;
			this->lbProdValue->Text = L"Кол-во товара:";
			// 
			// lbName
			// 
			this->lbName->AutoSize = true;
			this->lbName->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lbName->ForeColor = System::Drawing::Color::White;
			this->lbName->Location = System::Drawing::Point(23, 11);
			this->lbName->Name = L"lbName";
			this->lbName->Size = System::Drawing::Size(194, 23);
			this->lbName->TabIndex = 5;
			this->lbName->Text = L"Наименование товара:";
			// 
			// tbName
			// 
			this->tbName->Enabled = false;
			this->tbName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tbName->Location = System::Drawing::Point(27, 39);
			this->tbName->Margin = System::Windows::Forms::Padding(5);
			this->tbName->Name = L"tbName";
			this->tbName->Size = System::Drawing::Size(265, 27);
			this->tbName->TabIndex = 0;
			// 
			// pAddingCart
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(44)), static_cast<System::Int32>(static_cast<System::Byte>(44)),
				static_cast<System::Int32>(static_cast<System::Byte>(65)));
			this->ClientSize = System::Drawing::Size(600, 266);
			this->Controls->Add(this->panelAdd);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximumSize = System::Drawing::Size(618, 313);
			this->MinimumSize = System::Drawing::Size(618, 313);
			this->Name = L"pAddingCart";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Добавление продуктов в корзину";
			this->Load += gcnew System::EventHandler(this, &pAddingCart::pAddingCart_Load);
			this->panelAdd->ResumeLayout(false);
			this->panelAdd->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudCost))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudValue))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudWeight))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void pAddingCart_Load(System::Object^ sender, System::EventArgs^ e);
private: System::Void nudWeight_ValueChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void nudValue_ValueChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void btnAddCartConfirm_Click(System::Object^ sender, System::EventArgs^ e);
};
}
