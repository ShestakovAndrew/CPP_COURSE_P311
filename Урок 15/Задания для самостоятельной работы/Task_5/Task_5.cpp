#include <iostream>
#include <cstdlib>
#include <ctime>

//Написать программу, которая удаляет из
//двухмерного массива, заполненного случайными числами
//строки, содержащие нулевые элементы.

const size_t MAX_ROWS = 10;
const size_t MAX_COLS = 5;

// Функция для заполнения матрицы случайными числами
void FillMatrix(int** matrix, size_t rows, size_t cols)
{
	for (size_t i = 0; i < rows; ++i)
	{
		for (size_t j = 0; j < cols; ++j)
		{
			matrix[i][j] = rand() % 10;
		}
	}
}

// Функция для печати матрицы
void PrintMatrix(int** matrix, size_t rows, size_t cols)
{
	for (size_t i = 0; i < rows; ++i)
	{
		for (size_t j = 0; j < cols; ++j)
		{
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

// Функция для удаления строк с нулями
size_t RemoveZeroRows(int**& matrix, size_t rows, size_t cols)
{
	size_t countNonZeroRows = 0;
	for (size_t i = 0; i < rows; ++i)
	{
		bool hasZero = false;
		for (size_t j = 0; j < cols; ++j)
		{
			if (matrix[i][j] == 0)
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
					matrix[countNonZeroRows][k] = matrix[i][k];
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
	srand((unsigned int)time(0));

	// Выделение памяти
	int** arr = new int* [MAX_ROWS];
	for (size_t i = 0; i < MAX_ROWS; ++i)
	{
		arr[i] = new int[MAX_COLS];
	}

	// Заполнение массива
	FillMatrix(arr, MAX_ROWS, MAX_COLS);

	std::cout << "Исходный массив: " << std::endl;
	PrintMatrix(arr, MAX_ROWS, MAX_COLS);

	// Удаление строк и получение нового количества строк
	size_t rows = RemoveZeroRows(arr, MAX_ROWS, MAX_COLS);

	std::cout << "Массив после удаления строк с нулями: " << std::endl;
	PrintMatrix(arr, rows, MAX_COLS);

	// Освобождение памяти
	for (size_t i = 0; i < MAX_ROWS; ++i)
	{
		delete[] arr[i];
	}
	delete[] arr;

	return 0;
}
