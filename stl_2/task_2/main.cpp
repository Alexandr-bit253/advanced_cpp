#include <iostream>
#include <set>
#include <list>
#include <vector>


template <typename T>
void printContainer(const T& container) {
	for (auto it = container.begin(); it != container.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}


int main() {
	std::set<std::string> testSet{ "one", "two", "three", "four" };
	printContainer(testSet);

	std::list<std::string> testList{ "one", "two", "three", "four" };
	printContainer(testList);

	std::vector<std::string> testVector{ "one", "two", "three", "four" };
	printContainer(testVector);
	
	return 0;
}