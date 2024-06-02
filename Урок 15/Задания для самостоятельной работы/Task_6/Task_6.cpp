#include <iostream>
#include <ctime>

// Функция для создания и заполнения двумерного массива случайными числами
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

// Функция для суммирования двух двумерных массивов (матриц)
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
	srand((unsigned int)time(0)); // Инициализация генератора случайных чисел

	size_t rows, cols;
	std::cout << "Введите количество строк: ";
	std::cin >> rows;
	std::cout << "Введите количество столбцов: ";
	std::cin >> cols;

	// Создание и заполнение первой матрицы
	int** arr1 = CreateAndFillMatrix(rows, cols);
	std::cout << "Первая матрица:" << std::endl;
	PrintMatrix(arr1, rows, cols);

	// Создание и заполнение второй матрицы
	int** arr2 = CreateAndFillMatrix(rows, cols);
	std::cout << "Вторая матрица:" << std::endl;
	PrintMatrix(arr2, rows, cols);

	// Суммирование массивов
	int** sumMatrix = SumMatrix(arr1, arr2, rows, cols);
	std::cout << "Сумма матриц:" << std::endl;
	PrintMatrix(sumMatrix, rows, cols);

	// Освобождение памяти
	for (size_t i = 0; i < rows; ++i) 
	{
		delete[] arr1[i];
		delete[] arr2[i];
		delete[] sumMatrix[i];
	}
	delete[] arr1;
	delete[] arr2;
	delete[] sumMatrix;

	return 0;
}
