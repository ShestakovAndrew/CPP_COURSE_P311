#include <iostream>

struct Test
{
	int a;
	char b;
	double c;
	int* p;
};

int main() 
{
	int a;
	char b;
	double c;
	int* p;

	std::cout << "sizeof(int)=" << sizeof(a) << std::endl;
	std::cout << "sizeof(char)=" << sizeof(b) << std::endl;
	std::cout << "sizeof(double)=" << sizeof(c) << std::endl;
	std::cout << "sizeof(int*)=" << sizeof(p) << std::endl << std::endl;

	Test test = { '#',78 };

	std::cout << "sizeof(Test)=" << sizeof(Test) << std::endl;
	std::cout << "sizeof(test)=" << sizeof(test) << std::endl;
	//padding - выравнивание


	return 0;
}