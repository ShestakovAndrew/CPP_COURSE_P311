#include <iostream>

int main()
{
	setlocale(LC_ALL, "rus");

	const size_t SIZE_ARRAY = 100;
	char input[SIZE_ARRAY];
	char symbol;

	std::cout << "Введите строку: ";
	std::cin.getline(input, SIZE_ARRAY);

	std::cout << "Введите символ: ";
	std::cin >> symbol;

	size_t lastIndex = -1;

	for (size_t i = 0; input[i] != '\0'; ++i)
	{
		if (input[i] == symbol)
		{
			lastIndex = i;
		}
	}

	if (lastIndex != -1)
	{
		std::cout << "Индекс последнего совпадения: " << (lastIndex + 1) << std::endl;
	}
	else
	{
		std::cout << "Совпадение не найдено." << std::endl;
	}

	return 0;
}