#include <iostream>
#include <set>


int main() {
	int count{};
	std::set<int, std::greater<int>> numbers;

	std::cout << "Input count of numbers: ";
	std::cin >> count;

	std::cout << "Input numbers:\n";
	int num{};
	for (int i = 0; i < count; ++i) {
		std::cin >> num;
		numbers.insert(num);
	}

	std::cout << "[OUT]:\n";
	for (const auto& num : numbers) {
		std::cout << num << std::endl;
	}

	return 0;
}