#include <iostream>

using namespace std;

int main()
{
	float a;
	FILE* in;

	if (fopen_s(&in, "infile.txt", "r") != NULL)
	{
		cout << "The file cannot be opened";
	}
	else
	{
		while (!feof(in)) 
		{
			fscanf_s(in, "%f", &a);
			cout << a << " ";
		}
	}
	return 0;
}