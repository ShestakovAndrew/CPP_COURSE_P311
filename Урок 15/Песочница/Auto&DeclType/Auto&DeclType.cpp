#include <iostream>

int minF1()
{
	int a = 20;
	int b = 10;

	return (a < b) ? a : b;
}

auto minF2()
{
	auto a = 70;
	auto b = 30;

	return (a < b) ? (a) : (b + 10.5);
}

int myF3()
{
	int a = 20;
	return a + 5;
}

auto checkDiscount(int prodID)
{
	if (prodID == 1) ы
	{
		return 10; // Как поправить ошибку?
	}
	else
	{
		return 20.5;
	}
}

int main()
{
	double myVar1;
	myVar1 = 4.2;

	double myVar2 = 4.2;
	auto myVar3 = 4.2;
	auto myExpr = 2 + 5;

	auto ptr = &myVar3;

	auto min1 = minF1();
	std::cout << min1 << std::endl;

	auto min2 = minF2();
	std::cout << min2 << std::endl;

	//---------------------------------------
	
	int x = 1.2;
	decltype(x) j;


	int x = 1.2;
	auto j = x;


	auto a1 = 0; // int
	decltype (a1) a2 = a1; // auto a2=a1;


	typedef decltype (a1) АTYPE; // АTYPE = int
	typedef auto АTYPE = a1; // ошибка
	using АTYPE = int; // аналог
	АTYPE а3 = 5;


	int y = 10;
	int& r = y;
	auto x = r;


	int y = 10;
	const int& r = y;
	auto x = r;


	int y = 10;
	int x = 5;
	int& r = y;
	decltype(r) var = x;
	var = 12;
	std::cout << x;


	int x = 5;
	decltype(x) j = x + 5;
	std::cout << j;


	decltype(myF3()) varF = 3;
	std::cout << varF;

	return 0;
}
