#include <iostream>
#include <cctype>

size_t GetCountWords(const char* str)
{
	size_t words = 0;
	bool isWord = false;

	if (str == nullptr) return 0; // Проверка на nullptr

	for (size_t i = 0; str[i] != '\0'; ++i) // Перебор символов строки до нуль-терминатора 
	{
		if (std::isspace(str[i])) // Если символ - пробел
		{
			isWord = false; // Конец слова
		}
		else if (!isWord) // Если символ не пробел и мы не в слове
		{
			isWord = true; // Начало нового слова
			++words; // Увеличиваем счетчик слов
		}
	}

	return words;
}

int main() {
	const char sentence[] = "Hello, World! This is a test sentence."; // Исходное предложение
	size_t wordCount = GetCountWords(sentence); // Подсчет слов в предложении
	std::cout << "The sentence contains " << wordCount << " words." << std::endl;
	return 0;
}
