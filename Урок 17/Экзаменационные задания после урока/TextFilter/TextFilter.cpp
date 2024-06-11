#include <iostream>
#include <string>
#include <cctype>
#include <vector>

// Функция для проверки наличия символа в строке
bool IsSymbolContain(std::string const& str, char c)
{
	return str.find(c) != std::string::npos;
}

// Функция для фильтрации текста по заданному набору символов
void FilterText(std::string& text, std::string const& filterSet)
{
	for (char& c : text) 
	{
		if (IsSymbolContain(filterSet, c))
		{
			c = ' ';
		}
	}
}

int main()
{
	std::string text;
	std::cout << "Введите текст: ";
	std::getline(std::cin, text);

	std::vector<std::string> filters = 
	{
		"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ",
		"абвгдеёжзийклмнопрстуфхцчшщъыьэюяАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ",
		".,;:!?",
		"0123456789"
	};

	bool filtersActive[] = { false, false, false, false }; // Флаги активности фильтров

	// Ввод и обработка фильтров
	for (int i = 0; i < 4; ++i) 
	{
		char choice;
		std::cout << "Применить фильтр для ";
		switch (i) 
		{
		case 0:
			std::cout << "символов латинского алфавита? (y/n): ";
			break;
		case 1:
			std::cout << "символов кириллицы? (y/n): ";
			break;
		case 2:
			std::cout << "символов пунктуации? (y/n): ";
			break;
		case 3:
			std::cout << "цифр? (y/n): ";
			break;
		}
		std::cin >> choice;

		if (choice == 'y' || choice == 'Y') 
		{
			filtersActive[i] = true;
		}
	}

	// Применение фильтров
	for (int i = 0; i < 4; ++i) 
	{
		if (filtersActive[i]) 
		{
			FilterText(text, filters[i]); // true для удаления символов
		}
	}

	std::cout << "Отфильтрованный текст: " << text << std::endl;

	return 0;
}
