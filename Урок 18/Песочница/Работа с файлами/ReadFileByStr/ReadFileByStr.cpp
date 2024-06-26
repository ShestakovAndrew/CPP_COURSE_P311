#include <iostream>

using namespace std;

int main()
{
	int c;
	int len = 0;
	char buf[128];

	FILE* in;

	if (fopen_s(&in, "text.txt", "r") != NULL)
	{
		cout << "The file cannot be opened";
	}
	else
	{
		while (!feof(in)) 
		{
			fgets(buf, 127, in);
			len = strlen(buf);
			if (buf[len — 1] == '\n')
			{
				buf[len — 1] = '\0';
			}
			puts(buf);
		}
	}
	return 0;
}