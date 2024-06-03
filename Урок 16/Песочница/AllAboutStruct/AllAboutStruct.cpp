#include <iostream>

/*
 Создание пользовательского типа данных
 (структуры) для хранения даты.
 Все данные, касающиеся одного объекта собраны
 вместе.
*/

struct Date1
{
	int day; // день
	int month; // месяц
	int year; // год
	int weekday; // день недели
	char monthName[15]; // название месяца
};

struct Date2
{
	int day; // День.
	char month[10]; // Месяц.
	int year; // Год.
};

struct Person
{
	char name[32]; // Имя, фамилия, отчество.
	char address[32]; // Домашний адрес.
	int zipcode[2]; // Почтовый индекс.
	int s_number[2]; // Код соц.обеспечения.
	int salary[4]; // Зарплата.
	Date2 birthdate; // Дата рождения.
	Date2 hiredate; // Дата поступления на работу.
};

int main() 
{
	// создание объекта с типом date и инициализация его при создании
	Date1 myBirthday = { 26, 2, 2001, 4, "January" };

	// показ содержимого объекта на экран
	// обращение к отдельному члену структуры
	// производится через оператор точка (.)
	std::cout << "________MY BIRTHDAY __________" << std::endl << std::endl;
	std::cout << "DAY " << myBirthday.day << std::endl << std::endl;
	std::cout << "MONTH " << myBirthday.month << std::endl << std::endl;
	std::cout << "YEAR " << myBirthday.year << std::endl << std::endl;
	std::cout << "WEEK DAY " << myBirthday.weekday << std::endl << std::endl;
	std::cout << "MONTH NAME " << myBirthday.monthName << std::endl << std::endl;

	// Создание пустого объекта
	Date1 yourBirthday;

	// Заполнение с клавиатуры
	std::cout << "DAY ? ";
	std::cin >> yourBirthday.day;
	std::cout << "MONTH ?";
	std::cin >> yourBirthday.month;
	std::cout << "YEAR ?";
	std::cin >> yourBirthday.year;
	std::cout << "WEEK DAY ?";
	std::cin >> yourBirthday.weekday;
	std::cout << "MONTH NAME ?";
	std::cin >> yourBirthday.monthName;

	std::cout << "______YOUR BIRTHDAY_____" << std::endl << std::endl;
	std::cout << "DAY " << yourBirthday.day << std::endl << std::endl;
	std::cout << "MONTH " << yourBirthday.month << std::endl << std::endl;
	std::cout << "YEAR " << yourBirthday.year << std::endl << std::endl;
	std::cout << "WEEK DAY " << yourBirthday.weekday << std::endl << std::endl;
	std::cout << "MONTH NAME " << yourBirthday.monthName << std::endl << std::endl;

	return 0;
}