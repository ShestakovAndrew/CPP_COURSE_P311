#include <iostream>
#include <string>

struct Iron 
{
	std::string company;
	std::string model;
	std::string color;
	size_t minTemperature;
	size_t maxTemperature;
	bool steamSupply;
	size_t power;
};

// Функция для вывода информации об утюге
void PrintIron(const Iron& iron) 
{
	std::cout << "Утюг:" << std::endl;
	std::cout << "  Фирма: " << iron.company << std::endl;
	std::cout << "  Модель: " << iron.model << std::endl;
	std::cout << "  Цвет: " << iron.color << std::endl;
	std::cout << "  Температура: " << iron.minTemperature << " - " << iron.maxTemperature << " °C" << std::endl;
	std::cout << "  Подача пара: " << (iron.steamSupply ? "Да" : "Нет") << std::endl;
	std::cout << "  Мощность: " << iron.power << " Вт" << std::endl;
}

// Функция для изменения цвета утюга
void ChangeColor(Iron& iron, std::string const& newColor)
{
	iron.color = newColor;
}

// Функция для изменения минимальной температуры
void ChangeMinTemperature(Iron& iron, int newMinTemperature) 
{
	iron.minTemperature = newMinTemperature;
}

// Функция для изменения максимальной температуры
void ChangeMaxTemperature(Iron& iron, int newMaxTemperature) 
{
	iron.maxTemperature = newMaxTemperature;
}

// Функция для включения/отключения подачи пара
void ToggleSteamSupply(Iron& iron) 
{
	iron.steamSupply = !iron.steamSupply;
}

int main() 
{
	setlocale(LC_ALL, "rus");

	Iron myIron; // Создаем экземпляр структуры

	// Задаем значения для утюга
	myIron.company = "Philips";
	myIron.model = "GC4505";
	myIron.color = "Синий";
	myIron.minTemperature = 110;
	myIron.maxTemperature = 240;
	myIron.steamSupply = true;
	myIron.power = 2400;

	// Выводим информацию об утюге
	PrintIron(myIron);

	// Изменяем цвет
	ChangeColor(myIron, "Черный");
	std::cout << std::endl << "Измененный цвет: " << std::endl;
	PrintIron(myIron);

	// Изменяем минимальную температуру
	ChangeMinTemperature(myIron, 130);
	std::cout << std::endl << "Измененная минимальная температура: " << std::endl;
	PrintIron(myIron);

	// Отключаем подачу пара
	ToggleSteamSupply(myIron);
	std::cout << std::endl << "Подача пара отключена: " << std::endl;
	PrintIron(myIron);

	return 0;
}
