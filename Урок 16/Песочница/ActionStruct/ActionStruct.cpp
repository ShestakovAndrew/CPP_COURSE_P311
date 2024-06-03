#include <iostream>
#include <string>

/*
 Описание структуры с именем Date.
*/
struct Date
{
	int day;
	int month;
	int year;
	std::string monthName; //Как ещё мы можем задать месяцы?
};

/*
 Объект структуры передаётся в функцию по значению
 Возможна также передача по ссылке и по указателю
*/
void ShowDate(Date date) // Может лучше как то подругому передать?
{
	std::cout << date.day << " ";
	std::cout << date.month << " ";
	std::cout << date.year << " ";
	std::cout << date.monthName << std::endl << std::endl;
}

Date PutDate()
{
	Date temp;

	std::cout << "DAY ? ";
	std::cin >> temp.day;
	std::cout << "MONTH ? ";
	std::cin >> temp.month;
	std::cout << "YEAR ? ";
	std::cin >> temp.year;
	std::cout << "MONTH NAME ? ";
	std::cin >> temp.monthName;

	return temp;
}


bool IsLeapYear(int checkYear) // проверка на високосный год  
{
	// год не високосный, если условие истина
	if (checkYear % 4 != 0 || ((checkYear % 100 == 0) && (checkYear % 400 != 0))) 
	{
		return false;
	}

	// если условие ложно год високосный
	return true;
}

struct
{
	int x;
	int* y;
} *p; // p - указатель на структуру.

int main()
{
	Date date = { 2, 5, 1976, "July" };
	//Date date = PutDate();

	// Указатель p указывает на структуру типа date
	Date* datePtr = nullptr;

	// Показ содержимого структуры на экран
	// (обращение через объект)
	std::cout << date.day << " ";
	std::cout << date.month << " ";
	std::cout << date.year << " ";
	std::cout << date.monthName << std::endl << std::endl;
	// ShowDate(date);

	// запись адреса объекта структуры в указатель
	datePtr = &date;

	// Показ содержимого структуры на экран (обращение через указатель)
	// -> состоит из минуса - и знака больше >
	std::cout << datePtr->day << " ";
	std::cout << datePtr->month << " ";
	std::cout << datePtr->year << " ";
	std::cout << datePtr->monthName << std::endl << std::endl;


	int tempYear = 2024;
	Date curDate = { 12, 5, tempYear, "May" };


	if (IsLeapYear(curDate.year) == true) //Как упростить? А ещё?
	{
		std::cout << tempYear << " is leap year\n";
	}
	else 
	{
		std::cout << tempYear << " is NOT leap year\n";
	}

	return 0;
}