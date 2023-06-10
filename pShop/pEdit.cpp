#include "pEdit.h"
#include "Mainform.h"
#include "Functions.h"
#include "productOther.h"
#include "productExpiration.h"
#include "prodExpValue.h"
#include "prodExpWeight.h"
#include <fstream>
#include <string>
#include "pAdding.h"
#include "pEditing.h"
using namespace std;
using namespace System::Windows::Forms;

int pcount1 = 0; //кол-во элементов бд

prodExpWeight* prodEW1 = new prodExpWeight[100];
productOther* prodO1 = new productOther[100];

System::Void pShop::pEdit::pEdit_Load(System::Object^ sender, System::EventArgs^ e)
{
	/*Вывод DataGridView*/
	dataGridView_Load();
	return System::Void();
}

/*Шапка DataGridView*/
void pShop::pEdit::HeaderEdit()
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
void pShop::pEdit::ShowEdit()
{
	int i;
	for (i = 0; i < CounterExp(); i++) {
		dataGridView1->Rows[i]->HeaderCell->Value = Convert::ToString(i + 1);
		dataGridView1->Rows[i]->Cells[0]->Value = Convert_string_to_String(prodEW1[i].getProductName());
		dataGridView1->Rows[i]->Cells[1]->Value = Convert_string_to_String(prodEW1[i].getProductType());
		dataGridView1->Rows[i]->Cells[2]->Value = prodEW1[i].getProductCost();
		dataGridView1->Rows[i]->Cells[3]->Value = Convert_string_to_String(prodEW1[i].getProductExp());
		dataGridView1->Rows[i]->Cells[4]->Value = Convert::ToDecimal(prodEW1[i].getProdExpWeight());
	}
	for (int j = 0; j < CounterOther(); j++) {
		dataGridView1->Rows[j + i]->HeaderCell->Value = Convert::ToString(j + i + 1);
		dataGridView1->Rows[j + i]->Cells[0]->Value = Convert_string_to_String(prodO1[j].getProductName());
		dataGridView1->Rows[j + i]->Cells[1]->Value = Convert_string_to_String(prodO1[j].getProductType());
		dataGridView1->Rows[j + i]->Cells[2]->Value = prodO1[j].getProductCost();
		dataGridView1->Rows[j + i]->Cells[3]->Value = "--.--.----";
		dataGridView1->Rows[j + i]->Cells[4]->Value = Convert::ToDecimal(prodO1[j].getProdValue());
	}
}

/*Считывание данных из файлов в массив объектов*/
void pShop::pEdit::DataReaderEdit()
{
	string sbuff;
	float fbuff;
	if (pcount1 > 0) {
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
				prodEW1[i].setProductName(sbuff);
				getline(file, sbuff);
				prodEW1[i].setProductType(sbuff);
				file >> fbuff;
				prodEW1[i].setProductCost(fbuff);
				file >> sbuff;
				prodEW1[i].setProductExp(sbuff);
				file >> fbuff;
				prodEW1[i].setProdExpWeight(fbuff);
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
				prodO1[i].setProductName(sbuff);
				getline(file1, sbuff);
				prodO1[i].setProductType(sbuff);
				file1 >> fbuff;
				prodO1[i].setProductCost(fbuff);
				file1 >> fbuff;
				prodO1[i].setProdValue(fbuff);
				getline(file1, sbuff);
			}
		}
		file1.close();
	} 
	else MessageBox::Show("Сотрудников в базе данных не найдено...", "Внимание!");
	return;
}

/*Загрузка DataGridView*/
System::Void pShop::pEdit::dataGridView_Load()
{
	// Очистка сетки
	dataGridView1->Rows->Clear();
	dataGridView1->Columns->Clear();
	// Шапка
	HeaderEdit();
	pcount1 = Counter();
	DataReaderEdit();
	if (pcount1 > 0) {
		btnDeleteProduct->Enabled = true;
		btnDeleteAllProduct->Enabled = true;
		btnEditProduct->Enabled = true;
		nudDelete->Enabled = true;
		nudEdit->Enabled = true;
	}
	nudDelete->Maximum = pcount1;
	nudEdit->Maximum = pcount1;
	// Размер таблицы
	dataGridView1->RowCount = pcount1 + 1;
	dataGridView1->ColumnCount = 5;
	for (int i = 0; i < dataGridView1->RowCount; i++) {
		dataGridView1->Rows[i]->ReadOnly = true;
	}
	//Вывод таблицы
	ShowEdit();
    return System::Void();
}

System::Void pShop::pEdit::btnAddProduct_Click(System::Object^ sender, System::EventArgs^ e)
{
    pAdding^ form = gcnew pAdding();
    form->ShowDialog(this);
	/*Вывод DataGridView*/
	dataGridView_Load();
}

