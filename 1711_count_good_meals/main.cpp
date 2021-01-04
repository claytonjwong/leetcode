/*
 * 1711. Count Good Meals
 *
 * Q: https://leetcode.com/problems/count-good-meals/
 * A: https://leetcode.com/problems/count-good-meals/discuss/1001864/Kt-Js-Py3-Cpp-Map-%2B-Brute-Force-Search
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using Map = unordered_map<int, int>;
    int countPairs(VI& A, Map m = {}, int cnt = 0) {
        for (auto x: A) {
            for (auto t{ 1 }; t <= (1 << 21); t <<= 1) {
                auto y = t - x;
                if (0 <= y && m.find(y) != m.end())
                    cnt = (cnt + m[y]) % int(1e9 + 7);
            }
            ++m[x];
        }
        return cnt;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
