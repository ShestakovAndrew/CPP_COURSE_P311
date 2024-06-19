#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Функция для создания одномерного массива с общими значениями для A, B, C
vector<int> FindCommonValues(
	vector<vector<int>> const& A,
	vector<vector<int>> const& B,
	vector<vector<int>> const& C
)
{
	vector<int> commonValues;

	for (const auto& rowA : A)
	{
		for (int valueA : rowA)
		{
			bool foundInB = false;
			bool foundInC = false;

			for (const auto& rowB : B)
			{
				if (find(rowB.begin(), rowB.end(), valueA) != rowB.end())
				{
					foundInB = true;
					break;
				}
			}

			for (const auto& rowC : C)
			{
				if (find(rowC.begin(), rowC.end(), valueA) != rowC.end())
				{
					foundInC = true;
					break;
				}
			}

			if (foundInB && foundInC)
			{
				commonValues.push_back(valueA);
			}
		}
	}

	// Удаляем дубликаты
	sort(commonValues.begin(), commonValues.end());
	commonValues.erase(unique(commonValues.begin(), commonValues.end()), commonValues.end());

	return commonValues;
}

// Функция для создания одномерного массива с уникальными значениями для A, B, C
vector<int> FindUniqueValues(
	vector<vector<int>> const& A,
	vector<vector<int>> const& B,
	vector<vector<int>> const& C
)
{
	vector<int> allValues;

	// Собираем все значения в один вектор
	for (const auto& row : A)
	{
		allValues.insert(allValues.end(), row.begin(), row.end());
	}

	for (const auto& row : B)
	{
		allValues.insert(allValues.end(), row.begin(), row.end());
	}

	for (const auto& row : C)
	{
		allValues.insert(allValues.end(), row.begin(), row.end());
	}

	// Удаляем дубликаты
	sort(allValues.begin(), allValues.end());
	allValues.erase(unique(allValues.begin(), allValues.end()), allValues.end());

	return allValues;
}

// Функция для создания одномерного массива с общими значениями для A и C
vector<int> FindCommonValuesAC(
	vector<vector<int>> const& A,
	vector<vector<int>> const& C
)
{
	vector<int> commonValues;

	for (const auto& rowA : A)
	{
		for (int valueA : rowA)
		{
			for (const auto& rowC : C)
			{
				if (find(rowC.begin(), rowC.end(), valueA) != rowC.end())
				{
					commonValues.push_back(valueA);
					break;
				}
			}
		}
	}

	// Удаляем дубликаты
	sort(commonValues.begin(), commonValues.end());
	commonValues.erase(unique(commonValues.begin(), commonValues.end()), commonValues.end());

	return commonValues;
}

// Функция для создания одномерного массива с отрицательными значениями для A, B, C без повторений
vector<size_t> FindNegativeValues(
	const vector<vector<size_t>>& A,
	const vector<vector<size_t>>& B,
	const vector<vector<size_t>>& C
)
{
	vector<size_t> negativeValues;

	for (const auto& row : A)
	{
		for (int value : row)
		{
			if (value < 0 && find(negativeValues.begin(), negativeValues.end(), value) == negativeValues.end())
			{
				negativeValues.push_back(value);
			}
		}
	}

	for (const auto& row : B)
	{
		for (size_t value : row)
		{
			if (value < 0 && find(negativeValues.begin(), negativeValues.end(), value) == negativeValues.end())
			{
				negativeValues.push_back(value);
			}
		}
	}

	for (const auto& row : C)
	{
		for (size_t value : row)
		{
			if (value < 0 && find(negativeValues.begin(), negativeValues.end(), value) == negativeValues.end())
			{
				negativeValues.push_back(value);
			}
		}
	}

	return negativeValues;
}

void FillMatrix(vector<vector<size_t>>& matrix)
{
	for (size_t i = 0; i < matrix.size(); i++)
	{
		for (size_t j = 0; j < matrix[i].size(); j++)
		{
			matrix[i][j] = rand() % 10;
		}
	}
}

void PrintArray(vector<size_t> const& arr)
{
	for (size_t value : arr)
	{
		cout << value << " ";
	}
	cout << endl;
}

int main() 
{
	setlocale(LC_ALL, "rus");

	size_t rowsA, colsA, rowsB, colsB, rowsC, colsC;

	// Ввод размеров массивов
	cout << "Введите количество строк и столбцов для массива A: ";
	cin >> rowsA >> colsA;
	cout << "Введите количество строк и столбцов для массива B: ";
	cin >> rowsB >> colsB;
	cout << "Введите количество строк и столбцов для массива C: ";
	cin >> rowsC >> colsC;

	// Создание массивов
	vector<vector<size_t>> A(rowsA, vector<size_t>(colsA));
	vector<vector<size_t>> B(rowsB, vector<size_t>(colsB));
	vector<vector<size_t>> C(rowsC, vector<size_t>(colsC));

	// Заполнение матриц 
	FillMatrix(A);
	FillMatrix(B);
	FillMatrix(C);

	// Вычисление и вывод результатов
	cout << "Общие значения для A, B, C:\n";
	vector<size_t> commonValues = FindCommonValues(A, B, C); // вызов функции, которая должна быть определена
	PrintArray(commonValues);


	cout << "Уникальные значения для A, B, C:\n";
	vector<size_t> uniqueValues = FindUniqueValues(A, B, C); // вызов функции, которая должна быть определена
	PrintArray(uniqueValues);

	cout << "Общие значения для A и C:\n";
	vector<size_t> commonValuesAC = FindCommonValuesAC(A, C); // вызов функции, которая должна быть определена
	PrintArray(commonValuesAC);

	cout << "Отрицательные значения для A, B, C без повторений:\n";
	vector<size_t> negativeValues = FindNegativeValues(A, B, C); // вызов функции, которая должна быть определена
	PrintArray(negativeValues);

	return 0;
}
