#include <iostream>
#include <cstring>

void RemoveChar(char* str, size_t index) 
{
	if (index >= 0 && index < strlen(str)) 
	{
		// Сдвигаем символы после удаляемого на одну позицию влево
		for (size_t i = index; str[i] != '\0'; i++) 
		{
			str[i] = str[i + 1];
		}
	}
}

int main() 
{
	setlocale(LC_ALL, "rus");

	char myString[] = "Hello, world!";
	size_t charIndex = 7;

	std::cout << "Исходная строка: " << myString << std::endl;

	RemoveChar(myString, charIndex);

	std::cout << "Строка после удаления: " << myString << std::endl;

	return 0;
}
