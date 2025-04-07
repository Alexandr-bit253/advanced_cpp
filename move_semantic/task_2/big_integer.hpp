#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <stdexcept>
#include <algorithm>

class big_integer {
private:
    std::vector<int> digits;


    void remove_leading_zeros() {
        while (digits.size() > 1 && digits.back() == 0) {
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
            digits.push_back(c - '0');
        }

        if (digits.empty()) {
            digits.push_back(0);
        }

        remove_leading_zeros();
    }


    big_integer(big_integer&& other) noexcept = default;


    big_integer& operator=(big_integer&& other) noexcept = default;


    big_integer(const big_integer&) = default;
    big_integer& operator=(const big_integer&) = default;


    big_integer operator+(const big_integer& other) const {
        big_integer result;
        int carry = 0;
        size_t max_len = std::max(digits.size(), other.digits.size());

        for (size_t i = 0; i < max_len || carry != 0; ++i) {
            int d1 = (i < digits.size()) ? digits[i] : 0;
            int d2 = (i < other.digits.size()) ? other.digits[i] : 0;
            int sum = d1 + d2 + carry;

            result.digits.push_back(sum % 10);
            carry = sum / 10;
        }

        result.remove_leading_zeros();
        return result;
    }

    
    big_integer operator*(const big_integer& other) const {
        big_integer result;
        result.digits.resize(digits.size() + other.digits.size(), 0);

        for (size_t i = 0; i < digits.size(); ++i) {
            int carry = 0;
            for (size_t j = 0; j < other.digits.size() || carry != 0; ++j) {
                int d2 = (j < other.digits.size()) ? other.digits[j] : 0;
                int sum = result.digits[i + j] + digits[i] * d2 + carry;
                result.digits[i + j] = sum % 10;
                carry = sum / 10;
            }
        }

        result.remove_leading_zeros();
        return result;
    }

    
    big_integer operator*(int num) const {
        if (num < 0 || num > 9) {
            throw std::invalid_argument("only single-digit multiplication supported");
        }

        big_integer result;
        int carry = 0;

        for (size_t i = 0; i < digits.size() || carry != 0; ++i) {
            int d = (i < digits.size()) ? digits[i] : 0;
            int mul = d * num + carry;
            result.digits.push_back(mul % 10);
            carry = mul / 10;
        }

        result.remove_leading_zeros();
        return result;
    }

    friend std::ostream& operator<<(std::ostream& os, const big_integer& num) {
        for (auto it = num.digits.rbegin(); it != num.digits.rend(); ++it) {
            os << *it;
        }
        return os;
    }
};
