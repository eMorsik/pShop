#include "pAddCart.h"
#include "Mainform.h"
#include "Functions.h"
#include "productOther.h"
#include "productExpiration.h"
#include "prodExpValue.h"
#include "prodExpWeight.h"
#include <fstream>
#include <string>
#include "pAddingCart.h"
using namespace std;
using namespace System::Windows::Forms;

prodExpWeight* prodE2 = new prodExpWeight[100];
prodExpValue* prodEV1 = new prodExpValue[100];
productOther* prodO2 = new productOther[100];

int pcountAll = 0; //���-�� ��������� ��
int pcountCart = 0; //���-�� ��������� � �������
float CashCart = 0; //��������� ������� � �������

System::Void pShop::pAddCart::pAddCart_Load(System::Object^ sender, System::EventArgs^ e)
{
    /*����� DataGridView*/
    dataGridView_LoadAll();
	pcountCart = 0;
	float CashCart = 0;
	return System::Void();
}

/*����� DataGridView* ���� �� */
System::Void pShop::pAddCart::HeaderAll()
{
	DataGridViewTextBoxColumn^ c1 = gcnew DataGridViewTextBoxColumn();
	c1->Name = "name";
	c1->HeaderText = "������������ ������";
	c1->DefaultCellStyle->ForeColor = Color::Black;
	dataGridView1->Columns->Add(c1);

	DataGridViewTextBoxColumn^ c2 = gcnew DataGridViewTextBoxColumn();
	c2->Name = "type";
	c2->HeaderText = "��� ������";
	c2->DefaultCellStyle->ForeColor = Color::Black;
	dataGridView1->Columns->Add(c2);

	DataGridViewTextBoxColumn^ c3 = gcnew DataGridViewTextBoxColumn();
	c3->Name = "cost";
	c3->HeaderText = "��������� ������";
	c3->DefaultCellStyle->ForeColor = Color::Black;
	dataGridView1->Columns->Add(c3);

	DataGridViewTextBoxColumn^ c4 = gcnew DataGridViewTextBoxColumn();
	c4->Name = "expdate";
	c4->HeaderText = "���� ��������";
	c4->DefaultCellStyle->ForeColor = Color::Black;
	dataGridView1->Columns->Add(c4);

	DataGridViewTextBoxColumn^ c5 = gcnew DataGridViewTextBoxColumn();
	c5->Name = "value";
	c5->HeaderText = "���-�� ������(��/��)";
	c5->DefaultCellStyle->ForeColor = Color::Black;
	dataGridView1->Columns->Add(c5);
}

/*����� ���� �� � DataGridView*/
void pShop::pAddCart::ShowAll()
{
	int i;
	for (i = 0; i < CounterExp(); i++) {
		dataGridView1->Rows[i]->HeaderCell->Value = Convert::ToString(i + 1);
		dataGridView1->Rows[i]->Cells[0]->Value = Convert_string_to_String(prodE2[i].getProductName());
		dataGridView1->Rows[i]->Cells[1]->Value = Convert_string_to_String(prodE2[i].getProductType());
		dataGridView1->Rows[i]->Cells[2]->Value = prodE2[i].getProductCost();
		dataGridView1->Rows[i]->Cells[3]->Value = Convert_string_to_String(prodE2[i].getProductExp());
		dataGridView1->Rows[i]->Cells[4]->Value = Convert::ToDecimal(prodE2[i].getProdExpWeight());
	}
	for (int j = 0; j < CounterOther(); j++) {
		dataGridView1->Rows[j + i]->HeaderCell->Value = Convert::ToString(j + i + 1);
		dataGridView1->Rows[j + i]->Cells[0]->Value = Convert_string_to_String(prodO2[j].getProductName());
		dataGridView1->Rows[j + i]->Cells[1]->Value = Convert_string_to_String(prodO2[j].getProductType());
		dataGridView1->Rows[j + i]->Cells[2]->Value = prodO2[j].getProductCost();
		dataGridView1->Rows[j + i]->Cells[3]->Value = "--.--.----";
		dataGridView1->Rows[j + i]->Cells[4]->Value = Convert::ToDecimal(prodO2[j].getProdValue());
	}
}

