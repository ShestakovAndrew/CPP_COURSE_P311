#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int main()
{
	FILE* out;

	if ((out = fopen("outfile.txt", "w")) == NULL)
	{
		cout << "The file could not be created!";
		return 1;
	}

	cout << "OK!";

	return 0;
}