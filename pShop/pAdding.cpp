#include "pAdding.h"
#include "Functions.h"
#include "productOther.h"
#include "productExpiration.h"
#include "prodExpValue.h"
#include "prodExpWeight.h"
#include <fstream>
#include <iostream>

using namespace std;
using namespace System::Windows::Forms;

prodExpWeight prodEW;
prodExpValue prodEV;
productOther prodO;

System::Void pShop::pAdding::pAdding_Load(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}

System::Void pShop::pAdding::btnAddConfirm_Click(System::Object^ sender, System::EventArgs^ e)
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
	if(tbExpDate->Enabled)
		if (!tbExpDate->MaskCompleted) {
			MessageBox::Show("������� �� ��� ������!", "��������!");
			tbExpDate->Text = "";
			return;
		}
	//������������� ���������� ������
	string buff;
	System::Windows::Forms::DialogResult result =
		MessageBox::Show("��������� ���������?", "��������!", MessageBoxButtons::OKCancel);
	if (result == System::Windows::Forms::DialogResult::OK) {
		//�������� �� ��� ������
		if (cbType->SelectedItem->ToString() == "�����/������") {
			//������ ������ � �����
			Convert_String_to_string(tbName->Text, buff);
			prodEW.setProductName(buff);
			Convert_String_to_string(cbType->Text, buff);
			prodEW.setProductType(buff);
			prodEW.setProductCost(Convert::ToDouble(nudCost->Value));
			Convert_String_to_string(tbExpDate->Text, buff);
			prodEW.setProductExp(buff);
			prodEW.setProdExpWeight(Convert::ToDouble(nudWeight->Value));
			//�������� �����
			ofstream file("datafiles/productExpiration.txt", ios::app);
			if (file.is_open());
			else {
				MessageBox::Show("�� ������� ������� ����..", "������!");
				return System::Void();
			}
			//������ ������ �� ������ � ����
			file << prodEW.getProductName() << endl << prodEW.getProductType() << endl <<
				prodEW.getProductCost() << endl << prodEW.getProductExp() << endl << prodEW.getProdExpWeight() << endl;
			file.close();
		}
		else if (cbType->SelectedItem->ToString() == "������������� ������" || 
			cbType->SelectedItem->ToString() == "������� ������") {
			//������ ������ � �����
			Convert_String_to_string(tbName->Text, buff);
			prodO.setProductName(buff);
			Convert_String_to_string(cbType->Text, buff);
			prodO.setProductType(buff);
			prodO.setProductCost(Convert::ToDouble(nudCost->Value));
			prodO.setProdValue(Convert::ToInt32(nudValue->Value));
			//�������� �����
			ofstream file("datafiles/productOther.txt", ios::app);
			if (file.is_open());
			else {
				MessageBox::Show("�� ������� ������� ����..", "������!");
				return System::Void();
			}
			//������ ������ �� ������ � ����
			file << prodO.getProductName() << endl << prodO.getProductType() << endl <<
				prodO.getProductCost() << endl << prodO.getProdValue() << endl;
			file.close();
		}
		else if (cbType->SelectedItem->ToString() == "�����" || 
			cbType->SelectedItem->ToString() == "�������������" ||
			cbType->SelectedItem->ToString() == "�������") {
			//������ ������ � �����
			Convert_String_to_string(tbName->Text, buff);
			prodEV.setProductName(buff);
			Convert_String_to_string(cbType->Text, buff);
			prodEV.setProductType(buff);
			prodEV.setProductCost(Convert::ToDouble(nudCost->Value));
			Convert_String_to_string(tbExpDate->Text, buff);
			prodEV.setProductExp(buff);
			prodEV.setProdExpValue(Convert::ToInt32(nudValue->Value));
			//�������� �����
			ofstream file("datafiles/productExpiration.txt", ios::app);
			if (file.is_open());
			else {
				MessageBox::Show("�� ������� ������� ����..", "������!");
				return System::Void();
			}
			//������ ������ �� ������ � ����
			file << prodEV.getProductName() << endl << prodEV.getProductType() << endl <<
				prodEV.getProductCost() << endl << prodEV.getProductExp() << endl << prodEV.getProdExpValue() << endl;
			file.close();
		}
		MessageBox::Show("��������� ���������!", "����������");
		this->Close();
	}
}

System::Void pShop::pAdding::cbType_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
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

