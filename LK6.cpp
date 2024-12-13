#include <iostream>
#include <map>
#include <mutex>
#include <stdexcept>

using namespace std;

struct Algorithm {
	int id;
	string description;
};

class AlgorithmCollection {
private:
	map<int, Algorithm> algorithmMap;
	mutex collectionMutex;

public:
	Algorithm getAlgorithm(int algorithmId) {
		lock_guard<mutex> lock(collectionMutex);
		auto it = algorithmMap.find(algorithmId);
		if (it != algorithmMap.end()) {
			return it->second;
		}
		else {
			throw runtime_error("Algorithm not found");
		}
	}

	void showAllAlgorithms() {
		lock_guard<mutex> lock(collectionMutex);
		for (const auto& entry : algorithmMap) {
			cout << entry.first << ": " << entry.second.description << endl;
		}
	}

	void addAlgorithm(int algorithmId, const string& description) {
		lock_guard<mutex> lock(collectionMutex);
		algorithmMap[algorithmId] = { algorithmId, description };
	}
};

int main() {
	AlgorithmCollection algorithmManager;

	algorithmManager.addAlgorithm(1, "Algorithm One");
	algorithmManager.addAlgorithm(2, "Algorithm Two");

	try {
		Algorithm currentAlgorithm = algorithmManager.getAlgorithm(1);
		cout << "Fetched algorithm with ID " << currentAlgorithm.id << " and description: " << currentAlgorithm.description << endl;
	}
	catch (const exception& ex) {
		cout << ex.what() << endl;
	}

	cout << endl << "All algorithms:" << endl;
	algorithmManager.showAllAlgorithms();

	return 0;
}
