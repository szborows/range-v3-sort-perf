#include <vector>
#include <algorithm>

using namespace std;

extern vector<vector<int>> d1;

int main() {
    for (int i = 0; i < 1000; ++i) {
        asm volatile("");
        sort(std::begin(d1[i]), std::end(d1[i]));
    }
}
