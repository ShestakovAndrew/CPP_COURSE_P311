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

	size_t index = 1;
	std::cout << "Номера совпадений: ";
	for (char* ptr = input; *ptr != '\0'; ++ptr, ++index)
	{
		if (*ptr == symbol)
		{
			std::cout << index << " ";
		}
	}
	std::cout << std::endl;

	return 0;
}