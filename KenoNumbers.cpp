#include "KenoNumbers.h"
#include <iostream>
#include <algorithm>
#include <random>

void KenoNumbers::generateNumbers() {
    // Generate Keno numbers
    std::random_device rd;
    std::mt19937 gen(rd());
    gen.seed(0);
    std::uniform_int_distribution<int> distrib(1, 80);
    int num;
    for (int i = 1; i <= 20; ) {
        num = distrib(gen);
        if (std::find(m_numbers.begin(), m_numbers.end(), num) == m_numbers.end()) {
            m_numbers.push_back(num);
            i++;
        }
    }
}

std::vector<int> KenoNumbers::getKenoNumbers() {
    return m_numbers;
}
void KenoNumbers::printKenoNumbers() {
    std::sort(m_numbers.begin(), m_numbers.end());
    for (auto i:m_numbers) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}
void KenoNumbers::clearKenoNumbers() {
    m_numbers.clear();
}

