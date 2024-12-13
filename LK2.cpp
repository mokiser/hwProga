#include <iostream>

class FString
{
private:
	int len;
	char* buf;
public:
	FString(int temp)
	{
		len = temp;
		if (len > 0) {
			buf = new char[len];
			for (int i = 0; i < len; i++) {
				buf[i] = '0';
			};
		};
	};

	void show()
	{
		for (int i = 0; i < len; i++) {
			std::cout << buf[i];
		};
		std::cout << std::endl;
	};

	~FString()
	{
		delete[] buf;
		len = 0;
	};
};

int main()
{
	int len;
	std::cout << "Enter length of String: ";
	std::cin >> len;
	FString line(len);
	line.show();
	return 0;
}