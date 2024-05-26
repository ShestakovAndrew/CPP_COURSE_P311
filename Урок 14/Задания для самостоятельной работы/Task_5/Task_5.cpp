#include <iostream>
#include "StrLibrary.h"

int main() 
{
	const char str[] = "Hello, World!";
	const char strToCopy[] = "Sample Text";
	const char strToConcat[] = " Have a nice day!";
	const char charToFind = 'W';
	const char strToFind[] = "World";

	// Пример использования mystrlen
	size_t length = mystrlen(str);
	std::cout << "Length of '" << str << "' is: " << length << std::endl;

	// Пример использования mystrcpy
	char copy[50]; // Буфер достаточного размера для копирования строки
	mystrcpy(copy, strToCopy);
	std::cout << "Copy of string is: " << copy << std::endl;

	// Пример использования mystrcat
	char concat[100] = "Hello,"; // Буфер достаточного размера для конкатенации строк
	mystrcat(concat, strToConcat);
	std::cout << "Concatenated string is: " << concat << std::endl;

	// Пример использования mystrchr
	char* charFound = mystrchr(const_cast<char*>(str), charToFind);
	if (charFound) 
	{
		std::cout << "Character '" << charToFind << "' found in string: " << charFound << std::endl;
	}
	else 
	{
		std::cout << "Character '" << charToFind << "' not found in string." << std::endl;
	}

	// Пример использования mystrstr
	char* strFound = mystrstr(const_cast<char*>(str), const_cast<char*>(strToFind));
	if (strFound) 
	{
		std::cout << "Substring '" << strToFind << "' found in string: " << strFound << std::endl;
	}
	else 
	{
		std::cout << "Substring '" << strToFind << "' not found in string." << std::endl;
	}

	return 0;
}