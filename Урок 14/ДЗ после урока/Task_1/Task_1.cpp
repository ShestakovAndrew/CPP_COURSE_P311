#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> d2vector_init()
{
	int rows, cols;
	std::cout << "Введите количество строк и столбцов массива(строки, столбцы): ";
	std::cin >> rows >> cols;
	std::vector<std::vector<int>> d2vector(rows, std::vector<int>(cols));

	for (int i = 0; i != rows; ++i)
	{
		for (int j = 0; j != cols; ++j)
		{
			std::cin >> d2vector[i][j];
		}
	}
	return d2vector;
}

void d2vector_cout(std::vector<std::vector<int>> const& d2vector)
{
	for (auto const& row : d2vector)
	{
		for (auto el : row)
		{
			std::cout << el << " ";
		}
		std::cout << std::endl;
	}
}

bool IsElementInMatrix(std::vector<std::vector<int>> const& matrix, int element)
{
	for (const auto& row : matrix)
	{
		if (std::find(row.begin(), row.end(), element) != row.end())
		{
			return true;
		}
	}
	return false;
}

int main()
{
	setlocale(LC_ALL, "rus");

	std::cout << "---Массив A---" << std::endl;
	std::vector<std::vector<int>> A = d2vector_init();
	d2vector_cout(A);

	std::cout << "\n---Массив B---" << std::endl;
	std::vector<std::vector<int>> B = d2vector_init();
	d2vector_cout(B);

	std::cout << "\n---Массив C---" << std::endl;
	std::vector<std::vector<int>> C = d2vector_init();
	d2vector_cout(C);

	std::vector<int> common_ABC;
	for (auto const& row : A)
	{
		for (int el : row)
		{
			if (std::find(common_ABC.begin(), common_ABC.end(), el) == common_ABC.end() &&
				element_in_matrix(B, el) &&
				element_in_matrix(C, el))
			{
				common_ABC.push_back(el);
			}
		}
	}

	std::cout << "\n---Общие элементы---" << std::endl;
	for (int el : common_ABC)
	{
		std::cout << el << " ";
	}
	std::cout << std::endl;

	return 0;
}
