#pragma once
#include <string.h>
#include <iostream>
#include <Windows.h>
#include <conio.h>

int Counter(); //������� �������� ���-�� ��������� � ���� ������
int CounterExp();
int CounterOther();
/* ������������ std::string � System::string^ */
System::String^ Convert_string_to_String(std::string& os, System::String^ s);
System::String^ Convert_string_to_String(std::string& os);
/* ������������ System::string^ � std::string */
std::string& Convert_String_to_string(System::String^ s);
std::string& Convert_String_to_string(System::String^ s, std::string& os);
/* ������������ System::string^ � char* */
char* Convert_String_to_char(System::String^ string);