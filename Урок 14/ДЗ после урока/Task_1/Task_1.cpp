#include <iostream>
#include <string>

int main()
{
	setlocale(LC_ALL, "rus");

	const size_t SIZE_ARRAY = 100;
	char inputArray[SIZE_ARRAY];

	std::cout << "Введите строку: ";
	std::cin.getline(inputArray, SIZE_ARRAY);

	size_t count = 0;
	while (count < SIZE_ARRAY && inputArray[count] != '\0')
	{
		count++;
	}

	std::cout << "Занято элементов массива: " << count << std::endl;
	std::cout << "Свободно элементов массива: " << (SIZE_ARRAY - count - 1) << std::endl;
}