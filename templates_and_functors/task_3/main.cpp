#include <vector>
#include <iostream>
#include <algorithm>

#include "counter.hpp"


int main() {
	std::vector<int> numbers = { 4, 1, 3, 6, 25, 54 };

	Counter counter = std::for_each(numbers.begin(), numbers.end(), Counter());

	std::cout << "get_sum() = " << counter.get_sum() << std::endl;
	std::cout << "get_count() = " << counter.get_count() << std::endl;

	return 0;
}