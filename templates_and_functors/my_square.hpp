#pragma once 

#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>


template<typename T>
T my_square(const T& num) {
	return num * num;
}


template <typename T>
std::vector<T> my_square(const std::vector<T>& v) {
	std::vector<T> result(v.size());
	std::transform(v.begin(), v.end(), result.begin(), [](const T& x) { return x * x; });
	return result;
}


template <typename T>
void print_vector(const std::vector<T>& v) {
	if (!v.empty()) {
		for (size_t i = 0; i < v.size(); ++i) {
			std::cout << v[i];
			if (i + 1 < v.size()) std::cout << ", ";
		}
	}
}