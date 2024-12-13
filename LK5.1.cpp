#include <iostream>
#include <string>

template<typename T>
class DynamicList {
	struct Element {
		T value;
		Element* nextElement = nullptr;
	};

	Element* firstElement;
	unsigned int elementCount;

public:
	DynamicList();
	DynamicList(DynamicList&& other) noexcept;
	~DynamicList();

	void insertAtPosition(T value, unsigned int position);
	void deleteAt(unsigned int position);
	T getValueAt(unsigned int position) const;
	void printList() const;
};

template<typename T>
DynamicList<T>::DynamicList() : firstElement(nullptr), elementCount(0) {}

template<typename T>
DynamicList<T>::DynamicList(DynamicList&& other) noexcept : firstElement(other.firstElement), elementCount(other.elementCount) {
	other.firstElement = nullptr;
	other.elementCount = 0;
}

template<typename T>
DynamicList<T>::~DynamicList() {
	while (firstElement != nullptr) {
		Element* temp = firstElement;
		firstElement = firstElement->nextElement;
		delete temp;
	}
}

template<typename T>
void DynamicList<T>::insertAtPosition(T value, unsigned int position) {
	if (position > elementCount) {
		throw std::out_of_range("Position out of bounds");
	}

	Element* newElement = new Element{ value, nullptr };

	if (position == 0) {
		newElement->nextElement = firstElement;
		firstElement = newElement;
	}
	else {
		Element* currentElement = firstElement;
		for (unsigned int i = 1; i < position; ++i) {
			currentElement = currentElement->nextElement;
		}
		newElement->nextElement = currentElement->nextElement;
		currentElement->nextElement = newElement;
	}

	++elementCount;
}

template<typename T>
void DynamicList<T>::deleteAt(unsigned int position) {
	if (position >= elementCount) {
		throw std::out_of_range("Position out of bounds");
	}

	Element* elementToDelete = nullptr;

	if (position == 0) {
		elementToDelete = firstElement;
		firstElement = firstElement->nextElement;
	}
	else {
		Element* currentElement = firstElement;
		for (unsigned int i = 1; i < position; ++i) {
			currentElement = currentElement->nextElement;
		}
		elementToDelete = currentElement->nextElement;
		currentElement->nextElement = elementToDelete->nextElement;
	}

	delete elementToDelete;
	--elementCount;
}

template<typename T>
T DynamicList<T>::getValueAt(unsigned int position) const {
	if (position >= elementCount) {
		throw std::out_of_range("Position out of bounds");
	}

	Element* currentElement = firstElement;
	for (unsigned int i = 0; i < position; ++i) {
		currentElement = currentElement->nextElement;
	}

	return currentElement->value;
}

template<typename T>
void DynamicList<T>::printList() const {
	Element* currentElement = firstElement;
	while (currentElement != nullptr) {
		std::cout << currentElement->value << " ";
		currentElement = currentElement->nextElement;
	}
	std::cout << std::endl;
}

int main() {
	DynamicList<int> intList;
	intList.insertAtPosition(10, 0);
	intList.insertAtPosition(20, 1);
	intList.insertAtPosition(30, 0);
	intList.printList();

	DynamicList<int> movedList(std::move(intList));
	movedList.printList();

	DynamicList<std::string> strList;
	strList.insertAtPosition("first", 0);
	strList.insertAtPosition("second", 1);
	strList.insertAtPosition("middle", 1);
	strList.printList();

	return 0;
}
