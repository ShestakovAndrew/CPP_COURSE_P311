#include <iostream>
#include <cstdlib>
#include <ctime>

//Задание 1. Написать программу, которая удаляет из
//двухмерного массива, заполненного случайными числами
//строки, содержащие нулевые элементы.

const size_t MAX_ROWS = 10;
const size_t MAX_COLS = 5;

// Функция для заполнения массива случайными числами
void FillArray(int** arr, size_t rows, size_t cols)
{
	for (size_t i = 0; i < rows; ++i) 
	{
		for (size_t j = 0; j < cols; ++j)
		{
			arr[i][j] = rand() % 10; // Для примера, числа от 0 до 9
		}
	}
}

// Функция для печати массива
void PrintArray(int** arr, size_t rows, size_t cols)
{
	for (size_t i = 0; i < rows; ++i)
	{
		for (size_t j = 0; j < cols; ++j)
		{
			std::cout << arr[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

// Функция для удаления строк с нулями
size_t RemoveZeroRows(int**& arr, size_t rows, size_t cols)
{
	size_t countNonZeroRows = 0;
	for (size_t i = 0; i < rows; ++i)
	{
		bool hasZero = false;
		for (size_t j = 0; j < cols; ++j)
		{
			if (arr[i][j] == 0) 
			{
				hasZero = true;
				break;
			}
		}
		if (!hasZero) 
		{
			if (countNonZeroRows != i) 
			{
				for (size_t k = 0; k < cols; ++k) 
				{
					arr[countNonZeroRows][k] = arr[i][k];
				}
			}
			countNonZeroRows++;
		}
	}
	return countNonZeroRows;
}

int main() 
{
	setlocale(LC_ALL, "rus");
	srand(static_cast<unsigned int>(time(NULL)));

	// Выделение памяти
	int** arr = new int* [MAX_ROWS];
	for (size_t i = 0; i < MAX_ROWS; ++i) 
	{
		arr[i] = new int[MAX_COLS];
	}

	// Заполнение массива
	FillArray(arr, MAX_ROWS, MAX_COLS);

	std::cout << "Исходный массив: " << std::endl;
	PrintArray(arr, MAX_ROWS, MAX_COLS);

	// Удаление строк и получение нового количества строк
	size_t rows = RemoveZeroRows(arr, MAX_ROWS, MAX_COLS);

	std::cout << "Массив после удаления строк с нулями: " << std::endl;
	PrintArray(arr, rows, MAX_COLS);

	// Освобождение памяти
	for (size_t i = 0; i < MAX_ROWS; ++i) 
	{
		delete[] arr[i];
	}
	delete[] arr;

	return 0;
}
