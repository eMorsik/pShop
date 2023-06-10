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

int pcountAll = 0; //кол-во элементов бд
int pcountCart = 0; //кол-во элементов в корзине
float CashCart = 0; //Стоимость товаров в корзине

System::Void pShop::pAddCart::pAddCart_Load(System::Object^ sender, System::EventArgs^ e)
{
    /*Вывод DataGridView*/
    dataGridView_LoadAll();
	pcountCart = 0;
	float CashCart = 0;
	return System::Void();
}

/*Шапка DataGridView* всей БД */
System::Void pShop::pAddCart::HeaderAll()
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

/*Вывод всей БД в DataGridView*/
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

/*Считывание БД в массив объектов*/
void pShop::pAddCart::DataReaderAll()
{
	string sbuff;
	float fbuff;
	if (pcountAll > 0) {
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
	else MessageBox::Show("Сотрудников в базе данных не найдено...", "Внимание!");
	return;
}

/*Загрузка DataGridView всей БД*/
System::Void pShop::pAddCart::dataGridView_LoadAll()
{
	// Очистка сетки
	dataGridView1->Rows->Clear();
	dataGridView1->Columns->Clear();
	// Шапка
	HeaderAll();
	pcountAll = Counter();
	DataReaderAll();
	if (pcountAll > 0) {
		panelAddCart->Enabled = true;
	}
	nudAddCart->Maximum = pcountAll;
	// Размер таблицы
	dataGridView1->RowCount = pcountAll + 1;
	dataGridView1->ColumnCount = 5;
	for (int i = 0; i < dataGridView1->RowCount; i++) {
		dataGridView1->Rows[i]->ReadOnly = true;
	}
	//Вывод таблицы
	ShowAll();
	return System::Void();
}

/*Шапка DataGridView* корзины*/
void pShop::pAddCart::HeaderCart()
{
	DataGridViewTextBoxColumn^ c1 = gcnew DataGridViewTextBoxColumn();
	c1->Name = "name";
	c1->HeaderText = "Наименование товара";
	c1->DefaultCellStyle->ForeColor = Color::Black;
	dataGridView2->Columns->Add(c1);

	DataGridViewTextBoxColumn^ c2 = gcnew DataGridViewTextBoxColumn();
	c2->Name = "type";
	c2->HeaderText = "Тип товара";
	c2->DefaultCellStyle->ForeColor = Color::Black;
	dataGridView2->Columns->Add(c2);

	DataGridViewTextBoxColumn^ c3 = gcnew DataGridViewTextBoxColumn();
	c3->Name = "cost";
	c3->HeaderText = "Стоимость товара";
	c3->DefaultCellStyle->ForeColor = Color::Black;
	dataGridView2->Columns->Add(c3);

	DataGridViewTextBoxColumn^ c4 = gcnew DataGridViewTextBoxColumn();
	c4->Name = "expdate";
	c4->HeaderText = "Срок годности";
	c4->DefaultCellStyle->ForeColor = Color::Black;
	dataGridView2->Columns->Add(c4);

	DataGridViewTextBoxColumn^ c5 = gcnew DataGridViewTextBoxColumn();
	c5->Name = "value";
	c5->HeaderText = "Кол-во товара(кг/шт)";
	c5->DefaultCellStyle->ForeColor = Color::Black;
	dataGridView2->Columns->Add(c5);
}

/*Вывод корзины в DataGridView*/
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

/*Считывание корзины в массив объектов*/
void pShop::pAddCart::DataReaderCart()
{
    throw gcnew System::NotImplementedException();
}

/*Загрузка DataGridView корзины*/
void pShop::pAddCart::dataGridView_LoadCart()
{
	// Очистка сетки
	dataGridView2->Rows->Clear();
	dataGridView2->Columns->Clear();
	// Шапка
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
	//Размер таблицы
	dataGridView2->RowCount = pcountCart + 1;
	dataGridView2->ColumnCount = 5;
	for (int i = 0; i < dataGridView2->RowCount; i++) {
		dataGridView2->Rows[i]->ReadOnly = true;
	}
	//Вывод таблицы
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
		MessageBox::Show("Невозможно добавить в корзину! Товар закончился!", "Внимание!");
		return;
	}
	/*Загрузка данных изменяемого элемента в форму для редактирования*/
	if (Convert::ToString(dataGridView1->Rows[addnum]->Cells[1]->Value) == "Овощи/Фрукты") {
		form->tbName->Text = Convert::ToString(dataGridView1->Rows[addnum]->Cells[0]->Value);
		form->nudCost->Value = Convert::ToDecimal(dataGridView1->Rows[addnum]->Cells[2]->Value);
		form->nudWeight->Maximum = Convert::ToDecimal(dataGridView1->Rows[addnum]->Cells[4]->Value);
		form->nudWeight->Enabled = true;
	}
	else if (Convert::ToString(dataGridView1->Rows[addnum]->Cells[1]->Value) == "Гигиенические товары" ||
		Convert::ToString(dataGridView1->Rows[addnum]->Cells[1]->Value) == "Бытовые товары") {
		form->tbName->Text = Convert::ToString(dataGridView1->Rows[addnum]->Cells[0]->Value);
		form->nudCost->Value = Convert::ToDecimal(dataGridView1->Rows[addnum]->Cells[2]->Value);
		form->nudValue->Maximum = Convert::ToDecimal(dataGridView1->Rows[addnum]->Cells[4]->Value);
		form->nudValue->Enabled = true;
	}
	else if (Convert::ToString(dataGridView1->Rows[addnum]->Cells[1]->Value) == "Снеки" ||
		Convert::ToString(dataGridView1->Rows[addnum]->Cells[1]->Value) == "Полуфабрикаты" ||
		Convert::ToString(dataGridView1->Rows[addnum]->Cells[1]->Value) == "Молочка") {
		form->tbName->Text = Convert::ToString(dataGridView1->Rows[addnum]->Cells[0]->Value);
		form->nudCost->Value = Convert::ToDecimal(dataGridView1->Rows[addnum]->Cells[2]->Value);
		form->nudValue->Maximum = Convert::ToDecimal(dataGridView1->Rows[addnum]->Cells[4]->Value);
		form->nudValue->Enabled = true;
	}
	/*Открытие формы редактирования*/
	form->ShowDialog(this);
	string buff;
	if (ConfirmAdd) {
		//Запись данных из dataGridView в класс
		Convert_String_to_string(dataGridView1->Rows[addnum]->Cells[0]->Value->ToString(), buff);
		prodE2[pcountCart].setProductName(buff);
		Convert_String_to_string(dataGridView1->Rows[addnum]->Cells[1]->Value->ToString(), buff);
		prodE2[pcountCart].setProductType(buff);
		prodE2[pcountCart].setProductCost(Convert::ToDouble(form->nudCost->Value));
		Convert_String_to_string(dataGridView1->Rows[addnum]->Cells[3]->Value->ToString(), buff);
		prodE2[pcountCart].setProductExp(buff);
		if (Convert::ToString(dataGridView1->Rows[addnum]->Cells[1]->Value) == "Овощи/Фрукты")
			prodE2[pcountCart].setProdExpWeight(Convert::ToDouble(form->nudWeight->Value));
		else prodE2[pcountCart].setProdExpWeight(Convert::ToDouble(form->nudValue->Value));
		pcountCart++;
		dataGridView_LoadCart();
		if (Convert::ToString(dataGridView1->Rows[addnum]->Cells[1]->Value) == "Овощи/Фрукты") {
			dataGridView1->Rows[addnum]->Cells[4]->Value = 
				Decimal::operator-(Convert::ToDecimal(dataGridView1->Rows[addnum]->Cells[4]->Value), form->nudWeight->Value);
		}
		else {
			dataGridView1->Rows[addnum]->Cells[4]->Value =
				Decimal::operator-(Convert::ToDecimal(dataGridView1->Rows[addnum]->Cells[4]->Value), form->nudValue->Value);
		}
		CashCart += Convert::ToDouble(form->nudCost->Value);
		lbCashCart->Text = Convert::ToString(CashCart) + "р";
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
	//Подтверждение удаления из корзины
	System::Windows::Forms::DialogResult result =
		MessageBox::Show("Удалить товар из корзины?", "Внимание!", MessageBoxButtons::OKCancel);
	if (result == System::Windows::Forms::DialogResult::OK) {
		CashCart = CashCart - Convert::ToDouble(dataGridView2->Rows[delnum]->Cells[2]->Value);
		lbCashCart->Text = Convert::ToString(CashCart) + "р";
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
					lbCashCart->Text = "0р";
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
		MessageBox::Show("Подтвердить покупку?", "Внимание!", MessageBoxButtons::OKCancel);
	if (result == System::Windows::Forms::DialogResult::OK) {
		/*Сохраение изменений в файл*/
		string buff;
		prodExpWeight prodE;
		productOther prodO;
		/*запись данных в файл productExpiration.txt*/
		std::remove("datafiles/buffer.txt");
		ofstream file("datafiles/buffer.txt", ios::app);
		if (file.is_open());
		else {
			MessageBox::Show("Не удалось открыть файл..", "Ошибка!");
			return System::Void();
		}
		for (int i = 0; i < pcountAll; i++) {
			if (dataGridView1->Rows[i]->Cells[1]->Value->ToString() == "Овощи/Фрукты" ||
				dataGridView1->Rows[i]->Cells[1]->Value->ToString() == "Снеки" ||
				dataGridView1->Rows[i]->Cells[1]->Value->ToString() == "Полуфабрикаты" ||
				dataGridView1->Rows[i]->Cells[1]->Value->ToString() == "Молочка") {
				if (Convert::ToDouble(dataGridView1->Rows[i]->Cells[4]->Value) != 0) {
					//Запись данных из dataGridView в класс
					Convert_String_to_string(dataGridView1->Rows[i]->Cells[0]->Value->ToString(), buff);
					prodE.setProductName(buff);
					Convert_String_to_string(dataGridView1->Rows[i]->Cells[1]->Value->ToString(), buff);
					prodE.setProductType(buff);
					prodE.setProductCost(Convert::ToDouble(dataGridView1->Rows[i]->Cells[2]->Value));
					Convert_String_to_string(dataGridView1->Rows[i]->Cells[3]->Value->ToString(), buff);
					prodE.setProductExp(buff);
					prodE.setProdExpWeight(Convert::ToDouble(dataGridView1->Rows[i]->Cells[4]->Value));
					//запись данных из класса в файл
					file << prodE.getProductName() << endl << prodE.getProductType() << endl <<
						prodE.getProductCost() << endl << prodE.getProductExp() << endl << prodE.getProdExpWeight() << endl;
				}
			}
		}
		file.close();
		std::remove("datafiles/productExpiration.txt");
		std::rename("datafiles/buffer.txt", "datafiles/productExpiration.txt");

		/*запись данных в файл productOther.txt*/
		std::remove("datafiles/buffer.txt");
		ofstream file1("datafiles/buffer.txt", ios::app);
		if (file1.is_open());
		else {
			MessageBox::Show("Не удалось открыть файл..", "Ошибка!");
			return System::Void();
		}
		for (int i = 0; i < pcountAll; i++) {
			if (dataGridView1->Rows[i]->Cells[1]->Value->ToString() == "Гигиенические товары" ||
				dataGridView1->Rows[i]->Cells[1]->Value->ToString() == "Бытовые товары") {
				if (Convert::ToDouble(dataGridView1->Rows[i]->Cells[4]->Value) != 0) {
					//Запись данных из dataGridView в класс
					Convert_String_to_string(dataGridView1->Rows[i]->Cells[0]->Value->ToString(), buff);
					prodO.setProductName(buff);
					Convert_String_to_string(dataGridView1->Rows[i]->Cells[1]->Value->ToString(), buff);
					prodO.setProductType(buff);
					prodO.setProductCost(Convert::ToDouble(dataGridView1->Rows[i]->Cells[2]->Value));
					prodO.setProdValue(Convert::ToInt32(dataGridView1->Rows[i]->Cells[4]->Value));
					//запись данных из класса в файл
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
		lbCashCart->Text = "0р";
		/*Вывод DataGridView*/
		dataGridView_LoadAll();
		dataGridView_LoadCart();
	}
}
