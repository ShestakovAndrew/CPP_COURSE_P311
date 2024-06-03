#include <iostream>
#include <ctime>

#include "MatrixLibrary.h"

//Написать программу, которая удаляет из
//двухмерного массива, заполненного случайными числами
//строки, содержащие нулевые элементы.

const size_t MAX_ROWS = 10;
const size_t MAX_COLS = 5;

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

	int** matrix = CreateAndFillMatrix(MAX_ROWS, MAX_COLS);

	std::cout << "Исходный массив: " << std::endl;
	PrintMatrix(matrix, MAX_ROWS, MAX_COLS);

	size_t rows = RemoveZeroRows(matrix, MAX_ROWS, MAX_COLS);

	std::cout << "Массив после удаления строк с нулями: " << std::endl;
	PrintMatrix(matrix, rows, MAX_COLS);

	for (size_t i = 0; i < MAX_ROWS; ++i)
	{
		delete[] matrix[i];
	}
	delete[] matrix;

	return 0;
}
