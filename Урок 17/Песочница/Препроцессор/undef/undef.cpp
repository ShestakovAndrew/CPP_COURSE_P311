#include <iostream>

using namespace std;

#define NAME "Шестаков Андрей"
#undef NAME
#define NAME "Мухлыгин Роман"
#undef NAME
#define NAME "Романова Татьяна"


int main()
{
	setlocale(LC_ALL, "rus");

	cout << "My name is " << NAME << endl;

	return 0;
}