#include <iostream>

struct Rectangle 
{
	int x, y; // Координаты левого верхнего угла
	size_t width, height; // Ширина и высота
};

// Перемещение прямоугольника
void MoveRectangle(Rectangle& rectangle, int dx, int dy)
{
	rectangle.x += dx;
	rectangle.y += dy;
}

// Изменение размера прямоугольника
void ResizeRectangle(Rectangle& rectangle, size_t newWidth, size_t newHeight)
{
	rectangle.width = newWidth;
	rectangle.height = newHeight;
}

// Печать прямоугольника
void PrintRectangle(Rectangle const& rectangle)
{
	std::cout << "  Левый верхний угол: (" << rectangle.x << ", " << rectangle.y << ")" << std::endl;
	std::cout << "  Ширина: " << rectangle.width << std::endl;
	std::cout << "  Высота: " << rectangle.height << std::endl;
}

int main() 
{
	setlocale(LC_ALL, "rus");
	Rectangle rectangle = { 10, 20, 50, 30 }; // Создаем прямоугольник

	std::cout << "Исходный прямоугольник:" << std::endl;
	PrintRectangle(rectangle);

	MoveRectangle(rectangle, 15, -10); // Перемещаем прямоугольник
	std::cout << "\nПеремещенный прямоугольник:" << std::endl;
	PrintRectangle(rectangle);

	ResizeRectangle(rectangle, 70, 45); // Изменяем размер прямоугольника
	std::cout << "\nИзмененный прямоугольник:" << std::endl;
	PrintRectangle(rectangle);

	return 0;
}
