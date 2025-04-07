#include <iostream>
#include <sstream>
#include <cassert>
#include "big_integer.hpp"

int main() {
    auto number1 = big_integer("999999999999999999999");
    auto number2 = big_integer("1");
    auto result = number1 + number2;

    std::stringstream ss;
    ss << result;
    assert(ss.str() == "1000000000000000000000");

    std::cout << number1 << " + " << number2 << " = " << result << "\n";

    auto multiplied = number1 * 2;
    std::cout << number1 << " * 2 = " << multiplied << "\n";

    return 0;
}
