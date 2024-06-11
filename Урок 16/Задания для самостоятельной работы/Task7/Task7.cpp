#include <iostream>
#include <string>

#include "Windows.h"

// Перечисление для классов животных
enum AnimalClass 
{
	DOG,
	CAT,
	OTHER
};

struct Animal 
{
	std::string name;
	AnimalClass animalClass;
	std::string nickname;
};

// Функция для заполнения объекта
void FillAnimal(Animal& animal) 
{
	std::cout << "Введите название животного: ";
	std::getline(std::cin, animal.name);

	std::cout << "Введите класс животного (Собака, Кошка, Другое): ";
	std::string inputClass;
	std::getline(std::cin, inputClass);

	if (inputClass == "Собака") 
	{
		animal.animalClass = DOG;
	}
	else if (inputClass == "Кошка") 
	{
		animal.animalClass = CAT;
	}
	else 
	{
		animal.animalClass = OTHER;
	}

	std::cout << "Введите кличку животного: ";
	std::getline(std::cin, animal.nickname);
}

// Функция для вывода данных об объекте
void PrintAnimal(Animal const& animal) 
{
	std::cout << "Животное: " << std::endl;
	std::cout << "  Название: " << animal.name << std::endl;
	std::cout << "  Класс: ";
	switch (animal.animalClass) 
	{
		case DOG:
			std::cout << "Собака" << std::endl;
			break;
		case CAT:
			std::cout << "Кошка" << std::endl;
			break;
		case OTHER:
			std::cout << "Другое" << std::endl;
			break;
	}
	std::cout << "  Кличка: " << animal.nickname << std::endl;
}

// Функция «Подать голос»
void MakeSound(Animal const& animal)
{
	switch (animal.animalClass) 
	{
		case DOG:
			std::cout << "Гав-гав!" << std::endl;
			break;
		case CAT:
			std::cout << "Мяу!" << std::endl;
			break;
		case OTHER:
			std::cout << "..." << std::endl; // Неизвестное животное
			break;
	}
}

int main() 
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Animal animal; // Создаем экземпляр структуры

	// Заполняем объект
	FillAnimal(animal);

	// Выводим данные об объекте
	PrintAnimal(animal);

	// Подаем голос
	std::cout << std::endl << "Животное подает голос: " << std::endl;
	MakeSound(animal);

	return 0;
}
