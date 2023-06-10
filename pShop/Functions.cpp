#include "functions.h"
#include <string>
#include <fstream>

using namespace System::Windows::Forms;
using namespace std;
using namespace System;

//Функция подсчета кол-ва элементов в базе данных
int Counter() {
	char buff[100];
	int n = 0, N1 = 0;
	FILE* file = fopen("datafiles/productExpiration.txt", "a+");
	if (file == NULL) {
		MessageBox::Show("Не удалось открыть файл..", "Ошибка!");
		return 1;
	}
	rewind(file);
	//Подсчет кол-ва элементов
	while (fgets(buff, 100, file) != NULL)
		n += 1;
	N1 = n / 5;
	fclose(file);
	int N2 = 0;
	n = 0;
	FILE* file1 = fopen("datafiles/productOther.txt", "a+");
	if (file1 == NULL) {
		MessageBox::Show("Не удалось открыть файл..", "Ошибка!");
		return 1;
	}
	rewind(file1);
	//Подсчет кол-ва элементов
	while (fgets(buff, 100, file1) != NULL)
		n += 1;
	N2 = n / 4;
	fclose(file1);
	return (N1 + N2);
}

int CounterExp()
{
	char buff[100];
	int n = 0;
	FILE* file = fopen("datafiles/productExpiration.txt", "a+");
	if (file == NULL) {
		MessageBox::Show("Не удалось открыть файл..", "Ошибка!");
		return 1;
	}
	rewind(file);
	//Подсчет кол-ва элементов
	while (fgets(buff, 100, file) != NULL)
		n += 1;
	fclose(file);
	return (n / 5);
}

int CounterOther()
{
	char buff[100];
	int n = 0;
	FILE* file = fopen("datafiles/productOther.txt", "a+");
	if (file == NULL) {
		MessageBox::Show("Не удалось открыть файл..", "Ошибка!");
		return 1;
	}
	rewind(file);
	//Подсчет кол-ва элементов
	while (fgets(buff, 100, file) != NULL)
		n += 1;
	fclose(file);
	return (n / 4);
}

//конвертируем std::string в System::string^
System::String^ Convert_string_to_String(std::string& os, System::String^ s) {
	s = gcnew System::String(os.c_str());
	return s;
}

//конвертируем std::string в System::string^
System::String^ Convert_string_to_String(std::string& os) {
	System::String^ s = gcnew System::String(os.c_str());
	return s;
}

//конвертируем System::string^ в std::string
std::string& Convert_String_to_string(System::String^ s) {
	std::string os;
	using namespace Runtime::InteropServices;
	const char* chars =
		(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	os = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));
	return os;
}

//конвертируем System::string^ в std::string
std::string& Convert_String_to_string(System::String^ s, std::string& os) {
	using namespace Runtime::InteropServices;
	const char* chars =
		(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	os = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));
	return os;
}

char* Convert_String_to_char(System::String^ string)
{
	return nullptr;
}