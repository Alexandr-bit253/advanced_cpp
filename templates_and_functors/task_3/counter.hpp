#pragma once

class Counter {
private:
	int sum{ 0 };
	int count{ 0 };

public:
	void operator()(int num) {
		if (num % 3 == 0) {
			sum += num;
			count++;
		}
	}

	int get_sum() const {
		return sum;
	}

	int get_count() const {
		return count;
	}
};