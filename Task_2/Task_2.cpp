#include <iostream>
#include <cstring>

int main()
{
	setlocale(LC_ALL, "rus");

	const size_t SIZE_ARRAY = 100;
	char input[SIZE_ARRAY];
	char output[SIZE_ARRAY];
	size_t m, n;

	std::cout << "Введите строку: ";
	std::cin.getline(input, SIZE_ARRAY);

	std::cout << "Введите начальную позицию m: ";
	std::cin >> m;
	std::cout << "Введите конечную позицию n: ";
	std::cin >> n;

	if (m < 1 || n > strlen(input) || m > n)
	{
		std::cerr << "Ошибка: некорректный диапозон." << std::endl;
		return 1;
	}

	size_t j = 0;
	for (size_t i = m - 1; i < n && input[i] != '\0'; ++i)
	{
		output[j++] = input[i];
	}
	output[j] = '\0';

	std::cout << "Отрезок строки с " << m << " по " << n << " символы: " << output << std::endl;
	return 0;
}
