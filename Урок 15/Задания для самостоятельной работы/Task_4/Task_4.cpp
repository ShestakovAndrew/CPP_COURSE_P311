#include <iostream>
#include <ctime>

//Написать функцию, удаляющую строку двухмерного массива по указанному номеру.

const size_t MAX_ROWS = 5;
const size_t MAX_COLS = 3;
const size_t DELETE_ROW_POSITION = 3;

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

// Функция добавления строки в двумерный массив на заданную позицию
size_t RemoveRowToPosition(
	int**& matrix,
	size_t rows,
	size_t cols,
	size_t rowToRemove
)
{
	// Проверяем, что позиция находится в допустимом диапазоне
	if (rowToRemove < 0 || rowToRemove > rows)
	{
		std::cout << "Неверная позиция для вставки строки." << std::endl;
		return -1;
	}

	 // Удаляем строку по указанному номеру
	delete[] matrix[rowToRemove];

	// Сдвигаем оставшиеся строки вверх, чтобы заполнить пустоту
	for (size_t i = rowToRemove; i < rows - 1; ++i) 
	{
		matrix[i] = matrix[i + 1];
	}

	// Уменьшаем количество строк
	--rows;

	// Создаем новый массив указателей на одну строку меньше
	int** newMatrix = new int*[rows];

	// Копируем адреса оставшихся строк в новую матрицу
	for (size_t i = 0; i < rows; ++i) 
	{
		newMatrix[i] = matrix[i];
	}

	// Удаляем старый массив указателей
	delete[] matrix;

	// Обновляем указатель на массив указателей
	matrix = newMatrix;

	return rows;
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

	// Добавляем новую строку в матрицу на заданную позицию
	size_t newRows = RemoveRowToPosition(matrix, MAX_ROWS, MAX_COLS, DELETE_ROW_POSITION);

	std::cout << "Матрица после удаления строки в позиции " << DELETE_ROW_POSITION << ":" << std::endl;
	PrintMatrix(matrix, newRows, MAX_COLS);

	// Освобождаем память
	for (size_t i = 0; i < newRows; ++i)
	{
		delete[] matrix[i];
	}
	delete[] matrix;

	return 0;
}
