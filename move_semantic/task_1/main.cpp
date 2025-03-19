#include <iostream>
#include <vector>


template <typename T>
void move_vectors(std::vector<T>& src, std::vector<T>& dst) {
	dst = std::move(src);
}


int main() {
	std::vector <std::string> one = { "test_string1", "test_string2" };
	std::vector <std::string> two;

	std::cout << "Before moving:\n";
	std::cout << "Vector one size: " << one.size() << "\n";
	std::cout << "Vector two size: " << two.size() << "\n";

	move_vectors(one, two);

	std::cout << "After moving:\n";
	std::cout << "Vector one size: " << one.size() << "\n";
	std::cout << "Vector two size: " << two.size() << "\n";

	return 0;
}