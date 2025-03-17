#include <iostream>

#include "unique_ptr.hpp"



int main() {
	UniquePtr<int> uptr(new int(3));
	std::cout << *uptr << std::endl;

	int* ptr = uptr.release();
	std::cout << *ptr << std::endl;

	delete ptr;

	return 0;
}