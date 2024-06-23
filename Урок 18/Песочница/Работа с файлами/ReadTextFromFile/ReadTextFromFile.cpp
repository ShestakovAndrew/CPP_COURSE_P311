#include <iostream>
using namespace std;
int main()
{
	int c;
	int len = 0, cnt = 0;
	FILE* in;

	if (fopen_s(&in, "text.txt", "r") != NULL)
	{
		cout << "The file cannot be opened";
	}
	else
	{
		while (!feof(in)) 
		{
			c = fgetc(in);
			if (c == '\n') 
			{
				cnt++;
				cout << "String " << cnt << " length=" << len << "\n";
				len = 0;
			}
			else
			{
				len++;
			}
		}
		if (len)
		{
			cnt++;
			cout << "String " << cnt << " length=" << len << "\n";
		}
	}

	return 0;
}