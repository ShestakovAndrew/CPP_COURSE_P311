#include <iostream>
#include <bitset>

#include "Windows.h"

#define SIZE_INT 4

// Определим объединение, содержащее 4-байтовое целое число и массив логических переменных
union IntUnion 
{
	int32_t integer;
	bool bits[32];
};

// Функция для ввода целого числа
void InputInteger(IntUnion& intUnion)
{
	std::cout << "Введите целое число: ";
	std::cin >> intUnion.integer;
}

// Функция для подсчета количества нулевых байтов в числе
size_t CountZeroBytes(IntUnion const& intUnion)
{
	size_t zeroByteCount = 0;
	for (size_t i = 0; i < SIZE_INT; ++i)
	{
		if (reinterpret_cast<const unsigned char*>(&intUnion.integer)[i] == 0)
		{
			zeroByteCount++;
		}
	}
	return zeroByteCount;
}

// Функция для вывода информации о байтах числа (нулевой, не нулевой)
void PrintByteInfo(IntUnion const& intUnion)
{
	std::cout << "Информация о байтах числа:" << std::endl;
	for (size_t i = 0; i < SIZE_INT; ++i)
	{
		if (reinterpret_cast<const unsigned char*>(&intUnion.integer)[i] == 0)
		{
			std::cout << "Байт " << i << ": нулевой" << std::endl;
		}
		else 
		{
			std::cout << "Байт " << i << ": не нулевой" << std::endl;
		}
	}
}

int main() 
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	IntUnion intUnion;

	InputInteger(intUnion);

	std::cout << "Количество нулевых байтов: " << CountZeroBytes(intUnion) << std::endl;

	PrintByteInfo(intUnion);

	return 0;
}
