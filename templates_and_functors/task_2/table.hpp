#pragma once

#include <vector>


template <typename T>
class Table {
public:
	Table(size_t rows, size_t cols) : data(rows, std::vector<T>(cols)) {}

	std::vector<T>& operator[](size_t index) {
		return data[index];
	}

	const std::vector<T>& operator[](size_t index) const {
		return data[index];
	}

	std::pair<size_t, size_t> Size() const {
		return { data.size(), data.empty() ? 0 : data[0].size() };
	}

private:
	std::vector<std::vector<T>> data;
};