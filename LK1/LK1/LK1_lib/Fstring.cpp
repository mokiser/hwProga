#include "FString.h"
#include <iostream>

FString::FString(int temp)
{
	len = temp;
	if (len > 0) {
		buf = new char[len];
		for (int i = 0; i < len; i++) {
			buf[i] = '0';
		};
	};
};

FString::FString(const FString &str) {
	len = str.len;
	buf = new char[len];
	for (unsigned int i = 0; i < len; ++i) {
		buf[i] = str.buf[i];
	}
}


void FString::show()
{
	for (int i = 0; i < len; i++) {
		std::cout << buf[i];
	};
	std::cout << std::endl;
};

FString::~FString()
{
	delete[] buf;
	len = 0;
};
