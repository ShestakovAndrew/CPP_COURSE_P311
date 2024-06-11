#include <iostream>

#include "Windows.h"

union IntUnion 
{
	int32_t signedInt;
	uint32_t unsignedInt;
};

int main() 
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	IntUnion intUnion;

	// Запись значения как знаковому целому
	intUnion.signedInt = -123456;

	std::cout << "Знаковое целое: " << intUnion.signedInt << std::endl;
	std::cout << "Беззнаковое целое: " << intUnion.unsignedInt << std::endl;

	// Запись значения как беззнаковому целому
	intUnion.unsignedInt = 1234567890;

	std::cout << "Знаковое целое: " << intUnion.signedInt << std::endl;
	std::cout << "Беззнаковое целое: " << intUnion.unsignedInt << std::endl;

	return 0;
}
