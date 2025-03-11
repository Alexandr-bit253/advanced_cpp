#pragma once

#include <stdexcept>


template <typename T>
class MyVector {
private:
	T* data;
	size_t vec_size;
	size_t vec_capacity;

	void resize();

public:
	MyVector();
	MyVector(const MyVector<T>& other);
	~MyVector();

	void push_back(const T& value);
	T at(size_t index) const;
	size_t size() const;
	size_t capacity() const;
	MyVector<T>& operator=(const MyVector<T>& other);
};


template <typename T>
MyVector<T>::MyVector() : data(nullptr), vec_size(0), vec_capacity(0) {}


template <typename T>
MyVector<T>::MyVector(const MyVector<T>& other)
	: vec_size(other.vec_size), vec_capacity(other.vec_capacity), data(nullptr)
{
	if (vec_capacity > 0) {
		data = new T[vec_capacity];
		std::copy(other.data, other.data + vec_size, data);
	}
}


template <typename T>
MyVector<T>::~MyVector(){
	delete[] data;
}


template <typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector<T>& other) {
	if (this == other) return *this;

	T* new_data = nullptr;
	if (other.vec_capacity > 0) {
		new_data = new T[other.vec_capacity];
		std::copy(other.data, other.data + other.vec_size, new_data);
	}

	delete[] data;

	data = new_data;
	vec_size = other.vec_size;
	vec_capacity = other.vec_capacity;

	return *this;
}


template <typename T>
void MyVector<T>::resize() {
	vec_capacity = (vec_capacity == 0) ? 1 : vec_capacity * 2;
	T* new_data = new T[vec_capacity];

	for (size_t i = 0; i < vec_size; ++i) {
		new_data[i] = data[i];
	}

	delete[] data;
	data = new_data;
}


template <typename T>
void MyVector<T>::push_back(const T& value) {
	if (vec_size == vec_capacity) {
		resize();
	}
	data[vec_size++] = value;
}


template <typename T>
T MyVector<T>::at(size_t index) const {
	if (index >= vec_size) {
		throw std::out_of_range("Index out of range");
	}
	return data[index];
}

template <typename T>
size_t MyVector<T>::size() const {
	return vec_size;
}

template <typename T>
size_t MyVector<T>::capacity() const {
	return vec_capacity;
}