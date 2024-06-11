#include <iostream>
#include <numeric>
#include <algorithm>

struct Fraction 
{
	int numerator;
	int denominator;
};

// Функция для сокращения дроби
void Simplify(Fraction& frac) 
{
	int gcd = std::gcd(frac.numerator, frac.denominator); //Наибольший общий делитель
	frac.numerator /= gcd;
	frac.denominator /= gcd;
}

// Функция для перевода дроби в смешанное число
void ToMixedNumber(Fraction const& frac)
{
	if (abs(frac.numerator) >= abs(frac.denominator)) 
	{
		int wholePart = frac.numerator / frac.denominator;
		int newNumerator = frac.numerator % frac.denominator;
		std::cout << wholePart << " " << newNumerator << "/" << frac.denominator << std::endl;
	}
	else 
	{
		std::cout << frac.numerator << "/" << frac.denominator << std::endl;
	}
}

// Функции для арифметических операций
Fraction Add(Fraction const& f1, Fraction const& f2)
{
	Fraction result;
	result.numerator = f1.numerator * f2.denominator + f1.denominator * f2.numerator;
	result.denominator = f1.denominator * f2.denominator;
	Simplify(result);
	return result;
}

Fraction Subtract(Fraction const& f1, Fraction const& f2)
{
	Fraction result;
	result.numerator = f1.numerator * f2.denominator - f1.denominator * f2.numerator;
	result.denominator = f1.denominator * f2.denominator;
	Simplify(result);
	return result;
}

Fraction Multiply(Fraction const& f1, Fraction const& f2)
{
	Fraction result;
	result.numerator = f1.numerator * f2.numerator;
	result.denominator = f1.denominator * f2.denominator;
	Simplify(result);
	return result;
}

Fraction Divide(Fraction const& f1, Fraction const& f2)
{
	Fraction result;
	result.numerator = f1.numerator * f2.denominator;
	result.denominator = f1.denominator * f2.numerator;
	Simplify(result);
	return result;
}

int main() 
{
	setlocale(LC_ALL, "rus");

	Fraction frac1; // Создаем дробь с нулевыми значениями
	frac1.numerator = 3;
	frac1.denominator = 8;

	Fraction frac2; // Создаем дробь с нулевыми значениями
	frac2.numerator = 1;
	frac2.denominator = 2;

	std::cout << "Дробь 1: ";
	ToMixedNumber(frac1);

	std::cout << "Дробь 2: ";
	ToMixedNumber(frac2);

	std::cout << "Сумма: ";
	ToMixedNumber(Add(frac1, frac2));

	std::cout << "Разность: ";
	ToMixedNumber(Subtract(frac1, frac2));

	std::cout << "Умножение: ";
	ToMixedNumber(Multiply(frac1, frac2));

	std::cout << "Деление: ";
	ToMixedNumber(Divide(frac1, frac2));

	return 0;
}
