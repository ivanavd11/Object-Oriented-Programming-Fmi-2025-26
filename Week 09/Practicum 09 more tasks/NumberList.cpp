#include <print>
#include <vector>
#include <algorithm>

class NumberList {
    std::vector<int> numbers;

public:
    void addNum(int num) {
        numbers.push_back(num);
    }

    void sortAscending() {
        std::sort(numbers.begin(), numbers.end());
    }

    void sortDescending() {
        std::sort(numbers.begin(), numbers.end(), std::greater<int>());

        // алтернатвивно може и така:
        // sortAscending();
        // std::reverse(numbers.begin(), numbers.end());
        // не е най-доброто решение, но работи
    }

    void printAll() const {
        for (const int& x : numbers)
            print("{} ", x);
    }
};