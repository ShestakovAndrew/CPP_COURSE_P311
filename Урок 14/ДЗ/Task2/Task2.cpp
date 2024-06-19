#include <iostream>
#include <cstring>

char* RemoveCharAll(char* str, char ch) 
{
	char* dst = str;

	while (*str) 
	{
		if (*str != ch) 
		{
			*dst = *str;
			dst++;
		}
		str++;
	}
	*dst = '\0';

	return str;
}

int main() 
{
	setlocale(LC_ALL, "rus");

	char myString[] = "Hello, world!";
	char charToRemove = 'l';

	std::cout << "Исходная строка: " << myString << std::endl;

	RemoveCharAll(myString, charToRemove);

	std::cout << "Строка после удаления: " << myString << std::endl;

	return 0;
}
