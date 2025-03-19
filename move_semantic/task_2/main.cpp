#include <iostream>
#include "big_integer.hpp"


int main() {
	auto number1 = big_integer("114575");
	auto number2 = big_integer("78524");
	auto result1 = number1 + number2;
	auto result2 = number1 * number2;
	
	std::cout << number1 << " + " << number2 << " = " << result1 << std::endl;
	std::cout << number2 << " * " << number2 << " = " << result2 << std::endl;
}