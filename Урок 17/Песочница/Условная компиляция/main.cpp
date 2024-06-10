#include <iostream>

//#if <константное_выражение>
//#ifdef <идентификатор>
//#ifndef <идентификатор>
//#else
//#endif
//#elif

// Определение макросов
#define FEATURE_A
#define VALUE 10

#define ARRAY_FLAG


int main() 
{
	// Пример использования #if
#if VALUE > 5
	std::cout << "VALUE больше 5" << std::endl;
#else
	std::cout << "VALUE меньше или равно 5" << std::endl;
#endif

	// Пример использования #ifdef
#ifdef FEATURE_A
	std::cout << "FEATURE_A включен" << std::endl;
#else
	std::cout << "FEATURE_A не включен" << std::endl;
#endif

	// Пример использования #ifndef
#ifndef FEATURE_B
	std::cout << "FEATURE_B не включен" << std::endl;
#else
	std::cout << "FEATURE_B включен" << std::endl;
#endif

	// Пример использования #elif
#if VALUE < 5
	std::cout << "VALUE меньше 5" << std::endl;
#elif VALUE == 10
	std::cout << "VALUE равно 10" << std::endl;
#else
	std::cout << "VALUE больше 5, но не равно 10" << std::endl;
#endif

#ifdef ARRAY_FLAG
	int arr[30] = { 1, 21 };
	std::cout << arr[0] << " " << arr[1];
#else
	std::cout << "Array is not defined!";
#endif

	return 0;
}