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
	/*Проверка на пустые строки*/
	if (String::IsNullOrWhiteSpace(tbName->Text)) {
		MessageBox::Show("Введены не все данные!", "Внимание!");
		return;
	}
	if (String::IsNullOrWhiteSpace(cbType->Text)) {
		MessageBox::Show("Введены не все данные!", "Внимание!");
		return;
	}
	if (String::IsNullOrWhiteSpace(nudCost->Text)) {
		MessageBox::Show("Введены не все данные!", "Внимание!");
		return;
	}
	if(tbExpDate->Enabled)
		if (!tbExpDate->MaskCompleted) {
			MessageBox::Show("Введены не все данные!", "Внимание!");
			tbExpDate->Text = "";
			return;
		}
	//Подтверждение добавления товара
	string buff;
	System::Windows::Forms::DialogResult result =
		MessageBox::Show("Сохранить изменения?", "Внимание!", MessageBoxButtons::OKCancel);
	if (result == System::Windows::Forms::DialogResult::OK) {
		//проверка на тип товара
		if (cbType->SelectedItem->ToString() == "Овощи/Фрукты") {
			//запись данных в класс
			Convert_String_to_string(tbName->Text, buff);
			prodEW.setProductName(buff);
			Convert_String_to_string(cbType->Text, buff);
			prodEW.setProductType(buff);
			prodEW.setProductCost(Convert::ToDouble(nudCost->Value));
			Convert_String_to_string(tbExpDate->Text, buff);
			prodEW.setProductExp(buff);
			prodEW.setProdExpWeight(Convert::ToDouble(nudWeight->Value));
			//открытие файла
			ofstream file("datafiles/productExpiration.txt", ios::app);
			if (file.is_open());
			else {
				MessageBox::Show("Не удалось открыть файл..", "Ошибка!");
				return System::Void();
			}
			//запись данных из класса в файл
			file << prodEW.getProductName() << endl << prodEW.getProductType() << endl <<
				prodEW.getProductCost() << endl << prodEW.getProductExp() << endl << prodEW.getProdExpWeight() << endl;
			file.close();
		}
		else if (cbType->SelectedItem->ToString() == "Гигиенические товары" || 
			cbType->SelectedItem->ToString() == "Бытовые товары") {
			//запись данных в класс
			Convert_String_to_string(tbName->Text, buff);
			prodO.setProductName(buff);
			Convert_String_to_string(cbType->Text, buff);
			prodO.setProductType(buff);
			prodO.setProductCost(Convert::ToDouble(nudCost->Value));
			prodO.setProdValue(Convert::ToInt32(nudValue->Value));
			//открытие файла
			ofstream file("datafiles/productOther.txt", ios::app);
			if (file.is_open());
			else {
				MessageBox::Show("Не удалось открыть файл..", "Ошибка!");
				return System::Void();
			}
			//запись данных из класса в файл
			file << prodO.getProductName() << endl << prodO.getProductType() << endl <<
				prodO.getProductCost() << endl << prodO.getProdValue() << endl;
			file.close();
		}
		else if (cbType->SelectedItem->ToString() == "Снеки" || 
			cbType->SelectedItem->ToString() == "Полуфабрикаты" ||
			cbType->SelectedItem->ToString() == "Молочка") {
			//запись данных в класс
			Convert_String_to_string(tbName->Text, buff);
			prodEV.setProductName(buff);
			Convert_String_to_string(cbType->Text, buff);
			prodEV.setProductType(buff);
			prodEV.setProductCost(Convert::ToDouble(nudCost->Value));
			Convert_String_to_string(tbExpDate->Text, buff);
			prodEV.setProductExp(buff);
			prodEV.setProdExpValue(Convert::ToInt32(nudValue->Value));
			//открытие файла
			ofstream file("datafiles/productExpiration.txt", ios::app);
			if (file.is_open());
			else {
				MessageBox::Show("Не удалось открыть файл..", "Ошибка!");
				return System::Void();
			}
			//запись данных из класса в файл
			file << prodEV.getProductName() << endl << prodEV.getProductType() << endl <<
				prodEV.getProductCost() << endl << prodEV.getProductExp() << endl << prodEV.getProdExpValue() << endl;
			file.close();
		}
		MessageBox::Show("Изменения сохранены!", "Сохранение");
		this->Close();
	}
}

System::Void pShop::pAdding::cbType_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{
	tbExpDate->Enabled = false;
	nudValue->Enabled = false;
	nudWeight->Enabled = false;
	if (cbType->SelectedItem->ToString() == "Овощи/Фрукты") {
		tbExpDate->Enabled = true;
		nudWeight->Enabled = true;
	}
	else if (cbType->SelectedItem->ToString() == "Гигиенические товары" ||
		cbType->SelectedItem->ToString() == "Бытовые товары") {
		nudValue->Enabled = true;
	}
	else if (cbType->SelectedItem->ToString() == "Снеки" ||
		cbType->SelectedItem->ToString() == "Полуфабрикаты" ||
		cbType->SelectedItem->ToString() == "Молочка") {
		tbExpDate->Enabled = true;
		nudValue->Enabled = true;
	}
	return System::Void();
}

