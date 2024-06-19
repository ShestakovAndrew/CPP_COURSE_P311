#include <iostream>

using namespace std;

int main()
{
	unsigned int x = 4;
	x = x << 1; // x должен стать равным 8
	cout << x;
	return 0;
}

//int main()
//{
//	int x, y, z, k;
//	x = 5;
//	y = 6;
//
//	k = x | y; // Операция 5 | 6
//	cout << k << " ";
//
//	x = 1;
//	y = 4;
//	z = 6;
//
//	k = x | y | z; // Операция 1 | 4 | 6
//	cout << k << " ";
//
//	x = 5;
//	y = 6;
//
//	k = x & y; // Операция 5 & 6
//	cout << k << " ";
//
//	x = 1;
//	y = 3;
//	z = 7;
//
//	k = x & y & z; // Операция 1 & 3 & 7
//	cout << k << " ";
//
//	x = 6;
//	y = 3;
//
//	k = x ^ y; // Операция 6 ^ 3
//	cout << k << " ";
//
//	return 0;
//}

//int main()
//{
//	int y = 02, x = 03, z = 01, k;
//
//	k = x | y & z; // Операция 1
//	cout << k << " ";
//
//	k = x | y & ~z; // Операция 2
//	cout << k << " ";
//
//	k = x ^ y & ~z; // Операция 3
//	cout << k << " ";
//
//	k = x & y && z; // Операция 4
//	cout << k << " ";
//
//	x = 1;
//	y = -1;
//	k = !x | x; // Операции 5
//	cout << k << " ";
//
//	k = -x | x; // Операции 6
//	cout << k << " ";
//
//	k = x ^ x; // Операции 7
//	cout << k << " ";
//
//	x <<= 3; // Операции 8
//	cout << x << " ";
//
//	y <<= 3; // Операции 9
//	cout << y << " ";
//
//	y >>= 3; // Операции 10
//	cout << y << " ";
//
//	return 0;
//}

//int main()
//{
//	union
//	{
//		short int component1;
//		int component2;
//		long int component3;
//	} myUnion; // объект объединения
// 
//	myUnion.component1 = 22;
//	cout << myUnion.component1 << endl;
// 
//	myUnion.Component3 = 222222222;
//	cout << myUnion.Component3 << endl;
//	cout << myUnion.component1 << endl; // снова обращаемся к component1
//	return 0;
//}