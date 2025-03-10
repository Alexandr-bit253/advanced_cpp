#include <iostream>

#include "MyVector.hpp"


int main() {
	MyVector<int> vec;

	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);

	std::cout << "element at index 1: " << vec.at(1) << std::endl;
	std::cout << "size: " << vec.size() << std::endl;
	std::cout << "capacity: " << vec.capacity() << std::endl;

	return 0;
}