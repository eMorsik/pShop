#include "ModeAdmin.h"
#include "ModeSeller.h"
#include <string.h>
#include "Mainform.h"
#include "Functions.h"

using namespace System::Windows::Forms;

//проверка входа в режим админа
bool checkAdmin(std::string login, std::string password) {
    std::string log = "admin", pass = "admin";
    if (login == log && pass == password) {
        return true;
    }
    else {
        return false;
    }
}

System::Void pShop::ModeAdmin::ModeAdmin_Load(System::Object^ sender, System::EventArgs^ e)
{
    if (amod) {
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

System::Void pShop::ModeAdmin::tbLogin_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
    return System::Void();
}

System::Void pShop::ModeAdmin::tbPass_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
    return System::Void();
}

System::Void pShop::ModeAdmin::btnLogin_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (pShop::ModeSeller::smod) {
        MessageBox::Show("Вы уже в режиме продавца, необходимо выйти!", "Внимание!");
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
    amod = checkAdmin(login, pass);
    if (!amod)
        MessageBox::Show("Неверные имя пользователя или пароль!", "Внимание!");
    if (amod) {
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

System::Void pShop::ModeAdmin::btnExit_Click(System::Object^ sender, System::EventArgs^ e)
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
    amod = false;
    return System::Void();
}
