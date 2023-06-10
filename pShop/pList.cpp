#include "pList.h"
#include "Mainform.h"
#include "Functions.h"
#include "productOther.h"
#include "productExpiration.h"
#include "prodExpValue.h"
#include "prodExpWeight.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
using namespace System::Windows::Forms;

int pcount = 0; //���-�� ��������� ��

prodExpWeight* prodEW = new prodExpWeight[CounterExp()];
productOther* prodO = new productOther[CounterOther()];

System::Void pShop::pList::pList_Load(System::Object^ sender, System::EventArgs^ e)
{
	// ������� �����
	dataGridView1->Rows->Clear();
	dataGridView1->Columns->Clear();
	// �����
	Header();
	pcount = Counter();
	DataReader();
	// ������ �������
	dataGridView1->RowCount = pcount + 1;
	dataGridView1->ColumnCount = 5;
	for (int i = 0; i < dataGridView1->RowCount; i++) {
		dataGridView1->Rows[i]->ReadOnly = true;
	}
	//����� �������
	Show();
	return System::Void();
}

/*����� DataGridView*/
void pShop::pList::Header()
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

/*����� �������� �������� � DataGridView*/
void pShop::pList::Show()
{
	int i;
	for (i = 0 ; i < CounterExp(); i++) {
		dataGridView1->Rows[i]->HeaderCell->Value = Convert::ToString(i + 1);
		dataGridView1->Rows[i]->Cells[0]->Value = Convert_string_to_String(prodEW[i].getProductName());
		dataGridView1->Rows[i]->Cells[1]->Value = Convert_string_to_String(prodEW[i].getProductType());
		dataGridView1->Rows[i]->Cells[2]->Value = prodEW[i].getProductCost();
		dataGridView1->Rows[i]->Cells[3]->Value = Convert_string_to_String(prodEW[i].getProductExp());
		dataGridView1->Rows[i]->Cells[4]->Value = Convert::ToDecimal(prodEW[i].getProdExpWeight());
	}
	for (int j = 0; j < CounterOther(); j++) {
		dataGridView1->Rows[j+i]->HeaderCell->Value = Convert::ToString(j+ i + 1);
		dataGridView1->Rows[j+i]->Cells[0]->Value = Convert_string_to_String(prodO[j].getProductName());
		dataGridView1->Rows[j+i]->Cells[1]->Value = Convert_string_to_String(prodO[j].getProductType());
		dataGridView1->Rows[j+i]->Cells[2]->Value = prodO[j].getProductCost();
		dataGridView1->Rows[j+i]->Cells[3]->Value = "--.--.----";
		dataGridView1->Rows[j+i]->Cells[4]->Value = Convert::ToDecimal(prodO[j].getProdValue());
	}
}

/*���������� ������ �� ������ � ������ ��������*/
void pShop::pList::DataReader()
{
	string sbuff;
	float fbuff;
	if (pcount > 0) {
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
				prodEW[i].setProductName(sbuff);
				getline(file, sbuff);
				prodEW[i].setProductType(sbuff);
				file >> fbuff;
				prodEW[i].setProductCost(fbuff);
				file >> sbuff;
				prodEW[i].setProductExp(sbuff);
				file >> fbuff;
				prodEW[i].setProdExpWeight(fbuff);
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
				prodO[i].setProductName(sbuff);
				getline(file1, sbuff);
				prodO[i].setProductType(sbuff);
				file1 >> fbuff;
				prodO[i].setProductCost(fbuff);
				file1 >> fbuff;
				prodO[i].setProdValue(fbuff);
				getline(file1, sbuff);
			}
		}
		file1.close();
	}
	else MessageBox::Show("����������� � ���� ������ �� �������...", "��������!");
	return;
}
