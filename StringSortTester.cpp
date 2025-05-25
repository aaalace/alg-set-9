#include <algorithm>
#include <iomanip>
#include <iostream>

StringSortTester::StringSortTester() {}

void StringSortTester::testSort(
    std::function<void(std::vector<std::string> &, uint64_t &)> sort_func,
    int del,
    std::string &str,
    std::function<std::vector<std::string>(size_t)> gen
) {
    std::ofstream fle(str);
    for (size_t curSize = 100; curSize <= 3000; curSize += 100) {
        std::cout << "Running: " << std::to_string(curSize) << '\n';
        uint64_t timeSum = 0;
        uint64_t comparses = 0;
        std::vector<std::string> lst;
        uint64_t comp = 0;
        for (int32_t j = 0; j < del; ++j) {
            lst = gen(curSize);
            auto start = std::chrono::high_resolution_clock::now();
            sort_func(lst, comp);
            auto time = std::chrono::high_resolution_clock::now() - start;
            uint64_t microsec = std::chrono::duration_cast<std::chrono::microseconds>(time).count();
            timeSum += microsec;
            comparses += comp;
            comp = 0;
        }
        fle << std::to_string(curSize) + " --- " +
                std::to_string(static_cast<double>(timeSum) / del) + " --- " +
                std::to_string(static_cast<double>(comparses) / del) + '\n';
    }
    dataFile.close();
}