/*���������� �� � ������ ��������*/
void pShop::pAddCart::DataReaderAll()
{
	string sbuff;
	float fbuff;
	if (pcountAll > 0) {
		/*���� productExpiration.txt*/
		int n = CounterExp();
		ifstream file("datafiles/productExpiration.txt");
		if (file.is_open());
		else {
			MessageBox::Show("�� ������� ������� ����..", "������!");
			return;
		}
		//���������� ��������� �� �� ����� � ������
		if (n > 0) {
			file.seekg(0);
			for (int i = 0; i < n; i++) {
				getline(file, sbuff);
				prodE2[i].setProductName(sbuff);
				getline(file, sbuff);
				prodE2[i].setProductType(sbuff);
				file >> fbuff;
				prodE2[i].setProductCost(fbuff);
				file >> sbuff;
				prodE2[i].setProductExp(sbuff);
				file >> fbuff;
				prodE2[i].setProdExpWeight(fbuff);
				getline(file, sbuff);
			}
		}
		file.close();
		/*���� productOther.txt*/
		n = CounterOther();
		ifstream file1("datafiles/productOther.txt");
		if (file1.is_open());
		else {
			MessageBox::Show("�� ������� ������� ����..", "������!");
			return;
		}
		//���������� ��������� �� �� ����� � ������
		if (n > 0) {
			file1.seekg(0);
			for (int i = 0; i < n; i++) {
				getline(file1, sbuff);
				prodO2[i].setProductName(sbuff);
				getline(file1, sbuff);
				prodO2[i].setProductType(sbuff);
				file1 >> fbuff;
				prodO2[i].setProductCost(fbuff);
				file1 >> fbuff;
				prodO2[i].setProdValue(fbuff);
				getline(file1, sbuff);
			}
		}
		file1.close();
	}
	else MessageBox::Show("����������� � ���� ������ �� �������...", "��������!");
	return;
}

/*�������� DataGridView ���� ��*/
System::Void pShop::pAddCart::dataGridView_LoadAll()
{
	// ������� �����
	dataGridView1->Rows->Clear();
	dataGridView1->Columns->Clear();
	// �����
	HeaderAll();
	pcountAll = Counter();
	DataReaderAll();
	if (pcountAll > 0) {
		panelAddCart->Enabled = true;
	}
	nudAddCart->Maximum = pcountAll;
	// ������ �������
	dataGridView1->RowCount = pcountAll + 1;
	dataGridView1->ColumnCount = 5;
	for (int i = 0; i < dataGridView1->RowCount; i++) {
		dataGridView1->Rows[i]->ReadOnly = true;
	}
	//����� �������
	ShowAll();
	return System::Void();
}

/*����� DataGridView* �������*/
void pShop::pAddCart::HeaderCart()
{
	DataGridViewTextBoxColumn^ c1 = gcnew DataGridViewTextBoxColumn();
	c1->Name = "name";
	c1->HeaderText = "������������ ������";
	c1->DefaultCellStyle->ForeColor = Color::Black;
	dataGridView2->Columns->Add(c1);

	DataGridViewTextBoxColumn^ c2 = gcnew DataGridViewTextBoxColumn();
	c2->Name = "type";
	c2->HeaderText = "��� ������";
	c2->DefaultCellStyle->ForeColor = Color::Black;
	dataGridView2->Columns->Add(c2);

	DataGridViewTextBoxColumn^ c3 = gcnew DataGridViewTextBoxColumn();
	c3->Name = "cost";
	c3->HeaderText = "��������� ������";
	c3->DefaultCellStyle->ForeColor = Color::Black;
	dataGridView2->Columns->Add(c3);

	DataGridViewTextBoxColumn^ c4 = gcnew DataGridViewTextBoxColumn();
	c4->Name = "expdate";
	c4->HeaderText = "���� ��������";
	c4->DefaultCellStyle->ForeColor = Color::Black;
	dataGridView2->Columns->Add(c4);

	DataGridViewTextBoxColumn^ c5 = gcnew DataGridViewTextBoxColumn();
	c5->Name = "value";
	c5->HeaderText = "���-�� ������(��/��)";
	c5->DefaultCellStyle->ForeColor = Color::Black;
	dataGridView2->Columns->Add(c5);
}

