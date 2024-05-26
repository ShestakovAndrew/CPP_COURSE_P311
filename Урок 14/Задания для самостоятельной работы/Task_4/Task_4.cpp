#include <iostream>
#include <cctype>

bool IsPalindrome(const char* str) 
{
	if (str == nullptr) return false; // Проверка на nullptr

	size_t length = strlen(str);

	for (size_t i = 0; i < length / 2; ++i) // Перебираем символы до середины строки
	{
		// Проверяем, равен ли i-ый символ от начала (i-ый с конца) символу
		if (std::tolower(str[i]) != std::tolower(str[length - i - 1])) 
		{
			return false; // Если символы не равны, строка не является палиндромом
		}
	}

	return true; // Строка является палиндромом
}

int main() 
{
	const char str[] = "Madam"; // Исходная строка
	
	if (IsPalindrome(str)) 
	{
		std::cout << "The string is a palindrome." << std::endl;
	}
	else 
	{
		std::cout << "The string is not a palindrome." << std::endl;
	}

	return 0;
}
