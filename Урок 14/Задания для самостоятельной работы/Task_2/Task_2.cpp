#include <iostream>
#include <cctype>

void CountCharacters(const char* str, size_t& letters, size_t& digits, size_t& others)
{
	letters = digits = others = 0; // Инициализация счетчиков

	if (str == nullptr) return; // Проверка на nullptr

	for (size_t i = 0; str[i] != '\0'; ++i) // Перебор символов строки до нуль-терминатора
	{
		if (std::isalpha(str[i])) // Проверка, является ли символ буквой
		{
			++letters;
		}
		else if (std::isdigit(str[i])) // Проверка, является ли символ цифрой
		{
			++digits;
		}
		else // Все остальные символы
		{
			++others;
		}
	}
}

int main() 
{
	const char str[] = "Hello, World! 12345"; // Исходная строка
	size_t letters, digits, others;

	CountCharacters(str, letters, digits, others); // Вызов функции подсчета

	std::cout << "Letters: " << letters << std::endl;
	std::cout << "Digits: " << digits << std::endl;
	std::cout << "Others: " << others << std::endl;

	return 0;
}
