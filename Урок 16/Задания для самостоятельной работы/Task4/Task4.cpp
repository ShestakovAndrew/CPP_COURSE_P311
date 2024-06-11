#include <iostream>
#include <string>

struct WashingMachine 
{
	std::string company;
	std::string color;
	size_t width;
	size_t length;
	size_t height;
	size_t power;
	size_t spinSpeed;
	size_t heatingTemperature;
};

void PrintWashingMachine(WashingMachine const& machine) 
{
	std::cout << "Стиральная машинка:" << std::endl;
	std::cout << "  Фирма: " << machine.company << std::endl;
	std::cout << "  Цвет: " << machine.color << std::endl;
	std::cout << "  Размеры: " << machine.width << "x" << machine.length << "x" << machine.height << " см" << std::endl;
	std::cout << "  Мощность: " << machine.power << " Вт" << std::endl;
	std::cout << "  Скорость отжима: " << machine.spinSpeed << " об/мин" << std::endl;
	std::cout << "  Температура нагрева: " << machine.heatingTemperature << " °C" << std::endl;
}

// Функция для изменения цвета стиральной машинки
void ChangeColor(WashingMachine& machine, std::string const& newColor)
{
	machine.color = newColor;
}

// Функция для изменения скорости отжима
void ChangeSpinSpeed(WashingMachine& machine, size_t newSpinSpeed) 
{
	machine.spinSpeed = newSpinSpeed;
}

// Функция для изменения температуры нагрева
void ChangeHeatingTemperature(WashingMachine& machine, size_t newHeatingTemperature) 
{
	machine.heatingTemperature = newHeatingTemperature;
}

int main() 
{
	setlocale(LC_ALL, "rus");

	WashingMachine myMachine; // Создаем экземпляр структуры

	// Задаем значения для стиральной машинки
	myMachine.company = "Samsung";
	myMachine.color = "Белый";
	myMachine.width = 60;
	myMachine.length = 55;
	myMachine.height = 85;
	myMachine.power = 2000;
	myMachine.spinSpeed = 1200;
	myMachine.heatingTemperature = 90;

	// Выводим информацию о стиральной машинке
	PrintWashingMachine(myMachine);

	// Изменяем цвет
	ChangeColor(myMachine, "Серый");
	std::cout << std::endl << "Измененный цвет: " << std::endl;
	PrintWashingMachine(myMachine);

	// Изменяем скорость отжима
	ChangeSpinSpeed(myMachine, 1400);
	std::cout << std::endl << "Измененная скорость отжима: " << std::endl;
	PrintWashingMachine(myMachine);

	// Изменяем температуру нагрева
	ChangeHeatingTemperature(myMachine, 60);
	std::cout << std::endl << "Измененная температура нагрева: " << std::endl;
	PrintWashingMachine(myMachine);

	return 0;
}