/*����� ������� � DataGridView*/
void pShop::pAddCart::ShowCart()
{
	for (int i = 0; i < pcountCart; i++) {
		dataGridView2->Rows[i]->HeaderCell->Value = Convert::ToString(i + 1);
		dataGridView2->Rows[i]->Cells[0]->Value = Convert_string_to_String(prodE2[i].getProductName());
		dataGridView2->Rows[i]->Cells[1]->Value = Convert_string_to_String(prodE2[i].getProductType());
		dataGridView2->Rows[i]->Cells[2]->Value = prodE2[i].getProductCost();
		dataGridView2->Rows[i]->Cells[3]->Value = Convert_string_to_String(prodE2[i].getProductExp());
		dataGridView2->Rows[i]->Cells[4]->Value = Convert::ToDecimal(prodE2[i].getProdExpWeight());
	}
}

/*���������� ������� � ������ ��������*/
void pShop::pAddCart::DataReaderCart()
{
    throw gcnew System::NotImplementedException();
}

/*�������� DataGridView �������*/
void pShop::pAddCart::dataGridView_LoadCart()
{
	// ������� �����
	dataGridView2->Rows->Clear();
	dataGridView2->Columns->Clear();
	// �����
	HeaderCart();
	if (pcountCart > 0) {
		panelDeleteCart->Enabled = true;
		btnConfirm->Enabled = true;
		panelCash->Enabled = true;
		nudDeleteCart->Minimum = 1;
	}
	else {
		panelDeleteCart->Enabled = false;
		btnConfirm->Enabled = false;
		panelCash->Enabled = false;
	}
	nudDeleteCart->Maximum = pcountCart;
	//������ �������
	dataGridView2->RowCount = pcountCart + 1;
	dataGridView2->ColumnCount = 5;
	for (int i = 0; i < dataGridView2->RowCount; i++) {
		dataGridView2->Rows[i]->ReadOnly = true;
	}
	//����� �������
	ShowCart();
	return System::Void();
}

System::Void pShop::pAddCart::btnAddCart_Click(System::Object^ sender, System::EventArgs^ e)
{
	ConfirmAdd = false;
	pAddingCart^ form = gcnew pAddingCart();
	int addnum = Convert::ToInt32(nudAddCart->Value);
	int addnum1 = addnum - 1;
	for (int i = 0; i < pcountAll; i++)
		if (addnum == Convert::ToInt32(dataGridView1->Rows[i]->HeaderCell->Value)) {
			addnum = i;
			break;
		}
	if (Convert::ToDouble(dataGridView1->Rows[addnum]->Cells[4]->Value) == 0) {
		MessageBox::Show("���������� �������� � �������! ����� ����������!", "��������!");
		return;
	}
	/*�������� ������ ����������� �������� � ����� ��� ��������������*/
	if (Convert::ToString(dataGridView1->Rows[addnum]->Cells[1]->Value) == "�����/������") {
		form->tbName->Text = Convert::ToString(dataGridView1->Rows[addnum]->Cells[0]->Value);
		form->nudCost->Value = Convert::ToDecimal(dataGridView1->Rows[addnum]->Cells[2]->Value);
		form->nudWeight->Maximum = Convert::ToDecimal(dataGridView1->Rows[addnum]->Cells[4]->Value);
		form->nudWeight->Enabled = true;
	}
	else if (Convert::ToString(dataGridView1->Rows[addnum]->Cells[1]->Value) == "������������� ������" ||
		Convert::ToString(dataGridView1->Rows[addnum]->Cells[1]->Value) == "������� ������") {
		form->tbName->Text = Convert::ToString(dataGridView1->Rows[addnum]->Cells[0]->Value);
		form->nudCost->Value = Convert::ToDecimal(dataGridView1->Rows[addnum]->Cells[2]->Value);
		form->nudValue->Maximum = Convert::ToDecimal(dataGridView1->Rows[addnum]->Cells[4]->Value);
		form->nudValue->Enabled = true;
	}
	else if (Convert::ToString(dataGridView1->Rows[addnum]->Cells[1]->Value) == "�����" ||
		Convert::ToString(dataGridView1->Rows[addnum]->Cells[1]->Value) == "�������������" ||
		Convert::ToString(dataGridView1->Rows[addnum]->Cells[1]->Value) == "�������") {
		form->tbName->Text = Convert::ToString(dataGridView1->Rows[addnum]->Cells[0]->Value);
		form->nudCost->Value = Convert::ToDecimal(dataGridView1->Rows[addnum]->Cells[2]->Value);
		form->nudValue->Maximum = Convert::ToDecimal(dataGridView1->Rows[addnum]->Cells[4]->Value);
		form->nudValue->Enabled = true;
	}
	/*�������� ����� ��������������*/
	form->ShowDialog(this);
	string buff;
	if (ConfirmAdd) {
		//������ ������ �� dataGridView � �����
		Convert_String_to_string(dataGridView1->Rows[addnum]->Cells[0]->Value->ToString(), buff);
		prodE2[pcountCart].setProductName(buff);
		Convert_String_to_string(dataGridView1->Rows[addnum]->Cells[1]->Value->ToString(), buff);
		prodE2[pcountCart].setProductType(buff);
		prodE2[pcountCart].setProductCost(Convert::ToDouble(form->nudCost->Value));
		Convert_String_to_string(dataGridView1->Rows[addnum]->Cells[3]->Value->ToString(), buff);
		prodE2[pcountCart].setProductExp(buff);
		if (Convert::ToString(dataGridView1->Rows[addnum]->Cells[1]->Value) == "�����/������")
			prodE2[pcountCart].setProdExpWeight(Convert::ToDouble(form->nudWeight->Value));
		else prodE2[pcountCart].setProdExpWeight(Convert::ToDouble(form->nudValue->Value));
		pcountCart++;
		dataGridView_LoadCart();
		if (Convert::ToString(dataGridView1->Rows[addnum]->Cells[1]->Value) == "�����/������") {
			dataGridView1->Rows[addnum]->Cells[4]->Value = 
				Decimal::operator-(Convert::ToDecimal(dataGridView1->Rows[addnum]->Cells[4]->Value), form->nudWeight->Value);
		}
		else {
			dataGridView1->Rows[addnum]->Cells[4]->Value =
				Decimal::operator-(Convert::ToDecimal(dataGridView1->Rows[addnum]->Cells[4]->Value), form->nudValue->Value);
		}
		CashCart += Convert::ToDouble(form->nudCost->Value);
		lbCashCart->Text = Convert::ToString(CashCart) + "�";
	}
}

