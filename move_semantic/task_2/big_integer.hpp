#pragma once 

#include <vector>


class big_integer {
private:
	std::vector<char> digits;


	void remove_leading_zeros() {
		while (digits.size() > 1 && digits.back() == '0') {
			digits.pop_back();
		}
	}


public:
	big_integer() = default;
	

	explicit big_integer(const std::string& s) {
		for (auto it = s.rbegin(); it != s.rend(); ++it) {
			char c = *it;
			if (c < '0' || c > '9') {
				throw std::invalid_argument("invalid digit");
			}
			digits.push_back(c);
		}

		if (digits.empty()) {
			digits.push_back('0');
		}

		remove_leading_zeros();
	}


	big_integer(big_integer&& other) noexcept = default;


	big_integer& operator=(big_integer&& other) noexcept = default;


	big_integer operator+(const big_integer& other) const {
		big_integer result;
		int carry{ 0 };
		size_t max_len = std::max(digits.size(), other.digits.size());
		for (size_t i = 0; i < max_len; ++i) {
			int d1 = (i < digits.size()) ? (digits[i] - '0') : 0;
			int d2 = (i < other.digits.size()) ? (other.digits[i] - '0') : 0;
			int sum = d1 + d2 + carry;
			carry = sum / 10;
			result.digits.push_back((sum % 10) + '0');
		}
		result.remove_leading_zeros();
		return result;
	}


	big_integer operator*(const big_integer& other) const {
		big_integer result;
		result.digits.resize(digits.size() + other.digits.size(), '0');

		for (size_t i = 0; i < digits.size(); ++i) {
			int carry = 0;
			for (size_t j = 0; j < other.digits.size() || carry != 0; ++j) {
				int mul = (j < other.digits.size()) ? (digits[i] - '0') * (other.digits[j] - '0') : 0;
				int current = (result.digits[i + j] - '0') + mul + carry;
				result.digits[i + j] = (current % 10) + '0';
				carry = current / 10;
			}
		}

		result.remove_leading_zeros();
		return result;
	}


	friend std::ostream& operator<<(std::ostream& os, const big_integer& num) {
		if (num.digits.empty()) {
			os << '0';
		}
		else {
			for (auto it = num.digits.rbegin(); it != num.digits.rend(); ++it) {
				os << *it;
			}
		}
		return os;
	}
};