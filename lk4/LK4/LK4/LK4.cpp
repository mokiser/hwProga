#include <iostream>

class LinkedList {
private:
	struct Node {
		int data;
		Node* nextNode;
	};

	Node* firstNode = nullptr;
	Node* lastNode = nullptr;
	int size = 0;

public:
	void append(int newData) {
		Node* newNode = new Node{ newData, nullptr };

		if (lastNode) {
			lastNode->nextNode = newNode;
			lastNode = newNode;
		}
		else {
			firstNode = lastNode = newNode;
		}

		++size;
	}

	int fetch(int index) const {
		if (index < size) {
			Node* currentNode = firstNode;

			for (int i = 0; i < index; ++i) {
				currentNode = currentNode->nextNode;
			}

			return currentNode->data;
		}

		return NULL;
	}

	int* fetchAll() const {
		int* array = new int[size];
		Node* currentNode = firstNode;

		for (int i = 0; i < size; ++i) {
			array[i] = currentNode->data;
			currentNode = currentNode->nextNode;
		}

		return array;
	}

	void remove(int index) {
		if (index >= size) return;

		Node* currentNode = firstNode;
		Node* previousNode = nullptr;

		for (int i = 0; i < index; ++i) {
			previousNode = currentNode;
			currentNode = currentNode->nextNode;
		}

		if (previousNode) {
			previousNode->nextNode = currentNode->nextNode;
		}
		else {
			firstNode = firstNode->nextNode;
		}

		if (currentNode == lastNode) {
			lastNode = previousNode;
		}

		delete currentNode;
		--size;
	}

	int getSize() const {
		return size;
	}

	~LinkedList() {
		Node* currentNode = firstNode;

		while (currentNode) {
			Node* nextNode = currentNode->nextNode;
			delete currentNode;
			currentNode = nextNode;
		}
	}
};

int main() {
	LinkedList list;
	list.append(10);
	list.append(20);
	list.append(30);

	int* array = list.fetchAll();
	int length = list.getSize();

	for (int i = 0; i < length; ++i) {
		std::cout << array[i];
	}
	std::cout << std::endl;

	list.remove(0);
	array = list.fetchAll();
	length = list.getSize();

	for (int i = 0; i < length; ++i) {
		std::cout << array[i];
	}

	delete[] array;
	return 0;
}
