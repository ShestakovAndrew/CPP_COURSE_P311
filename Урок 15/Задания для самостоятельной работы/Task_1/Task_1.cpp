#include <iostream>
#include <ctime>

//Написать функцию, добавляющую строку
//двухмерному массиву в конец.

const size_t MAX_ROWS = 2;
const size_t MAX_COLS = 3;

// Функция для заполнения массива случайными числами
void FillArray(int** arr, size_t rows, size_t cols)
{
	for (size_t i = 0; i < rows; ++i)
	{
		for (size_t j = 0; j < cols; ++j)
		{
			arr[i][j] = rand() % 10; // Для примера, числа от 0 до 9
		}
	}
}

// Функция для печати массива
void PrintArray(int** arr, size_t rows, size_t cols)
{
	for (size_t i = 0; i < rows; ++i)
	{
		for (size_t j = 0; j < cols; ++j)
		{
			std::cout << arr[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

// Функция добавления строки в конец двумерного массива
size_t AddRowToBack(int**& arr, size_t rows, size_t cols, const int* newRowValues)
{
	// Создаем новый массив с размером на одну строку больше
	int** newArr = new int* [rows + 1];

	// Копируем существующие строки в новый массив
	for (size_t i = 0; i < rows; ++i)
	{
		newArr[i] = new int[cols];
		for (size_t j = 0; j < cols; ++j)
		{
			newArr[i][j] = arr[i][j];
		}
	}

	// Добавляем новую строку в конец нового массива
	newArr[rows] = new int[cols];
	for (size_t j = 0; j < cols; ++j) 
	{
		newArr[rows][j] = newRowValues[j];
	}

	// Удаляем старый массив
	for (size_t i = 0; i < rows; ++i)
	{
		delete[] arr[i];
	}
	delete[] arr;

	// Обновляем указатель на массив
	arr = newArr;

	return ++rows;
}

int main() 
{
	setlocale(LC_ALL, "rus");
	srand(static_cast<unsigned int>(time(NULL)));

	// Выделение памяти
	int** arr = new int* [MAX_ROWS];
	for (size_t i = 0; i < MAX_ROWS; ++i)
	{
		arr[i] = new int[MAX_COLS];
	}

	// Заполнение массива
	FillArray(arr, MAX_ROWS, MAX_COLS);

	std::cout << "Исходный массив: " << std::endl;
	PrintArray(arr, MAX_ROWS, MAX_COLS);

	// Значения для новой строки
	int newRowValues[MAX_COLS] = { 1, 1, 1 };

	// Добавляем новую строку в массив
	size_t newRows = AddRowToBack(arr, MAX_ROWS, MAX_COLS, newRowValues);

	std::cout << "Массив после добавления строки: " << std::endl;
	PrintArray(arr, newRows, MAX_COLS);

	// Освобождаем память
	for (size_t i = 0; i < newRows; ++i)
	{
		delete[] arr[i];
	}
	delete[] arr;

	return 0;
}
