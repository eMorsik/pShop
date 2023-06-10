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

int pcount = 0; //кол-во элементов бд

prodExpWeight* prodEW = new prodExpWeight[CounterExp()];
productOther* prodO = new productOther[CounterOther()];

System::Void pShop::pList::pList_Load(System::Object^ sender, System::EventArgs^ e)
{
	// Очистка сетки
	dataGridView1->Rows->Clear();
	dataGridView1->Columns->Clear();
	// Шапка
	Header();
	pcount = Counter();
	DataReader();
	// Размер таблицы
	dataGridView1->RowCount = pcount + 1;
	dataGridView1->ColumnCount = 5;
	for (int i = 0; i < dataGridView1->RowCount; i++) {
		dataGridView1->Rows[i]->ReadOnly = true;
	}
	//Вывод таблицы
	Show();
	return System::Void();
}

/*Шапка DataGridView*/
void pShop::pList::Header()
{
	DataGridViewTextBoxColumn^ c1 = gcnew DataGridViewTextBoxColumn();
	c1->Name = "name";
	c1->HeaderText = "Наименование товара";
	c1->DefaultCellStyle->ForeColor = Color::Black;
	dataGridView1->Columns->Add(c1);

	DataGridViewTextBoxColumn^ c2 = gcnew DataGridViewTextBoxColumn();
	c2->Name = "type";
	c2->HeaderText = "Тип товара";
	c2->DefaultCellStyle->ForeColor = Color::Black;
	dataGridView1->Columns->Add(c2);

	DataGridViewTextBoxColumn^ c3 = gcnew DataGridViewTextBoxColumn();
	c3->Name = "cost";
	c3->HeaderText = "Стоимость товара";
	c3->DefaultCellStyle->ForeColor = Color::Black;
	dataGridView1->Columns->Add(c3);

	DataGridViewTextBoxColumn^ c4 = gcnew DataGridViewTextBoxColumn();
	c4->Name = "expdate";
	c4->HeaderText = "Срок годности";
	c4->DefaultCellStyle->ForeColor = Color::Black;
	dataGridView1->Columns->Add(c4);

	DataGridViewTextBoxColumn^ c5 = gcnew DataGridViewTextBoxColumn();
	c5->Name = "value";
	c5->HeaderText = "Кол-во товара(кг/шт)";
	c5->DefaultCellStyle->ForeColor = Color::Black;
	dataGridView1->Columns->Add(c5);
}

/*Вывод массивов объектов в DataGridView*/
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

/*Считывание данных из файлов в массив объектов*/
void pShop::pList::DataReader()
{
	string sbuff;
	float fbuff;
	if (pcount > 0) {
		/*Файл productExpiration.txt*/
		int n = CounterExp();
		ifstream file("datafiles/productExpiration.txt");
		if (file.is_open());
		else {
			MessageBox::Show("Не удалось открыть файл..", "Ошибка!");
			return;
		}
		//Считывание элементов бд из файла в массив
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
		/*Файл productOther.txt*/
		n = CounterOther();
		ifstream file1("datafiles/productOther.txt");
		if (file1.is_open());
		else {
			MessageBox::Show("Не удалось открыть файл..", "Ошибка!");
			return;
		}
		//Считывание элементов бд из файла в массив
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
	else MessageBox::Show("Сотрудников в базе данных не найдено...", "Внимание!");
	return;
}