System::Void pShop::pEdit::btnEditProduct_Click(System::Object^ sender, System::EventArgs^ e)
{
	backup = false;
    pEditing^ form = gcnew pEditing();
	//Номер изменяемого элемента
	int editnum = Convert::ToInt32(nudEdit->Value);
	int editnum1 = editnum - 1;
	for (int i = 0; i < pcount1; i++)
		if (editnum == Convert::ToInt32(dataGridView1->Rows[i]->HeaderCell->Value)) {
			editnum = i;
			break;
		}
	/*Загрузка данных изменяемого элемента в форму для редактирования*/
	if (Convert::ToString(dataGridView1->Rows[editnum]->Cells[1]->Value) == "Овощи/Фрукты") {
		form->tbName->Text = Convert::ToString(dataGridView1->Rows[editnum]->Cells[0]->Value);
		form->cbType->Text = Convert::ToString(dataGridView1->Rows[editnum]->Cells[1]->Value);
		form->nudCost->Value = Convert::ToDecimal(dataGridView1->Rows[editnum]->Cells[2]->Value);
		form->tbExpDate->Text = Convert::ToString(dataGridView1->Rows[editnum]->Cells[3]->Value);
		form->nudWeight->Value = Convert::ToDecimal(dataGridView1->Rows[editnum]->Cells[4]->Value);
	}
	else if (Convert::ToString(dataGridView1->Rows[editnum]->Cells[1]->Value) == "Гигиенические товары" ||
		Convert::ToString(dataGridView1->Rows[editnum]->Cells[1]->Value) == "Бытовые товары") {
		form->tbName->Text = Convert::ToString(dataGridView1->Rows[editnum]->Cells[0]->Value);
		form->cbType->Text = Convert::ToString(dataGridView1->Rows[editnum]->Cells[1]->Value);
		form->nudCost->Value = Convert::ToDecimal(dataGridView1->Rows[editnum]->Cells[2]->Value);
		form->nudValue->Value = Convert::ToDecimal(dataGridView1->Rows[editnum]->Cells[4]->Value);
	}
	else if (Convert::ToString(dataGridView1->Rows[editnum]->Cells[1]->Value) == "Снеки" ||
		Convert::ToString(dataGridView1->Rows[editnum]->Cells[1]->Value) == "Полуфабрикаты" || 
		Convert::ToString(dataGridView1->Rows[editnum]->Cells[1]->Value) == "Молочка") {
		form->tbName->Text = Convert::ToString(dataGridView1->Rows[editnum]->Cells[0]->Value);
		form->cbType->Text = Convert::ToString(dataGridView1->Rows[editnum]->Cells[1]->Value);
		form->nudCost->Value = Convert::ToDecimal(dataGridView1->Rows[editnum]->Cells[2]->Value);
		form->tbExpDate->Text = Convert::ToString(dataGridView1->Rows[editnum]->Cells[3]->Value);
		form->nudValue->Value = Convert::ToDecimal(dataGridView1->Rows[editnum]->Cells[4]->Value);
	}
	/*Открытие формы редактирования*/
	form->ShowDialog(this);
	if (!backup) {
		/*запись данных из формы в dataGridView*/
		if (form->cbType->SelectedItem->ToString() == "Овощи/Фрукты" ||
			form->cbType->SelectedItem->ToString() == "Снеки" ||
			form->cbType->SelectedItem->ToString() == "Полуфабрикаты" ||
			form->cbType->SelectedItem->ToString() == "Молочка") {
			dataGridView1->Rows[editnum]->Cells[0]->Value = form->tbName->Text;
			dataGridView1->Rows[editnum]->Cells[1]->Value = form->cbType->Text;
			dataGridView1->Rows[editnum]->Cells[2]->Value = form->nudCost->Value;
			dataGridView1->Rows[editnum]->Cells[3]->Value = form->tbExpDate->Text;
			if (form->cbType->SelectedItem->ToString() == "Овощи/Фрукты")
				dataGridView1->Rows[editnum]->Cells[4]->Value = form->nudWeight->Value;
			else dataGridView1->Rows[editnum]->Cells[4]->Value = form->nudValue->Value;
		}
		else if (form->cbType->SelectedItem->ToString() == "Гигиенические товары" ||
			form->cbType->SelectedItem->ToString() == "Бытовые товары") {
			dataGridView1->Rows[editnum]->Cells[0]->Value = form->tbName->Text;
			dataGridView1->Rows[editnum]->Cells[1]->Value = form->cbType->Text;
			dataGridView1->Rows[editnum]->Cells[2]->Value = form->nudCost->Value;
			dataGridView1->Rows[editnum]->Cells[4]->Value = form->nudValue->Value;
		}

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
		for (int i = 0; i < pcount1; i++) {
			if (dataGridView1->Rows[i]->Cells[1]->Value->ToString() == "Овощи/Фрукты" ||
				dataGridView1->Rows[i]->Cells[1]->Value->ToString() == "Снеки" ||
				dataGridView1->Rows[i]->Cells[1]->Value->ToString() == "Полуфабрикаты" ||
				dataGridView1->Rows[i]->Cells[1]->Value->ToString() == "Молочка") {
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
		for (int i = 0; i < pcount1; i++) {
			if (dataGridView1->Rows[i]->Cells[1]->Value->ToString() == "Гигиенические товары" ||
				dataGridView1->Rows[i]->Cells[1]->Value->ToString() == "Бытовые товары") {
				//Запись данных из dataGridView в класс
				Convert_String_to_string(dataGridView1->Rows[i]->Cells[0]->Value->ToString(), buff);
				prodO.setProductName(buff);
				Convert_String_to_string(dataGridView1->Rows[i]->Cells[1]->Value->ToString(), buff);
				prodO.setProductType(buff);
				prodO.setProductCost(Convert::ToDouble(dataGridView1->Rows[i]->Cells[2]->Value));
				prodO.setProdValue(Convert::ToDouble(dataGridView1->Rows[i]->Cells[4]->Value));
				//запись данных из класса в файл
				file1 << prodO.getProductName() << endl << prodO.getProductType() << endl <<
					prodO.getProductCost() << endl << prodO.getProdValue() << endl;
			}
		}
		file1.close();
		std::remove("datafiles/productOther.txt");
		std::rename("datafiles/buffer.txt", "datafiles/productOther.txt");
	}
	/*Вывод DataGridView*/
	dataGridView_Load();
	return System::Void();
}

System::Void pShop::pEdit::btnDeleteProduct_Click(System::Object^ sender, System::EventArgs^ e)
{
	System::Windows::Forms::DialogResult result = MessageBox::Show("Удалить данные сотрудника?", "Внимание!", MessageBoxButtons::OKCancel);
	if (result == System::Windows::Forms::DialogResult::OK) {
		int deletenum = Convert::ToInt32(nudDelete->Value);
		int deletenum1 = deletenum - 1;
		for (int i = 0; i < pcount1; i++)
			if (deletenum == Convert::ToInt32(dataGridView1->Rows[i]->HeaderCell->Value)) {
				deletenum = i;
				break;
			}
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
		for (int i = 0; i < pcount1; i++) {
			if (dataGridView1->Rows[i]->Cells[1]->Value->ToString() == "Овощи/Фрукты" ||
				dataGridView1->Rows[i]->Cells[1]->Value->ToString() == "Снеки" ||
				dataGridView1->Rows[i]->Cells[1]->Value->ToString() == "Полуфабрикаты" ||
				dataGridView1->Rows[i]->Cells[1]->Value->ToString() == "Молочка") {
				//Запись данных из dataGridView в класс
				if (i != deletenum) {
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
		for (int i = 0; i < pcount1; i++) {
			if (dataGridView1->Rows[i]->Cells[1]->Value->ToString() == "Гигиенические товары" ||
				dataGridView1->Rows[i]->Cells[1]->Value->ToString() == "Бытовые товары") {
				//Запись данных из dataGridView в класс
				if (i != deletenum) {
					Convert_String_to_string(dataGridView1->Rows[i]->Cells[0]->Value->ToString(), buff);
					prodO.setProductName(buff);
					Convert_String_to_string(dataGridView1->Rows[i]->Cells[1]->Value->ToString(), buff);
					prodO.setProductType(buff);
					prodO.setProductCost(Convert::ToDouble(dataGridView1->Rows[i]->Cells[2]->Value));
					prodO.setProdValue(Convert::ToDouble(dataGridView1->Rows[i]->Cells[4]->Value));
					//запись данных из класса в файл
					file1 << prodO.getProductName() << endl << prodO.getProductType() << endl <<
						prodO.getProductCost() << endl << prodO.getProdValue() << endl;
				}
			}
		}
		file1.close();
		std::remove("datafiles/productOther.txt");
		std::rename("datafiles/buffer.txt", "datafiles/productOther.txt");
	}
	/*Вывод DataGridView*/
	dataGridView_Load();
    return System::Void();
}

System::Void pShop::pEdit::btnDeleteAllProduct_Click(System::Object^ sender, System::EventArgs^ e)
{
	System::Windows::Forms::DialogResult result =
		MessageBox::Show("Вы уверены, что хотите удалить все данные?", "Внимание!", MessageBoxButtons::OKCancel);
	if (result == System::Windows::Forms::DialogResult::OK) {
		std::remove("datafiles/productOther.txt");
		ofstream file("datafiles/productOther.txt");
		file.close();
		std::remove("datafiles/productExpiration.txt");
		ofstream file1("datafiles/productExpiration.txt");
		file1.close();
	}
	/*Вывод DataGridView*/
	dataGridView_Load();
    return System::Void();
}
