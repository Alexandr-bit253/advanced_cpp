#include <iostream>
#include "my_square.hpp"

int main() {
    int a = 4;
    std::cout << "[IN]: " << a << std::endl;
    std::cout << "[OUT]: " << my_square(a) << std::endl;

    std::vector<int> v{ -1, 4, 8 };

    std::cout << "[IN]: ";
    print_vector(v);
    std::cout << std::endl;

    std::cout << "[OUT]: ";
    print_vector(my_square(v));
    std::cout << std::endl;

    return 0;
}