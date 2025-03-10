#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>


struct SymbolFreq {
	char symbol;
	int freq;
};


int main() {
	std::string str{};
	std::unordered_map<char, int> freqMap{};

	std::cout << "Input text: ";
	std::getline(std::cin, str);

	for (char c : str) {
		++freqMap[c];
	}

	std::vector<SymbolFreq> frequencies{};
	for (const auto& pair : freqMap) {
		frequencies.push_back({ pair.first, pair.second });
	}

	std::sort(frequencies.begin(), frequencies.end(),
		[](const SymbolFreq& a, const SymbolFreq& b) {
			return a.freq > b.freq;
		});

	for (const auto& item : frequencies) {
		std::cout << item.symbol << ": " << item.freq << std::endl;
	}

    return 0;
}