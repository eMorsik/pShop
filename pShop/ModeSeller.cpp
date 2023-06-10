#include "ModeSeller.h"
#include "ModeAdmin.h"
#include <string.h>
#include "Mainform.h"
#include "Functions.h"

using namespace System::Windows::Forms;

//проверка входа в режим админа
bool checkSeller(std::string login, std::string password) {
	std::string log = "seller", pass = "seller";
	if (login == log && pass == password) {
		return true;
	}
	else {
		return false;
	}
}

System::Void pShop::ModeSeller::ModeSeller_Load(System::Object^ sender, System::EventArgs^ e)
{
	if (smod) {
		btnLogin->Enabled = false;
		btnLogin->Visible = false;
		tbLogin->Enabled = false;
		tbPass->Enabled = false;
		lblAdmOn->Visible = true;
		btnExit->Visible = true;
		btnExit->Enabled = true;
	}
	return System::Void();
}

System::Void pShop::ModeSeller::tbLogin_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
    return System::Void();
}

System::Void pShop::ModeSeller::tbPass_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
    return System::Void();
}

System::Void pShop::ModeSeller::btnLogin_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (pShop::ModeAdmin::amod) {
		MessageBox::Show("Вы уже в режиме админа, необходимо выйти!", "Внимание!");
		return;
	}
	std::string login, pass;
	if (String::IsNullOrWhiteSpace(tbLogin->Text)) {
		MessageBox::Show("Неверные имя пользователя или пароль!", "Внимание!");
		return;
	}
	if (String::IsNullOrWhiteSpace(tbPass->Text)) {
		MessageBox::Show("Неверные имя пользователя или пароль!", "Внимание!");
		return;
	}
	Convert_String_to_string(tbLogin->Text, login);
	Convert_String_to_string(tbPass->Text, pass);
	smod = checkSeller(login, pass);
	if (!smod)
		MessageBox::Show("Неверные имя пользователя или пароль!", "Внимание!");
	if (smod) {
		btnLogin->Enabled = false;
		btnLogin->Visible = false;
		tbLogin->Enabled = false;
		tbPass->Enabled = false;
		lblAdmOn->Visible = true;
		btnExit->Visible = true;
		btnExit->Enabled = true;
	}
	return System::Void();
}

System::Void pShop::ModeSeller::btnExit_Click(System::Object^ sender, System::EventArgs^ e)
{
	btnLogin->Enabled = true;
	btnLogin->Visible = true;
	tbLogin->Enabled = true;
	tbPass->Enabled = true;
	lblAdmOn->Visible = false;
	btnExit->Visible = false;
	btnExit->Enabled = false;
	tbLogin->Text = "";
	tbPass->Text = "";
	smod = false;
	return System::Void();
}
