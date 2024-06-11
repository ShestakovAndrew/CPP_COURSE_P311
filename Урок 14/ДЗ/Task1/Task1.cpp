#include <iostream>
#include <string>

std::string RemoveChar(std::string str, size_t index)
{
	if (index >= 0 && index < str.length()) 
	{
		str.erase(index, 1); // Удаляем символ с заданным индексом
	}
	return str;
}

int main() 
{
	std::string myString = "Hello, world!";
	size_t charIndex = 7;

	std::cout << "Исходная строка: " << myString << std::endl;

	myString = RemoveChar(myString, charIndex);

	std::cout << "Строка после удаления: " << myString << std::endl;

	return 0;
}
