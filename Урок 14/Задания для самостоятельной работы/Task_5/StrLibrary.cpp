int mystrlen(const char* str)
{
	int length = 0;
	while (str[length] != '\0')
	{
		++length;
	}
	return length;
}

char* mystrcpy(char* str1, const char* str2)
{
	char* start = str1;
	while (*str2 != '\0')
	{
		*str1++ = *str2++;
	}
	*str1 = '\0'; //Добавляем нуль-терминатор в конец
	return start;
}

char* mystrcat(char* str1, const char* str2)
{
	char* start = str1;
	while (*str1 != '\0') // Находим конец первой строки
	{
		str1++;
	}
	mystrcpy(str1, str2);
	return start;
}

char* mystrchr(char* str, char s)
{
	while (*str != '\0')
	{
		if (*str == s) return str; // Возвращаем указатель на символ, если найден
		str++;
	}
	return nullptr;
}

char* mystrstr(char* str1, char* str2)
{
	if (*str2 == '\0') return str1; // Пустая строка всегда найдена

	char* p1 = str1;
	while (*p1 != '\0')
	{
		char* p1Begin = p1, * p2 = str2;

		while (*p1 && *p2 && *p1 == *p2)
		{
			p1++;
			p2++;
		}

		if (*p2 == '\0') return p1Begin; // Найдено полное совпадение

		p1 = p1Begin + 1; // Продолжаем поиск со следующего символа
	}

	return nullptr; // Подстрока не найдена
}