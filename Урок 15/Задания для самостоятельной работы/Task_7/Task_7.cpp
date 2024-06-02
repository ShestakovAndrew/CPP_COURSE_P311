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

// Функция умножения двух матриц
int** MultiplyMatrices(int** A, int** B, size_t M, size_t N, size_t K)
{
	// Создаем матрицу C размером MxK для результата
	int** C = new int* [M];
	for (size_t i = 0; i < M; ++i)
	{
		C[i] = new int[K]();
	}

	// Выполняем умножение матриц
	for (size_t i = 0; i < M; ++i)
	{
		for (size_t j = 0; j < K; ++j)
		{
			for (size_t n = 0; n < N; ++n)
			{
				C[i][j] += A[i][n] * B[n][j];
			}
		}
	}

	return C;
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

int main() 
{
	setlocale(LC_ALL, "rus");
	srand((unsigned int)time(0));

	size_t M = 2, N = 3, K = 4;

	// Создание матрицы A размером MxN
	int** A = CreateAndFillMatrix(M, N);
	std::cout << "Матрица A:" << std::endl;
	PrintMatrix(A, M, N);

	// Создание матрицы B размером MxN
	int** B = CreateAndFillMatrix(N, K);
	std::cout << "Матрица B:" << std::endl;
	PrintMatrix(B, N, K);

	// Умножение матриц A и B
	int** C = MultiplyMatrices(A, B, M, N, K);

	// Вывод результата
	std::cout << "Матрица C (результат умножения A и B):" << std::endl;
	PrintMatrix(C, M, K);

	// Освобождение памяти
	for (int i = 0; i < M; ++i) 
	{
		delete[] A[i];
		delete[] C[i];
	}
	delete[] A;
	delete[] C;

	for (int i = 0; i < N; ++i) 
	{
		delete[] B[i];
	}
	delete[] B;

	return 0;
}
