#include <iostream>
#include <bitset>
#include <iomanip>

#include "Windows.h"

#define SIZE_INT 4

union IntUnion  
{
	int32_t integer;
	char bytes[SIZE_INT];
};

// Функция для ввода целого числа
void InputInteger(IntUnion & intUnion)
{
	std::cout << "Введите целое число: ";
	std::cin >> intUnion.integer;
}

// Функция для просмотра всех байтов числа
void ViewAllBytes(IntUnion const& intUnion)
{
	std::cout << "Все байты числа:" << std::endl;
	for (size_t index = 0; index < SIZE_INT; index++)
	{
		std::cout << std::hex 
			<< static_cast<int>(static_cast<unsigned char>(intUnion.bytes[index]))
			<< " ";
	}
	std::cout << std::dec << std::endl;
}

// Функция для просмотра выбранного байта числа
void ViewByte(IntUnion const& intUnion, size_t index)
{
	if (index < 0 || index >= SIZE_INT)
	{
		std::cerr << "Индекс байта должен быть от 0 до 3." << std::endl;
		return;
	}

	std::cout << "Байт " << index << ": "
		<< std::hex << static_cast<int>(static_cast<unsigned char>(intUnion.bytes[index]))
		<< std::dec << std::endl;
}

// Функция для вывода байтов числа в двоичном и шестнадцатеричном виде
void PrintBytesBinary(IntUnion const& intUnion)
{
	std::cout << "Байты числа в двоичном виде: ";
	for (size_t i = 0; i < SIZE_INT; ++i)
	{
		std::bitset<8> byte(intUnion.bytes[i]);
		std::cout << byte << " ";
	}
	std::cout << std::endl;
}

// Функция для вывода байтов числа в шестнадцатеричном виде
void PrintBytesHex(IntUnion const& intUnion)
{
	std::cout << "Байты числа в шестнадцатеричном виде: ";
	for (size_t i = 0; i < SIZE_INT; ++i)
	{
		std::cout << std::hex
			<< static_cast<int>(static_cast<unsigned char>(intUnion.bytes[i]))
			<< " ";
	}
	std::cout << std::dec << std::endl;
}

int main() 
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	IntUnion intUnion;

	InputInteger(intUnion);
	ViewAllBytes(intUnion);

	size_t index;
	std::cout << "Введите индекс байта (от 0 до 3): ";
	std::cin >> index;
	ViewByte(intUnion, index);

	PrintBytesBinary(intUnion);
	PrintBytesHex(intUnion);

	return 0;
}
