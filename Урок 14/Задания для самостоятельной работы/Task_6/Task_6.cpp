#include <iostream>
#include <cstring>

// Функция для подсчета количества вхождений заданного слова в текст
size_t CountWordOccurrences(const char* text, const char* word) 
{
	size_t count = 0;
	const char* temp = text;

	while ((temp = strstr(temp, word)) != nullptr) 
	{
		count++;
		temp += strlen(word); // Сдвигаем указатель вперед на длину слова
	}

	return count;
}

// Функция для подсчета количества предложений в тексте
size_t CountSentences(const char* text)
{
	size_t count = 0;
	while (*text) 
	{
		if (*text == '.' || *text == '?' || *text == '!') 
		{
			count++;
		}
		text++;
	}
	return count;
}

// Функция для подсчета количества точек и запятых
size_t CountPunctuationMarks(const char* text)
{
	size_t count = 0;
	while (*text) 
	{
		if (*text == '.' || *text == ',') 
		{
			count++;
		}
		text++;
	}
	return count;
}

// Функция для переворачивания текста целиком
void ReverseText(char* text) 
{
	size_t len = strlen(text);

	for (size_t i = 0; i < len / 2; i++)
	{
		std::swap(text[i], text[len - i - 1]);
	}
}

// Функция для переворачивания каждого предложения в тексте
void ReverseSentences(char* text) 
{
	char* start = text;
	char* end;
	while ((end = strchr(start, '.')) != nullptr) 
	{
		std::reverse(start, end);
		start = end + 1;
	}
	std::reverse(start, text + strlen(text)); // Переворот последнего предложения
}

int main() 
{
	char text[] = "Hello, world. This is a test. Test is successful.";
	const char word[] = "test";

	std::cout << "Word occurrences: " << CountWordOccurrences(text, word) << std::endl;
	std::cout << "Number of sentences: " << CountSentences(text) << std::endl;
	std::cout << "Punctuation marks: " << CountPunctuationMarks(text) << std::endl;

	ReverseText(text);
	std::cout << "Reversed text: " << text << std::endl;

	// Возвращаем текст в исходное состояние перед переворачиванием предложений
	ReverseText(text);
	ReverseSentences(text);
	std::cout << "Reversed sentences: " << text << std::endl;

	return 0;
}
