#include <iostream>

struct ComplexNumber 
{
	double real;
	double imag;
};

// Сложение комплексных чисел
ComplexNumber add(const ComplexNumber& c1, const ComplexNumber& c2) 
{
	ComplexNumber result;
	result.real = c1.real + c2.real;
	result.imag = c1.imag + c2.imag;
	return result;
}

// Вычитание комплексных чисел
ComplexNumber subtract(const ComplexNumber& c1, const ComplexNumber& c2) 
{
	ComplexNumber result;
	result.real = c1.real - c2.real;
	result.imag = c1.imag - c2.imag;
	return result;
}

// Умножение комплексных чисел
ComplexNumber multiply(const ComplexNumber& c1, const ComplexNumber& c2) 
{
	ComplexNumber result;
	result.real = c1.real * c2.real - c1.imag * c2.imag;
	result.imag = c1.real * c2.imag + c1.imag * c2.real;
	return result;
}

// Деление комплексных чисел
ComplexNumber divide(const ComplexNumber& c1, const ComplexNumber& c2) 
{
	ComplexNumber result;
	double denominator = c2.real * c2.real + c2.imag * c2.imag;
	result.real = (c1.real * c2.real + c1.imag * c2.imag) / denominator;
	result.imag = (c1.imag * c2.real - c1.real * c2.imag) / denominator;
	return result;
}

// Вывод комплексного числа
void printComplex(const ComplexNumber& c) 
{
	if (c.imag >= 0) {
		std::cout << c.real << " + " << c.imag << "i" << std::endl;
	}
	else {
		std::cout << c.real << " - " << -c.imag << "i" << std::endl;
	}
}

int main() 
{
	ComplexNumber c1; // Создаем комплексное число без конструктора
	c1.real = 2;
	c1.imag = 3;

	ComplexNumber c2; // Создаем комплексное число без конструктора
	c2.real = 1;
	c2.imag = -2;

	std::cout << "Комплексное число 1: ";
	printComplex(c1);

	std::cout << "Комплексное число 2: ";
	printComplex(c2);

	std::cout << "nСумма: ";
	printComplex(add(c1, c2));

	std::cout << "Разность: ";
	printComplex(subtract(c1, c2));

	std::cout << "Умножение: ";
	printComplex(multiply(c1, c2));

	std::cout << "Деление: ";
	printComplex(divide(c1, c2));

	return 0;
}
