#include <iostream>
#include "mainConfig.h"
#include "FString.h"

int main()
{
	std::cout << "VERSION " << LK1_VERSION_MAJOR << std::endl;
	int len;
	std::cout << "Enter length of String: ";
	std::cin >> len;
	FString line(len);
	line.show();
	return 0;
}