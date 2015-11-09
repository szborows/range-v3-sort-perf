#include <range/v3/all.hpp>
#include <vector>

using namespace std;

extern vector<vector<int>> d2;

int main() {
    for (int i = 0; i < 1000; ++i) {
        asm volatile("");
        ranges::sort(d2[i]);
    }
}
