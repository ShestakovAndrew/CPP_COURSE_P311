#include <iostream>
#include <ctime>

#include "MatrixLibrary.h"

//Написать функцию, добавляющую строку
//двухмерному массиву в начало.

const size_t MAX_ROWS = 2;
const size_t MAX_COLS = 3;

// Функция добавления строки в начало матрицы
size_t AddRowToFront(int**& matrix, size_t rows, size_t cols, const int* newRowValues)
{
	// Создаем новую матрицы с размером на одну строку больше
	int** newMatrix = new int* [rows + 1];

	// Добавляем новую строку в начало новой матрицы
	newMatrix[0] = new int[cols];
	for (size_t j = 0; j < cols; ++j)
	{
		newMatrix[0][j] = newRowValues[j];
	}

	// Копируем существующие строки в новую матрицу со смещением на одну позицию вниз
	for (size_t i = 0; i < rows; ++i) 
	{
		newMatrix[i + 1] = new int[cols];
		for (size_t j = 0; j < cols; ++j)
		{
			newMatrix[i + 1][j] = matrix[i][j];
		}
	}

	// Освобождение памяти
	for (size_t i = 0; i < rows; ++i)
	{
		delete[] matrix[i];
	}
	delete[] matrix;

	// Обновляем указатель на массив указателей
	matrix = newMatrix;

	return ++rows;
}

int main() 
{
	setlocale(LC_ALL, "rus");
	srand((unsigned int)time(0));

	int** matrix = CreateAndFillMatrix(MAX_ROWS, MAX_COLS);

	std::cout << "Исходная матрица: " << std::endl;
	PrintMatrix(matrix, MAX_ROWS, MAX_COLS);

	// Значения для новой строки
	int newRowValues[MAX_COLS] = { 1, 1, 1 };

	size_t newRows = AddRowToFront(matrix, MAX_ROWS, MAX_COLS, newRowValues);

	std::cout << "Матрица после добавления строки в начало: " << std::endl;
	PrintMatrix(matrix, newRows, MAX_COLS);

	// Освобождение памяти
	for (size_t i = 0; i < newRows; ++i)
	{
		delete[] matrix[i];
	}
	delete[] matrix;

	return 0;
}
