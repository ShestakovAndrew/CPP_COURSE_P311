#include <iostream>

using namespace std;

struct statusField
{
	unsigned int JS;
	unsigned int PHP;
	unsigned int Python;
} state1;

struct statusField
{
	unsigned int JS : 1;
	unsigned int PHP : 1;
	unsigned int Python : 1;

} state2;

struct fieldbite
{
	unsigned short field1 : 2;
	unsigned short field2 : 2;
	unsigned short field3 : 4;
} field;

struct Date 
{
	unsigned short nWeekDay : 3; // 0..7 (3 bits)
	unsigned short nMonthDay : 6; // 0..31 (6 bits)
	unsigned short nMonth : 5; // 0..12 (5 bits)
	unsigned short nYear : 8; // 0..100 (8 bits)
};

int main()
{
	std::cout << "Size of statusField: " << sizeof(statusField) << " bytes" << std::endl;
	std::cout << "Size of fieldbite: " << sizeof(fieldbite) << " bytes" << std::endl;
	std::cout << "Size of Date: " << sizeof(Date) << " bytes" << std::endl;
}

//int main()
//{
//	struct DateTime {
//		unsigned short DayNum : 5;
//		unsigned short MonthNum : 4;
//		unsigned short YearNum : 7;
//		unsigned short HourNum : 5;
//		unsigned short MinuteNum : 6;
//		unsigned short SecondNum : 6;
//	};
//	DateTime d;
//	int i
//		cout << "Input the day number (from 1 to 31):"
//		<< '\t';
//	cin >> i;
//	d.DayNum = i;
//	cout << "Input the month number (from 1 to 12):"
//		<< '\t';
//	cin >> i;
//	d.MonthNum = i;
//	cout << "Input Year (from 00 to 99) :" << '\t';
//	cin >> i;
//	d.YearNum = i;
//	cout << endl << "Input Hours (from 0 to 24):"
//		<< '\t';
//	cin >> i;
//	d.HourNum = i;
//	cout << "Input Minutes (from 0 tp60):" << '\t';
//	cin >> i;
//	d.MinuteNum = i;
//	cout << "Input Seconds (0-60):" << '\t';
//	cin >> i;
//	d.SecondNum = i;
//	cout << endl << "Date is: " << d.DayNum << "."
//		<< d.MonthNum << ".20" << d.YearNum << " ";
//	cout << d.HourNum << ":" << d.MinuteNum << ":"
//		<< d.SecondNum << endl;
//	cout << sizeof(d) << endl;
//	return 0;
//}

//int main()
//{
//	struct myInfo 
//	{
//		unsigned char part1 : 2;
//		unsigned char part2 : 3;
//		unsigned char part3 : 1;
//		unsigned char part4 : 1;
//		unsigned char mySymbol;
//	};
//	myInfo user1;
//	cout << "Size of my data is " << sizeof(user1);
//	return 0;
//}