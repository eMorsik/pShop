#pragma once

namespace pShop {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для ModeAdmin
	/// </summary>
	public ref class ModeAdmin : public System::Windows::Forms::Form
	{
	//public: static bool amod = false;
	public: static bool amod = true;
	public:
		ModeAdmin(void)
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
		~ModeAdmin()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	protected:
	private: System::Windows::Forms::Button^ btnExit;
	private: System::Windows::Forms::Button^ btnLogin;
	private: System::Windows::Forms::Label^ lblAdmOn;

	private: System::Windows::Forms::Label^ lbPass;
	private: System::Windows::Forms::Label^ lbLogin;
	private: System::Windows::Forms::TextBox^ tbPass;
	private: System::Windows::Forms::TextBox^ tbLogin;
	private: System::Windows::Forms::PictureBox^ pbSeller;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ModeAdmin::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->pbSeller = (gcnew System::Windows::Forms::PictureBox());
			this->btnExit = (gcnew System::Windows::Forms::Button());
			this->btnLogin = (gcnew System::Windows::Forms::Button());
			this->lblAdmOn = (gcnew System::Windows::Forms::Label());
			this->lbPass = (gcnew System::Windows::Forms::Label());
			this->lbLogin = (gcnew System::Windows::Forms::Label());
			this->tbPass = (gcnew System::Windows::Forms::TextBox());
			this->tbLogin = (gcnew System::Windows::Forms::TextBox());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbSeller))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom));
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->panel1->Controls->Add(this->pbSeller);
			this->panel1->Controls->Add(this->btnExit);
			this->panel1->Controls->Add(this->btnLogin);
			this->panel1->Controls->Add(this->lblAdmOn);
			this->panel1->Controls->Add(this->lbPass);
			this->panel1->Controls->Add(this->lbLogin);
			this->panel1->Controls->Add(this->tbPass);
			this->panel1->Controls->Add(this->tbLogin);
			this->panel1->Location = System::Drawing::Point(178, 77);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(460, 317);
			this->panel1->TabIndex = 1;
			// 
			// pbSeller
			// 
			this->pbSeller->ImageLocation = L"C:\\Users\\MorDg\\source\\repos\\pShop\\images\\admin.png";
			this->pbSeller->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbSeller.InitialImage")));
			this->pbSeller->Location = System::Drawing::Point(212, 42);
			this->pbSeller->Name = L"pbSeller";
			this->pbSeller->Size = System::Drawing::Size(30, 30);
			this->pbSeller->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pbSeller->TabIndex = 7;
			this->pbSeller->TabStop = false;
			// 
			// btnExit
			// 
			this->btnExit->BackColor = System::Drawing::Color::Teal;
			this->btnExit->Enabled = false;
			this->btnExit->FlatAppearance->BorderSize = 0;
			this->btnExit->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
			this->btnExit->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightSeaGreen;
			this->btnExit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnExit->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnExit->ForeColor = System::Drawing::Color::White;
			this->btnExit->Location = System::Drawing::Point(171, 216);
			this->btnExit->Name = L"btnExit";
			this->btnExit->Size = System::Drawing::Size(123, 38);
			this->btnExit->TabIndex = 1;
			this->btnExit->Text = L"Выйти";
			this->btnExit->UseVisualStyleBackColor = false;
			this->btnExit->Visible = false;
			this->btnExit->Click += gcnew System::EventHandler(this, &ModeAdmin::btnExit_Click);
			// 
			// btnLogin
			// 
			this->btnLogin->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->btnLogin->BackColor = System::Drawing::Color::Teal;
			this->btnLogin->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->btnLogin->FlatAppearance->BorderSize = 0;
			this->btnLogin->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Gainsboro;
			this->btnLogin->FlatAppearance->MouseOverBackColor = System::Drawing::Color::LightSeaGreen;
			this->btnLogin->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnLogin->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnLogin->ForeColor = System::Drawing::Color::White;
			this->btnLogin->Location = System::Drawing::Point(171, 216);
			this->btnLogin->Name = L"btnLogin";
			this->btnLogin->Size = System::Drawing::Size(123, 38);
			this->btnLogin->TabIndex = 5;
			this->btnLogin->Text = L"Войти";
			this->btnLogin->UseVisualStyleBackColor = false;
			this->btnLogin->Click += gcnew System::EventHandler(this, &ModeAdmin::btnLogin_Click);
			// 
			// lblAdmOn
			// 
			this->lblAdmOn->AutoSize = true;
			this->lblAdmOn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lblAdmOn->ForeColor = System::Drawing::Color::White;
			this->lblAdmOn->Location = System::Drawing::Point(147, 267);
			this->lblAdmOn->Name = L"lblAdmOn";
			this->lblAdmOn->Size = System::Drawing::Size(164, 20);
			this->lblAdmOn->TabIndex = 0;
			this->lblAdmOn->Text = L"Вы авторизованы!";
			this->lblAdmOn->Visible = false;
			// 
			// lbPass
			// 
			this->lbPass->AutoSize = true;
			this->lbPass->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lbPass->ForeColor = System::Drawing::Color::White;
			this->lbPass->Location = System::Drawing::Point(193, 149);
			this->lbPass->Name = L"lbPass";
			this->lbPass->Size = System::Drawing::Size(77, 20);
			this->lbPass->TabIndex = 3;
			this->lbPass->Text = L"Пароль:";
			// 
			// lbLogin
			// 
			this->lbLogin->AutoSize = true;
			this->lbLogin->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lbLogin->ForeColor = System::Drawing::Color::White;
			this->lbLogin->Location = System::Drawing::Point(200, 86);
			this->lbLogin->Name = L"lbLogin";
			this->lbLogin->Size = System::Drawing::Size(64, 20);
			this->lbLogin->TabIndex = 2;
			this->lbLogin->Text = L"Логин:";
			// 
			// tbPass
			// 
			this->tbPass->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tbPass->Location = System::Drawing::Point(140, 172);
			this->tbPass->Name = L"tbPass";
			this->tbPass->PasswordChar = '*';
			this->tbPass->Size = System::Drawing::Size(180, 27);
			this->tbPass->TabIndex = 1;
			this->tbPass->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tbPass->TextChanged += gcnew System::EventHandler(this, &ModeAdmin::tbPass_TextChanged);
			// 
			// tbLogin
			// 
			this->tbLogin->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tbLogin->Location = System::Drawing::Point(140, 109);
			this->tbLogin->Name = L"tbLogin";
			this->tbLogin->Size = System::Drawing::Size(180, 27);
			this->tbLogin->TabIndex = 0;
			this->tbLogin->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tbLogin->TextChanged += gcnew System::EventHandler(this, &ModeAdmin::tbLogin_TextChanged);
			// 
			// ModeAdmin
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(44)), static_cast<System::Int32>(static_cast<System::Byte>(44)),
				static_cast<System::Int32>(static_cast<System::Byte>(65)));
			this->ClientSize = System::Drawing::Size(841, 506);
			this->Controls->Add(this->panel1);
			this->MinimumSize = System::Drawing::Size(859, 553);
			this->Name = L"ModeAdmin";
			this->Text = L"ModeAdmin";
			this->Load += gcnew System::EventHandler(this, &ModeAdmin::ModeAdmin_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbSeller))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void ModeAdmin_Load(System::Object^ sender, System::EventArgs^ e);
private: System::Void tbLogin_TextChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void tbPass_TextChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void btnLogin_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void btnExit_Click(System::Object^ sender, System::EventArgs^ e);
};
}
