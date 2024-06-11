#include <iostream>
#include <string>

struct Boiler 
{
	std::string company;
	std::string color;
	size_t power;
	size_t volume;
	size_t heatingTemperature;
};

// Функция для вывода информации о бойлере
void PrintBoiler(Boiler const& boiler)
{
	std::cout << "Бойлер:" << std::endl;
	std::cout << "  Фирма: " << boiler.company << std::endl;
	std::cout << "  Цвет: " << boiler.color << std::endl;
	std::cout << "  Мощность: " << boiler.power << " Вт" << std::endl;
	std::cout << "  Объем: " << boiler.volume << " л" << std::endl;
	std::cout << "  Температура нагрева: " << boiler.heatingTemperature << " °C" << std::endl;
}

// Функция для изменения цвета бойлера
void ChangeColor(Boiler& boiler, std::string const& newColor)
{
	boiler.color = newColor;
}

// Функция для изменения температуры нагрева
void ChangeHeatingTemperature(Boiler& boiler, size_t newHeatingTemperature)
{
	boiler.heatingTemperature = newHeatingTemperature;
}

int main() 
{
	setlocale(LC_ALL, "rus");

	Boiler boiler; // Создаем экземпляр структуры

	// Задаем значения для бойлера
	myBoiler.company = "Ariston";
	myBoiler.color = "Белый";
	myBoiler.power = 2000;
	myBoiler.volume = 80;
	myBoiler.heatingTemperature = 75;

	// Выводим информацию о бойлере
	PrintBoiler(myBoiler);

	// Изменяем цвет
	ChangeColor(myBoiler, "Серый");
	std::cout << std::endl << "Измененный цвет: " << std::endl;
	PrintBoiler(myBoiler);

	// Изменяем температуру нагрева
	ChangeHeatingTemperature(myBoiler, 60);
	std::cout << std::endl << "Измененная температура нагрева: " << std::endl;
	PrintBoiler(myBoiler);

	return 0;
}
