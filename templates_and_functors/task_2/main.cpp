#include <iostream>

#include "table.hpp"


int main() {
	Table<int> test(2, 3);
	
	test[0][0] = 4;
	std::cout << test[0][0] << std::endl;

	auto [rows, cols] = test.Size();
	std::cout << "Table size: " << rows << " x " << cols << std::endl;

	return 0;
}