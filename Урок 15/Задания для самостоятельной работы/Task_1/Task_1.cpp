#include <iostream>
#include <ctime>

//Написать функцию, добавляющую строку
//двухмерному массиву в конец.

const size_t MAX_ROWS = 2;
const size_t MAX_COLS = 3;

// Функция для заполнения массива случайными числами
void FillMatrix(int** matrix, size_t rows, size_t cols)
{
	for (size_t i = 0; i < rows; ++i)
	{
		for (size_t j = 0; j < cols; ++j)
		{
			matrix[i][j] = rand() % 10; // Для примера, числа от 0 до 9
		}
	}
}

// Функция для печати массива
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

// Функция добавления строки в конец двумерного массива
size_t AddRowToBack(int**& matrix, size_t rows, size_t cols, const int* newRowValues)
{
	// Создаем новый массив с размером на одну строку больше
	int** newMatrix = new int* [rows + 1];

	// Копируем существующие строки в новую матрицу
	for (size_t i = 0; i < rows; ++i)
	{
		newMatrix[i] = new int[cols];
		for (size_t j = 0; j < cols; ++j)
		{
			newMatrix[i][j] = matrix[i][j];
		}
	}

	// Добавляем новую строку в конец новой матрицы
	newMatrix[rows] = new int[cols];
	for (size_t j = 0; j < cols; ++j) 
	{
		newMatrix[rows][j] = newRowValues[j];
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
	srand(static_cast<unsigned int>(time(NULL)));

	// Выделение памяти
	int** matrix = new int* [MAX_ROWS];
	for (size_t i = 0; i < MAX_ROWS; ++i)
	{
		matrix[i] = new int[MAX_COLS];
	}

	// Заполнение матрицы
	FillMatrix(matrix, MAX_ROWS, MAX_COLS);

	std::cout << "Исходная матрица: " << std::endl;
	PrintMatrix(matrix, MAX_ROWS, MAX_COLS);

	// Значения для новой строки
	int newRowValues[MAX_COLS] = { 1, 1, 1 };

	// Добавляем новую строку в матрицу
	size_t newRows = AddRowToBack(matrix, MAX_ROWS, MAX_COLS, newRowValues);

	std::cout << "Матрица после добавления строки в конец: " << std::endl;
	PrintMatrix(matrix, newRows, MAX_COLS);

	// Освобождение памяти
	for (size_t i = 0; i < newRows; ++i)
	{
		delete[] matrix[i];
	}
	delete[] matrix;

	return 0;
}
