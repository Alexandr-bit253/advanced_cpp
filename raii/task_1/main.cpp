#include <iostream>

using namespace std;


class SmartArray {
private:
	int* arr;
	size_t len{};
	size_t cur{ 0 };

public:
	SmartArray(int len) {
		if (len < 0) {
			throw invalid_argument("Array size must be greater then 0");
		}
		arr = new int[len];
		this->len = len;
	}

	void addElement(int elem) {
		if (cur >= len) {
			throw std::overflow_error("The array is full");
		}
		arr[cur++] = elem;
	}

	int getElement(size_t index) {
		if (index >= cur) {
			throw std::out_of_range("Index out of range");
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
		arr.addElement(14);
		arr.addElement(15);
		cout << arr.getElement(4) << endl;
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}
}