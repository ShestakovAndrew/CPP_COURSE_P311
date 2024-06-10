#include <iostream>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int main() 
{
	int num1 = 10;
	int num2 = 5;

	std::cout << "Меньшее число: " << MIN(num1, num2) << std::endl;

	return 0;
}
