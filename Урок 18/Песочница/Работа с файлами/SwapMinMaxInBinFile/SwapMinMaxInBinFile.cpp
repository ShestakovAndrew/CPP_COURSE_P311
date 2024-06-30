#include <iostream>

using namespace std;

int main()
{
	int n = 10, imax, imin, i;
	int* a, max, min;

	FILE* f;

	//1.
	if (fopen_s(&f, "b_data.dat", "wb") != NULL)
	{
		cout << "The file cannot be opened";
	}
	else
	{
		for (i = 0; i < n; i++)
		{
			fwrite(&i, sizeof(int), 1, f);
		}
		fclose(f);
	}

	//2.
	if (fopen_s(&f, "b_data.dat", "rb") != NULL)
	{
		cout << "The file cannot be opened";
	}
	else
	{
		a = new int[n];

		fread(a, sizeof(int), n, f);

		//3.
		for (imax = imin = 0, max = min = a[0], i = 1; i < n; i++)
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

		//4. 
		fseek(f, sizeof(int) + imax * sizeof(double), SEEK_SET);
		fwrite(&min, sizeof(double), 1, f);

		fseek(f, sizeof(int) + imin * sizeof(double), SEEK_SET);
		fwrite(&max, sizeof(double), 1, f);

		fclose(f);
		delete[]a;
	}

	return 0;
}