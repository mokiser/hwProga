#include <iostream>
#include <string>

template<typename T, std::size_t Rows, std::size_t Cols>
class Image {
private:
	T imageData[Rows][Cols];

public:
	explicit Image(T initialValue);
	void setPixel(T value, std::size_t x, std::size_t y);
	void display() const;
};

template<typename T, std::size_t Rows, std::size_t Cols>
Image<T, Rows, Cols>::Image(T initialValue) {
	for (std::size_t row = 0; row < Rows; ++row) {
		for (std::size_t col = 0; col < Cols; ++col) {
			imageData[row][col] = initialValue;
		}
	}
}

template<typename T, std::size_t Rows, std::size_t Cols>
void Image<T, Rows, Cols>::setPixel(T value, std::size_t x, std::size_t y) {
	if (x >= Rows || y >= Cols) {
		throw std::out_of_range("Pixel coordinates out of range");
	}
	imageData[x][y] = value;
}

template<typename T, std::size_t Rows, std::size_t Cols>
void Image<T, Rows, Cols>::display() const {
	for (std::size_t row = 0; row < Rows; ++row) {
		for (std::size_t col = 0; col < Cols; ++col) {
			std::cout << imageData[row][col] << " ";
		}
		std::cout << std::endl;
	}
}

int main() {
	Image<std::string, 3, 3> stringImage("00");
	stringImage.setPixel("X", 1, 1);
	stringImage.display();

	std::cout << "\n";

	Image<int, 4, 4> intImage(0);
	intImage.setPixel(9, 2, 2);
	intImage.display();

	return 0;
}
