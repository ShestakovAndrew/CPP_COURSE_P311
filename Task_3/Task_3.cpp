#include <iostream>
#include <cstring>

int main()
{
	setlocale(LC_ALL, "rus");

	const size_t SIZE_ARRAY = 100;
	char input[SIZE_ARRAY];
	size_t m, n;

	std::cout << "Введите строку: ";
	std::cin.getline(input, SIZE_ARRAY);

	std::cout << "Введите начальную позицию m (нумерация с 1): ";
	std::cin >> m;
	std::cout << "Введите конечную позицию n (нумерация с 1): ";
	std::cin >> n;

	m--;
	n--;
	size_t length = strlen(input);

	if (m < 0 || n > length || m > n)
	{
		std::cerr << "Ошибка: некорректный диапозон." << std::endl;
		return 1;
	}

	for (size_t i = n + 1; i <= length; i++)
	{
		input[m++] = input[i];
	}

	std::cout << "Изменённая строка: " << input << std::endl;

	return 0;
}