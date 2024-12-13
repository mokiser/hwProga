#include <thread>
#include <vector>
#include <iostream>

class Picture {
	int data[1000][1000]{};

public:
	Picture() = default;

	Picture(const Picture& other) {
		unsigned int coreCount = std::max(std::thread::hardware_concurrency(), 1u);
		unsigned int rowsPerCore = 1000 / coreCount;
		unsigned int remainingRows = 1000 % coreCount;

		std::vector<std::thread> workers;
		unsigned int firstRow = 0;

		for (unsigned int i = 0; i < coreCount; ++i) {
			unsigned int lastRow = firstRow + rowsPerCore + (i < remainingRows ? 1 : 0);

			workers.emplace_back([this, &other, firstRow, lastRow]() {
				for (unsigned int r = firstRow; r < lastRow; ++r) {
					for (unsigned int c = 0; c < 1000; ++c) {
						data[r][c] = other.data[r][c];
					}
				}
			});

			firstRow = lastRow;
		}

		for (auto& worker : workers) {
			worker.join();
		}
	}

	void display() const {
		for (unsigned int r = 0; r < 10; ++r) {
			for (unsigned int c = 0; c < 10; ++c) {
				std::cout << data[r][c] << " ";
			}
			std::cout << std::endl;
		}
	}
};

int main() {
	Picture original;
	std::cout << "Displaying original picture:" << std::endl;
	original.display();

	Picture duplicate = original;
	std::cout << "\nDisplaying duplicate picture:" << std::endl;
	duplicate.display();

	return 0;
}
