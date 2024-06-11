#include <iostream>
#include <cmath>

struct Point 
{
	double x;
	double y;
};

// Функция для вычисления расстояния между двумя точками
double distance(Point const& p1, Point const& p2)
{
	double dx = p2.x - p1.x;
	double dy = p2.y - p1.y;
	return sqrt(dx * dx + dy * dy);
}

int main() 
{
	setlocale(LC_ALL, "rus");

	Point point1 = { 1.0, 2.0 };
	Point point2 = { 4.0, 6.0 };

	std::cout << "Расстояние между точками: " << distance(point1, point2) << std::endl;

	return 0;
}
