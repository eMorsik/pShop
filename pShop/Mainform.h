#pragma once

namespace pShop {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Mainform
	/// </summary>
	public ref class Mainform : public System::Windows::Forms::Form
	{
	public: static bool isopen = false;
	public: static float Cashbox;
	public:
		Mainform(void)
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
		~Mainform()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panelMenu;
	protected:
	private: System::Windows::Forms::Button^ btnCashbox;
	private: System::Windows::Forms::Button^ btnAddCart;
	private: System::Windows::Forms::Button^ btnEdit;
	private: System::Windows::Forms::Button^ btnList;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ lblName;
	private: System::Windows::Forms::Panel^ panelTop;
	private: System::Windows::Forms::Label^ lblTitle;
	private: System::Windows::Forms::Panel^ panelMain;
	private: System::Windows::Forms::Button^ btnSeller;

	private: System::Windows::Forms::Button^ btnAdmin;

	private: System::Windows::Forms::Timer^ time;
	private: System::Windows::Forms::Label^ lbTime;
	public: System::Windows::Forms::Label^ lbCashbox;



	private: System::ComponentModel::IContainer^ components;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Mainform::typeid));
			this->panelMenu = (gcnew System::Windows::Forms::Panel());
			this->lbCashbox = (gcnew System::Windows::Forms::Label());
			this->btnSeller = (gcnew System::Windows::Forms::Button());
			this->btnAdmin = (gcnew System::Windows::Forms::Button());
			this->btnCashbox = (gcnew System::Windows::Forms::Button());
			this->btnAddCart = (gcnew System::Windows::Forms::Button());
			this->btnEdit = (gcnew System::Windows::Forms::Button());
			this->btnList = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->lbTime = (gcnew System::Windows::Forms::Label());
			this->lblName = (gcnew System::Windows::Forms::Label());
			this->panelTop = (gcnew System::Windows::Forms::Panel());
			this->lblTitle = (gcnew System::Windows::Forms::Label());
			this->panelMain = (gcnew System::Windows::Forms::Panel());
			this->time = (gcnew System::Windows::Forms::Timer(this->components));
			this->panelMenu->SuspendLayout();
			this->panel1->SuspendLayout();
			this->panelTop->SuspendLayout();
			this->SuspendLayout();
			// 
			// panelMenu
			// 
			this->panelMenu->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->panelMenu->Controls->Add(this->lbCashbox);
			this->panelMenu->Controls->Add(this->btnSeller);
			this->panelMenu->Controls->Add(this->btnAdmin);
			this->panelMenu->Controls->Add(this->btnCashbox);
			this->panelMenu->Controls->Add(this->btnAddCart);
			this->panelMenu->Controls->Add(this->btnEdit);
			this->panelMenu->Controls->Add(this->btnList);
			this->panelMenu->Controls->Add(this->panel1);
			this->panelMenu->Dock = System::Windows::Forms::DockStyle::Left;
			this->panelMenu->Location = System::Drawing::Point(0, 0);
			this->panelMenu->Name = L"panelMenu";
			this->panelMenu->Size = System::Drawing::Size(330, 653);
			this->panelMenu->TabIndex = 0;
			// 
			// lbCashbox
			// 
			this->lbCashbox->AutoSize = true;
			this->lbCashbox->BackColor = System::Drawing::Color::Transparent;
			this->lbCashbox->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold));
			this->lbCashbox->ForeColor = System::Drawing::Color::White;
			this->lbCashbox->Location = System::Drawing::Point(207, 261);
			this->lbCashbox->Name = L"lbCashbox";
			this->lbCashbox->Size = System::Drawing::Size(36, 28);
			this->lbCashbox->TabIndex = 9;
			this->lbCashbox->Text = L"0р";
			this->lbCashbox->Visible = false;
			// 
			// btnSeller
			// 
			this->btnSeller->BackColor = System::Drawing::Color::Transparent;
			this->btnSeller->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->btnSeller->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->btnSeller->FlatAppearance->BorderSize = 0;
			this->btnSeller->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Teal;
			this->btnSeller->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnSeller->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnSeller->ForeColor = System::Drawing::SystemColors::Control;
			this->btnSeller->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnSeller.Image")));
			this->btnSeller->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnSeller->Location = System::Drawing::Point(0, 553);
			this->btnSeller->Name = L"btnSeller";
			this->btnSeller->Size = System::Drawing::Size(330, 50);
			this->btnSeller->TabIndex = 8;
			this->btnSeller->Text = L" Режим продавца";
			this->btnSeller->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->btnSeller->UseVisualStyleBackColor = false;
			this->btnSeller->Click += gcnew System::EventHandler(this, &Mainform::btnSeller_Click);
			// 
			// btnAdmin
			// 
			this->btnAdmin->BackColor = System::Drawing::Color::Transparent;
			this->btnAdmin->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->btnAdmin->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->btnAdmin->FlatAppearance->BorderSize = 0;
			this->btnAdmin->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Teal;
			this->btnAdmin->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnAdmin->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnAdmin->ForeColor = System::Drawing::SystemColors::Control;
			this->btnAdmin->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnAdmin.Image")));
			this->btnAdmin->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnAdmin->Location = System::Drawing::Point(0, 603);
			this->btnAdmin->Name = L"btnAdmin";
			this->btnAdmin->Size = System::Drawing::Size(330, 50);
			this->btnAdmin->TabIndex = 7;
			this->btnAdmin->Text = L" Режим администратора";
			this->btnAdmin->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->btnAdmin->UseVisualStyleBackColor = false;
			this->btnAdmin->Click += gcnew System::EventHandler(this, &Mainform::btnAdmin_Click);
			// 
			// btnCashbox
			// 
			this->btnCashbox->BackColor = System::Drawing::Color::Transparent;
			this->btnCashbox->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->btnCashbox->Dock = System::Windows::Forms::DockStyle::Top;
			this->btnCashbox->FlatAppearance->BorderSize = 0;
			this->btnCashbox->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Teal;
			this->btnCashbox->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnCashbox->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnCashbox->ForeColor = System::Drawing::SystemColors::Control;
			this->btnCashbox->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnCashbox.Image")));
			this->btnCashbox->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnCashbox->Location = System::Drawing::Point(0, 250);
			this->btnCashbox->Name = L"btnCashbox";
			this->btnCashbox->Size = System::Drawing::Size(330, 50);
			this->btnCashbox->TabIndex = 6;
			this->btnCashbox->Text = L" Касса:";
			this->btnCashbox->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->btnCashbox->UseVisualStyleBackColor = false;
			this->btnCashbox->Click += gcnew System::EventHandler(this, &Mainform::btnCashbox_Click);
			// 
			// btnAddCart
			// 
			this->btnAddCart->BackColor = System::Drawing::Color::Transparent;
			this->btnAddCart->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->btnAddCart->Dock = System::Windows::Forms::DockStyle::Top;
			this->btnAddCart->FlatAppearance->BorderSize = 0;
			this->btnAddCart->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Teal;
			this->btnAddCart->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnAddCart->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnAddCart->ForeColor = System::Drawing::SystemColors::Control;
			this->btnAddCart->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnAddCart.Image")));
			this->btnAddCart->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnAddCart->Location = System::Drawing::Point(0, 200);
			this->btnAddCart->Name = L"btnAddCart";
			this->btnAddCart->Size = System::Drawing::Size(330, 50);
			this->btnAddCart->TabIndex = 5;
			this->btnAddCart->Text = L" Добавить чек";
			this->btnAddCart->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->btnAddCart->UseVisualStyleBackColor = false;
			this->btnAddCart->Click += gcnew System::EventHandler(this, &Mainform::btnAddCart_Click);
			// 
			// btnEdit
			// 
			this->btnEdit->BackColor = System::Drawing::Color::Transparent;
			this->btnEdit->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->btnEdit->Dock = System::Windows::Forms::DockStyle::Top;
			this->btnEdit->FlatAppearance->BorderSize = 0;
			this->btnEdit->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Teal;
			this->btnEdit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnEdit->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnEdit->ForeColor = System::Drawing::SystemColors::Control;
			this->btnEdit->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnEdit.Image")));
			this->btnEdit->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnEdit->Location = System::Drawing::Point(0, 150);
			this->btnEdit->Name = L"btnEdit";
			this->btnEdit->Size = System::Drawing::Size(330, 50);
			this->btnEdit->TabIndex = 4;
			this->btnEdit->Text = L" Редактирование данных";
			this->btnEdit->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->btnEdit->UseVisualStyleBackColor = false;
			this->btnEdit->Click += gcnew System::EventHandler(this, &Mainform::btnEdit_Click);
			// 
			// btnList
			// 
			this->btnList->BackColor = System::Drawing::Color::Transparent;
			this->btnList->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->btnList->Dock = System::Windows::Forms::DockStyle::Top;
			this->btnList->FlatAppearance->BorderSize = 0;
			this->btnList->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Teal;
			this->btnList->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnList->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnList->ForeColor = System::Drawing::SystemColors::Control;
			this->btnList->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnList.Image")));
			this->btnList->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnList->Location = System::Drawing::Point(0, 100);
			this->btnList->Name = L"btnList";
			this->btnList->Size = System::Drawing::Size(330, 50);
			this->btnList->TabIndex = 3;
			this->btnList->Text = L" Список продуктов";
			this->btnList->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->btnList->UseVisualStyleBackColor = false;
			this->btnList->Click += gcnew System::EventHandler(this, &Mainform::btnList_Click);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(44)), static_cast<System::Int32>(static_cast<System::Byte>(44)),
				static_cast<System::Int32>(static_cast<System::Byte>(65)));
			this->panel1->Controls->Add(this->lbTime);
			this->panel1->Controls->Add(this->lblName);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(330, 100);
			this->panel1->TabIndex = 0;
			// 
			// lbTime
			// 
			this->lbTime->AutoSize = true;
			this->lbTime->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lbTime->ForeColor = System::Drawing::Color::White;
			this->lbTime->Location = System::Drawing::Point(26, 69);
			this->lbTime->Name = L"lbTime";
			this->lbTime->Size = System::Drawing::Size(59, 23);
			this->lbTime->TabIndex = 3;
			this->lbTime->Text = L"label1";
			// 
			// lblName
			// 
			this->lblName->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lblName->AutoSize = true;
			this->lblName->Font = (gcnew System::Drawing::Font(L"Segoe UI Black", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lblName->ForeColor = System::Drawing::Color::White;
			this->lblName->Location = System::Drawing::Point(23, 31);
			this->lblName->Name = L"lblName";
			this->lblName->Size = System::Drawing::Size(190, 38);
			this->lblName->TabIndex = 1;
			this->lblName->Text = L"ПО Магазин";
			this->lblName->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panelTop
			// 
			this->panelTop->BackColor = System::Drawing::Color::Teal;
			this->panelTop->Controls->Add(this->lblTitle);
			this->panelTop->Dock = System::Windows::Forms::DockStyle::Top;
			this->panelTop->Location = System::Drawing::Point(330, 0);
			this->panelTop->Name = L"panelTop";
			this->panelTop->Size = System::Drawing::Size(852, 100);
			this->panelTop->TabIndex = 1;
			// 
			// lblTitle
			// 
			this->lblTitle->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->lblTitle->AutoSize = true;
			this->lblTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lblTitle->ForeColor = System::Drawing::Color::White;
			this->lblTitle->Location = System::Drawing::Point(320, 31);
			this->lblTitle->Name = L"lblTitle";
			this->lblTitle->Size = System::Drawing::Size(260, 38);
			this->lblTitle->TabIndex = 2;
			this->lblTitle->Text = L"Главная страница";
			this->lblTitle->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panelMain
			// 
			this->panelMain->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(44)), static_cast<System::Int32>(static_cast<System::Byte>(44)),
				static_cast<System::Int32>(static_cast<System::Byte>(65)));
			this->panelMain->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelMain->Location = System::Drawing::Point(330, 100);
			this->panelMain->Name = L"panelMain";
			this->panelMain->Size = System::Drawing::Size(852, 553);
			this->panelMain->TabIndex = 2;
			// 
			// time
			// 
			this->time->Tick += gcnew System::EventHandler(this, &Mainform::time_Tick);
			// 
			// Mainform
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1182, 653);
			this->Controls->Add(this->panelMain);
			this->Controls->Add(this->panelTop);
			this->Controls->Add(this->panelMenu);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MinimumSize = System::Drawing::Size(1200, 700);
			this->Name = L"Mainform";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"ПО \"Магазин\"";
			this->Load += gcnew System::EventHandler(this, &Mainform::Mainform_Load);
			this->panelMenu->ResumeLayout(false);
			this->panelMenu->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panelTop->ResumeLayout(false);
			this->panelTop->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

void OpenChildForm(System::Windows::Forms::Form^ form);
private: System::Void Mainform_Load(System::Object^ sender, System::EventArgs^ e);
private: System::Void btnAdmin_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void btnSeller_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void btnCashbox_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void btnAddCart_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void btnEdit_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void btnList_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void time_Tick(System::Object^ sender, System::EventArgs^ e);
};
}