System::Void pShop::pAddCart::btnDeleteCart_Click(System::Object^ sender, System::EventArgs^ e)
{
	int delnum = Convert::ToInt32(nudDeleteCart->Value);
	for (int i = 0; i <= pcountCart; i++)
		if (delnum == Convert::ToInt32(dataGridView2->Rows[i]->HeaderCell->Value)) {
			delnum = i;
			break;
		}
	//������������� �������� �� �������
	System::Windows::Forms::DialogResult result =
		MessageBox::Show("������� ����� �� �������?", "��������!", MessageBoxButtons::OKCancel);
	if (result == System::Windows::Forms::DialogResult::OK) {
		CashCart = CashCart - Convert::ToDouble(dataGridView2->Rows[delnum]->Cells[2]->Value);
		lbCashCart->Text = Convert::ToString(CashCart) + "�";
		for (int i = 0; i < pcountAll; i++) {
			if (Convert::ToString(dataGridView1->Rows[i]->Cells[0]->Value) == 
				Convert::ToString(dataGridView2->Rows[delnum]->Cells[0]->Value)) {
				dataGridView1->Rows[i]->Cells[4]->Value = Decimal::operator+(Convert::ToDecimal(dataGridView1->Rows[i]->Cells[4]->Value),
					Convert::ToDecimal(dataGridView2->Rows[delnum]->Cells[4]->Value));
				pcountCart--;
				if (pcountCart != 0) {
					dataGridView2->Rows->RemoveAt(delnum);
					dataGridView2->Refresh();
					nudDeleteCart->Maximum--;
					for (int i = delnum; i < pcountCart; i++) {
						dataGridView2->Rows[i]->HeaderCell->Value = Convert::ToString(i + 1);
					}
				}
				else {
					CashCart = 0;
					lbCashCart->Text = "0�";
					dataGridView_LoadCart();
				}
				break;
			}
		}
	}
	return System::Void();
}

