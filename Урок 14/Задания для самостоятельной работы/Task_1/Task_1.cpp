#include <iostream>

void ReplaceSpacesWithTabs(char* str) 
{
	if (str == nullptr) return; // Проверка на nullptr

	int i = 0;
	while (str[i] != '\0') // Перебор символов строки до нуль-терминатора
	{ 
		if (std::isspace(str[i])) // Если текущий символ - пробел
		{
			str[i] = '\t'; // Замена пробела на табуляцию
		}
		i++; // Переход к следующему символу
	}
}

int main() 
{
	char str[] = "This is a test string."; // Исходная строка
	ReplaceSpacesWithTabs(str); // Вызов функции замены
	std::cout << str << std::endl; // Вывод результата
	return 0;
}
