#pragma once

namespace pShop {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для pEditing
	/// </summary>
	public ref class pEditing : public System::Windows::Forms::Form
	{
	public:
		pEditing(void)
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
		~pEditing()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panelEdit;
	private: System::Windows::Forms::Button^ btnEditConfirm;
	public: System::Windows::Forms::TextBox^ tbName;
	public: System::Windows::Forms::ComboBox^ cbType;
	public: System::Windows::Forms::NumericUpDown^ nudCost;
	public: System::Windows::Forms::MaskedTextBox^ tbExpDate;
	public: System::Windows::Forms::NumericUpDown^ nudValue;
	public: System::Windows::Forms::NumericUpDown^ nudWeight;

	private: System::Windows::Forms::Label^ lbName;
	private: System::Windows::Forms::Label^ lbCost;
	private: System::Windows::Forms::Label^ lbType;
	private: System::Windows::Forms::Label^ lbExpDate;
	private: System::Windows::Forms::Label^ lbProdValue;
	private: System::Windows::Forms::Label^ lbWeight;
	private: System::Windows::Forms::Label^ lbValue;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(pEditing::typeid));
			this->panelEdit = (gcnew System::Windows::Forms::Panel());
			this->lbWeight = (gcnew System::Windows::Forms::Label());
			this->nudValue = (gcnew System::Windows::Forms::NumericUpDown());
			this->nudWeight = (gcnew System::Windows::Forms::NumericUpDown());
			this->lbValue = (gcnew System::Windows::Forms::Label());
			this->nudCost = (gcnew System::Windows::Forms::NumericUpDown());
			this->cbType = (gcnew System::Windows::Forms::ComboBox());
			this->lbCost = (gcnew System::Windows::Forms::Label());
			this->tbExpDate = (gcnew System::Windows::Forms::MaskedTextBox());
			this->btnEditConfirm = (gcnew System::Windows::Forms::Button());
			this->lbProdValue = (gcnew System::Windows::Forms::Label());
			this->lbExpDate = (gcnew System::Windows::Forms::Label());
			this->lbType = (gcnew System::Windows::Forms::Label());
			this->lbName = (gcnew System::Windows::Forms::Label());
			this->tbName = (gcnew System::Windows::Forms::TextBox());
			this->panelEdit->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudValue))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudWeight))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudCost))->BeginInit();
			this->SuspendLayout();
			// 
			// panelEdit
			// 
			this->panelEdit->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom));
			this->panelEdit->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->panelEdit->Controls->Add(this->lbWeight);
			this->panelEdit->Controls->Add(this->nudValue);
			this->panelEdit->Controls->Add(this->nudWeight);
			this->panelEdit->Controls->Add(this->lbValue);
			this->panelEdit->Controls->Add(this->nudCost);
			this->panelEdit->Controls->Add(this->cbType);
			this->panelEdit->Controls->Add(this->lbCost);
			this->panelEdit->Controls->Add(this->tbExpDate);
			this->panelEdit->Controls->Add(this->btnEditConfirm);
			this->panelEdit->Controls->Add(this->lbProdValue);
			this->panelEdit->Controls->Add(this->lbExpDate);
			this->panelEdit->Controls->Add(this->lbType);
			this->panelEdit->Controls->Add(this->lbName);
			this->panelEdit->Controls->Add(this->tbName);
			this->panelEdit->Location = System::Drawing::Point(7, 7);
			this->panelEdit->MaximumSize = System::Drawing::Size(595, 348);
			this->panelEdit->Name = L"panelEdit";
			this->panelEdit->Size = System::Drawing::Size(576, 348);
			this->panelEdit->TabIndex = 2;
			// 
			// lbWeight
			// 
			this->lbWeight->AutoSize = true;
			this->lbWeight->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lbWeight->ForeColor = System::Drawing::Color::White;
			this->lbWeight->Location = System::Drawing::Point(23, 310);
			this->lbWeight->Name = L"lbWeight";
			this->lbWeight->Size = System::Drawing::Size(138, 23);
			this->lbWeight->TabIndex = 37;
			this->lbWeight->Text = L"В килограммах:";
			// 
			// nudValue
			// 
			this->nudValue->Enabled = false;
			this->nudValue->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->nudValue->Location = System::Drawing::Point(167, 277);
			this->nudValue->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->nudValue->Name = L"nudValue";
			this->nudValue->Size = System::Drawing::Size(125, 27);
			this->nudValue->TabIndex = 36;
			this->nudValue->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// nudWeight
			// 
			this->nudWeight->DecimalPlaces = 1;
			this->nudWeight->Enabled = false;
			this->nudWeight->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->nudWeight->Location = System::Drawing::Point(27, 277);
			this->nudWeight->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
			this->nudWeight->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 65536 });
			this->nudWeight->Name = L"nudWeight";
			this->nudWeight->Size = System::Drawing::Size(132, 27);
			this->nudWeight->TabIndex = 35;
			this->nudWeight->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// lbValue
			// 
			this->lbValue->AutoSize = true;
			this->lbValue->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lbValue->ForeColor = System::Drawing::Color::White;
			this->lbValue->Location = System::Drawing::Point(167, 310);
			this->lbValue->Name = L"lbValue";
			this->lbValue->Size = System::Drawing::Size(86, 23);
			this->lbValue->TabIndex = 34;
			this->lbValue->Text = L"В штуках:";
			// 
			// nudCost
			// 
			this->nudCost->DecimalPlaces = 1;
			this->nudCost->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->nudCost->Location = System::Drawing::Point(27, 157);
			this->nudCost->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->nudCost->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->nudCost->Name = L"nudCost";
			this->nudCost->Size = System::Drawing::Size(125, 27);
			this->nudCost->TabIndex = 33;
			this->nudCost->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// cbType
			// 
			this->cbType->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cbType->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F));
			this->cbType->FormattingEnabled = true;
			this->cbType->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->cbType->Items->AddRange(gcnew cli::array< System::Object^  >(6) {
				L"Овощи/Фрукты", L"Гигиенические товары", L"Бытовые товары",
					L"Снеки", L"Полуфабрикаты", L"Молочка"
			});
			this->cbType->Location = System::Drawing::Point(27, 97);
			this->cbType->Name = L"cbType";
			this->cbType->Size = System::Drawing::Size(265, 28);
			this->cbType->TabIndex = 32;
			this->cbType->SelectedIndexChanged += gcnew System::EventHandler(this, &pEditing::cbType_SelectedIndexChanged);
			// 
			// lbCost
			// 
			this->lbCost->AutoSize = true;
			this->lbCost->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lbCost->ForeColor = System::Drawing::Color::White;
			this->lbCost->Location = System::Drawing::Point(23, 131);
			this->lbCost->Name = L"lbCost";
			this->lbCost->Size = System::Drawing::Size(158, 23);
			this->lbCost->TabIndex = 31;
			this->lbCost->Text = L"Стоимость товара:";
			// 
			// tbExpDate
			// 
			this->tbExpDate->Enabled = false;
			this->tbExpDate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tbExpDate->Location = System::Drawing::Point(27, 219);
			this->tbExpDate->Mask = L"00/00/0000";
			this->tbExpDate->Name = L"tbExpDate";
			this->tbExpDate->Size = System::Drawing::Size(265, 27);
			this->tbExpDate->TabIndex = 10;
			// 
			// btnEditConfirm
			// 
			this->btnEditConfirm->BackColor = System::Drawing::Color::Teal;
			this->btnEditConfirm->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->btnEditConfirm->FlatAppearance->BorderSize = 0;
			this->btnEditConfirm->FlatAppearance->MouseDownBackColor = System::Drawing::Color::WhiteSmoke;
			this->btnEditConfirm->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightSeaGreen;
			this->btnEditConfirm->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnEditConfirm->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnEditConfirm->ForeColor = System::Drawing::Color::White;
			this->btnEditConfirm->Location = System::Drawing::Point(327, 39);
			this->btnEditConfirm->Margin = System::Windows::Forms::Padding(30, 3, 30, 3);
			this->btnEditConfirm->Name = L"btnEditConfirm";
			this->btnEditConfirm->Size = System::Drawing::Size(235, 55);
			this->btnEditConfirm->TabIndex = 0;
			this->btnEditConfirm->Text = L"Сохранить изменения";
			this->btnEditConfirm->UseVisualStyleBackColor = false;
			this->btnEditConfirm->Click += gcnew System::EventHandler(this, &pEditing::btnEditConfirm_Click);
			// 
			// lbProdValue
			// 
			this->lbProdValue->AutoSize = true;
			this->lbProdValue->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lbProdValue->ForeColor = System::Drawing::Color::White;
			this->lbProdValue->Location = System::Drawing::Point(23, 249);
			this->lbProdValue->Name = L"lbProdValue";
			this->lbProdValue->Size = System::Drawing::Size(129, 23);
			this->lbProdValue->TabIndex = 8;
			this->lbProdValue->Text = L"Кол-во товара:";
			// 
			// lbExpDate
			// 
			this->lbExpDate->AutoSize = true;
			this->lbExpDate->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lbExpDate->ForeColor = System::Drawing::Color::White;
			this->lbExpDate->Location = System::Drawing::Point(23, 192);
			this->lbExpDate->Name = L"lbExpDate";
			this->lbExpDate->Size = System::Drawing::Size(131, 23);
			this->lbExpDate->TabIndex = 7;
			this->lbExpDate->Text = L"Срок годности:";
			// 
			// lbType
			// 
			this->lbType->AutoSize = true;
			this->lbType->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lbType->ForeColor = System::Drawing::Color::White;
			this->lbType->Location = System::Drawing::Point(23, 71);
			this->lbType->Name = L"lbType";
			this->lbType->Size = System::Drawing::Size(101, 23);
			this->lbType->TabIndex = 6;
			this->lbType->Text = L"Тип товара:";
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
			this->tbName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tbName->Location = System::Drawing::Point(27, 39);
			this->tbName->Margin = System::Windows::Forms::Padding(5);
			this->tbName->Name = L"tbName";
			this->tbName->Size = System::Drawing::Size(265, 27);
			this->tbName->TabIndex = 0;
			// 
			// pEditing
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->ClientSize = System::Drawing::Size(591, 362);
			this->Controls->Add(this->panelEdit);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximumSize = System::Drawing::Size(800, 500);
			this->MinimumSize = System::Drawing::Size(609, 409);
			this->Name = L"pEditing";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Редактирование товара";
			this->Load += gcnew System::EventHandler(this, &pEditing::pEditing_Load);
			this->panelEdit->ResumeLayout(false);
			this->panelEdit->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudValue))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudWeight))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudCost))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void pEditing_Load(System::Object^ sender, System::EventArgs^ e);
private: System::Void btnEditConfirm_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void pEditing_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e);
private: System::Void cbType_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
};
}
