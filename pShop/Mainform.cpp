#include "Mainform.h"
#include "ModeAdmin.h"
#include "ModeSeller.h"
#include "pList.h"
#include "pEdit.h"
#include "pAddCart.h"
#include <fstream>
#include <string>

using namespace System;
using namespace System::Windows::Forms;


[STAThreadAttribute]
void main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	pShop::Mainform form;
	Application::Run(% form);
}

void pShop::Mainform::OpenChildForm(System::Windows::Forms::Form^ form)
{
	form->TopLevel = false;
	form->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
	form->Dock = DockStyle::Fill;
	this->panelMain->Controls->Add(form);
	this->panelMain->Tag = form;
	form->BringToFront();
	form->Show();
}
System::Void pShop::Mainform::Mainform_Load(System::Object^ sender, System::EventArgs^ e)
{
	time->Start();
	lblTitle->Text = "����� ��������";
	ModeSeller^ form = gcnew ModeSeller();
	OpenChildForm(form);
}

System::Void pShop::Mainform::btnAdmin_Click(System::Object^ sender, System::EventArgs^ e)
{
	lblTitle->Text = "����� ������";
	ModeAdmin^ form = gcnew ModeAdmin();
	OpenChildForm(form);
}

System::Void pShop::Mainform::btnSeller_Click(System::Object^ sender, System::EventArgs^ e)
{
	lblTitle->Text = "����� ��������";
	ModeSeller^ form = gcnew ModeSeller();
	OpenChildForm(form);
}

System::Void pShop::Mainform::btnCashbox_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (!pShop::ModeSeller::smod && !pShop::ModeAdmin::amod) {
		MessageBox::Show("� ��� ��� ������� � �������!", "��������!");
		return;
	}
	//�������� ������� �����
	if (!isopen) {
		System::Windows::Forms::DialogResult result =
			MessageBox::Show("������� ������� �����?", "��������!", MessageBoxButtons::OKCancel);
		if (result != System::Windows::Forms::DialogResult::OK) {
			return;
		}
		else {
			pShop::Mainform::Cashbox = NULL;
			isopen = true;
			lbCashbox->Visible = true;
			MessageBox::Show("     ����� �������!     ", "��������!");
		}
	}
	else {
		System::Windows::Forms::DialogResult result =
			MessageBox::Show("������� �����?", "��������!", MessageBoxButtons::OKCancel);
		if (result != System::Windows::Forms::DialogResult::OK) {
			return;
		}
		else {
			isopen = false;
			lbCashbox->Visible = false;
			lblTitle->Text = "����� ��������";
			ModeSeller^ form = gcnew ModeSeller();
			OpenChildForm(form);
			MessageBox::Show("     ����� �������!     ", "��������!");
		}
	}
}

System::Void pShop::Mainform::btnAddCart_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (!pShop::ModeSeller::smod && !pShop::ModeAdmin::amod) {
		MessageBox::Show("� ��� ��� ������� � �������!", "��������!");
		return;
	}
	if (isopen) {
		lblTitle->Text = "���������� ����";
		pAddCart^ form = gcnew pAddCart();
		OpenChildForm(form);
	}
	else MessageBox::Show("����� �������, ���������� �������� ���!", "��������!");
}

System::Void pShop::Mainform::btnEdit_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (!pShop::ModeAdmin::amod) {
		MessageBox::Show("� ��� ��� ������� � �������!", "��������!");
		return;
	}
	lblTitle->Text = "�������������� ������";
	pEdit^ form = gcnew pEdit();
	OpenChildForm(form);
}

System::Void pShop::Mainform::btnList_Click(System::Object^ sender, System::EventArgs^ e)
{
	lblTitle->Text = "������ ���������";
	pList^ form = gcnew pList();
	OpenChildForm(form);
}

System::Void pShop::Mainform::time_Tick(System::Object^ sender, System::EventArgs^ e)
{
	DateTime dtTmp = DateTime::Now;
	lbTime->Text = dtTmp.ToString("dd/MM/yy, hh:mm:ss tt");
	lbCashbox->Text = Convert::ToString(Cashbox) + "�";
}