#include <iostream>

#define DEBUG 1

int main() 
{

#if DEBUG
	std::cout << "Режим отладки включен!" << std::endl;
#else
#error "Режим отладки отключен! Необходимо включить DEBUG."
#endif

	// ... остальной код программы ...

	return 0;
}
