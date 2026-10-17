#include "KenoNumbers.h"
#include <iostream>
#include <algorithm>
#include <random>

void KenoNumbers::generateNumbers() {
    // Generate Keno numbers
    std::vector <int> playerNumbers, kenoNumbers, matches;;

    std::random_device rd;
    std::mt19937 gen(rd());
    gen.seed(0);
    std::uniform_int_distribution<int> distrib(1, 80);
    int num;
    for (int i = 1; i <= 20; ) {
        num = distrib(gen);
        if (std::find(kenoNumbers.begin(), kenoNumbers.end(), num) == kenoNumbers.end()) {
            kenoNumbers.push_back(num);
            i++;
        }
    }
}

std::vector<int> KenoNumbers::getKenoNumbers() {
    return m_Numbers;
}
void KenoNumbers::printKenoNumbers() {
    std::sort(m_Numbers.begin(), m_Numbers.end());
    for (auto i:m_Numbers) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}
void KenoNumbers::clearKenoNumbers() {
    m_Numbers.clear();
}

