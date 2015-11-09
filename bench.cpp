#include <range/v3/all.hpp>
#include <chrono>
#include <vector>
#include <iostream>

using namespace std;

extern vector<vector<int>> d1;
extern vector<vector<int>> d2;

int main() {
    auto start = std::chrono::system_clock::now();

    for (int i = 0; i < 1000; ++i) {
        asm volatile("");
        sort(std::begin(d1[i]), std::end(d1[i]));
    }

    auto end = std::chrono::system_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << elapsed.count() << '\n';

    start = std::chrono::system_clock::now();
    for (int i = 0; i < 1000; ++i) {
        asm volatile("");
        ranges::sort(d2[i]);
    }

    end = std::chrono::system_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << elapsed.count() << '\n';
}
