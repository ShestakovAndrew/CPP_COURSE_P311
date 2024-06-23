#include <iostream>

using namespace std;

int main()
{
	const int n = 5;
	int arr[n];
	FILE* out;

	for (int i = 0; i < n; i++)
	{
		arr[i] = i + 5;
	}

	if ((fopen_s(&out, "outfile.txt", "w")) != NULL)
	{
		cout << "The file could not be created";
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			fprintf(out, "%1d ", arr[i]);
			fprintf(out, "\n");
		}
		
		//после окончания работы рекомендуется закрыть явно
		fclose(out);
	}
	return 0;
}