System::Void pShop::pAddCart::btnConfirm_Click(System::Object^ sender, System::EventArgs^ e) {
	System::Windows::Forms::DialogResult result =
		MessageBox::Show("����������� �������?", "��������!", MessageBoxButtons::OKCancel);
	if (result == System::Windows::Forms::DialogResult::OK) {
		/*��������� ��������� � ����*/
		string buff;
		prodExpWeight prodE;
		productOther prodO;
		/*������ ������ � ���� productExpiration.txt*/
		std::remove("datafiles/buffer.txt");
		ofstream file("datafiles/buffer.txt", ios::app);
		if (file.is_open());
		else {
			MessageBox::Show("�� ������� ������� ����..", "������!");
			return System::Void();
		}
		for (int i = 0; i < pcountAll; i++) {
			if (dataGridView1->Rows[i]->Cells[1]->Value->ToString() == "�����/������" ||
				dataGridView1->Rows[i]->Cells[1]->Value->ToString() == "�����" ||
				dataGridView1->Rows[i]->Cells[1]->Value->ToString() == "�������������" ||
				dataGridView1->Rows[i]->Cells[1]->Value->ToString() == "�������") {
				if (Convert::ToDouble(dataGridView1->Rows[i]->Cells[4]->Value) != 0) {
					//������ ������ �� dataGridView � �����
					Convert_String_to_string(dataGridView1->Rows[i]->Cells[0]->Value->ToString(), buff);
					prodE.setProductName(buff);
					Convert_String_to_string(dataGridView1->Rows[i]->Cells[1]->Value->ToString(), buff);
					prodE.setProductType(buff);
					prodE.setProductCost(Convert::ToDouble(dataGridView1->Rows[i]->Cells[2]->Value));
					Convert_String_to_string(dataGridView1->Rows[i]->Cells[3]->Value->ToString(), buff);
					prodE.setProductExp(buff);
					prodE.setProdExpWeight(Convert::ToDouble(dataGridView1->Rows[i]->Cells[4]->Value));
					//������ ������ �� ������ � ����
					file << prodE.getProductName() << endl << prodE.getProductType() << endl <<
						prodE.getProductCost() << endl << prodE.getProductExp() << endl << prodE.getProdExpWeight() << endl;
				}
			}
		}
		file.close();
		std::remove("datafiles/productExpiration.txt");
		std::rename("datafiles/buffer.txt", "datafiles/productExpiration.txt");

		/*������ ������ � ���� productOther.txt*/
		std::remove("datafiles/buffer.txt");
		ofstream file1("datafiles/buffer.txt", ios::app);
		if (file1.is_open());
		else {
			MessageBox::Show("�� ������� ������� ����..", "������!");
			return System::Void();
		}
		for (int i = 0; i < pcountAll; i++) {
			if (dataGridView1->Rows[i]->Cells[1]->Value->ToString() == "������������� ������" ||
				dataGridView1->Rows[i]->Cells[1]->Value->ToString() == "������� ������") {
				if (Convert::ToDouble(dataGridView1->Rows[i]->Cells[4]->Value) != 0) {
					//������ ������ �� dataGridView � �����
					Convert_String_to_string(dataGridView1->Rows[i]->Cells[0]->Value->ToString(), buff);
					prodO.setProductName(buff);
					Convert_String_to_string(dataGridView1->Rows[i]->Cells[1]->Value->ToString(), buff);
					prodO.setProductType(buff);
					prodO.setProductCost(Convert::ToDouble(dataGridView1->Rows[i]->Cells[2]->Value));
					prodO.setProdValue(Convert::ToInt32(dataGridView1->Rows[i]->Cells[4]->Value));
					//������ ������ �� ������ � ����
					file1 << prodO.getProductName() << endl << prodO.getProductType() << endl <<
						prodO.getProductCost() << endl << prodO.getProdValue() << endl;
				}
			}
		}
		file1.close();
		std::remove("datafiles/productOther.txt");
		std::rename("datafiles/buffer.txt", "datafiles/productOther.txt");
		pShop::Mainform::Cashbox += CashCart;
		pcountCart = 0;
		CashCart = 0;
		lbCashCart->Text = "0�";
		/*����� DataGridView*/
		dataGridView_LoadAll();
		dataGridView_LoadCart();
	}
}
