#include <iostream>

using namespace std;

int main()
{
	const int n = 5;
	int arr[n];

	FILE* out;
	
	if (fopen_s(&out, "b_data.dat", "wb") != NULL)
	{
		cout << "The file cannot be opened";
	}
	else
	{
		for (int i = 0; i < 10; i++) //Записываем массив целых чисел
		{
			fwrite(&arr[i], sizeof(int), 1, out);
		}
	}
	return 0;
}