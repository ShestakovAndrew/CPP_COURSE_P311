#include <iostream>
#include <ctime>

#include "MatrixLibrary.h"

int** SumMatrix(int** matrix1, int** matrix2, size_t rows, size_t cols)
{
	int** resultMatrix = new int* [rows];
	for (size_t i = 0; i < rows; ++i)
	{
		resultMatrix[i] = new int[cols];
		for (size_t j = 0; j < cols; ++j) 
		{
			resultMatrix[i][j] = matrix1[i][j] + matrix2[i][j];
		}
	}
	return resultMatrix;
}

int main() 
{
	setlocale(LC_ALL, "rus");
	srand((unsigned int)time(0));

	size_t rows, cols;
	std::cout << "Введите количество строк: ";
	std::cin >> rows;
	std::cout << "Введите количество столбцов: ";
	std::cin >> cols;

	// Создание и заполнение первой матрицы
	int** matrix1 = CreateAndFillMatrix(rows, cols);
	std::cout << "Первая матрица:" << std::endl;
	PrintMatrix(matrix1, rows, cols);

	// Создание и заполнение второй матрицы
	int** matrix2 = CreateAndFillMatrix(rows, cols);
	std::cout << "Вторая матрица:" << std::endl;
	PrintMatrix(matrix2, rows, cols);

	// Суммирование массивов
	int** sumMatrix = SumMatrix(matrix1, matrix2, rows, cols);
	std::cout << "Сумма матриц:" << std::endl;
	PrintMatrix(sumMatrix, rows, cols);

	// Освобождение памяти
	for (size_t i = 0; i < rows; ++i) 
	{
		delete[] matrix1[i];
		delete[] matrix2[i];
		delete[] sumMatrix[i];
	}
	delete[] matrix1;
	delete[] matrix2;
	delete[] sumMatrix;

	return 0;
}
