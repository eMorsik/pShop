#include "pEditing.h"
#include "Functions.h"
#include "pEdit.h"
#include <iostream>

using namespace std;
using namespace System::Windows::Forms;

System::Void pShop::pEditing::pEditing_Load(System::Object^ sender, System::EventArgs^ e)
{
	pShop::pEdit::backup = true;
    return System::Void();
}

System::Void pShop::pEditing::btnEditConfirm_Click(System::Object^ sender, System::EventArgs^ e)
{
	/*�������� �� ������ ������*/
	if (String::IsNullOrWhiteSpace(tbName->Text)) {
		MessageBox::Show("������� �� ��� ������!", "��������!");
		return;
	}
	if (String::IsNullOrWhiteSpace(cbType->Text)) {
		MessageBox::Show("������� �� ��� ������!", "��������!");
		return;
	}
	if (String::IsNullOrWhiteSpace(nudCost->Text)) {
		MessageBox::Show("������� �� ��� ������!", "��������!");
		return;
	}
	if (tbExpDate->Enabled)
		if (!tbExpDate->MaskCompleted) {
			MessageBox::Show("������� �� ��� ������!", "��������!");
			tbExpDate->Text = "";
			return;
		}
	//������������� ���������� ���������
	System::Windows::Forms::DialogResult result =
		MessageBox::Show("��������� ���������?", "��������!", MessageBoxButtons::OKCancel);
	if (result == System::Windows::Forms::DialogResult::OK) {
		pShop::pEdit::backup = false;
		MessageBox::Show("��������� ���������!", "����������");
		this->Close();
	}
	return System::Void();
}

System::Void pShop::pEditing::pEditing_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
{
	return System::Void();
}

System::Void pShop::pEditing::cbType_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{
	tbExpDate->Enabled = false;
	nudValue->Enabled = false;
	nudWeight->Enabled = false;
	if (cbType->SelectedItem->ToString() == "�����/������") {
		tbExpDate->Enabled = true;
		nudWeight->Enabled = true;
	}
	else if (cbType->SelectedItem->ToString() == "������������� ������" ||
		cbType->SelectedItem->ToString() == "������� ������") {
		nudValue->Enabled = true;
	}
	else if (cbType->SelectedItem->ToString() == "�����" ||
		cbType->SelectedItem->ToString() == "�������������" ||
		cbType->SelectedItem->ToString() == "�������") {
		tbExpDate->Enabled = true;
		nudValue->Enabled = true;
	}
	return System::Void();
}
