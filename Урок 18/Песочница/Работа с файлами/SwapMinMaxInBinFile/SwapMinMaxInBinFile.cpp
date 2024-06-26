#include <iostream>
using namespace std;
int main()
{
	const char* path = "D:\\examples\\b_data.dat";
	int n = 10, imax, imin, i;
	int* a, max, min;
	FILE* f;
	if (fopen_s(&f, path, "wb") != NULL)
		cout << "The file cannot be opened";
	else
	{
		for (i = 0; i < n; i++)
		{
			fwrite(&i, sizeof(int), 1, f);
		}
		fclose(f);
	}
	if (fopen_s(&f, path, "rb") != NULL)
		cout << "The file cannot be opened";
	else
	{
		a = new int[n];
		fread(a, sizeof(int), n, f);
		for (imax = imin = 0, max = min = a[0], i = 1;
			i < n; i++)
		{
			if (a[i] > max)
			{
				max = a[i];
				imax = i;
			}
			if (a[i] < min)
			{
				min = a[i];
				imin = i;
			}
		}
		fseek(f, sizeof(int) + imax * sizeof(double),
			SEEK_SET);
		fwrite(&min, sizeof(double), 1, f);
		fseek(f, sizeof(int) + imin * sizeof(double),
			SEEK_SET);
		fwrite(&max, sizeof(double), 1, f);
		fclose(f);
		delete[]a;
	}
	return 0;
}