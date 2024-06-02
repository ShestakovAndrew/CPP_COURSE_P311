#include <iostream>
#include <ctime>

//Написать функцию, добавляющую строку
//двухмерному массиву в указанную позицию.

const size_t MAX_ROWS = 5;
const size_t MAX_COLS = 3;
const size_t ROW_POSITION = 3;

// Функция для заполнения матрицы случайными числами
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

// Функция добавления строки в двумерный массив на заданную позицию
size_t AddRowToPosition(
	int**& matrix,
	size_t rows,
	size_t cols,
	const int* newRowValues,
	size_t position
) 
{
	// Проверяем, что позиция находится в допустимом диапазоне
	if (position < 0 || position > rows) 
	{
		std::cout << "Неверная позиция для вставки строки." << std::endl;
		return -1;
	}

	// Создаем новый массив с размером на одну строку больше
	int** newMatrix = new int* [rows + 1];

	// Копируем строки до позиции вставки
	for (size_t i = 0; i < position; ++i)
	{
		newMatrix[i] = new int[cols];
		for (size_t j = 0; j < cols; ++j)
		{
			newMatrix[i][j] = matrix[i][j];
		}
	}

	// Вставляем новую строку
	newMatrix[position] = new int[cols];
	for (int j = 0; j < cols; ++j) 
	{
		newMatrix[position][j] = newRowValues[j];
	}

	// Копируем оставшиеся строки
	for (size_t i = position; i < rows; ++i) 
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

	// Добавляем новую строку в матрицу на заданную позицию
	size_t newRows = AddRowToPosition(matrix, MAX_ROWS, MAX_COLS, newRowValues, ROW_POSITION);

	std::cout << "Матрица после добавления строки в позицию " << ROW_POSITION << ":" << std::endl;
	PrintMatrix(matrix, newRows, MAX_COLS);

	// Освобождаем память
	for (int i = 0; i < newRows; ++i)
	{
		delete[] matrix[i];
	}
	delete[] matrix;

	return 0;
}
