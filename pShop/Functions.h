#pragma once
#include <string.h>
#include <iostream>
#include <Windows.h>
#include <conio.h>

int Counter(); //Функция подсчета кол-ва элементов в базе данных
int CounterExp();
int CounterOther();
/* конвертируем std::string в System::string^ */
System::String^ Convert_string_to_String(std::string& os, System::String^ s);
System::String^ Convert_string_to_String(std::string& os);
/* конвертируем System::string^ в std::string */
std::string& Convert_String_to_string(System::String^ s);
std::string& Convert_String_to_string(System::String^ s, std::string& os);
/* конвертируем System::string^ в char* */
char* Convert_String_to_char(System::String^ string);