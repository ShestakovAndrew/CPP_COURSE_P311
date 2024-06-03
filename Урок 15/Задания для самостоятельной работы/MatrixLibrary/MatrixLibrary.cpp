#include <iostream>

int** CreateAndFillMatrix(size_t rows, size_t cols)
{
	int** arr = new int* [rows];
	for (size_t i = 0; i < rows; ++i)
	{
		arr[i] = new int[cols];
		for (size_t j = 0; j < cols; ++j)
		{
			arr[i][j] = rand() % 10;
		}
	}
	return arr;
}

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