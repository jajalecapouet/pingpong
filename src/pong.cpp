#include <iostream>
#include <string>
#include <unistd.h>

int main()
{
	std::string line;
	std::cerr << "pong : Me too !\n";
	while (1)
	{
		std::cin >> line;
		std::cerr << "pong : ping said to me " << line << '\n';
		sleep(1);
		std::cout << "PONG!\n";
	}
}
