#include <iostream>
#include <vector>
#include <algorithm>


void removeDuplicate(std::vector<int>& vec) {
	std::sort(vec.begin(), vec.end());
	auto last = std::unique(vec.begin(), vec.end());
	vec.erase(last, vec.end());
}


void printVector(const std::vector<int>& vec) {
	for (auto num : vec) {
		std::cout << num << " ";
	}
	std::cout << std::endl;
}


int main() {
	std::vector<int> vec{ 1, 1, 2, 5, 6, 1, 2, 4 };
	printVector(vec);

	removeDuplicate(vec);
	printVector(vec);

	return 0;
}