#include <iostream>

using namespace std;


class SmartArray {
private:
	int* arr;
	int len{};
	int cur{ 0 };

public:
	SmartArray(int len) {
		if (len < 0) {
			throw invalid_argument("Array size must be greater then 0");
		}
		arr = new int[len];
		this->len = len;
	}

	SmartArray(const SmartArray& otherArr) : len(otherArr.len), cur(otherArr.cur) {
		arr = new int[len];

		for (int i = 0; i < len; ++i) {
			arr[i] = otherArr.arr[i];
		}
	}

	SmartArray& operator=(const SmartArray& other) {
		if (this != &other) {
			delete[] arr;
			len = other.len;
			cur = other.cur;
			arr = new int[len];
			for (int i = 0; i < cur; ++i) {
				arr[i] = other.arr[i];
			}
		}
		return *this;
	}

	bool addElement(int elem) {
		if (cur < len) {
			arr[cur++] = elem;
			return true;
		}
		throw overflow_error("The array is full");
	}

	int getElement(int index) {
		if (index < 0 || index >= len) {
			throw out_of_range("Index out of range");
		}
		return arr[index];
	}

	~SmartArray() {
		delete[] arr;
	}
};


int main() {
	try
	{
		SmartArray arr(5);
		arr.addElement(1);
		arr.addElement(4);
		arr.addElement(155);

		SmartArray newArr(2);
		newArr.addElement(44);
		newArr.addElement(34);

		arr = newArr;
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}
}